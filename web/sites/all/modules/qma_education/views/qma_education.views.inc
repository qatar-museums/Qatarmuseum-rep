<?php

/**
 * @file
 * Custom views implementations for the qma_education module.
 */


/**
 * Implements hook_views_data_alter().
 */
function qma_education_views_data_alter(&$data) {
  // Registration: remaining slots.
  $data['registration']['capacity_remaining'] = array(
    'real field' => 'registration_id',
    'group' => t('Registration'),
    'title' => t('Spaces remaining'),
    'help' => t('Current number of spaces remaining for this registration slot.'),
    'field' => array(
      'handler' => 'qma_education_registration_handler_field_entity_capacity_remaining',
    ),
  );
}
