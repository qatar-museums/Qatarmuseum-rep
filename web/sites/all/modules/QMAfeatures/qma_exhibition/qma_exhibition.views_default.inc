<?php
/**
 * @file
 * qma_exhibition.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function qma_exhibition_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'current_exhibitions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Current Exhibitions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Current Exhibitions';
  $handler->display->display_options['css_class'] = 'exhibition-items';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'exhibition-item';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Display weight (field_display_weight) */
  $handler->display->display_options['sorts']['field_display_weight_value']['id'] = 'field_display_weight_value';
  $handler->display->display_options['sorts']['field_display_weight_value']['table'] = 'field_data_field_display_weight';
  $handler->display->display_options['sorts']['field_display_weight_value']['field'] = 'field_display_weight_value';
  /* Contextual filter: Content: Language */
  $handler->display->display_options['arguments']['language']['id'] = 'language';
  $handler->display->display_options['arguments']['language']['table'] = 'node';
  $handler->display->display_options['arguments']['language']['field'] = 'language';
  $handler->display->display_options['arguments']['language']['default_action'] = 'default';
  $handler->display->display_options['arguments']['language']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['language']['default_argument_options']['code'] = '//return interface language if content language not provided by template 
global $language;
return $language->language;';
  $handler->display->display_options['arguments']['language']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['language']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['language']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'exhibition' => 'exhibition',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'current_exhibitions_block');
  $handler->display->display_options['block_description'] = 'current_exhibitions_block';
  $export['current_exhibitions'] = $view;

  $view = new view();
  $view->name = 'past_exhibitions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Past Exhibitions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Past Exhibitions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_date',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'exhibition-item';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = '';
  $handler->display->display_options['fields']['field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'year_only',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Sort criterion: Content: Date -  start date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
  /* Sort criterion: Content: Display weight (field_display_weight) */
  $handler->display->display_options['sorts']['field_display_weight_value']['id'] = 'field_display_weight_value';
  $handler->display->display_options['sorts']['field_display_weight_value']['table'] = 'field_data_field_display_weight';
  $handler->display->display_options['sorts']['field_display_weight_value']['field'] = 'field_display_weight_value';
  /* Contextual filter: Content: Language */
  $handler->display->display_options['arguments']['language']['id'] = 'language';
  $handler->display->display_options['arguments']['language']['table'] = 'node';
  $handler->display->display_options['arguments']['language']['field'] = 'language';
  $handler->display->display_options['arguments']['language']['default_action'] = 'default';
  $handler->display->display_options['arguments']['language']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['language']['default_argument_options']['code'] = '//return interface language if content language not provided by template 
global $language;
return $language->language;';
  $handler->display->display_options['arguments']['language']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['language']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['language']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'exhibition' => 'exhibition',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'past_exhibition_block');
  $handler->display->display_options['block_description'] = 'past_exhibition_block';
  $export['past_exhibitions'] = $view;

  return $export;
}
