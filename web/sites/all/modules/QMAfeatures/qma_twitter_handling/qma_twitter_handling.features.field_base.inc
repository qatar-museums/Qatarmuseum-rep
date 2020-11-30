<?php
/**
 * @file
 * qma_twitter_handling.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function qma_twitter_handling_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_twitter_account'
  $field_bases['field_twitter_account'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_twitter_account',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'cck_allowed_values_php',
      'allowed_values_php' => '$returnArr = array();
$result = db_select(\'twitter_account\',\'ta\')
          ->fields(\'ta\',array(\'screen_name\'))
          ->execute();

foreach($result as $item) {
         $returnArr[$item->screen_name] = $item->screen_name;
}
return $returnArr;',
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_twitter_hashtag'
  $field_bases['field_twitter_hashtag'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_twitter_hashtag',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 127,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
