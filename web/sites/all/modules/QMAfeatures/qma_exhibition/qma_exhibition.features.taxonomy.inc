<?php
/**
 * @file
 * qma_exhibition.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function qma_exhibition_taxonomy_default_vocabularies() {
  return array(
    'exhibition_status_' => array(
      'name' => 'Exhibition status',
      'machine_name' => 'exhibition_status_',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 4,
    ),
  );
}
