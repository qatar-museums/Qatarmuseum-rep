<?php
/**
 * @file
 * qma_area_of_work.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function qma_area_of_work_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_instagram_account_name'
  $field_bases['field_instagram_account_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_instagram_account_name',
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
      'max_length' => 255,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
