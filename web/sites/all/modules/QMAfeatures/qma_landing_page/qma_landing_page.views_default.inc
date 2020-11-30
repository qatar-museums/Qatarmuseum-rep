<?php
/**
 * @file
 * qma_landing_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function qma_landing_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'child_pages_by_menu';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Child Pages by Menu';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'grid-3';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Sort criterion: Menu: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'menu_links';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Menu: i18n Node id */
  $handler->display->display_options['arguments']['i18n_nid']['id'] = 'i18n_nid';
  $handler->display->display_options['arguments']['i18n_nid']['table'] = 'menu_links';
  $handler->display->display_options['arguments']['i18n_nid']['field'] = 'i18n_nid';
  $handler->display->display_options['arguments']['i18n_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['i18n_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['i18n_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['i18n_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['i18n_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['i18n_nid']['depth'] = '5';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['arguments']['nid_1']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid_1']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid_1']['not'] = TRUE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'child_pages_block');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Menu: i18n Node id */
  $handler->display->display_options['arguments']['i18n_nid']['id'] = 'i18n_nid';
  $handler->display->display_options['arguments']['i18n_nid']['table'] = 'menu_links';
  $handler->display->display_options['arguments']['i18n_nid']['field'] = 'i18n_nid';
  $handler->display->display_options['arguments']['i18n_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['i18n_nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['i18n_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['i18n_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['i18n_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['i18n_nid']['depth'] = '1';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['arguments']['nid_1']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid_1']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid_1']['not'] = TRUE;

  /* Display: Child page filter */
  $handler = $view->new_display('entityreference', 'Child page filter', 'grandchild_select_filter');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'type' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'type' => 'type',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Menu: i18n Node id */
  $handler->display->display_options['arguments']['i18n_nid']['id'] = 'i18n_nid';
  $handler->display->display_options['arguments']['i18n_nid']['table'] = 'menu_links';
  $handler->display->display_options['arguments']['i18n_nid']['field'] = 'i18n_nid';
  $handler->display->display_options['arguments']['i18n_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['i18n_nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['i18n_nid']['default_argument_options']['code'] = '//get the node id of the calling page or edit form, use of php code here to allow us to do special handling of translations where we wish to pass the source node id
if (arg(0)==\'node\' && is_numeric(arg(1))) {
return arg(1);
} else if(isset($_GET[\'translation\'])) {
return $_GET[\'translation\'];
} else {
return \'all\';
}';
  $handler->display->display_options['arguments']['i18n_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['i18n_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['i18n_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['i18n_nid']['depth'] = '5';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['arguments']['nid_1']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid_1']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid_1']['default_argument_options']['code'] = '//get the node id of the calling page or edit form, use of php code here to allow us to do special handling of translations where we wish to pass the source node id
if (arg(0)==\'node\' && is_numeric(arg(1))) {
return arg(1);
} else if(isset($_GET[\'translation\'])) {
return $_GET[\'translation\'];
} else {
return \'all\';
}';
  $handler->display->display_options['arguments']['nid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid_1']['not'] = TRUE;
  $export['child_pages_by_menu'] = $view;

  return $export;
}
