<?php
/**
 * @file
 * qma_education_content_types.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function qma_education_content_types_taxonomy_default_vocabularies() {
  return array(
    'affiliation' => array(
      'name' => 'Affiliation',
      'machine_name' => 'affiliation',
      'description' => 'Which organisation a registrant is affiliated with',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'age_groups' => array(
      'name' => 'Age groups',
      'machine_name' => 'age_groups',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => -10,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'programme_type' => array(
      'name' => 'Programme Type',
      'machine_name' => 'programme_type',
      'description' => 'Categories for education programmes',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'topics' => array(
      'name' => 'Topics',
      'machine_name' => 'topics',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => -9,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
