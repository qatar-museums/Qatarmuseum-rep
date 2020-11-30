<?php
/**
 * @file
 * qma_news.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function qma_news_taxonomy_default_vocabularies() {
  return array(
    'blog_tags' => array(
      'name' => 'Blog tags',
      'machine_name' => 'blog_tags',
      'description' => 'Add tags to blog posts',
      'hierarchy' => 1,
      'module' => 'qma_news',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 4,
    ),
  );
}
