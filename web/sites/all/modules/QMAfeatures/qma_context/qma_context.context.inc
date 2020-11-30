<?php
/**
 * @file
 * qma_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function qma_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'homepage';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'page_layout';
  $context->description = 'Global context to control header/footer etc';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~admin' => '~admin',
        '~admin/*' => '~admin/*',
        '~*/edit*' => '~*/edit*',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'header',
          'weight' => '-9',
        ),
        'logintoboggan-logintoboggan_logged_in' => array(
          'module' => 'logintoboggan',
          'delta' => 'logintoboggan_logged_in',
          'region' => 'header',
          'weight' => '-8',
        ),
        'menu_block-qma_menus_header_menu' => array(
          'module' => 'menu_block',
          'delta' => 'qma_menus_header_menu',
          'region' => 'header_menu',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'header_search',
          'weight' => '-10',
        ),
        'menu-menu-contact-us' => array(
          'module' => 'menu',
          'delta' => 'menu-contact-us',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'menu-menu-professional-services' => array(
          'module' => 'menu',
          'delta' => 'menu-professional-services',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'menu-menu-using-this-website' => array(
          'module' => 'menu',
          'delta' => 'menu-using-this-website',
          'region' => 'footer',
          'weight' => '-7',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global context to control header/footer etc');
  $export['page_layout'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'project_page';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'project' => 'project',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['project_page'] = $context;

  return $export;
}
