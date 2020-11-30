<?php
/**
 * @file
 * qma_creative_resources.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function qma_creative_resources_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'creative_resource_suggetions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'qma_forms_resource_question';
  $view->human_name = 'Creative Resource Suggetions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Creative Resource Suggestions';
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
  /* Field: Qma Forms Creative Resource Question: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'qma_forms_resource_question';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Field: Qma Forms Creative Resource Question: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'qma_forms_resource_question';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Field: Qma Forms Creative Resource Question: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'qma_forms_resource_question';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Qma Forms Creative Resource Question: Email */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'qma_forms_resource_question';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  /* Field: Qma Forms Creative Resource Question: Suggestion */
  $handler->display->display_options['fields']['question']['id'] = 'question';
  $handler->display->display_options['fields']['question']['table'] = 'qma_forms_resource_question';
  $handler->display->display_options['fields']['question']['field'] = 'question';
  /* Sort criterion: Qma Forms Creative Resource Question: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'qma_forms_resource_question';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Qma Forms Creative Resource Question: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'qma_forms_resource_question';
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
  $handler->display->display_options['path'] = 'admin/reports/creative-resource-suggestions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Creative Resource Suggestions';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['creative_resource_suggetions'] = $view;

  $view = new view();
  $view->name = 'creative_resources';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Creative Resources';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Creative Resources';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_resource_tags_tid' => array(
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'header';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<h2><?php print t(\'What are you looking for?\',array(), array(\'context\' => \'QMA\')); ?></h2>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = 'list/map links';
  $handler->display->display_options['header']['area_1']['empty'] = TRUE;
  $handler->display->display_options['header']['area_1']['content'] = '<?php 
  $outputQueryArr=array(\'tagid\'=>(isset($_REQUEST[\'tagid\'])?check_plain($_REQUEST[\'tagid\']):\'All\'));
  if(isset($_REQUEST[\'display\']) && $_REQUEST[\'display\']==\'list\') {
  	print \'<p>\'.t(\'View\',array(), array(\'context\' => \'QMA\')).\': \'.t(\'List\',array(), array(\'context\' => \'QMA\')).\' | \'.l(t(\'Map\',array(), array(\'context\' => \'QMA\')), current_path(), array(\'query\' => $outputQueryArr, \'fragment\' => \'resources-list\')).\'</p>\';
  } else {
  	$outputQueryArr[\'display\'] = \'list\';
  	print \'<p>\'.t(\'View\',array(), array(\'context\' => \'QMA\')).\': \'.l(t(\'List\',array(), array(\'context\' => \'QMA\')), current_path(), array(\'query\' => $outputQueryArr, \'fragment\' => \'resources-list\')).\' | \'.t(\'Map\',array(), array(\'context\' => \'QMA\')).\'</p>\';  	
  }
?>';
  $handler->display->display_options['header']['area_1']['format'] = 'php_code';
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
  $handler->display->display_options['fields']['title']['label'] = 'Resource';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Short description */
  $handler->display->display_options['fields']['field_resource_description']['id'] = 'field_resource_description';
  $handler->display->display_options['fields']['field_resource_description']['table'] = 'field_data_field_resource_description';
  $handler->display->display_options['fields']['field_resource_description']['field'] = 'field_resource_description';
  $handler->display->display_options['fields']['field_resource_description']['label'] = '';
  $handler->display->display_options['fields']['field_resource_description']['element_label_colon'] = FALSE;
  /* Field: Content: Website URL */
  $handler->display->display_options['fields']['field_resource_website_url']['id'] = 'field_resource_website_url';
  $handler->display->display_options['fields']['field_resource_website_url']['table'] = 'field_data_field_resource_website_url';
  $handler->display->display_options['fields']['field_resource_website_url']['field'] = 'field_resource_website_url';
  $handler->display->display_options['fields']['field_resource_website_url']['label'] = '';
  $handler->display->display_options['fields']['field_resource_website_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resource_website_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_resource_website_url']['type'] = 'link_plain';
  /* Field: Location: Address */
  $handler->display->display_options['fields']['address']['id'] = 'address';
  $handler->display->display_options['fields']['address']['table'] = 'location';
  $handler->display->display_options['fields']['address']['field'] = 'address';
  $handler->display->display_options['fields']['address']['label'] = 'Location';
  $handler->display->display_options['fields']['address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['address']['hide'] = array(
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
    'map_link' => 0,
    'coords' => 0,
  );
  /* Field: Content: Opening times */
  $handler->display->display_options['fields']['field_resource_opening_times']['id'] = 'field_resource_opening_times';
  $handler->display->display_options['fields']['field_resource_opening_times']['table'] = 'field_data_field_resource_opening_times';
  $handler->display->display_options['fields']['field_resource_opening_times']['field'] = 'field_resource_opening_times';
  $handler->display->display_options['fields']['field_resource_opening_times']['label'] = 'Opening Hours';
  $handler->display->display_options['fields']['field_resource_opening_times']['element_label_colon'] = FALSE;
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_resource_tags']['id'] = 'field_resource_tags';
  $handler->display->display_options['fields']['field_resource_tags']['table'] = 'field_data_field_resource_tags';
  $handler->display->display_options['fields']['field_resource_tags']['field'] = 'field_resource_tags';
  $handler->display->display_options['fields']['field_resource_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resource_tags']['delta_offset'] = '0';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'creative_resource' => 'creative_resource',
  );
  /* Filter criterion: Content: Tags (field_resource_tags) (translated) */
  $handler->display->display_options['filters']['field_resource_tags_tid_i18n']['id'] = 'field_resource_tags_tid_i18n';
  $handler->display->display_options['filters']['field_resource_tags_tid_i18n']['table'] = 'field_data_field_resource_tags';
  $handler->display->display_options['filters']['field_resource_tags_tid_i18n']['field'] = 'field_resource_tags_tid_i18n';
  $handler->display->display_options['filters']['field_resource_tags_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_resource_tags_tid_i18n']['expose']['operator_id'] = 'field_resource_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_resource_tags_tid_i18n']['expose']['label'] = 'Filter by Tag';
  $handler->display->display_options['filters']['field_resource_tags_tid_i18n']['expose']['operator'] = 'field_resource_tags_tid_i18n_op';
  $handler->display->display_options['filters']['field_resource_tags_tid_i18n']['expose']['identifier'] = 'tagid';
  $handler->display->display_options['filters']['field_resource_tags_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['field_resource_tags_tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_resource_tags_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_resource_tags_tid_i18n']['vocabulary'] = 'creative_resource_tags';

  /* Display: List Block */
  $handler = $view->new_display('block', 'List Block', 'creative_list_block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_resource_description' => 'title',
    'field_resource_website_url' => 'title',
    'address' => 'address',
    'field_resource_opening_times' => 'field_resource_opening_times',
    'field_resource_tags' => 'field_resource_tags',
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
    'field_resource_description' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_resource_website_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'address' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_resource_opening_times' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_resource_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Resource';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Short description */
  $handler->display->display_options['fields']['field_resource_description']['id'] = 'field_resource_description';
  $handler->display->display_options['fields']['field_resource_description']['table'] = 'field_data_field_resource_description';
  $handler->display->display_options['fields']['field_resource_description']['field'] = 'field_resource_description';
  $handler->display->display_options['fields']['field_resource_description']['label'] = '';
  $handler->display->display_options['fields']['field_resource_description']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_resource_description']['element_label_colon'] = FALSE;
  /* Field: Content: Website URL */
  $handler->display->display_options['fields']['field_resource_website_url']['id'] = 'field_resource_website_url';
  $handler->display->display_options['fields']['field_resource_website_url']['table'] = 'field_data_field_resource_website_url';
  $handler->display->display_options['fields']['field_resource_website_url']['field'] = 'field_resource_website_url';
  $handler->display->display_options['fields']['field_resource_website_url']['label'] = '';
  $handler->display->display_options['fields']['field_resource_website_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resource_website_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_resource_website_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_resource_website_url']['type'] = 'link_plain';
  /* Field: Location: Address */
  $handler->display->display_options['fields']['address']['id'] = 'address';
  $handler->display->display_options['fields']['address']['table'] = 'location';
  $handler->display->display_options['fields']['address']['field'] = 'address';
  $handler->display->display_options['fields']['address']['label'] = 'Location';
  $handler->display->display_options['fields']['address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['address']['hide'] = array(
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
    'map_link' => 0,
    'coords' => 0,
  );
  /* Field: Content: Opening times */
  $handler->display->display_options['fields']['field_resource_opening_times']['id'] = 'field_resource_opening_times';
  $handler->display->display_options['fields']['field_resource_opening_times']['table'] = 'field_data_field_resource_opening_times';
  $handler->display->display_options['fields']['field_resource_opening_times']['field'] = 'field_resource_opening_times';
  $handler->display->display_options['fields']['field_resource_opening_times']['label'] = 'Opening Hours';
  $handler->display->display_options['fields']['field_resource_opening_times']['element_label_colon'] = FALSE;
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_resource_tags']['id'] = 'field_resource_tags';
  $handler->display->display_options['fields']['field_resource_tags']['table'] = 'field_data_field_resource_tags';
  $handler->display->display_options['fields']['field_resource_tags']['field'] = 'field_resource_tags';
  $handler->display->display_options['fields']['field_resource_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resource_tags']['delta_offset'] = '0';

  /* Display: Map Block */
  $handler = $view->new_display('block', 'Map Block', 'creative_map_block');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'gmap';
  $handler->display->display_options['style_options']['macro'] = '[gmap zoom=12 | center=25.291727828223245,51.49566650390625]';
  $handler->display->display_options['style_options']['markertype'] = 'qma_pink';
  $handler->display->display_options['style_options']['latfield'] = 'title';
  $handler->display->display_options['style_options']['lonfield'] = 'title';
  $handler->display->display_options['style_options']['markerfield'] = 'title';
  $handler->display->display_options['style_options']['geofield'] = 'title';
  $handler->display->display_options['style_options']['enablermt'] = 0;
  $handler->display->display_options['style_options']['rmtfield'] = 'title';
  $handler->display->display_options['style_options']['rmtfieldraw'] = 1;
  $handler->display->display_options['style_options']['center_on_nodearg_arg'] = 'language';
  $handler->display->display_options['style_options']['animation'] = '2';
  $handler->display->display_options['style_options']['highlight_nodearg_arg'] = 'language';
  $handler->display->display_options['style_options']['autoclick_on_nodearg_arg'] = 'language';
  $handler->display->display_options['style_options']['tooltipfield'] = 'title';
  $handler->display->display_options['style_options']['bubbletextfield'] = 'title';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'gmaps_popup';
  $handler->display->display_options['row_options']['links'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['creative_resources'] = $view;

  return $export;
}
