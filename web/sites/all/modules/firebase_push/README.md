Firebase Push Notifications Overview
====================================

The Firebase Push Notifications module provides the feature set to send out 
push notifications to Chrome, Mozila and Opera browser Firebase web Push 
Notifications Service.
This module does not rely on any external services and allows site owners to
send out push notifications to any of listed browser for free.

Firebase Push Notifications Settings
====================================
Navigate to /admin/config/services/firebase/push_notifications/configure to 
configure the push notification settings for web.

Add "Firebase Push Notification JS" block in footer or header. This block allow 
Module js file to include and start token registration.

Firebase credentials
--------------------
  Firebase requires you to create an API key. https://firebase.google.com/

  Follow steps mentioned in video provided by
  Firebase https://www.youtube.com/watch?v=BF6hPJigwUE to get the Frebase
  credentials and add them in admin setting page
  /admin/config/services/firebase/push_notifications/configure.

Setup Fireabse push notification on Android devices.
----------------------------------------------------
  https://firebase.google.com/docs/cloud-messaging/android/client

Firebase supported payload
==========================
$payload = array(
    "to" => $token, // single token
    "registration_ids" => $tokens, // array of tokens
    "collapse_key" => 15,
    "dry_run" => true,
    // notification will be use if and only if user want to use Firebase 
    // serviceworker to display notification.
    "notification" => array(
      "title" => "custom title",
      "body" => $node->title,
      "icon" => $icon,
      "click_action" => $node_url,
      "tag" => $node->nid,
    ),
    // data will be use if and only if user want to use custom serviceworker
    // to display notification.
    "data" => array (
      "title" => "custom title",
      "body" => $node->title,
      "icon" => $icon,
      "click_action" => $node_url,
      "tag" => $node->nid,
    ),
  );

Firebase token registration for IOS and Android devices
=======================================================
Module support web service to register update FCM token.

service name:- firebase_push_notifications
Request json format:-

 {
  "old_token" : "04aa81162ee---------------1888459818ad3d33711",
  "token": "04aa81162ee7a79b----------------888459818ad3d33711",
  "type":"ios",
  "uid": 0
 }

  Where:-
    old_token   Optional  only in use when token need to update.
    token       Required  FCM token provided by app.
    type        Required  Device type should be one of 'ios' or 'android'.
    uid         Optional  Drupal User Id. Remove uid filed for anonymous user.

Response json:-

Success:-

  <result>
    <success>1</success>
    <message>This token is already registered.</message>
  </result>

Error:-
  <result>Type not supported.</result>

Module support payload alter:-
=============================
Alter payload which has node title as message for Implement
hook_firebase_push_prepair_payload_alter(&$payload, &$nid, &$device_type)

Alter payload which has custom string as message for Implement
hook_firebase_push_prepair_csutom_payload_alter(&$payload, &$nid, &$device_type)


Module support Token filter :-
=============================
Filter Tokens by user id, role by Implement
hook_firebase_push_get_tokens_alter(&$tokens) $tokens only contains token value
not uid and other fields. It is strongly recommended to write your own query to
get filtered tokens from database.

Make sure $tokens array format should be like.

$tokens['device_type']['tokens'];
$tokens = array(
  'ios' => array(
    '04aa81162ee---------------1888459818ad3d33711',
    '04aa81162ee7a79b---------------1888459818ad3d33711'
  ),
  'android' => array(
    '04aa81162ee---------------1888459818ad3d33711',
    '04aa81162ee7a79b---------------1888459818ad3d33711'
  ),
  'web' => array(
    '04aa81162ee---------------1888459818ad3d33711',
    '04aa81162ee7a79b---------------1888459818ad3d33711'
  ),
);
