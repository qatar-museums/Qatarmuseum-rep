<?php
/**
 * @file
 * qma_press.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_press_ctools_plugin_api($module = NULL, $api = NULL) {
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
function qma_press_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function qma_press_node_info() {
  $items = array(
    'press_release' => array(
      'name' => t('Press Release'),
      'base' => 'node_content',
      'description' => t('Use this content type to make press materials available for download. These items will appear only on the Press Room page and will not create a page of their own.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Use this content type to make press materials available for download. These items will appear only on the Press Room page and will not create a page of their own.'),
    ),
    'press_room' => array(
      'name' => t('Press Room'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
