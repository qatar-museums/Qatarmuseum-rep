<?php
/**
 * @file
 * qma_twitter_handling.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_twitter_handling_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function qma_twitter_handling_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
