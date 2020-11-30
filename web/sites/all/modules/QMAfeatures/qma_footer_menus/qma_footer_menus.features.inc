<?php
/**
 * @file
 * qma_footer_menus.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_footer_menus_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
