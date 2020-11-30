<?php
/**
 * @file
 * qma_project.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function qma_project_taxonomy_default_vocabularies() {
  return array(
    'sample_vocab' => array(
      'name' => 'Subject tags',
      'machine_name' => 'sample_vocab',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
