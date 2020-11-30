<?php

/**
 * @file
 */


/**
 * Implements hook_form_FORM_ID_alter().
 */
function qma_education_form_registration_entity_settings_form_alter(&$form, &$form_state) {
  // Disable settings for reminders. Out of scope - would need modification to
  // work per date slot or be automatic based on the bookings.
  unset($form['reminder']);

  // Disable the confirmation message tooltip.
  unset($form['settings']['confirmation']);

  $form['#submit'][] = 'qma_education_form_registration_entity_settings_submit';
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function qma_education_form_views_exposed_form_alter(&$form, &$form_state) {
  if ($form['#id'] === 'views-exposed-form-qma-edu-repeat-calendar-block-3') {
    $form['field_eduprog_agegroup_tid']['#options']['All'] = t('Any age group', array(), array('context' => 'QMA'));
    $form['field_eduprog_type_tid']['#options']['All'] = t('Any topic', array(), array('context' => 'QMA'));
    $form['field_eduprog_institution_target_id']['#options']['All'] = t('Any institution', array(), array('context' => 'QMA'));
  }
}

/**
 * Add education notification email setting to email settings form.
 */
function qma_education_form_qma_forms_email_admin_form_alter(&$form, &$form_state) {
  $form['education_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Education registration e-mail address', array(), array('context' => 'QMA')),
    '#description' => t('The e-mail address that registrations will be sent to.', array(), array('context' => 'QMA')),
    '#default_value' => variable_get('qma_forms_admin_education_email', ''),
  );

  $form['#validate'][] = 'qma_education_email_admin_form_validate';
  $form['#submit'][] = 'qma_education_email_admin_form_submit';
}

/**
 * Validation function for education notification email.
 */
function qma_education_email_admin_form_validate($form, &$form_state) {
  $education_email = trim($form_state['values']['education_email']);

  if (empty($education_email)) {
    form_set_error('education_email', t('Please enter a value for the education notification e-mail address', array(), array('context' => 'QMA')));
  }

  if (!preg_match('/.+@.+/', $education_email)) {
    form_set_error('education_email', t('Please enter a valid e-mail address for education notifications', array(), array('context' => 'QMA')));
  }
}

/**
 * Submission function for education notification email.
 */
function qma_education_email_admin_form_submit($form, &$form_state) {
  variable_set('qma_forms_admin_education_email', filter_xss($form_state['values']['education_email']));
}

/**
 * Implements hook_registration_entity_settings().
 *
 * Adds a setting for the confirmation e-mail text.
 *
 * @param $settings
 * @return array
 */
function qma_education_registration_entity_settings($settings) {
  $item = array(
    'confirmation_email_user' => array(
      '#type' => 'textarea',
      '#title' => t('Confirmation Email (Registered)', array(), array('context' => 'QMA')),
      '#description' => t('The confirmation e-mail text for registered users', array(), array('context' => 'QMA')),
      '#default_value' => $settings['settings']['confirmation_email_user'],
    ),
    'confirmation_email_anon' => array(
      '#type' => 'textarea',
      '#title' => t('Confirmation Email (Anonymous)', array(), array('context' => 'QMA')),
      '#description' => t('The confirmation e-mail text for anonymous users', array(), array('context' => 'QMA')),
      '#default_value' => $settings['settings']['confirmation_email_anon'],
    ),
  );

  // add token support
  if (module_exists('token')) {
    $item['token_tree'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array(
        'node',
        'registration',
        'user',
      ),
      '#global_types' => FALSE,
    );
  }

  return $item;
}

/**
 * Custom submission handler for the registration settings form.
 *
 * If the type of entity the settings are attached to is a QMA_EDUCATION_PROGRAMME,
 * update any translations of the page to keep the settings in sync.
 *
 * @see registration_entity_settings_form_submit()
 */
