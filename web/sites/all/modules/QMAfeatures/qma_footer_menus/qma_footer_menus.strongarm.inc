<?php
/**
 * @file
 * qma_footer_menus.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function qma_footer_menus_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_menu_node_translation_menu-behind-the-scenes';
  $strongarm->value = 1;
  $export['i18n_menu_node_translation_menu-behind-the-scenes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_menu_node_translation_menu-using-this-website';
  $strongarm->value = 1;
  $export['i18n_menu_node_translation_menu-using-this-website'] = $strongarm;

  return $export;
}
