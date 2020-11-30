<?php

/**
 * @file
 * Admin files for Push Notifications module.
 */

/**
 * Overview form for Push Notification Settings.
 */
function firebase_push_admin_overview_form($form_state) {
  // Load all tokens stored in the database.
  $query = db_select('firebase_push_tokens', 'pnt');
  $query->fields('pnt', array('token', 'type', 'timestamp'));
  $result = $query->execute();
  $counts = array(
    'total' => 0,
    'web' => 0,
    'android' => 0,
    'ios' => 0,
  );

  foreach ($result as $data) {

    $counts['total']++;

    switch ($data->type) {
      case FIREBASE_PUSH_TYPE_WEB:
        $counts['web']++;
        break;

      case FIREBASE_PUSH_NOTIFICATIONS_TYPE_ANDROID:
        $counts['android']++;
        break;

      case FIREBASE_PUSH_NOTIFICATIONS_TYPE_IOS:
        $counts['ios']++;
        break;

    }
  }

  $form = array();

  $statistics_description = (!$counts['total']) ? t('No tokens registred.') : NULL;
  $form['statistics'] = array(
    '#type' => 'fieldset',
    '#title' => 'Firebase Notification Statistics',
    '#description' => $statistics_description,
  );

  $form['statistics']['total'] = array(
    '#type' => 'item',
    '#title' => t('Total Tokens Registred'),
    '#markup' => $counts['total'],
  );

  $form['statistics']['web'] = array(
    '#type' => 'item',
    '#title' => t('Web Tokens Registred'),
    '#markup' => $counts['web'],
  );

  $form['statistics']['android'] = array(
    '#type' => 'item',
    '#title' => t('Android Tokens Registred'),
    '#markup' => $counts['android'],
  );

  $form['statistics']['ios'] = array(
    '#type' => 'item',
    '#title' => t('iOS Tokens Registred'),
    '#markup' => $counts['ios'],
  );

  return $form;
}

/**
 * Form callback for Push Notifications Settings.
 */
function firebase_push_admin_form($form_state) {
  $form = array();

  $form['api_configuration_general'] = array(
    '#type' => 'fieldset',
    '#title' => t('API Firebase Push Notifications Settings'),
  );

  $form['api_configuration_general']['firebase_push_js_snipt'] = array(
    '#type' => 'textarea',
    '#resizable' => FALSE,
    '#title' => t('JavaScript Add to web app'),
    '#description' => t('JavaScript api configuration provided by firebase app admin. Can retrive from Generatl->yourapps section of url:- <b>https://console.firebase.google.com/project/{firebase_project_bname}/settings/general/</b>'),
    '#default_value' => variable_get('firebase_push_js_snipt', ''),
  );

  $form['api_configuration_general']['firebase_push_server_key'] = array(
    '#type' => 'textarea',
    '#resizable' => FALSE,
    '#title' => t('Firebase push Server Key'),
    '#rows' => 1,
    '#attributes' => array('maxlength' => 180, 'size' => 180),
    '#description' => t('Firebase Servicer Key. will be provided by firebase app admin. Can retrive from Generatl->CLOUD MESSAGNIG section of url:- <b>https://console.firebase.google.com/project/{firebase_project_bname}/settings/cloudmessaging/</b>'),
    '#default_value' => variable_get('firebase_push_server_key', ''),
  );

  $form['api_configuration_general']['firebase_push_notificatin_icon'] = array(
    '#type' => 'managed_file',
    '#title' => t('Firebase Push notificaiton logo'),
    '#description' => t('Upload Firebase push notificaiton logo. will be apeari in notificaiton popup.'),
    '#upload_location' => 'public://firebase_push/',
    '#default_value' => variable_get('firebase_push_notificatin_icon', ''),
  );

  $form = system_settings_form($form);
  $form['#submit'][] = 'firebase_push_admin_form_submit';
  return system_settings_form($form);
}

/**
 * Validation handler for fireabse push configuration form.
 */
function firebase_push_admin_form_validate($form, &$form_state) {
  // If form submit without notification logo uploaded/deleted. add file uses.
  if (!empty($form_state['values']['firebase_push_notificatin_icon'])) {
    $file = file_load($form_state['values']['firebase_push_notificatin_icon']);
    file_usage_add($file, 'firebase_push', 'admin', 1);
  }
  if (!empty($form_state['values']['firebase_push_js_snipt'])) {
    firebase_push_create_service_worker($form_state['values']['firebase_push_js_snipt']);
  }
}

/**
 * Submit callback for fireabse push configuration page.
 */
function firebase_push_admin_form_submit($form, &$form_state) {
  // Upload notification logo iamge.
  if (isset($form_state['values']['firebase_push_notificatin_icon'])) {
    $file = file_load($form_state['values']['firebase_push_notificatin_icon']);
    if ($file) {
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);

      // Set fid for admin use only.
      variable_set('firebase_push_notificatin_icon', $file->fid);

      // Set icon url to add in notification payload.
      variable_set('firebase_notificatin_icon_url', file_create_url($file->uri));
    }
  }
  else {
    $file = file_load(variable_get('firebase_push_notificatin_icon', ''));
    if ($file->fid) {
      file_delete($file, TRUE);
      variable_del('firebase_push_notificatin_icon');
    }
  }
}

/**
 * Helper function.
 *
 * To create service worker file with firebase configuration and set variable
 *  of firebase configuration.
 */
function firebase_push_create_service_worker($firebase_push_js_snipt) {
  $firebase_push_js_snipt = str_replace('<script>', '', $firebase_push_js_snipt);
  $firebase_push_js_snipt = preg_replace('#<script(.*?)>(.*?)</script>#is', '', $firebase_push_js_snipt);
  $firebase_push_js_snipt = str_replace('</script>', '', $firebase_push_js_snipt);

  $source_path = drupal_get_path('module', 'firebase_push') . '/js/firebase-messaging-sw-default.js';
  $target_path = 'public://firebase_push/firebase-messaging-sw.js';

  // Read the entire string.
  $file_contents = file_get_contents($source_path);

  // Replace placeholder with firebase configuration in the file string.
  $str = str_replace("{firebase_configuration}", $firebase_push_js_snipt, $file_contents);

  $file = file_save_data($str, $target_path);
  field_attach_update('file', $file);
  $file = get_object_vars($file);
  variable_set('firebase_push_sw_url', $file['uri']);

  // Craete configuration string for main.js file.
  $sw_config = preg_replace('/(.*)= {(.*)};(.*)/sm', '\2', $firebase_push_js_snipt);

  $sw_config = str_replace('apiKey', '"apiKey"', $sw_config);
  $sw_config = str_replace('authDomain', '"authDomain"', $sw_config);
  $sw_config = str_replace('databaseURL', '"databaseURL"', $sw_config);
  $sw_config = str_replace('projectId', '"projectId"', $sw_config);
  $sw_config = str_replace('storageBucket', '"storageBucket"', $sw_config);
  $sw_config = str_replace('messagingSenderId', '"messagingSenderId"', $sw_config);

  variable_set('sw_config', '{' . $sw_config . '}');
}
