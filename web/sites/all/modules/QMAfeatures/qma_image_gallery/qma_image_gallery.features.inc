<?php
/**
 * @file
 * qma_image_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_image_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