function qma_education_form_registration_entity_settings_submit($form, &$form_state) {
  $entity = $form_state['entity'];
  $registration_entity = entity_load_single($entity['entity_type'], $entity['entity_id']);

  if ($entity['entity_type'] === 'node' && $registration_entity->type === QMA_EDUCATION_PROGRAMME) {
    $tnid = isset($registration_entity->tnid) ? $registration_entity->tnid : $registration_entity->nid;
    $node_translations = translation_node_get_translations($tnid);

    foreach ($node_translations as $translation_node) {
      if ($translation_node->nid === $registration_entity->nid) {
        continue; // Don't re-update the current entity
      }

      $fields = registration_convert_form_settings($form_state['values']);
      // @todo this results in duplicate notifications that settings have been saved
      registration_update_entity_settings($entity['entity_type'], $translation_node->nid, $fields);
    }
  }
}

/**
 * Form callback: create or edit a registration.
 *
 * @param $registration
 *   The registration object to edit or for a create form an empty registration
 *   object with a node defined.
 */
function qma_education_registration_form($form, &$form_state, Registration $registration, $startdate = FALSE, $enddate = FALSE) {
  $wrapper = entity_metadata_wrapper('registration', $registration);
  $user = $wrapper->user->value();
  $host = $wrapper->entity->value();
  $state = $wrapper->state->value();

  $form['#prefix'] = '<div class="membership-half-width">';
  $form['#suffix'] = '</div>';

  $form_state['registration'] = $registration;

  $who_options = registration_access_people($registration);

  // Default value for who is registering.
  $who_default = NULL;
  if (isset($registration->registration_id)) {
    $who_default = $registration->registrant_type($GLOBALS['user']);
  }
  elseif (count($who_options) == 1) {
    $keys = array_keys($who_options);
    $who_default = reset($keys);
  }

  // Show a message if there's only one option as we're going to hide the form.
  if (count($who_options) == 1 && !user_is_anonymous()) {
    $form['who_message'] = array(
      '#markup' => '<div class="registration-who-msg">' .
        t('You are registering: %who', array('%who' => current($who_options))) .
        '</div>',
    );
  }

  $form['who_is_registering'] = array(
    '#type' => 'select',
    '#title' => t('This registration is for'),
    '#options' => $who_options,
    '#default_value' => $who_default,
    '#required' => TRUE,
    '#access' => (count($who_options) > 1),
  );

  $form['user'] = array(
    '#type' => 'textfield',
    '#title' => t('User'),
    '#default_value' => ($user ? $user->name : ''),
    '#maxlength' => 60,
    '#size' => 30,
    '#description' => t('Select a user by typing their username to get a list of matches.'),
    '#autocomplete_path' => 'user/autocomplete',
    '#access' => isset($who_options[REGISTRATION_REGISTRANT_TYPE_USER]),
    '#states' => array(
      'visible' => array(
        ':input[name="who_is_registering"]' => array('value' => REGISTRATION_REGISTRANT_TYPE_USER),
      ),
    ),
  );

  $form['anon_mail'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#description' => t('The email to associate with this registration.'),
    '#default_value' => isset($registration->anon_mail) ? $registration->anon_mail : '',
    '#size' => 40,
    '#maxlength' => 255,
    '#access' => isset($who_options[REGISTRATION_REGISTRANT_TYPE_ANON]),
    '#states' => array(
      'visible' => array(
        ':input[name="who_is_registering"]' => array('value' => REGISTRATION_REGISTRANT_TYPE_ANON),
      ),
    ),
  );

  $dates = qma_education_host_dates($registration->entity_id);
  $options = qma_education_host_dates_options($registration->entity_id);
  $form_state['storage']['date_options'] = $dates;
  $default_value = 0;

  // If startdate and enddate are set, set this date as default (assume it's valid).
  if ($startdate && $enddate) {
    foreach ($dates as $idx => $date) {
      if ($startdate == $date['value'] && $enddate == $date['value2']) {
        $default_value = $idx;
        break;
      }
    }
  }
  else {
    foreach ($dates as $idx => $date) {
      if ($date['bookable']) {
        $default_value = $idx;
        break;
      }
    }
  }

  $form['date_select'] = array(
    '#type' => 'select',
    '#title' => t('Booking date'),
    '#options' => $options,
    '#default_value' => $default_value,
  );

  $settings = registration_entity_settings($registration->entity_type, $registration->entity_id);
  $capacity = $settings['capacity'];
  $limit = isset($settings['settings']['maximum_spaces']) ? $settings['settings']['maximum_spaces'] : 1;
  // Just in case it was unset:
  $settings['settings']['maximum_spaces'] = $limit;
  $remaining = $capacity - qma_education_registration_event_count($registration->entity_type, $registration->entity_id, $startdate, $enddate, $registration->entity_id);

  $description = t('The number of spaces you wish to reserve.');

  // If we're limited per user and per event, then pick the smallest. Else
  // prefer the per-attendee limit, then the event capacity, then a constant.
  if ($limit && $capacity) {
    $max = min($limit, $capacity);
  }
  elseif ($limit) {
    $max = $limit;
  }
  elseif ($capacity) {
    $max = $capacity;
  }
  else {
    $max = 30;
  }

  $space_options = array();

  for ($i = 1; $i < $max + 1; $i++) {
    $space_options[$i] = $i;
  }

  $form['count'] = array(
    '#type' => 'select',
    '#title' => t('Spaces'),
    '#description' => $description,
    '#default_value' => isset($registration->count) ? $registration->count : 1,
    '#options' => $space_options,
    '#access' => (isset($settings['settings']['maximum_spaces']) && $settings['settings']['maximum_spaces'] == 1) ? FALSE : TRUE,
    '#element_validate' => array('element_validate_integer_positive', '_registration_validate_space_request'),
  );

  $default_state = registration_get_default_state();
  $states = registration_get_states_options(array('show_on_form' => TRUE));

  $form['state'] = array(
    '#type' => 'select',
    '#title' => t('State'),
    '#description' => t('State of this registration'),
    '#default_value' => ($state ? $state->identifier() : $default_state->identifier()),
    '#options' => $states,
    '#access' => !empty($states) && user_access('edit ' . $registration->type . ' registration state'),
  );

  field_attach_form('registration', $registration, $form, $form_state);

  // Replace field labels and descriptions where defaults are used to make
  // sure they are translated
  // @todo Remove this when field label translation is working correctly.
  $form['field_qma_edu_reg_affiliation'][LANGUAGE_NONE]['#title'] = t('Affiliation');
  $form['field_qma_edu_pref_lang'][LANGUAGE_NONE]['#title'] = t('Preferred language');
  $form['field_qma_edu_reg_role'][LANGUAGE_NONE]['#title'] = t('Role');
  $form['field_qma_edu_reg_role'][LANGUAGE_NONE]['#description'] = t('To help us improve our events, please select the most appropriate role.');

  // Make this field inaccessible on the front-end - we set this manually in
  // the submission function using values from $form['date_select'].
  $form['field_qma_edu_reg_date']['#access'] = FALSE;

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Registration'),
  );

  // Add a delete button for existing registration:
  if (isset($registration->registration_id) && entity_access('delete', 'registration', $registration)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('registration_form_delete_submit'),
      "#limit_validation_errors" => array(),
    );
  }

  if ($host && entity_access('view', $registration->entity_type, $host)) {
    $uri = entity_uri($registration->entity_type, $host);
    $form['actions']['cancel'] = array(
      '#type' => 'link',
      '#title' => t('Cancel'),
      '#href' => $uri['path'],
    );
  }
  $form['#registration_settings'] = $settings;

  return $form;
}

