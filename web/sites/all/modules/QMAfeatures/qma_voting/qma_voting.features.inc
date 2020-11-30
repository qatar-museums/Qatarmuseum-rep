<?php
/**
 * @file
 * qma_voting.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_voting_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function qma_voting_node_info() {
  $items = array(
    'advpoll' => array(
      'name' => t('Feedback Poll'),
      'base' => 'node_content',
      'description' => t('Feedback Polls allow for creating a simple question/answer vote for site users. Once created polls may be included on certain other content types '),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => t('Feedback Polls allow for creating a simple question/answer vote for site users. Once created polls may be included on certain other content types '),
    ),
  );
  return $items;
}
