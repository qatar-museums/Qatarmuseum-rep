<?php
/**
 * @file
 * qma_promo_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_promo_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function qma_promo_type_node_info() {
  $items = array(
    'promo' => array(
      'name' => t('Promo'),
      'base' => 'node_content',
      'description' => t('Re-useable elements for inclusion on other pages'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
