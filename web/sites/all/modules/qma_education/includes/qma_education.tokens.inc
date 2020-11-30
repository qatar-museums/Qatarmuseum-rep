<?php

/**
 * @file
 * qma_education.tokens.inc
 */


/**
 * Implements hook_token_info_alter().
 *
 * @param $data
 */
function qma_education_token_info_alter(&$data) {
  $data['tokens']['registration']['registration_date_formatted'] = array(
    'name' => t('Registration date formatted', array(), array('context' => 'QMA')),
    'description' => 'A human-readable version of the registration date field',
  );
}

/**
 * Implements hook_tokens_alter().
 *
 * @param array $replacements
 * @param array $context
 */
function qma_education_tokens_alter(array &$replacements, array $context) {
  if ($context['type'] === 'registration' && !empty($context['data']['registration'])) {
    $tokens = $context['tokens'];
    $registration = $context['data']['registration'];
    $wrapper = entity_metadata_wrapper('registration', $registration);
    $date_value = $wrapper->field_qma_edu_reg_date->value();

    if (count($date_value) && isset($tokens['registration_date_formatted'])) {
      $variables = array(
        'startdate' => $date_value['value'],
        'enddate' => $date_value['value2'],
        'join' => '-',
      );

      $replacements[$tokens['registration_date_formatted']] = theme('qma_education_date_range', $variables);
    }
  }
}
