<?php
/**
 * @file
 * qma_instagram.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function qma_instagram_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'project_instagram';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'drupagram';
  $view->human_name = 'Project Instagram';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'instagram-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Instagram: Link */
  $handler->display->display_options['fields']['link']['id'] = 'link';
  $handler->display->display_options['fields']['link']['table'] = 'drupagram';
  $handler->display->display_options['fields']['link']['field'] = 'link';
  $handler->display->display_options['fields']['link']['label'] = '';
  $handler->display->display_options['fields']['link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['link']['display_as_link'] = FALSE;
  /* Field: Instagram: Caption */
  $handler->display->display_options['fields']['caption']['id'] = 'caption';
  $handler->display->display_options['fields']['caption']['table'] = 'drupagram';
  $handler->display->display_options['fields']['caption']['field'] = 'caption';
  $handler->display->display_options['fields']['caption']['label'] = '';
  $handler->display->display_options['fields']['caption']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['caption']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['caption']['element_type'] = 'p';
  $handler->display->display_options['fields']['caption']['element_class'] = 'instagram-caption';
  $handler->display->display_options['fields']['caption']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['caption']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['caption']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['caption']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['caption']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['caption']['format'] = 'key';
  /* Field: Instagram: Instagram author username */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'drupagram';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  $handler->display->display_options['fields']['username']['label'] = '';
  $handler->display->display_options['fields']['username']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['username']['alter']['text'] = '[username] on Instagram';
  $handler->display->display_options['fields']['username']['element_type'] = 'div';
  $handler->display->display_options['fields']['username']['element_class'] = 'instagram-user';
  $handler->display->display_options['fields']['username']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['username']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['username']['element_default_classes'] = FALSE;
  /* Field: Instagram: Instagram image */
  $handler->display->display_options['fields']['images']['id'] = 'images';
  $handler->display->display_options['fields']['images']['table'] = 'drupagram';
  $handler->display->display_options['fields']['images']['field'] = 'images';
  $handler->display->display_options['fields']['images']['label'] = '';
  $handler->display->display_options['fields']['images']['element_type'] = 'div';
  $handler->display->display_options['fields']['images']['element_class'] = 'instagram-image';
  $handler->display->display_options['fields']['images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['images']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['images']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['images']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['images']['source'] = 'local';
  $handler->display->display_options['fields']['images']['secure'] = 0;
  $handler->display->display_options['fields']['images']['link_to_post'] = 0;
  $handler->display->display_options['fields']['images']['image_style'] = 'instagram_image_square';
  /* Sort criterion: Instagram: Created time */
  $handler->display->display_options['sorts']['created_time']['id'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['table'] = 'drupagram';
  $handler->display->display_options['sorts']['created_time']['field'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['order'] = 'DESC';

  /* Display: Latest five Instagram block */
  $handler = $view->new_display('block', 'Latest five Instagram block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';

  /* Display: Latest three social block */
  $handler = $view->new_display('block', 'Latest three social block', 'block_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Instagram: Instagram image */
  $handler->display->display_options['fields']['images']['id'] = 'images';
  $handler->display->display_options['fields']['images']['table'] = 'drupagram';
  $handler->display->display_options['fields']['images']['field'] = 'images';
  $handler->display->display_options['fields']['images']['label'] = '';
  $handler->display->display_options['fields']['images']['element_type'] = 'div';
  $handler->display->display_options['fields']['images']['element_class'] = 'instagram-image';
  $handler->display->display_options['fields']['images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['images']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['images']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['images']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['images']['source'] = 'local';
  $handler->display->display_options['fields']['images']['secure'] = 0;
  $handler->display->display_options['fields']['images']['link_to_post'] = 1;
  $handler->display->display_options['fields']['images']['image_style'] = 'instagram_square_large';
  /* Field: Instagram: Link */
  $handler->display->display_options['fields']['link']['id'] = 'link';
  $handler->display->display_options['fields']['link']['table'] = 'drupagram';
  $handler->display->display_options['fields']['link']['field'] = 'link';
  $handler->display->display_options['fields']['link']['label'] = '';
  $handler->display->display_options['fields']['link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['link']['display_as_link'] = FALSE;
  /* Field: Instagram: Caption */
  $handler->display->display_options['fields']['caption']['id'] = 'caption';
  $handler->display->display_options['fields']['caption']['table'] = 'drupagram';
  $handler->display->display_options['fields']['caption']['field'] = 'caption';
  $handler->display->display_options['fields']['caption']['label'] = '';
  $handler->display->display_options['fields']['caption']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['caption']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['caption']['element_type'] = 'p';
  $handler->display->display_options['fields']['caption']['element_class'] = 'instagram-caption';
  $handler->display->display_options['fields']['caption']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['caption']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['caption']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['caption']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['caption']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['caption']['format'] = 'key';
  /* Field: Instagram: Created time */
  $handler->display->display_options['fields']['created_time']['id'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['table'] = 'drupagram';
  $handler->display->display_options['fields']['created_time']['field'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['label'] = '';
  $handler->display->display_options['fields']['created_time']['element_type'] = 'p';
  $handler->display->display_options['fields']['created_time']['element_class'] = 'instagram-postdate';
  $handler->display->display_options['fields']['created_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_time']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['created_time']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created_time']['date_format'] = 'time ago';
  /* Field: Instagram: Instagram author username */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'drupagram';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  $handler->display->display_options['fields']['username']['label'] = '';
  $handler->display->display_options['fields']['username']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['username']['alter']['path'] = 'www.instagram.com/[username]';
  $handler->display->display_options['fields']['username']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['username']['alter']['prefix'] = '<span>Follow on Instagram:</span>';
  $handler->display->display_options['fields']['username']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['username']['element_type'] = 'p';
  $handler->display->display_options['fields']['username']['element_class'] = 'instagram-user';
  $handler->display->display_options['fields']['username']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['username']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['username']['element_default_classes'] = FALSE;

  /* Display: Latest ten social block */
  $handler = $view->new_display('block', 'Latest ten social block', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Instagram: Instagram image */
  $handler->display->display_options['fields']['images']['id'] = 'images';
  $handler->display->display_options['fields']['images']['table'] = 'drupagram';
  $handler->display->display_options['fields']['images']['field'] = 'images';
  $handler->display->display_options['fields']['images']['label'] = '';
  $handler->display->display_options['fields']['images']['element_type'] = 'div';
  $handler->display->display_options['fields']['images']['element_class'] = 'instagram-image';
  $handler->display->display_options['fields']['images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['images']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['images']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['images']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['images']['source'] = 'local';
  $handler->display->display_options['fields']['images']['secure'] = 0;
  $handler->display->display_options['fields']['images']['link_to_post'] = 1;
  $handler->display->display_options['fields']['images']['image_style'] = 'instagram_square_large';
  /* Field: Instagram: Link */
  $handler->display->display_options['fields']['link']['id'] = 'link';
  $handler->display->display_options['fields']['link']['table'] = 'drupagram';
  $handler->display->display_options['fields']['link']['field'] = 'link';
  $handler->display->display_options['fields']['link']['label'] = '';
  $handler->display->display_options['fields']['link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['link']['display_as_link'] = FALSE;
  /* Field: Instagram: Caption */
  $handler->display->display_options['fields']['caption']['id'] = 'caption';
  $handler->display->display_options['fields']['caption']['table'] = 'drupagram';
  $handler->display->display_options['fields']['caption']['field'] = 'caption';
  $handler->display->display_options['fields']['caption']['label'] = '';
  $handler->display->display_options['fields']['caption']['alter']['max_length'] = '120';
  $handler->display->display_options['fields']['caption']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['caption']['element_type'] = 'p';
  $handler->display->display_options['fields']['caption']['element_class'] = 'instagram-caption';
  $handler->display->display_options['fields']['caption']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['caption']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['caption']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['caption']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['caption']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['caption']['format'] = 'key';
  /* Field: Instagram: Created time */
  $handler->display->display_options['fields']['created_time']['id'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['table'] = 'drupagram';
  $handler->display->display_options['fields']['created_time']['field'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['label'] = '';
  $handler->display->display_options['fields']['created_time']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created_time']['element_type'] = 'p';
  $handler->display->display_options['fields']['created_time']['element_class'] = 'instagram-postdate';
  $handler->display->display_options['fields']['created_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_time']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['created_time']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created_time']['date_format'] = 'time ago';
  /* Field: Instagram: Instagram author username */
  $handler->display->display_options['fields']['username']['id'] = 'username';
  $handler->display->display_options['fields']['username']['table'] = 'drupagram';
  $handler->display->display_options['fields']['username']['field'] = 'username';
  $handler->display->display_options['fields']['username']['label'] = '';
  $handler->display->display_options['fields']['username']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['username']['alter']['path'] = 'www.instagram.com/[username]';
  $handler->display->display_options['fields']['username']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['username']['alter']['prefix'] = '<span>Follow on Instagram:</span>';
  $handler->display->display_options['fields']['username']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['username']['element_type'] = 'p';
  $handler->display->display_options['fields']['username']['element_class'] = 'instagram-user';
  $handler->display->display_options['fields']['username']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['username']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['username']['element_default_classes'] = FALSE;
  $export['project_instagram'] = $view;

  return $export;
}