/**
 * Implements hook_form_alter().
 *
 * Adds a default for the registration name when the user is logged in.
 *
 * @param $form
 * @param $form_state
 */
function qma_education_form_qma_education_registration_form_alter(&$form, &$form_state) {
  if (user_is_logged_in() && isset($form['field_qma_edu_reg_name'])) {
    global $user;
    $wrapper = entity_metadata_wrapper('user', user_load($user->uid));
    $first_name = $wrapper->field_first_name->value();
    $last_name = $wrapper->field_last_name->value();

    $lang = $form['field_qma_edu_reg_name']['#language'];
    $form['field_qma_edu_reg_name'][$lang][0]['value']['#default_value'] = $first_name . ' ' . $last_name;
  }

  $form['actions']['submit']['#value'] = t('Book now', array(), array('context' => 'QMA'));
}

/**
 * Overridden validation function for the registration form.
 *
 * @param $form
 * @param $form_state
 */
function qma_education_registration_form_validate($form, &$form_state) {
  // Set the correct date in the attached field element based on the submission.
  $lang = $form['field_qma_edu_reg_date']['#language'];
  $date_options = $form_state['storage']['date_options'];
  $date = $date_options[$form_state['values']['date_select']];
  $startdate = $date['value'];
  $enddate = $date['value2'];

  $timezone = 'Asia/Qatar';

  $form_state['values']['field_qma_edu_reg_date'][$lang][0]['value'] = $startdate;
  $form_state['values']['field_qma_edu_reg_date'][$lang][0]['value2'] = $enddate;
  $form_state['values']['field_qma_edu_reg_date'][$lang][0]['timezone'] = $timezone;

  $date1 = new DateTime();
  $date1->setTimestamp($startdate);
  $date1->setTimezone(new DateTimeZone($timezone));
  $form_state['values']['field_qma_edu_reg_date'][$lang][0]['offset'] = $date1->getOffset();

  $date2 = new DateTime();
  $date2->setTimestamp($enddate);
  $date2->setTimezone(new DateTimeZone($timezone));
  $form_state['values']['field_qma_edu_reg_date'][$lang][0]['offset2'] = $date2->getOffset();

  $registration = $form_state['registration'];

  $count = $form_state['values']['count'];

  $label = entity_label($registration->entity_type, entity_load_single($registration->entity_type, $registration->entity_id));

  // If the date is not bookable, return an error
  if (!qma_education_is_bookable_date($registration->entity_type, $registration->entity_id, $startdate, $enddate)) {
    $error = t('There was a problem with the date selected. Please try again', array(), array('context' => 'QMA'));
    form_set_error('date_select', $error);
  }
  // If the number of places being booked is greater than those selected, also return an error
  elseif (!qma_education_registration_has_room($registration->entity_type, $registration->entity_id, $startdate, $enddate, $count, $registration->registration_id)) {
    if (!$has_room) {
      form_set_error('', t('Sorry, unable to register for %label due to: insufficient spaces remaining.',
        array('%label' => $label)));
    }
  }

  // Test status on new registrations.
  if (isset($registration->is_new) && $registration->is_new) {
    $registration_status = qma_education_registration_status($registration->entity_type, $registration->entity_id, $startdate, $enddate, TRUE, $count, $registration->registration_id, $errors);

    if (!$registration_status) {
      form_set_error('', t('Sorry, unable to register for %label due to: %errors.',
        array('%label' => $label, '%errors' => implode(', ', $errors))
      ));
    }
  }
  // Only check capacity for existing registrations that are active.
  elseif (in_array($registration->state, registration_get_active_states())) {
    $has_room = qma_education_registration_has_room($registration->entity_type, $registration->entity_id, $startdate, $enddate, $count, $registration->registration_id);
    if (!$has_room) {
      form_set_error('', t('Sorry, unable to register for %label due to: insufficient spaces remaining.',
        array('%label' => $label)));
    }
  }

  $settings = registration_entity_settings($registration->entity_type, $registration->entity_id);
  $allow_multiple = !empty($settings['settings']['multiple_registrations']) && $settings['settings']['multiple_registrations'];

  // Validate according to who's registering.
  switch ($form_state['values']['who_is_registering']) {
    case REGISTRATION_REGISTRANT_TYPE_ANON:
      if (!valid_email_address($form_state['values']['anon_mail'])) {
        form_set_error('anon_mail', t('The email address is invalid.'));
      }
      if (!$allow_multiple && registration_is_registered($registration, $form_state['values']['anon_mail'])) {
        form_set_error('anon_mail', t('%mail is already registered for this event.',
          array('%mail' => $form_state['values']['anon_mail'])));
      }
      break;
    case REGISTRATION_REGISTRANT_TYPE_ME:
      global $user;
      if (!$allow_multiple && registration_is_registered($registration, NULL, $user->uid)) {
        form_set_error('user', t('You are already registered for this event.'));
      }
      break;
    case REGISTRATION_REGISTRANT_TYPE_USER:
      $user = user_load_by_name($form_state['values']['user']);
      if ($user) {
        if (!$allow_multiple && registration_is_registered($registration, NULL, $user->uid)) {
          form_set_error('user', t('%user is already registered for this event.', array('%user' => $user->name)));
        }
      }
      else {
        form_set_error('user', t('%user is not a valid user.', array('%user' => $form_state['values']['user'])));
      }
      break;
  }

  // Notify field widgets to validate their data.
  field_attach_form_validate('registration', $registration, $form, $form_state);
}

