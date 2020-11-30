<?php
/**
 * @file
 * qma_area_of_work.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_area_of_work_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
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
function qma_area_of_work_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function qma_area_of_work_node_info() {
  $items = array(
    'area_of_work' => array(
      'name' => t('Area of Work'),
      'base' => 'node_content',
      'description' => t('Areas of Work are categories to group Projects under. The categories are Museums & Galleries, Archaeology, Public Art. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Areas of Work are categories to group Projects under. The categories are Museums & Galleries, Archaeology, Public Art. '),
    ),
  );
  return $items;
}
