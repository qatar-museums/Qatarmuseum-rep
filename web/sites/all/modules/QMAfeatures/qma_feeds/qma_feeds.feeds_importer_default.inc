<?php
/**
 * @file
 * qma_feeds.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function qma_feeds_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'news_items';
  $feeds_importer->config = array(
    'name' => 'News items',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
        'directory' => 'private://feeds',
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'text',
            'target' => 'field_body_elements:field_element_text_area',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'status',
            'target' => 'status',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'uid',
            'target' => 'uid',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'published',
            'target' => 'field_news_date:start',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'langcode',
            'target' => 'language',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'input_format' => 'editor_html',
        'skip_hash_check' => 0,
        'bundle' => 'news_article',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['news_items'] = $feeds_importer;

  return $export;
}
