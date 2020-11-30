<?php

/**
 * @file
 * Drush commands to generate send push notification.
 */

/**
 * Implements hook_drush_help().
 */
function firebase_push_drush_help($section) {
  switch ($section) {
    case 'drush:firebase-custom-notification':
      return dt('Usage: drush custom-web-notification <message>.');

    case 'drush:firebase-send-notification ':
      return dt('Usage: drush firebase-send-notification <nid>.');
  }
}

/**
 * Implements hook_drush_command().
 */
function firebase_push_drush_command() {
  $items = array();
  $items['firebase-custom-notification'] = array(
    'description' => 'Fireabase custom notification',
    'drupal dependencies' => array('firebase_push'),
    'arguments' => array(
      'message' => 'Send custom message in web notification',
    ),
    'aliases' => array('fcn'),
  );
  $items['firebase-send-notification'] = array(
    'description' => 'firebase send notification',
    'drupal dependencies' => array('firebase_push'),
    'arguments' => array(
      'nid' => 'Node id of the content neecd to send notification for.',
    ),
    'aliases' => array('fsn'),
  );
  return $items;
}

/**
 * Command callback to send notifications.
 *
 * Ex. drush_{module_name}_{item_id_for_command}().
 */
function drush_firebase_push_firebase_custom_notification($message = '') {
  if (!empty($message)) {
    module_load_include('inc', 'firebase_push', 'firebase_push.cron');
    firebase_push_custom_notification($message);
    drush_log(t('Send notification command Successfully run'), 'success');
  }
  else {
    drush_log(t('Notification message is empty. Refer drush help firebase-send-notification'), 'ok');
  }
}

/**
 * Command callback. Send push notifications.
 */
function drush_firebase_push_firebase_send_notification($nid = NULL) {
  if ($nid == NULL) {
    drush_log(t('At least one perameter needed. add Node id at least. Rrefer drush help firebase-send-notification'), 'error');
  }

  // Default to an 5 minute interval. Of course, cron has to be running at least
  // in every 1 minute for this to work.
  $interval = variable_get('drush_firebase_push_interval', 1);

  // Max wait time  for last execution complete. maximum wait time is 60 minute.
  $max_error_wait_time = variable_get('drush_firebase_push_max_error_wait_time', 100);
  if (time() >= variable_get('drush_firebase_push_next_execution', 15) + $max_error_wait_time) {
    variable_set('drush_firebase_push_is_running', 0);
  }
  // We usually don't want to act every time command runs (which could be every
  // 1 minute) so keep a time 15 minutes for the next run in a variable.
  if (time() >= variable_get('drush_firebase_push_next_execution', 15) && variable_get('drush_firebase_push_is_running', 0) == 0
  ) {
    watchdog('firebase_push', 'Start firebase push notification hit by Drush at  %time', array('%time' => date_iso8601(time(0))));
    variable_set('drush_firebase_push_is_running', 1);

    firebase_push_initiate($nid);

    variable_set('drush_firebase_push_is_running', 0);
    variable_set('drush_firebase_push_next_execution', time() + $interval);
    watchdog('firebase_push', 'End  firebase push notification hit by Drush at  %time', array('%time' => date_iso8601(time(0))));
  }
}

/**
 * Callback function for Send push notifications.
 */
function firebase_push_initiate($nid = NULL) {
  module_load_include('inc', 'firebase_push', 'firebase_push.cron');
  if (!$nid) {
    $ids = '';
    watchdog('firebase_push', 'Sending web push notification for all queued nodes');
    $queue = DrupalQueue::get('firebase_push_notification');
    while ($item = $queue->claimItem()) {
      // Trigger send notifications all error, messages are in watchdog.
      // no need of return.
      if (firebase_push_trigger($item->data['nid'])) {
        // Collect nid for log only.
        $ids .= ',' . $item->data['nid'];
      }
      // Remove item from queue.
      $queue->deleteItem($item);
    }
    watchdog('firebase_push', 'Sent Web Notification for all nids @ids excpet expaired node ', array('@ids' => $ids));
  }
  elseif (firebase_push_trigger($nid)) {
    watchdog('firebase_push', 'Web notification sent for nid-> @nid.', array('@nid' => $nid));
  }
}