/**
 * Overridden submission function for the registration form.
 *
 * @param $form
 * @param $form_state
 */
function qma_education_registration_form_submit($form, &$form_state) {
  $to_email = FALSE;
  $registration = $form_state['registration'];
  $registration_type = $form_state['values']['who_is_registering'];
  $confirmation_email_type = 'confirmation_email_user';

  // Set the registration's author uid
  if (!isset($registration->registration_id)) {
    $registration->author_uid = $GLOBALS['user']->uid;
  }
  $registration->count = $form_state['values']['count'];

  if (!empty($form_state['values']['state'])) {
    $registration->state = $form_state['values']['state'];
  }

  switch ($registration_type) {
    case REGISTRATION_REGISTRANT_TYPE_ANON:
      $registration->anon_mail = $form_state['values']['anon_mail'];
      $confirmation_email_type = 'confirmation_email_anon';
      $to_email = $registration->anon_mail;
      break;
    case REGISTRATION_REGISTRANT_TYPE_ME:
      global $user;
      $registration->user_uid = $user->uid;
      $registered_user = $user;
      $to_email = $user->mail;
      break;
    case REGISTRATION_REGISTRANT_TYPE_USER:
      if ($reg_user = user_load_by_name($form_state['values']['user'])) {
        $registration->user_uid = $reg_user->uid;
        $registered_user = $reg_user;
        $to_email = $reg_user->mail;
      }
      break;
  }

  // Notify field widgets.
  field_attach_submit('registration', $registration, $form, $form_state);

  // Save the registration and redirect.
  if (registration_save($registration)) {
    $reg_config = registration_entity_settings($registration->entity_type, $registration->entity_id);

    if (!empty($reg_config['settings']['confirmation']) && strlen($reg_config['settings']['confirmation'])) {
      drupal_set_message(t($reg_config['settings']['confirmation']));
    }

    if (!empty($reg_config['settings'][$confirmation_email_type]) && strlen($reg_config['settings'][$confirmation_email_type])) {
      $mail_template = $reg_config['settings'][$confirmation_email_type];
    }
    else {
      $mail_template = qma_education_confirmation_mail_defaults($confirmation_email_type);
    }

    // Generate a confirmation e-mail for the registrant.
    if ($to_email) {
      $languages = language_list();
      $params['body'] = $mail_template;
      $from_email = '"QMA Education" <' . $reg_config['settings']['from_address'] . '>';

      if (module_exists('token')) {
        $tokens = array(
          'registration' => $registration,
          $registration->entity_type => entity_load_single($registration->entity_type, $registration->entity_id),
        );

        if (isset($registered_user)) {
          $tokens['user'] = user_load($registered_user->uid);
        }

        $params['body'] = token_replace($params['body'], $tokens);
      }

      $bcc_mail = qma_education_get_bcc_from_programme($registration->entity_id);

      if (strlen($bcc_mail)) {
        $params['headers']['Bcc'] = $bcc_mail;
      }
      else {
        $params['headers']['Bcc'] = variable_get('qma_forms_admin_education_email', 'education@qm.org.qa');
      }

      drupal_mail('qma_education', 'confirmation', $to_email, $languages['en'], $params, $from_email);
    }

    $wrapper = entity_metadata_wrapper('registration', $registration);
    $host = $wrapper->entity->value();

    // Redirect to registration
    if (entity_access('view', 'registration', $registration)) {
      $uri = entity_uri('registration', $registration);
      $form_state['redirect'] = $uri['path'];
    }
    // Redirect to host entity
    else {
      if (entity_access('view', $registration->entity_type, $host)) {
        $uri = entity_uri($registration->entity_type, $host);
        $form_state['redirect'] = $uri['path'];
      }
    }
  }
  else {
    drupal_set_message(t('There was a problem submitting your registration.'));
  }
}

