<?php
/**
 * @file
 * qma_https_handling.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_https_handling_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
