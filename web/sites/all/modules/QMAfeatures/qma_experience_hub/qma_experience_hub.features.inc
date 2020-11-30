<?php
/**
 * @file
 * qma_experience_hub.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_experience_hub_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function qma_experience_hub_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function qma_experience_hub_node_info() {
  $items = array(
    'areas_hub' => array(
      'name' => t('Experience Hub'),
      'base' => 'node_content',
      'description' => t('Experience Hub is the landing page for the Experience section. It lists all Projects and Areas of Work.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Experience Hub is the landing page for the Experience section. It lists all Projects and Areas of Work.'),
    ),
  );
  return $items;
}
