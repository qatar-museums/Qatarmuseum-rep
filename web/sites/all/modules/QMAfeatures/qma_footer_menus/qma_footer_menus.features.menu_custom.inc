<?php
/**
 * @file
 * qma_footer_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function qma_footer_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-behind-the-scenes.
  $menus['menu-behind-the-scenes'] = array(
    'menu_name' => 'menu-behind-the-scenes',
    'title' => 'Behind The Scenes',
    'description' => 'Behind the scenes menu found in the footer.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-contact-us.
  $menus['menu-contact-us'] = array(
    'menu_name' => 'menu-contact-us',
    'title' => 'Contact Us',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-professional-services.
  $menus['menu-professional-services'] = array(
    'menu_name' => 'menu-professional-services',
    'title' => 'Professional Services',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-using-this-website.
  $menus['menu-using-this-website'] = array(
    'menu_name' => 'menu-using-this-website',
    'title' => 'Using this website',
    'description' => 'Using this website menu found in the footer',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Behind The Scenes');
  t('Behind the scenes menu found in the footer.');
  t('Contact Us');
  t('Professional Services');
  t('Using this website');
  t('Using this website menu found in the footer');


  return $menus;
}
