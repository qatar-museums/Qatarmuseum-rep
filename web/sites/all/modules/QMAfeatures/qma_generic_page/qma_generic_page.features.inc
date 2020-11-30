<?php
/**
 * @file
 * qma_generic_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_generic_page_ctools_plugin_api($module = NULL, $api = NULL) {
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
function qma_generic_page_node_info() {
  $items = array(
    'generic_page' => array(
      'name' => t('Generic Page'),
      'base' => 'node_content',
      'description' => t('The most common type of page, Generic Content, is highly flexible with the ability to incorporate diverse types of content. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('The most common type of page, Generic Content, is highly flexible with the ability to incorporate diverse types of content. '),
    ),
  );
  return $items;
}
