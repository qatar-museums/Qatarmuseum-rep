<?php
/**
 * @file
 * qma_in_conversation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function qma_in_conversation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'interviews';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Interviews';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'In Conversation';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
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
  /* Field: Content: Interviewee role */
  $handler->display->display_options['fields']['field_interviewee_role']['id'] = 'field_interviewee_role';
  $handler->display->display_options['fields']['field_interviewee_role']['table'] = 'field_data_field_interviewee_role';
  $handler->display->display_options['fields']['field_interviewee_role']['field'] = 'field_interviewee_role';
  $handler->display->display_options['fields']['field_interviewee_role']['label'] = '';
  $handler->display->display_options['fields']['field_interviewee_role']['element_label_colon'] = FALSE;
  /* Field: Content: Teaser image */
  $handler->display->display_options['fields']['field_teaser_image']['id'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['table'] = 'field_data_field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['field'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_teaser_image']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  /* Field: Content: Interview date */
  $handler->display->display_options['fields']['field_interview_date']['id'] = 'field_interview_date';
  $handler->display->display_options['fields']['field_interview_date']['table'] = 'field_data_field_interview_date';
  $handler->display->display_options['fields']['field_interview_date']['field'] = 'field_interview_date';
  $handler->display->display_options['fields']['field_interview_date']['label'] = '';
  $handler->display->display_options['fields']['field_interview_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_interview_date']['settings'] = array(
    'format_type' => 'standard',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Teaser text */
  $handler->display->display_options['fields']['field_teaser_text']['id'] = 'field_teaser_text';
  $handler->display->display_options['fields']['field_teaser_text']['table'] = 'field_data_field_teaser_text';
  $handler->display->display_options['fields']['field_teaser_text']['field'] = 'field_teaser_text';
  $handler->display->display_options['fields']['field_teaser_text']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_text']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Interview date (field_interview_date) */
  $handler->display->display_options['sorts']['field_interview_date_value']['id'] = 'field_interview_date_value';
  $handler->display->display_options['sorts']['field_interview_date_value']['table'] = 'field_data_field_interview_date';
  $handler->display->display_options['sorts']['field_interview_date_value']['field'] = 'field_interview_date_value';
  $handler->display->display_options['sorts']['field_interview_date_value']['order'] = 'DESC';
  /* Contextual filter: Content: Area of Work (field_area_of_work) */
  $handler->display->display_options['arguments']['field_area_of_work_target_id']['id'] = 'field_area_of_work_target_id';
  $handler->display->display_options['arguments']['field_area_of_work_target_id']['table'] = 'field_data_field_area_of_work';
  $handler->display->display_options['arguments']['field_area_of_work_target_id']['field'] = 'field_area_of_work_target_id';
  $handler->display->display_options['arguments']['field_area_of_work_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_area_of_work_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_area_of_work_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_area_of_work_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_area_of_work_target_id']['summary_options']['items_per_page'] = '25';
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
    'interview' => 'interview',
  );

  /* Display: interview listing */
  $handler = $view->new_display('block', 'interview listing', 'interview_listing');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'offset by 1 to list out all but the latest interview';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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

  /* Display: Latest Interview */
  $handler = $view->new_display('block', 'Latest Interview', 'latest_interview');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'featured_conversation';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Interview date */
  $handler->display->display_options['fields']['field_interview_date']['id'] = 'field_interview_date';
  $handler->display->display_options['fields']['field_interview_date']['table'] = 'field_data_field_interview_date';
  $handler->display->display_options['fields']['field_interview_date']['field'] = 'field_interview_date';
  $handler->display->display_options['fields']['field_interview_date']['label'] = '';
  $handler->display->display_options['fields']['field_interview_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_interview_date']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_interview_date']['element_wrapper_class'] = 'subheading';
  $handler->display->display_options['fields']['field_interview_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_interview_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Interviewee role */
  $handler->display->display_options['fields']['field_interviewee_role']['id'] = 'field_interviewee_role';
  $handler->display->display_options['fields']['field_interviewee_role']['table'] = 'field_data_field_interviewee_role';
  $handler->display->display_options['fields']['field_interviewee_role']['field'] = 'field_interviewee_role';
  $handler->display->display_options['fields']['field_interviewee_role']['label'] = '';
  $handler->display->display_options['fields']['field_interviewee_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_interviewee_role']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_interviewee_role']['element_wrapper_class'] = 'subheading';
  $handler->display->display_options['fields']['field_interviewee_role']['element_default_classes'] = FALSE;
  /* Field: Content: Teaser image */
  $handler->display->display_options['fields']['field_teaser_image']['id'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['table'] = 'field_data_field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['field'] = 'field_teaser_image';
  $handler->display->display_options['fields']['field_teaser_image']['label'] = '';
  $handler->display->display_options['fields']['field_teaser_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_teaser_image']['element_wrapper_class'] = 'featured-interview-image';
  $handler->display->display_options['fields']['field_teaser_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_teaser_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_teaser_image']['settings'] = array(
    'image_style' => 'latest_interview',
    'image_link' => 'content',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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

  /* Display: Latest Interview by Area */
  $handler = $view->new_display('block', 'Latest Interview by Area', 'latest_area_interview');
  $handler->display->display_options['display_description'] = 'appears on an Area of Work page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'full_width_teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['interviews'] = $view;

  $view = new view();
  $view->name = 'questions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'qma_forms_question';
  $view->human_name = 'Questions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Questions';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access site reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'language' => 'language',
    'location' => 'location',
    'name' => 'name',
    'interviewee' => 'interviewee',
    'email' => 'email',
    'question' => 'question',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'interviewee' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'email' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'question' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Qma Forms Question: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'qma_forms_question';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: Qma Forms Question: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'qma_forms_question';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Field: Qma Forms Question: Location */
  $handler->display->display_options['fields']['location']['id'] = 'location';
  $handler->display->display_options['fields']['location']['table'] = 'qma_forms_question';
  $handler->display->display_options['fields']['location']['field'] = 'location';
  /* Field: Qma Forms Question: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'qma_forms_question';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Qma Forms Question: Interviewee */
  $handler->display->display_options['fields']['interviewee']['id'] = 'interviewee';
  $handler->display->display_options['fields']['interviewee']['table'] = 'qma_forms_question';
  $handler->display->display_options['fields']['interviewee']['field'] = 'interviewee';
  /* Field: Qma Forms Question: Email */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'qma_forms_question';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  /* Field: Qma Forms Question: Question */
  $handler->display->display_options['fields']['question']['id'] = 'question';
  $handler->display->display_options['fields']['question']['table'] = 'qma_forms_question';
  $handler->display->display_options['fields']['question']['field'] = 'question';
  /* Filter criterion: Qma Forms Question: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'qma_forms_question';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );
  /* Filter criterion: Qma Forms Question: Interviewee */
  $handler->display->display_options['filters']['interviewee']['id'] = 'interviewee';
  $handler->display->display_options['filters']['interviewee']['table'] = 'qma_forms_question';
  $handler->display->display_options['filters']['interviewee']['field'] = 'interviewee';
  $handler->display->display_options['filters']['interviewee']['exposed'] = TRUE;
  $handler->display->display_options['filters']['interviewee']['expose']['operator_id'] = 'interviewee_op';
  $handler->display->display_options['filters']['interviewee']['expose']['label'] = 'Interviewee';
  $handler->display->display_options['filters']['interviewee']['expose']['operator'] = 'interviewee_op';
  $handler->display->display_options['filters']['interviewee']['expose']['identifier'] = 'interviewee';
  $handler->display->display_options['filters']['interviewee']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/reports/questions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Conversation Questions';
  $handler->display->display_options['menu']['description'] = 'Questions for the conversation pages';
  $handler->display->display_options['menu']['weight'] = '-20';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: CSV data export */
  $handler = $view->new_display('views_data_export', 'CSV data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view-%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = '1';
  $handler->display->display_options['style_options']['trim'] = 1;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'admin/reports/questions/csv_export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );

  /* Display: XLS data export */
  $handler = $view->new_display('views_data_export', 'XLS data export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'admin/reports/questions/xls_export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $export['questions'] = $view;

  return $export;
}
