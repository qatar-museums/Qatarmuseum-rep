<?php
/**
 * @file
 * qma_email_setup.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_email_setup_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
