<?php
/**
 * @file
 * qma_project.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_project_ctools_plugin_api($module = NULL, $api = NULL) {
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
function qma_project_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('Projects are the main child elements of the Experience section. These provide evidence for all the work that QM has done.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Projects are the main child elements of the Experience section. These provide evidence for all the work that QM has done.'),
    ),
  );
  return $items;
}
