<?php
/**
 * @file
 * qma_creative_resources.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function qma_creative_resources_taxonomy_default_vocabularies() {
  return array(
    'creative_resource_tags' => array(
      'name' => 'Creative Resource Tags',
      'machine_name' => 'creative_resource_tags',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
