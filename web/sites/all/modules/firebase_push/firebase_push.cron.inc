<?php

/**
 * @file
 * Drush commands to generate send push notification.
 */

/**
 * Create payload and send notificaitons drush call back.
 *
 * @param object $nid
 *   Node id to check.
 */
function firebase_push_trigger($nid) {

  // Get Token by device type.
  $device_tokens = firebase_push_get_tokens();
  // Stop right here if none of these users have any endpoint.
  if (empty($device_tokens)) {
    watchdog('firebase_push', 'No tokens found');
    return FALSE;
  }

  foreach ($device_tokens as $device_type => $tokens) {
    $payload = firebase_push_prepair_payload($nid, $device_type);
    if ($payload == FALSE) {
      watchdog('firebase_push', 'Payload is NULL for nid @nid and device type !type', array('@nid' => $nid, '!type' => $device_type));
      return FALSE;
    }

    $token_chunk = array_chunk($tokens, 1000);
    // print_r($token_chunk);
    if (is_array($token_chunk)) {
      foreach ($token_chunk as $token) {
        $payload['registration_ids'] = $token;
        firebase_push_send_message($payload);
      }
    }
    watchdog('firebase_push', 'firebase_push sent for nid @nid and device type !type', array('@nid' => $nid, '!type' => $device_type));
  }
  return TRUE;
}

/**
 * Create payload.
 *
 * @param int $nid
 *   The nid to prepare payload.
 */
function firebase_push_prepair_payload($nid, $device_type) {
  $node = node_load($nid);
  // If node changed before 10 minute. discard notificaiton of that node.
  if ($node->changed < strtotime("-10 minutes")) {
    watchdog('firebase_push', 'News published before 10 minutes. Message expaired for nid @nid', array('@nid' => $node->nid));
    return FALSE;
  }

  // Custom web_push_notification payload. see payload structure in Readme.
  $payload = array(
    // "dry_run" => TRUE,
    // The notification will be use if and only if user want to use firebase
    // service worker to display notificaiton.
    "notification" => array(
      "title" => variable_get('firebase_push_notification_title', ""),
      "body" => $node->title,
    ),
  );

  switch ($device_type) {
    case FIREBASE_PUSH_NOTIFICATIONS_TYPE_IOS:
      break;

    case FIREBASE_PUSH_NOTIFICATIONS_TYPE_ANDROID:
      $payload["notification"]["icon"] = 'myicon';
      $payload["notification"]["tag"] = $node->nid;
      break;

    case FIREBASE_PUSH_TYPE_WEB:
      $payload["notification"]["icon"] = variable_get('firebase_notificatin_icon_url');
      $payload["notification"]["tag"] = $node->nid;
      break;
  }

  // Allow other modules to alter payload. this may currept payload and cause
  // issue to delever notification.
  drupal_alter('firebase_push_prepair_payload', $payload, $nid, $device_type);
  return $payload;
}

/**
 * Fetch all endpoints in database.
 *
 * @return array
 *   Nested array of web push notification endpoints.
 */
function firebase_push_get_tokens() {
  // Select all tokens for this user.
  $result = db_select('firebase_push_tokens', 'c')
    ->fields('c')
    ->execute();

  $tokens = array();
  foreach ($result as $record) {
    $tokens[$record->type][$record->token] = $record->token;
  }

  // Allow other modules to write custom query and filter tokens by user id.
  // $tokens must only contain token. uid & other fild will break execution.
  // Format should be $tokens[$record->type][$record->token] = $record->token.
  drupal_alter('firebase_push_get_tokens', $tokens);

  return $tokens;
}

/**
 * Send the notifications to all subscribed users.
 *
 * @param array $payload
 *   Payload contain message tag and url of notification.
 *
 * @return bool
 *   TURE or FALSE depend on json file status.
 */
