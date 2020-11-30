<?php
/**
 * @file
 * qma_pattern_generator.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_pattern_generator_ctools_plugin_api($module = NULL, $api = NULL) {
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
function qma_pattern_generator_node_info() {
  $items = array(
    'pattern_gallery' => array(
      'name' => t('Pattern Gallery'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'pattern_generator' => array(
      'name' => t('Pattern Generator'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
