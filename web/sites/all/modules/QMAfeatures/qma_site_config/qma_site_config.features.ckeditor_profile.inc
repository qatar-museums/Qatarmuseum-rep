<?php
/**
 * @file
 * qma_site_config.features.ckeditor_profile.inc
 */

/**
 * Implements hook_ckeditor_profile_defaults().
 */
function qma_site_config_ckeditor_profile_defaults() {
  $data = array(
    'Editors' => array(
      'name' => 'Editors',
      'settings' => array(
        'ss' => 2,
        'toolbar' => '[
    [\'Source\',\'Format\',\'Styles\',\'Bold\',\'Italic\',\'NumberedList\',\'BulletedList\',\'Link\',\'Unlink\'],
    [\'Table\'],
    [\'Copy\',\'Cut\',\'Paste\'],
    [\'Undo\',\'Redo\',\'IMCE\']
]',
        'expand' => 't',
        'default' => 't',
        'show_toggle' => 'f',
        'uicolor' => 'custom',
        'uicolor_user' => '#D3D3D3',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'allowed_content' => 't',
        'extraAllowedContent' => '',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;div;h3;h4',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
            'breakBeforeClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'none',
        'css_path' => '',
        'css_style' => 'self',
        'styles_path' => '/sites/all/themes/shiny/ckeditor.styles.js',
        'filebrowser' => 'imce',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'forcePasteAsPlainText' => 't',
        'html_entities' => 'f',
        'scayt_autoStartup' => 'f',
        'theme_config_js' => 'f',
        'js_conf' => '',
        'loadPlugins' => array(
          'ckeditor_link' => array(
            'name' => 'drupal_path',
            'desc' => 'CKEditor Link - A plugin to easily create links to Drupal internal paths',
            'path' => '%base_path%sites/all/modules/ckeditor_link/plugins/link/',
            'buttons' => FALSE,
          ),
          'imce' => array(
            'name' => 'imce',
            'desc' => 'Plugin for inserting files from IMCE without image dialog',
            'path' => '%plugin_dir%imce/',
            'buttons' => array(
              'IMCE' => array(
                'label' => 'IMCE',
                'icon' => 'images/icon.png',
              ),
            ),
            'default' => 'f',
          ),
        ),
      ),
      'input_formats' => array(
        'editor_html' => 'editor_html',
      ),
    ),
  );
  return $data;
}
