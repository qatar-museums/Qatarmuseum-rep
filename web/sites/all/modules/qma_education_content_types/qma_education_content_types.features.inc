<?php
/**
 * @file
 * qma_education_content_types.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_education_content_types_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function qma_education_content_types_node_info() {
  $items = array(
    'education_hub' => array(
      'name' => t('Education Hub'),
      'base' => 'node_content',
      'description' => t('An <em>Education Hub</em> page lists its child pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('An <em>Education Hub</em> page lists its child pages.'),
    ),
    'education_institution' => array(
      'name' => t('Education Institution'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'education_prog' => array(
      'name' => t('Education Programme'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'education_resource' => array(
      'name' => t('Education Resource'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'education_resource_hub' => array(
      'name' => t('Education Resource Hub'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_registration_state().
 */
function qma_education_content_types_default_registration_state() {
  $items = array();
  $items['canceled'] = entity_import('registration_state', '{
    "name" : "canceled",
    "label" : "Canceled",
    "description" : "Registration was cancelled",
    "default_state" : "0",
    "active" : "0",
    "show_on_form" : "0",
    "weight" : "1"
  }');
  $items['complete'] = entity_import('registration_state', '{
    "name" : "complete",
    "label" : "Complete",
    "description" : "Registration has been completed.",
    "default_state" : "1",
    "active" : "1",
    "show_on_form" : "0",
    "weight" : "1"
  }');
  $items['pending'] = entity_import('registration_state', '{
    "name" : "pending",
    "label" : "Pending",
    "description" : "Registration is pending.",
    "default_state" : "0",
    "active" : "0",
    "show_on_form" : "0",
    "weight" : "1"
  }');
  return $items;
}

/**
 * Implements hook_default_registration_type().
 */
function qma_education_content_types_default_registration_type() {
  $items = array();
  $items['qma_education_event_registration'] = entity_import('registration_type', '{
    "name" : "qma_education_event_registration",
    "label" : "Event registration",
    "locked" : "0",
    "weight" : "0",
    "data" : null
  }');
  return $items;
}
