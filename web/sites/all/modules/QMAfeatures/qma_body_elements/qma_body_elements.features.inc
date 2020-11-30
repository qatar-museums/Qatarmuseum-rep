<?php
/**
 * @file
 * qma_body_elements.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_body_elements_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
