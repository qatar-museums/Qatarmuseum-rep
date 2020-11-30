<?php
/**
 * @file
 * qma_landing_page.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function qma_landing_page_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_landing-page:node/add/landing-page
  $menu_links['navigation_landing-page:node/add/landing-page'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/landing-page',
    'router_path' => 'node/add/landing-page',
    'link_title' => 'Landing Page',
    'options' => array(
      'identifier' => 'navigation_landing-page:node/add/landing-page',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'navigation_add-content:node/add',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Landing Page');


  return $menu_links;
}
