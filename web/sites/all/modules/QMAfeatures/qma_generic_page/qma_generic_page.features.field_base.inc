<?php
/**
 * @file
 * qma_generic_page.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function qma_generic_page_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_display_social_media'
  $field_bases['field_display_social_media'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_display_social_media',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
