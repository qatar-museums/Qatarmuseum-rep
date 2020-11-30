<?php

/**
 * @file
 * Services callbacks.
 */

/**
 * Service callback to set a device token.
 *
 * @param array $data
 *   Array with the following keys:
 *   - old_token
 *   - token
 *   - type.
 *
 * @return array
 *   Service data
 */
function firebase_push_service_set_device_token(array $data) {
  if (!isset($data['token']) || !isset($data['type'])) {
    return services_error(t('At least one parameter is missing.'), 400);
  }

  // Decode data.
  $old_token = isset($data['old_token']) ? str_replace(' ', '', $data['old_token']) : NULL;

  $subscription['registration_id'] = $data['token'];
  $subscription['type'] = $data['type'];
  $subscription['uid'] = isset($data['uid']) ? $data['uid'] : 0;

  // Remove empty spaces from the token.
  $subscription['registration_id'] = str_replace(' ', '', $subscription['registration_id']);
  // Convert type to integer value.
  if ($subscription['type'] != 'ios' && $subscription['type'] != 'android') {
    return services_error(t('Type not supported.'), 400);
  }
  else {
    $subscription['type'] = ($subscription['type'] == 'ios') ? FIREBASE_PUSH_NOTIFICATIONS_TYPE_IOS : FIREBASE_PUSH_NOTIFICATIONS_TYPE_ANDROID;
  }

  if (firebase_push_check_duplicate_tokens($subscription)) {
    return array(
      'success' => 1,
      'message' => t('Token is already registered.'),
    );
  }

  // Create multidimantional array for token update.
  if ($old_token) {
    $subscription = array($old_token => $subscription);
  }

  // Register / update token in database.
  if (firebase_push_register_webpush($subscription)) {
    return array(
      'success' => 1,
      'message' => t('Token is successfully Added / Updted.'),
    );
  }
  else {
    return services_error(t('Token could not be stored.'), 400);
  }
}