/**
 * Build booking form for an event node.
 */
function qma_education_booking_form($form, &$form_state, $node) {
  // Save node and dates for use in submission function.
  $form_state['storage']['node'] = $node;
  $form_state['storage']['dates'] = qma_education_host_dates($node->nid, 'node', $node->vid);
  $options = qma_education_host_dates_options($node->nid, 'node', $node->vid);

  $default_value = array_shift(array_keys($options));

  foreach ($form_state['storage']['dates'] as $idx => $date) {
    if ($date['bookable']) {
      $default_value = $idx;
      break;
    }
  }

  $form['date_select'] = array(
    '#type' => 'select',
    '#title' => t('Booking date', array(), array('context' => 'QMA')),
    '#options' => $options,
    '#default_value' => (string) $default_value,
  );

  $form['actions'] = array(
    '#prefix' => '<div class="actions">',
    '#suffix' => '</div>',
  );

  // If there are no bookable slots the button is disabled.
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Register', array(), array('context' => 'QMA')),
    '#disabled' => !count(qma_education_bookable_dates($node->nid)),
    '#states' => array(
      'disabled' => array(
        ':input[name="date_select"]' => array(),
      ),
    ),
  );

  // The #states api is used to disable sold out dates in a mixed list.
  foreach ($form_state['storage']['dates'] as $idx => $option) {
    if (!$option['bookable']) {
      $form['actions']['submit']['#states']['disabled'][':input[name="date_select"]'][] = array(
        'value' => (string) $idx,
      );
    }
  }

  return $form;
}

/**
 * Validation function for education booking form.
 */
function qma_education_booking_form_validate($form, &$form_state) {
  $node = $form_state['storage']['node'];
  $date_index = $form_state['values']['date_select'];
  $date = $form_state['storage']['dates'][$date_index];

  if (!qma_education_is_bookable_date('node', $node->nid, $date['value'], $date['value2'])) {
    $error = t('There was a problem with the date selected. Please try again', array(), array('context' => 'QMA'));
    form_set_error('date_select', $error);
  }
}

/**
 * Submission function for education booking form.
 */
function qma_education_booking_form_submit($form, &$form_state) {
  $node = $form_state['storage']['node'];
  $date_index = $form_state['values']['date_select'];
  $date = $form_state['storage']['dates'][$date_index];

  $options = array(
    'query' => array(
      'startdate' => $date['value'],
      'enddate' => $date['value2'],
    ),
    'absolute' => TRUE,
  );

  $url = url('node/' . $node->nid . '/register', $options);
  drupal_goto($url);
}
