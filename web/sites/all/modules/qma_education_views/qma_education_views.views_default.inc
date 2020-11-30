<?php
/**
 * @file
 * qma_education_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function qma_education_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'education_programme_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Education programme map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Education programme map';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'gmap';
  $handler->display->display_options['style_options']['macro'] = '[gmap zoom=15 |height=450px]';
  $handler->display->display_options['style_options']['markertype'] = 'qma_pink';
  $handler->display->display_options['style_options']['latfield'] = 'title';
  $handler->display->display_options['style_options']['lonfield'] = 'title';
  $handler->display->display_options['style_options']['markerfield'] = 'title';
  $handler->display->display_options['style_options']['geofield'] = 'title';
  $handler->display->display_options['style_options']['enablermt'] = 0;
  $handler->display->display_options['style_options']['rmtfield'] = 'title';
  $handler->display->display_options['style_options']['rmtfieldraw'] = 1;
  $handler->display->display_options['style_options']['center_on_nodearg'] = 1;
  $handler->display->display_options['style_options']['center_on_nodearg_arg'] = 'nid';
  $handler->display->display_options['style_options']['animation'] = '0';
  $handler->display->display_options['style_options']['highlight_nodearg_arg'] = 'nid';
  $handler->display->display_options['style_options']['autoclick_on_nodearg'] = 1;
  $handler->display->display_options['style_options']['autoclick_on_nodearg_arg'] = 'nid';
  $handler->display->display_options['style_options']['tooltipfield'] = 'title';
  $handler->display->display_options['style_options']['bubbletextfield'] = 'title';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'gmaps_popup';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Location: Address */
  $handler->display->display_options['fields']['address']['id'] = 'address';
  $handler->display->display_options['fields']['address']['table'] = 'location';
  $handler->display->display_options['fields']['address']['field'] = 'address';
  $handler->display->display_options['fields']['address']['label'] = '';
  $handler->display->display_options['fields']['address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['address']['hide'] = array(
    'map_link' => 'map_link',
    'name' => 0,
    'street' => 0,
    'additional' => 0,
    'city' => 0,
    'province' => 0,
    'postal_code' => 0,
    'country' => 0,
    'locpick' => 0,
    'province_name' => 0,
    'country_name' => 0,
    'coords' => 0,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'education_prog' => 'education_prog',
  );

  /* Display: Map block */
  $handler = $view->new_display('block', 'Map block', 'map_block');
  $export['education_programme_map'] = $view;

  $view = new view();
  $view->name = 'qma_edu_bookings_by_programme';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'registration';
  $view->human_name = 'QMA Edu: Bookings by Programme';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'QMA Admin Registration Page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'education data access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'registration_id' => 'registration_id',
    'anon_mail' => 'anon_mail',
    'author' => 'author',
    'author_uid' => 'author_uid',
    'field_qma_edu_reg_date' => 'field_qma_edu_reg_date',
    'created' => 'created',
    'field_qma_edu_reg_firstname' => 'field_qma_edu_reg_firstname',
    'entity_id' => 'entity_id',
    'field_qma_edu_reg_lastname' => 'field_qma_edu_reg_lastname',
    'field_qma_edu_bookings' => 'field_qma_edu_bookings',
    'type' => 'type',
    'field_qma_edu_reg_role' => 'field_qma_edu_reg_role',
    'field_qma_edu_reg_schoold' => 'field_qma_edu_reg_schoold',
    'count' => 'count',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'registration_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'anon_mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'author' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'author_uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_qma_edu_reg_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_qma_edu_reg_firstname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'entity_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_qma_edu_reg_lastname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_qma_edu_bookings' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_qma_edu_reg_role' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_qma_edu_reg_schoold' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Relationship to Programme */
  $handler->display->display_options['relationships']['registration_related_node']['id'] = 'registration_related_node';
  $handler->display->display_options['relationships']['registration_related_node']['table'] = 'registration';
  $handler->display->display_options['relationships']['registration_related_node']['field'] = 'registration_related_node';
  $handler->display->display_options['relationships']['registration_related_node']['ui_name'] = 'Relationship to Programme';
  $handler->display->display_options['relationships']['registration_related_node']['label'] = 'Relationship to Programme';
  /* Relationship: User registering the event */
  $handler->display->display_options['relationships']['user_uid']['id'] = 'user_uid';
  $handler->display->display_options['relationships']['user_uid']['table'] = 'registration';
  $handler->display->display_options['relationships']['user_uid']['field'] = 'user_uid';
  $handler->display->display_options['relationships']['user_uid']['ui_name'] = 'User registering the event';
  /* Field: Registration: Registration ID */
  $handler->display->display_options['fields']['registration_id']['id'] = 'registration_id';
  $handler->display->display_options['fields']['registration_id']['table'] = 'registration';
  $handler->display->display_options['fields']['registration_id']['field'] = 'registration_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'registration_related_node';
  $handler->display->display_options['fields']['title']['label'] = 'Programme';
  /* Field: Registration: Registration date */
  $handler->display->display_options['fields']['field_qma_edu_reg_date']['id'] = 'field_qma_edu_reg_date';
  $handler->display->display_options['fields']['field_qma_edu_reg_date']['table'] = 'field_data_field_qma_edu_reg_date';
  $handler->display->display_options['fields']['field_qma_edu_reg_date']['field'] = 'field_qma_edu_reg_date';
  $handler->display->display_options['fields']['field_qma_edu_reg_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Registration: Name */
  $handler->display->display_options['fields']['field_qma_edu_reg_name']['id'] = 'field_qma_edu_reg_name';
  $handler->display->display_options['fields']['field_qma_edu_reg_name']['table'] = 'field_data_field_qma_edu_reg_name';
  $handler->display->display_options['fields']['field_qma_edu_reg_name']['field'] = 'field_qma_edu_reg_name';
  $handler->display->display_options['fields']['field_qma_edu_reg_name']['label'] = 'Registration name';
  /* Field: Registration: Anonymous e-mail */
  $handler->display->display_options['fields']['anon_mail']['id'] = 'anon_mail';
  $handler->display->display_options['fields']['anon_mail']['table'] = 'registration';
  $handler->display->display_options['fields']['anon_mail']['field'] = 'anon_mail';
  /* Field: User email */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'user_uid';
  $handler->display->display_options['fields']['mail']['ui_name'] = 'User email';
  /* Field: Registration: Slots consumed */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'registration';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['label'] = 'Tickets booked';
  /* Field: Registration: Spaces remaining */
  $handler->display->display_options['fields']['capacity_remaining']['id'] = 'capacity_remaining';
  $handler->display->display_options['fields']['capacity_remaining']['table'] = 'registration';
  $handler->display->display_options['fields']['capacity_remaining']['field'] = 'capacity_remaining';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_qma_edu_reg_schoold']['id'] = 'field_qma_edu_reg_schoold';
  $handler->display->display_options['fields']['field_qma_edu_reg_schoold']['table'] = 'field_data_field_qma_edu_reg_schoold';
  $handler->display->display_options['fields']['field_qma_edu_reg_schoold']['field'] = 'field_qma_edu_reg_schoold';
  $handler->display->display_options['fields']['field_qma_edu_reg_schoold']['label'] = 'School';
  /* Field: Registration: Role */
  $handler->display->display_options['fields']['field_qma_edu_reg_role']['id'] = 'field_qma_edu_reg_role';
  $handler->display->display_options['fields']['field_qma_edu_reg_role']['table'] = 'field_data_field_qma_edu_reg_role';
  $handler->display->display_options['fields']['field_qma_edu_reg_role']['field'] = 'field_qma_edu_reg_role';
  /* Filter criterion: Programme title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'registration_related_node';
  $handler->display->display_options['filters']['title']['ui_name'] = 'Programme title';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Programme';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'pid';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    6 => 0,
    12 => 0,
    11 => 0,
  );

  /* Display: Registrations Admin Overview */
  $handler = $view->new_display('page', 'Registrations Admin Overview', 'page_1');
  $handler->display->display_options['path'] = 'admin/qma/registrations';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'QMA Event registrations';
  $handler->display->display_options['menu']['description'] = 'Registration listing and export page';
  $handler->display->display_options['menu']['weight'] = '99';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: CSV data export */
  $handler = $view->new_display('views_data_export', 'CSV data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/qma/registrations/csv_export';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );

  /* Display: XLS data export */
  $handler = $view->new_display('views_data_export', 'XLS data export', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'admin/qma/registrations/xls_export';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );
  $export['qma_edu_bookings_by_programme'] = $view;

  $view = new view();
  $view->name = 'qma_edu_institutes_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'QMA Edu: Institutes listing';
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
  $handler->display->display_options['pager']['type'] = 'full';
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
  /* Sort criterion: Content: Type */
  $handler->display->display_options['sorts']['type']['id'] = 'type';
  $handler->display->display_options['sorts']['type']['table'] = 'node';
  $handler->display->display_options['sorts']['type']['field'] = 'type';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
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
    'education_institution' => 'education_institution',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'education_resource_hub' => 'education_resource_hub',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 2;
  $export['qma_edu_institutes_listing'] = $view;

  $view = new view();
  $view->name = 'qma_edu_programme_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'QMA Edu: Programme listing';
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
  $handler->display->display_options['pager']['type'] = 'full';
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
  /* Sort criterion: Content: Type */
  $handler->display->display_options['sorts']['type']['id'] = 'type';
  $handler->display->display_options['sorts']['type']['table'] = 'node';
  $handler->display->display_options['sorts']['type']['field'] = 'type';
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
    'education_prog' => 'education_prog',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['qma_edu_programme_listing'] = $view;

  $view = new view();
  $view->name = 'qma_edu_repeat_calendar';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'QMA Edu Repeat Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Find a Programme';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_eduprog_institution_target_id' => array(
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
    'field_eduprog_agegroup_tid' => array(
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
    'field_eduprog_type_tid' => array(
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
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'editor_html';
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  /* Relationship: Field collection item: Entity with the Date Repeat (field_eduprog_repeat_date) */
  $handler->display->display_options['relationships']['field_eduprog_repeat_date_node']['id'] = 'field_eduprog_repeat_date_node';
  $handler->display->display_options['relationships']['field_eduprog_repeat_date_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_eduprog_repeat_date_node']['field'] = 'field_eduprog_repeat_date_node';
  /* Field: Field collection item: Date */
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['id'] = 'field_eduprog_repeat_field_date';
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['table'] = 'field_data_field_eduprog_repeat_field_date';
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['field'] = 'field_eduprog_repeat_field_date';
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['label'] = '';
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_eduprog_repeat_date_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Field collection item: Date -  start date (field_eduprog_repeat_field_date) */
  $handler->display->display_options['sorts']['field_eduprog_repeat_field_date_value']['id'] = 'field_eduprog_repeat_field_date_value';
  $handler->display->display_options['sorts']['field_eduprog_repeat_field_date_value']['table'] = 'field_data_field_eduprog_repeat_field_date';
  $handler->display->display_options['sorts']['field_eduprog_repeat_field_date_value']['field'] = 'field_eduprog_repeat_field_date_value';
  /* Contextual filter: Content: Language */
  $handler->display->display_options['arguments']['language']['id'] = 'language';
  $handler->display->display_options['arguments']['language']['table'] = 'node';
  $handler->display->display_options['arguments']['language']['field'] = 'language';
  $handler->display->display_options['arguments']['language']['relationship'] = 'field_eduprog_repeat_date_node';
  $handler->display->display_options['arguments']['language']['default_action'] = 'default';
  $handler->display->display_options['arguments']['language']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['language']['default_argument_options']['code'] = '//return interface language if content language not provided by template 
global $language;
return $language->language;';
  $handler->display->display_options['arguments']['language']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['language']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['language']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Date: Date (field_collection_item) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_eduprog_repeat_field_date.field_eduprog_repeat_field_date_value' => 'field_data_field_eduprog_repeat_field_date.field_eduprog_repeat_field_date_value',
  );
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_eduprog_repeat_date_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_eduprog_repeat_date_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'education_prog' => 'education_prog',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Museum / Department (field_eduprog_institution) */
  $handler->display->display_options['filters']['field_eduprog_institution_target_id']['id'] = 'field_eduprog_institution_target_id';
  $handler->display->display_options['filters']['field_eduprog_institution_target_id']['table'] = 'field_data_field_eduprog_institution';
  $handler->display->display_options['filters']['field_eduprog_institution_target_id']['field'] = 'field_eduprog_institution_target_id';
  $handler->display->display_options['filters']['field_eduprog_institution_target_id']['relationship'] = 'field_eduprog_repeat_date_node';
  $handler->display->display_options['filters']['field_eduprog_institution_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_eduprog_institution_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_eduprog_institution_target_id']['expose']['operator_id'] = 'field_eduprog_institution_target_id_op';
  $handler->display->display_options['filters']['field_eduprog_institution_target_id']['expose']['label'] = 'Institution';
  $handler->display->display_options['filters']['field_eduprog_institution_target_id']['expose']['operator'] = 'field_eduprog_institution_target_id_op';
  $handler->display->display_options['filters']['field_eduprog_institution_target_id']['expose']['identifier'] = 'field_eduprog_institution_target_id';
  $handler->display->display_options['filters']['field_eduprog_institution_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    16 => 0,
    11 => 0,
  );
  /* Filter criterion: Content: Age group (field_eduprog_agegroup) */
  $handler->display->display_options['filters']['field_eduprog_agegroup_tid']['id'] = 'field_eduprog_agegroup_tid';
  $handler->display->display_options['filters']['field_eduprog_agegroup_tid']['table'] = 'field_data_field_eduprog_agegroup';
  $handler->display->display_options['filters']['field_eduprog_agegroup_tid']['field'] = 'field_eduprog_agegroup_tid';
  $handler->display->display_options['filters']['field_eduprog_agegroup_tid']['relationship'] = 'field_eduprog_repeat_date_node';
  $handler->display->display_options['filters']['field_eduprog_agegroup_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_eduprog_agegroup_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_eduprog_agegroup_tid']['expose']['operator_id'] = 'field_eduprog_agegroup_tid_op';
  $handler->display->display_options['filters']['field_eduprog_agegroup_tid']['expose']['label'] = 'Age group';
  $handler->display->display_options['filters']['field_eduprog_agegroup_tid']['expose']['operator'] = 'field_eduprog_agegroup_tid_op';
  $handler->display->display_options['filters']['field_eduprog_agegroup_tid']['expose']['identifier'] = 'field_eduprog_agegroup_tid';
  $handler->display->display_options['filters']['field_eduprog_agegroup_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    16 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_eduprog_agegroup_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_eduprog_agegroup_tid']['vocabulary'] = 'age_groups';
  /* Filter criterion: Content: Programme type (field_eduprog_type) */
  $handler->display->display_options['filters']['field_eduprog_type_tid']['id'] = 'field_eduprog_type_tid';
  $handler->display->display_options['filters']['field_eduprog_type_tid']['table'] = 'field_data_field_eduprog_type';
  $handler->display->display_options['filters']['field_eduprog_type_tid']['field'] = 'field_eduprog_type_tid';
  $handler->display->display_options['filters']['field_eduprog_type_tid']['relationship'] = 'field_eduprog_repeat_date_node';
  $handler->display->display_options['filters']['field_eduprog_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_eduprog_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_eduprog_type_tid']['expose']['operator_id'] = 'field_eduprog_type_tid_op';
  $handler->display->display_options['filters']['field_eduprog_type_tid']['expose']['label'] = 'Programme type';
  $handler->display->display_options['filters']['field_eduprog_type_tid']['expose']['operator'] = 'field_eduprog_type_tid_op';
  $handler->display->display_options['filters']['field_eduprog_type_tid']['expose']['identifier'] = 'field_eduprog_type_tid';
  $handler->display->display_options['filters']['field_eduprog_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    16 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_eduprog_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_eduprog_type_tid']['vocabulary'] = 'programme_type';
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state_1']['id'] = 'state_1';
  $handler->display->display_options['filters']['state_1']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state_1']['field'] = 'state';
  $handler->display->display_options['filters']['state_1']['relationship'] = 'field_eduprog_repeat_date_node';
  $handler->display->display_options['filters']['state_1']['operator'] = 'empty';
  $handler->display->display_options['filters']['state_1']['group'] = 2;
  /* Filter criterion: Workbench Moderation: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'workbench_moderation_node_history';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'field_eduprog_repeat_date_node';
  $handler->display->display_options['filters']['state']['value'] = array(
    'published' => 'published',
  );
  $handler->display->display_options['filters']['state']['group'] = 2;

  /* Display: Month */
  $handler = $view->new_display('page', 'Month', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['legend'] = 'type';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (field_collection_item) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_eduprog_repeat_field_date.field_eduprog_repeat_field_date_value' => 'field_data_field_eduprog_repeat_field_date.field_eduprog_repeat_field_date_value',
  );
  $handler->display->display_options['path'] = 'calendar-field-collection-item-field-eduprog-repeat-field-date/month';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Month';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Week */
  $handler = $view->new_display('page', 'Week', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'week';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'week';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (field_collection_item) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_eduprog_repeat_field_date.field_eduprog_repeat_field_date_value' => 'field_data_field_eduprog_repeat_field_date.field_eduprog_repeat_field_date_value',
  );
  $handler->display->display_options['path'] = 'calendar-field-collection-item-field-eduprog-repeat-field-date/week';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Week';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Day */
  $handler = $view->new_display('page', 'Day', 'page_3');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'day';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'day';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['style_options']['groupby_times'] = 'half';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Language */
  $handler->display->display_options['arguments']['language']['id'] = 'language';
  $handler->display->display_options['arguments']['language']['table'] = 'node';
  $handler->display->display_options['arguments']['language']['field'] = 'language';
  $handler->display->display_options['arguments']['language']['relationship'] = 'field_eduprog_repeat_date_node';
  $handler->display->display_options['arguments']['language']['default_action'] = 'default';
  $handler->display->display_options['arguments']['language']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['language']['default_argument_options']['code'] = '//return interface language if content language not provided by template 
global $language;
return $language->language;';
  $handler->display->display_options['arguments']['language']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['language']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['language']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Date: Date (field_collection_item) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_eduprog_repeat_field_date.field_eduprog_repeat_field_date_value' => 'field_data_field_eduprog_repeat_field_date.field_eduprog_repeat_field_date_value',
  );
  $handler->display->display_options['path'] = 'education-calendar-day';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Day';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Year */
  $handler = $view->new_display('page', 'Year', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'year';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'year';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Date */
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['id'] = 'field_eduprog_repeat_field_date';
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['table'] = 'field_data_field_eduprog_repeat_field_date';
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['field'] = 'field_eduprog_repeat_field_date';
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['label'] = '';
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_eduprog_repeat_field_date']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (field_collection_item) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_eduprog_repeat_field_date.field_eduprog_repeat_field_date_value' => 'field_data_field_eduprog_repeat_field_date.field_eduprog_repeat_field_date_value',
  );
  $handler->display->display_options['path'] = 'calendar-field-collection-item-field-eduprog-repeat-field-date/year';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Year';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'mini';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '1';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (field_collection_item) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'field_collection_item';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_eduprog_repeat_field_date.field_eduprog_repeat_field_date_value' => 'field_data_field_eduprog_repeat_field_date.field_eduprog_repeat_field_date_value',
  );

  /* Display: Upcoming */
  $handler = $view->new_display('block', 'Upcoming', 'block_2');
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Date: Date (field_collection_item) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'field_collection_item';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_eduprog_repeat_field_date.field_eduprog_repeat_field_date_value' => 'field_data_field_eduprog_repeat_field_date.field_eduprog_repeat_field_date_value',
  );

  /* Display: Monthly Block */
  $handler = $view->new_display('block', 'Monthly Block', 'block_3');
  $export['qma_edu_repeat_calendar'] = $view;

  $view = new view();
  $view->name = 'qma_edu_resource_listings';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'QMA Edu: Resource listings';
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
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_eduprog_institution_target_id' => array(
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
    'title' => array(
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_edures_description' => 'title',
    'field_edures_file_attachment' => 'field_edures_file_attachment',
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
    'field_edures_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_edures_file_attachment' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Search result count in header */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['ui_name'] = 'Search result count in header';
  $handler->display->display_options['header']['result']['content'] = 'Displaying @start to @end of @total educational resources';
  /* Field: Education resource title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Education resource title';
  $handler->display->display_options['fields']['title']['label'] = 'Item';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Education resource description */
  $handler->display->display_options['fields']['field_edures_description']['id'] = 'field_edures_description';
  $handler->display->display_options['fields']['field_edures_description']['table'] = 'field_data_field_edures_description';
  $handler->display->display_options['fields']['field_edures_description']['field'] = 'field_edures_description';
  $handler->display->display_options['fields']['field_edures_description']['ui_name'] = 'Education resource description';
  /* Field: Educational resource file */
  $handler->display->display_options['fields']['field_edures_file_attachment']['id'] = 'field_edures_file_attachment';
  $handler->display->display_options['fields']['field_edures_file_attachment']['table'] = 'field_data_field_edures_file_attachment';
  $handler->display->display_options['fields']['field_edures_file_attachment']['field'] = 'field_edures_file_attachment';
  $handler->display->display_options['fields']['field_edures_file_attachment']['ui_name'] = 'Educational resource file';
  $handler->display->display_options['fields']['field_edures_file_attachment']['label'] = 'Info';
  $handler->display->display_options['fields']['field_edures_file_attachment']['click_sort_column'] = 'fid';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'education_resource' => 'education_resource',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Programme resource listing */
  $handler = $view->new_display('block', 'Programme resource listing', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_eduprog_resources_node']['id'] = 'reverse_field_eduprog_resources_node';
  $handler->display->display_options['relationships']['reverse_field_eduprog_resources_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_eduprog_resources_node']['field'] = 'reverse_field_eduprog_resources_node';
  $handler->display->display_options['relationships']['reverse_field_eduprog_resources_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Education resource title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Education resource title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Education resource description */
  $handler->display->display_options['fields']['field_edures_description']['id'] = 'field_edures_description';
  $handler->display->display_options['fields']['field_edures_description']['table'] = 'field_data_field_edures_description';
  $handler->display->display_options['fields']['field_edures_description']['field'] = 'field_edures_description';
  $handler->display->display_options['fields']['field_edures_description']['ui_name'] = 'Education resource description';
  $handler->display->display_options['fields']['field_edures_description']['label'] = '';
  $handler->display->display_options['fields']['field_edures_description']['element_label_colon'] = FALSE;
  /* Field: Educational resource file */
  $handler->display->display_options['fields']['field_edures_file_attachment']['id'] = 'field_edures_file_attachment';
  $handler->display->display_options['fields']['field_edures_file_attachment']['table'] = 'field_data_field_edures_file_attachment';
  $handler->display->display_options['fields']['field_edures_file_attachment']['field'] = 'field_edures_file_attachment';
  $handler->display->display_options['fields']['field_edures_file_attachment']['ui_name'] = 'Educational resource file';
  $handler->display->display_options['fields']['field_edures_file_attachment']['label'] = '';
  $handler->display->display_options['fields']['field_edures_file_attachment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_edures_file_attachment']['click_sort_column'] = 'fid';
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
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_eduprog_resources_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Resource hub listing */
  $handler = $view->new_display('block', 'Resource hub listing', 'block_2');
  $export['qma_edu_resource_listings'] = $view;

  $view = new view();
  $view->name = 'referenced_programmes_by_event';
  $view->description = 'A view to display referenced programme titles';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'QMA Edu: Referenced institutions by programmes';
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Institution Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['ui_name'] = 'Institution Title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Programme nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Programme nid';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'education_institution' => 'education_institution',
  );

  /* Display: Programmes referenced in an event */
  $handler = $view->new_display('entityreference', 'Programmes referenced in an event', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['referenced_programmes_by_event'] = $view;

  return $export;
}
