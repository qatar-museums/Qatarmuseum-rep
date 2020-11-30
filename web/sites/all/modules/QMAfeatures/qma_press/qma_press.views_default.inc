<?php
/**
 * @file
 * qma_press.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function qma_press_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'press';
  $view->description = 'List all press releases for use on the press room page';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Press';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Update';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_press_news_type_tid_i18n' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'field_press_tags_tid_i18n' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_select_all_none_nested' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
    'combine' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'editor_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_press_description' => 'title',
    'field_display_date' => 'title',
    'field_press_file_attachment' => 'field_press_file_attachment',
    'field_press_news_type' => 'field_press_tags',
    'field_press_tags' => 'field_press_tags',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_press_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_display_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_press_file_attachment' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_press_news_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_press_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Showing @start to @end of @total press releases';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results found. Please choose a different combination of filters.';
  $handler->display->display_options['empty']['area']['format'] = 'editor_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Item';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_press_description']['id'] = 'field_press_description';
  $handler->display->display_options['fields']['field_press_description']['table'] = 'field_data_field_press_description';
  $handler->display->display_options['fields']['field_press_description']['field'] = 'field_press_description';
  $handler->display->display_options['fields']['field_press_description']['label'] = '';
  $handler->display->display_options['fields']['field_press_description']['element_label_colon'] = FALSE;
  /* Field: Content: Display date */
  $handler->display->display_options['fields']['field_display_date']['id'] = 'field_display_date';
  $handler->display->display_options['fields']['field_display_date']['table'] = 'field_data_field_display_date';
  $handler->display->display_options['fields']['field_display_date']['field'] = 'field_display_date';
  $handler->display->display_options['fields']['field_display_date']['label'] = '';
  $handler->display->display_options['fields']['field_display_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_date']['settings'] = array(
    'format_type' => 'medium_plain_month',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: File Attachment */
  $handler->display->display_options['fields']['field_press_file_attachment']['id'] = 'field_press_file_attachment';
  $handler->display->display_options['fields']['field_press_file_attachment']['table'] = 'field_data_field_press_file_attachment';
  $handler->display->display_options['fields']['field_press_file_attachment']['field'] = 'field_press_file_attachment';
  $handler->display->display_options['fields']['field_press_file_attachment']['label'] = 'Info';
  $handler->display->display_options['fields']['field_press_file_attachment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_file_attachment']['click_sort_column'] = 'fid';
  /* Field: Content: News Type */
  $handler->display->display_options['fields']['field_press_news_type']['id'] = 'field_press_news_type';
  $handler->display->display_options['fields']['field_press_news_type']['table'] = 'field_data_field_press_news_type';
  $handler->display->display_options['fields']['field_press_news_type']['field'] = 'field_press_news_type';
  $handler->display->display_options['fields']['field_press_news_type']['label'] = '';
  $handler->display->display_options['fields']['field_press_news_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_news_type']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_press_news_type']['multi_type'] = 'ul';
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_press_tags']['id'] = 'field_press_tags';
  $handler->display->display_options['fields']['field_press_tags']['table'] = 'field_data_field_press_tags';
  $handler->display->display_options['fields']['field_press_tags']['field'] = 'field_press_tags';
  $handler->display->display_options['fields']['field_press_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_press_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_press_tags']['multi_type'] = 'ul';
  /* Sort criterion: Content: Display date (field_display_date) */
  $handler->display->display_options['sorts']['field_display_date_value']['id'] = 'field_display_date_value';
  $handler->display->display_options['sorts']['field_display_date_value']['table'] = 'field_data_field_display_date';
  $handler->display->display_options['sorts']['field_display_date_value']['field'] = 'field_display_date_value';
  $handler->display->display_options['sorts']['field_display_date_value']['order'] = 'DESC';
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
    'press_release' => 'press_release',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: News Type (field_press_news_type) (translated) */
  $handler->display->display_options['filters']['field_press_news_type_tid_i18n']['id'] = 'field_press_news_type_tid_i18n';
  $handler->display->display_options['filters']['field_press_news_type_tid_i18n']['table'] = 'field_data_field_press_news_type';
  $handler->display->display_options['filters']['field_press_news_type_tid_i18n']['field'] = 'field_press_news_type_tid_i18n';
  $handler->display->display_options['filters']['field_press_news_type_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_press_news_type_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_press_news_type_tid_i18n']['expose']['operator_id'] = 'field_press_news_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_press_news_type_tid_i18n']['expose']['label'] = 'Filter by Type';
  $handler->display->display_options['filters']['field_press_news_type_tid_i18n']['expose']['operator'] = 'field_press_news_type_tid_i18n_op';
  $handler->display->display_options['filters']['field_press_news_type_tid_i18n']['expose']['identifier'] = 'typeid';
  $handler->display->display_options['filters']['field_press_news_type_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_press_news_type_tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_press_news_type_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_press_news_type_tid_i18n']['vocabulary'] = 'press_news_type';
  /* Filter criterion: Content: Tags (field_press_tags) (translated) */
  $handler->display->display_options['filters']['field_press_tags_tid_i18n']['id'] = 'field_press_tags_tid_i18n';
  $handler->display->display_options['filters']['field_press_tags_tid_i18n']['table'] = 'field_data_field_press_tags';
  $handler->display->display_options['filters']['field_press_tags_tid_i18n']['field'] = 'field_press_tags_tid_i18n';
  $handler->display->display_options['filters']['field_press_tags_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_press_tags_tid_i18n']['expose']['operator_id'] = 'field_press_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_press_tags_tid_i18n']['expose']['label'] = 'Filter by Tag';
  $handler->display->display_options['filters']['field_press_tags_tid_i18n']['expose']['operator'] = 'field_press_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_press_tags_tid_i18n']['expose']['identifier'] = 'tagid';
  $handler->display->display_options['filters']['field_press_tags_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_press_tags_tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_press_tags_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_press_tags_tid_i18n']['vocabulary'] = 'press_tags';
  $handler->display->display_options['filters']['field_press_tags_tid_i18n']['hierarchy'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Filter';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'field_press_description' => 'field_press_description',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['field_language'] = 'en';
  $export['press'] = $view;

  $view = new view();
  $view->name = 'press_questions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'qma_forms_press_question';
  $view->human_name = 'Press Questions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Press Questions';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access site reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Qma Forms Press Question: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'qma_forms_press_question';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: Qma Forms Press Question: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'qma_forms_press_question';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Field: Qma Forms Press Question: Request */
  $handler->display->display_options['fields']['request_type']['id'] = 'request_type';
  $handler->display->display_options['fields']['request_type']['table'] = 'qma_forms_press_question';
  $handler->display->display_options['fields']['request_type']['field'] = 'request_type';
  /* Field: Qma Forms Press Question: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'qma_forms_press_question';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Qma Forms Press Question: Company */
  $handler->display->display_options['fields']['organisation']['id'] = 'organisation';
  $handler->display->display_options['fields']['organisation']['table'] = 'qma_forms_press_question';
  $handler->display->display_options['fields']['organisation']['field'] = 'organisation';
  /* Field: Qma Forms Press Question: Email */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'qma_forms_press_question';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  /* Field: Qma Forms Press Question: Question */
  $handler->display->display_options['fields']['question']['id'] = 'question';
  $handler->display->display_options['fields']['question']['table'] = 'qma_forms_press_question';
  $handler->display->display_options['fields']['question']['field'] = 'question';
  /* Sort criterion: Qma Forms Press Question: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'qma_forms_press_question';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Qma Forms Press Question: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'qma_forms_press_question';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['description'] = 'enter \'en\' for english or \'ar\' for arabic';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/reports/press-questions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Press Questions';
  $handler->display->display_options['menu']['description'] = 'User submitted questions for the press department';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['press_questions'] = $view;

  return $export;
}
