<?php
/**
 * @file
 * qma_homepage_v2.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_homepage_v2_ctools_plugin_api($module = NULL, $api = NULL) {
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
function qma_homepage_v2_node_info() {
  $items = array(
    'qma_homepage' => array(
      'name' => t('Homepage'),
      'base' => 'node_content',
      'description' => t('The most visited page of the site the homepage celebrates QM\'s achievements and aims. It will offer several ways for users to engage with local culture.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
