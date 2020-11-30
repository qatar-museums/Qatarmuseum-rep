<?php
/**
 * @file
 * qma_press.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function qma_press_taxonomy_default_vocabularies() {
  return array(
    'press_news_type' => array(
      'name' => 'Press News Type',
      'machine_name' => 'press_news_type',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
    'press_tags' => array(
      'name' => 'Press Tags',
      'machine_name' => 'press_tags',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
