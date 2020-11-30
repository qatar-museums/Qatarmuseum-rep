<?php
/**
 * @file
 * qma_creative_resources.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_creative_resources_ctools_plugin_api($module = NULL, $api = NULL) {
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
function qma_creative_resources_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function qma_creative_resources_node_info() {
  $items = array(
    'creative_resource' => array(
      'name' => t('Creative Resource'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'creative_resource_hub' => array(
      'name' => t('Creative Resource Hub'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
