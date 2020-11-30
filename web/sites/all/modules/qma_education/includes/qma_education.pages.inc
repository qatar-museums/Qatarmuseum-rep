<?php

/**
 * @file
 * qma_education.pages.inc
 */


/**
 * Menu handler for the overridden registration page.
 *
 * @todo Does the access callback need to change to take status into account?
 * @see registration_register_page().
 */
function qma_education_register_page($entity_type, $entity) {
  list($entity_id) = entity_extract_ids($entity_type, $entity);

  // For registration entities that aren't education_events, use the standard
  // registration page callback.
  if ($entity_type !== 'node' || $entity->type !== QMA_EDUCATION_PROGRAMME) {
    return registration_register_page($entity_type, $entity);
  }
  else {
    $startdate = $enddate = FALSE;

    // Capture any startdates and enddates set in the URL and validate
    if (isset($_GET['startdate'], $_GET['enddate'])) {
      $url_startdate = (int) $_GET['startdate'];
      $url_enddate = (int) $_GET['enddate'];

      if (qma_education_is_bookable_date($entity_type, $entity_id, $url_startdate, $url_enddate)) {
        $startdate = $url_startdate;
        $enddate = $url_enddate;
      }
      else {
        $message = t('The selected date slot is no longer available. Please select from available slots below', array(), array('context' => 'QMA'));
        drupal_set_message($message, 'warning');
      }
    }

    // If they aren't set by now, find the first available date.
    if (!$startdate && !$enddate) {
      $dates = qma_education_host_dates($entity_id);

      foreach ($dates as $date) {
        if ($date['bookable']) {
          $startdate = $date['value'];
          $enddate = $date['value2'];
          break;
        }
      }
    }

    // If they aren't set by now, bail out.
    if (!$startdate && !$enddate) {
      return '<p>' . t('Sorry, there are no registration slots available for %name',
        array('%name' => entity_label($entity_type, $entity)), array('context' => 'QMA')) . '</p>';
    }

    if (qma_education_registration_status($entity_type, $entity_id, $startdate, $enddate)) {
      $registration_type = registration_get_entity_registration_type($entity_type, $entity);
      $registration = entity_get_controller('registration')->create(array(
        'entity_type' => $entity_type,
        'entity_id' => $entity_id,
        'type' => $registration_type,
      ));
      return drupal_get_form('qma_education_registration_form', $registration, $startdate, $enddate);
    }
    else {
      return t('Sorry, registrations are no longer available for %name',
        array('%name' => entity_label($entity_type, $entity)));
    }
  }
}

/**
 * Overridden page callback for registrations admin page.
 *
 * Updates the table to include the start and end dates for the booked slot.
 */
function qma_education_registration_registrations_page($entity_type, $entity) {
  $header = array(
    array(
      'data' => t('ID'),
      'field' => 'registration_id',
      'type' => 'property',
      'specifier' => 'registration_id'
    ),
    array(
      'data' => t('Email'),
    ),
    array(
      'data' => t('User'),
      'field' => 'user_uid',
      'type' => 'property',
      'specifier' => 'user_uid'
    ),
    array(
      'data' => t('Created By'),
      'field' => 'author_uid',
      'type' => 'property',
      'specifier' => 'author_uid'
    ),
    array(
      'data' => t('Date slot (start)', array(), array('context' => 'QMA')),
      'type' => 'field',
      'specifier' => array(
        'field' => 'field_qma_edu_reg_date',
        'column' => 'value',
      ),
    ),
    array(
      'data' => t('Date slot (end)', array(), array('context' => 'QMA')),
      'type' => 'field',
      'specifier' => array(
        'field' => 'field_qma_edu_reg_date',
        'column' => 'value2',
      ),
    ),
    array(
      'data' => t('Tickets booked'),
      'field' => 'count',
      'type' => 'property',
      'specifier' => 'count'
    ),
    array(
      'data' => t('Tickets remaining', array(), array('context' => 'QMA')),
    ),
    array(
      'data' => t('Created'),
      'field' => 'created',
      'sort' => 'desc',
      'type' => 'property',
      'specifier' => 'created'
    ),
    array(
      'data' => t('State'),
      'field' => 'state',
      'type' => 'property',
      'specifier' => 'state'
    ),
    array('data' => t('Actions')),
  );

  list($entity_id) = entity_extract_ids($entity_type, $entity);
  $label = entity_label($entity_type, $entity);

  $query = new EntityFieldQuery;
  $result = $query
    ->entityCondition('entity_type', 'registration')
    ->propertyCondition('entity_id', $entity_id)
    ->propertyCondition('entity_type', $entity_type)
    ->pager(20)
    ->tableSort($header)
    ->execute();

  if (!empty($result['registration'])) {
    $registrations = registration_load_multiple(array_keys($result['registration']));
    $rows = array();

    foreach ($registrations as $registration) {
      $wrapper = entity_metadata_wrapper('registration', $registration);
      $author = $wrapper->author->value();
      $user = $wrapper->user->value();
      $state = $wrapper->state->value();
      $date_slot = $wrapper->field_qma_edu_reg_date->value();

      $booked_slots = qma_education_registration_event_count($entity_type, $entity_id, $date_slot['value'], $date_slot['value2']);
      $settings = registration_entity_settings($entity_type, $entity_id);

      if ((int) $settings['capacity'] === 0) {
        $slots_remaining = t('No capacity set');
      }
      else {
        $slots_remaining = $settings['capacity'] - $booked_slots;
      }

      $author_col = '';
      if ($registration->author_uid) {
        $author_col = theme('username', array('account' => $author));
      }

      $user_col = '';
      if ($registration->user_uid) {
        $user_col = theme('username', array('account' => $user));
      }

      $actions = array();
      if (entity_access('view', 'registration', $registration)) {
        $actions[] = l(t('View'), 'registration/' . $registration->registration_id);
      }
      if (entity_access('update', 'registration', $registration)) {
        $actions[] = l(t('Edit'), 'registration/' . $registration->registration_id . '/edit', array('query' => drupal_get_destination()));
      }
      if (entity_access('delete', 'registration', $registration)) {
        $actions[] = l(t('Delete'), 'registration/' . $registration->registration_id . '/delete', array('query' => drupal_get_destination()));
      }

      $rows[] = array(
        l($registration->registration_id, 'registration/' . $registration->registration_id),
        l($wrapper->mail->value(), 'mailto:' . $wrapper->mail->value()),
        $user_col,
        $author_col,
        date('j M Y, h:i', $date_slot['value']),
        date('j M Y, h:i', $date_slot['value2']),
        $registration->count,
        $slots_remaining,
        format_date($registration->created),
        ($state ? filter_xss_admin(entity_label('registration_state', $state)) : ''),
        implode(' | ', $actions)
      );
    }

    $table = array(
      'header' => $header,
      'rows' => $rows,
      'caption' => t('List of registrations for %title.', array('%title' => $label)),
    );

    $out = theme('table', $table) . theme('pager');
  }
  else {
    $out = t('There are no registrants for %name', array('%name' => $label));
  }

  return $out;
}