function firebase_push_send_message(array $payload) {
  if (empty($payload)) {
    watchdog('firebase_push', 'Web push endpoitns not found.', array(), WATCHDOG_ERROR);
    return FALSE;
  }

  $firebase_server_key = variable_get('firebase_push_server_key', '');

  $headers = array(
    "Authorization: key=$firebase_server_key",
    'Content-Type: application/json',
  );

  // Create a cURL handle.
  $curl = curl_init();
  curl_setopt($curl, CURLOPT_HTTPHEADER, $headers);
  curl_setopt($curl, CURLOPT_POSTFIELDS, json_encode($payload));
  curl_setopt($curl, CURLOPT_URL, FIREBASE_PUSH_NOTIFICATIONS_POST_URL);
  curl_setopt($curl, CURLOPT_FOLLOWLOCATION, TRUE);
  curl_setopt($curl, CURLOPT_CONNECTTIMEOUT, 20);
  curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, variable_get('firebase_push_use_ssl', 0));
  curl_setopt($curl, CURLOPT_POST, TRUE);
  curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
  $response_json = curl_exec($curl);
  $info = curl_getinfo($curl);

  /*
   * If Google's server returns a reply, but that reply includes an error,
   * log the error message. Ref:
   * http://firebase.google.com/docs/cloud-messaging/http-server-ref#error-codes
   */
  switch ($info['http_code']) {
    case 200:

      if (isset($response_json)) {
        // Res parcer https://firebase.google.com/docs/cloud-messaging/server.
        $response = json_decode($response_json);
        $results = $response->results;

        // $results[$key]->error != 'Unavailable' meanse need to retry.
        // $results[$key]->message_id == 'fake_message_id' token should deleted.
        foreach ($payload['registration_ids'] as $key => $token) {
          if ((!empty($results[$key]->error) && $results[$key]->error != 'Unavailable') || $results[$key]->message_id == 'fake_message_id') {
            $delete[$token] = $results[$key];
          }
          elseif (!empty($results[$key]->registration_id)) {
            $results[$key]->type = 'web';
            $update[$token] = (array) $results[$key];
          }
          else {
            $success[$token] = $results[$key];
          }
        }
        watchdog('firebase_push_notifications', "Firebase Server returned an 
           error: @response for !cnt  tokens.", array('@response' => $response_json, '!cnt' => count($success)), WATCHDOG_ERROR);
        watchdog('firebase_push', 'Fireabse push sent for !cnt tokens for nid !news', array(
          '!cnt' => count($success),
          '!news' => $payload['notification']['tag'],
        ), WATCHDOG_NOTICE);

        if (!empty($delete)) {
          // If the invalid device token or not registered (anymore because the
          // user has uninstalled the application), remove this device token.
          watchdog('firebase_push', 'Deleting !cnt broken tokens.', array('!cnt' => count($delete)), WATCHDOG_NOTICE);
          firebase_push_purge_token($delete);
        }
        if (!empty($update)) {
          // If the device client update token end, update device token in db.
          watchdog('firebase_push', 'Updating !cnt refreshed tokens.', array('!cnt' => count($update)), WATCHDOG_NOTICE);
          print_r($update);
          firebase_push_register_webpush($update);
        }
      }
      else {
        watchdog('firebase_push', 'Firebase return empty response.', array(), WATCHDOG_WARNING);
      }
      break;

    case 401:
      watchdog('firebase_push', 'Response: @res: The sender account used to send
        a message couldnt be authenticated. Possible causes are:  
        Authorization header missing or with invalid syntax in HTTP request.
        Invalid project number sent as key.
        Key valid but with FCM service disabled.
        Request originated from a server not whitelisted in the Server key IPs.
        Check that the token youre sending inside the Authentication header is 
        the correct Server key associated with your project. See Checking the 
        validity of a Server key for details.', array('@res' => $info['http_code']), WATCHDOG_ERROR);
      break;

    case 400:
      watchdog('firebase_push', 'Response: @res: Check that the JSON message is
        properly formatted and contains valid fields (for instance, making sure
        the right data type is passed).', array('@res' => $info['http_code']), WATCHDOG_ERROR);
      break;

    case 500:
      watchdog('firebase_push', 'Response: @res The server encountered an error
        while trying to process the request. You could retry the same request
        following the requirements listed in "Timeout" (see row above). If the
        error persists, please report the problem in the android-gcm 
        group.', array('@res' => $info['http_code']), WATCHDOG_ERROR);
      break;

    default:
      watchdog('firebase_push', 'Error in sending curl request with error 
        code @err_code. refer:-
        https://firebase.google.com/docs/cloud-messaging/http-server-ref#error-codes', array('@err_code' => $info['http_code']), WATCHDOG_ERROR);
      break;
  }
}

/**
 * Send custom message in notification.
 *
 * @param string $mesasge
 *   The message to sent.
 */
function firebase_push_custom_notification($mesasge = '') {

  // Get Token by device type.
  $device_tokens = firebase_push_get_tokens();
  // Stop right here if none of these users have any endpoint.
  if (empty($device_tokens)) {
    watchdog('firebase_push', 'No tokens found');
    return FALSE;
  }

  foreach ($device_tokens as $device_type => $tokens) {
    $payload = firebase_push_prepair_csutom_payload($mesasge, $device_type);
    if ($payload == FALSE) {
      watchdog('firebase_push', 'NULL Payload for message @msg and device type !type', array('@msg' => $mesasge, '!type' => $device_type));
      return FALSE;
    }

    $token_chunk = array_chunk($tokens, 1000);

    // print_r($token_chunk);
    if (is_array($token_chunk)) {
      foreach ($token_chunk as $token) {
        $payload['registration_ids'] = $token;
        firebase_push_send_message($payload);
      }
    }
    watchdog('firebase_push', 'firebase_push sent for message @msg and device type !type', array('@msg' => $mesasge, '!type' => $device_type));
  }
  watchdog('web_push_notification', 'Hit for custom message, web push sent for mssage @title', array('@title' => $payload['title']));
  return TRUE;
}

/**
 * Create payload.
 *
 * @param string $mesasge
 *   The nid to prepare payload.
 */
function firebase_push_prepair_csutom_payload($mesasge, $device_type) {

  // Custom web_push_notification payload. see payload structure in Readme.
  $payload = array(
    // "dry_run" => TRUE,
    // The notification will be use if and only if user want to use firebase
    // service worker to display notificaiton.
    "notification" => array(
      "title" => variable_get('firebase_push_notification_title', ""),
      "body" => $mesasge,
    ),
  );

  switch ($device_type) {
    case FIREBASE_PUSH_NOTIFICATIONS_TYPE_IOS:
      break;

    case FIREBASE_PUSH_NOTIFICATIONS_TYPE_ANDROID:
      $payload["notification"]["icon"] = 'myicon';
      $payload["notification"]["tag"] = 'csutom message';
      break;

    case FIREBASE_PUSH_TYPE_WEB:
      $payload["notification"]["icon"] = variable_get('firebase_notificatin_icon_url');
      $payload["notification"]["tag"] = 'csutom message';
      // Add home page url.
      $payload["notification"]["click_action"] = url(NULL, array('absolute' => TRUE));
      break;
  }

  // Allow other modules to alter payload. this may currept payload and cause
  // issue to delever notification.
  drupal_alter('firebase_push_prepair_csutom_payload', $payload, $mesasge, $device_type);
  return $payload;
}
