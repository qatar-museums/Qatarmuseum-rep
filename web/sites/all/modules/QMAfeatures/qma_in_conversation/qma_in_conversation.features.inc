<?php
/**
 * @file
 * qma_in_conversation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_in_conversation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function qma_in_conversation_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function qma_in_conversation_node_info() {
  $items = array(
    'interview' => array(
      'name' => t('In Conversation Article'),
      'base' => 'node_content',
      'description' => t('In Conversation Article contains an interview with a local talent. '),
      'has_title' => '1',
      'title_label' => t('Interviewee name'),
      'help' => t('In Conversation Article contains an interview with a local talent. '),
    ),
    'interview_hub' => array(
      'name' => t('In Conversation Hub'),
      'base' => 'node_content',
      'description' => t('In Conversation Hub is a landing page that lists all of the In Conversation Articles. It is a section of the website that showcases interviews with local talent. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('In Conversation Hub is a landing page that lists all of the In Conversation Articles. It is a section of the website that showcases interviews with local talent. '),
    ),
  );
  return $items;
}
