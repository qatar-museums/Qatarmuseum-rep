<?php
/**
 * @file
 * qma_area_of_work.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function qma_area_of_work_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'projects_by_area';
  $view->description = 'For use on Area of work pages';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Projects and Work Areas listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'What We\'re Doing';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => '-',
    ),
    'field_area_of_work_target_id_entityreference_filter' => array(
      'bef_format' => 'bef',
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
    'tid_i18n' => array(
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
    'field_project_status_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
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
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h3>Cultivating, supporting and celebrating our Art, Heritage and Creativity</h3>
<p>View: <a href="/what-we-are-doing">List</a> | Map</p>';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Prominence (field_prominence) */
  $handler->display->display_options['sorts']['field_prominence_value']['id'] = 'field_prominence_value';
  $handler->display->display_options['sorts']['field_prominence_value']['table'] = 'field_data_field_prominence';
  $handler->display->display_options['sorts']['field_prominence_value']['field'] = 'field_prominence_value';
  $handler->display->display_options['sorts']['field_prominence_value']['order'] = 'DESC';
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
    'project' => 'project',
  );
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid']['expose']['operator_id'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['label'] = 'Term';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = 'tid_op';
  $handler->display->display_options['filters']['tid']['expose']['identifier'] = 'tid';
  $handler->display->display_options['filters']['tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'sample_vocab';
  $handler->display->display_options['filters']['tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Highlight (field_highlight_flag) */
  $handler->display->display_options['filters']['field_highlight_flag_value']['id'] = 'field_highlight_flag_value';
  $handler->display->display_options['filters']['field_highlight_flag_value']['table'] = 'field_data_field_highlight_flag';
  $handler->display->display_options['filters']['field_highlight_flag_value']['field'] = 'field_highlight_flag_value';
  $handler->display->display_options['filters']['field_highlight_flag_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_highlight_flag_value']['value'] = array(
    1 => '1',
  );

  /* Display: All projects & Areas */
  $handler = $view->new_display('block', 'All projects & Areas', 'all_projects_and_areas');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'for use on the experience hub page';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'experience_teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = 'Showing @end stories';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'status links';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div class="status-filter">-
<?php 
  $outputQueryArr=array(\'areaid\'=>(isset($_REQUEST[\'areaid\'])?check_plain($_REQUEST[\'areaid\']):\'All\'),\'tagid\'=>(isset($_REQUEST[\'tagid\'])?check_plain($_REQUEST[\'tagid\']):\'All\'));
  if(isset($_REQUEST[\'display\'])) {
  	$outputQueryArr[\'display\'] = check_plain($_REQUEST[\'display\']);
  }
  $outputAttributesArr = array(\'class\'=>array(\'activefilter\'));

  if (isset($_REQUEST[\'status\']) && $_REQUEST[\'status\'] == \'now\')  {
    $outputQueryArrTmp = $outputQueryArr;
    $outputAttributesArr[\'class\']=array(\'activefilter\');
  } else {
    $outputQueryArrTmp = $outputQueryArr+array(\'status\'=>\'now\');
    $outputAttributesArr[\'class\']=array();
  }
  print  l(  t(\'On now\',array(), array(\'context\' => \'QMA\')), current_path(), array(\'query\' => $outputQueryArrTmp,\'attributes\'=>$outputAttributesArr));
  
  if (isset($_REQUEST[\'status\']) && $_REQUEST[\'status\'] == \'future\')  {
    $outputQueryArrTmp = $outputQueryArr;
    $outputAttributesArr[\'class\']=array(\'activefilter\');
  } else {
    $outputQueryArrTmp = $outputQueryArr+array(\'status\'=>\'future\');
    $outputAttributesArr[\'class\']=array();
  }
  print  l(  t(\'Future\',array(), array(\'context\' => \'QMA\')), current_path(), array(\'query\' => $outputQueryArrTmp,\'attributes\'=>$outputAttributesArr));
  
  if (isset($_REQUEST[\'status\']) && $_REQUEST[\'status\'] == \'past\')  {
    $outputQueryArrTmp = $outputQueryArr;
    $outputAttributesArr[\'class\']=array(\'activefilter\');
  } else {
    $outputQueryArrTmp = $outputQueryArr+array(\'status\'=>\'past\');
    $outputAttributesArr[\'class\']=array();
  }
  print  l(  t(\'Past\',array(), array(\'context\' => \'QMA\')), current_path(), array(\'query\' => $outputQueryArrTmp,\'attributes\'=>$outputAttributesArr));
?>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = 'list/map links';
  $handler->display->display_options['header']['area_1']['empty'] = TRUE;
  $handler->display->display_options['header']['area_1']['content'] = '<?php 
  $outputQueryArr=array(\'areaid\'=>(isset($_REQUEST[\'areaid\'])?check_plain($_REQUEST[\'areaid\']):\'All\'),\'tagid\'=>(isset($_REQUEST[\'tagid\'])?check_plain($_REQUEST[\'tagid\']):\'All\'),\'status\'=>(isset($_REQUEST[\'status\'])?check_plain($_REQUEST[\'status\']):\'All\'));
  if(isset($_REQUEST[\'display\']) && $_REQUEST[\'display\']==\'map\') {
	print \'<p>\'.t(\'View\',array(), array(\'context\' => \'QMA\')).\': \'.l(t(\'List\',array(), array(\'context\' => \'QMA\')), current_path(), array(\'query\' => $outputQueryArr, \'fragment\'=>\'all-project-listing\')).\' | \'.t(\'Map\',array(), array(\'context\' => \'QMA\')).\'</p>\';  	
  } else {
  	$outputQueryArr[\'display\'] = \'map\';
  	print \'<p>\'.t(\'View\',array(), array(\'context\' => \'QMA\')).\': \'.t(\'List\',array(), array(\'context\' => \'QMA\')).\' | \'.l(t(\'Map\',array(), array(\'context\' => \'QMA\')), current_path(), array(\'query\' => $outputQueryArr, \'fragment\'=>\'all-project-listing\')).\'</p>\';
  }
?>';
  $handler->display->display_options['header']['area_1']['format'] = 'php_code';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
    3 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Area of Work (field_area_of_work) (entityreference filter) */
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['id'] = 'field_area_of_work_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['table'] = 'field_data_field_area_of_work';
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['field'] = 'field_area_of_work_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['expose']['operator_id'] = 'field_area_of_work_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['expose']['operator'] = 'field_area_of_work_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['expose']['identifier'] = 'areaid';
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['reference_display'] = 'projects_by_area:entityreference_1';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 2;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'area_of_work' => 'area_of_work',
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Content: Has taxonomy term (translated) */
  $handler->display->display_options['filters']['tid_i18n']['id'] = 'tid_i18n';
  $handler->display->display_options['filters']['tid_i18n']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_i18n']['field'] = 'tid_i18n';
  $handler->display->display_options['filters']['tid_i18n']['group'] = 2;
  $handler->display->display_options['filters']['tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_i18n']['expose']['operator_id'] = 'tid_i18n_op';
  $handler->display->display_options['filters']['tid_i18n']['expose']['label'] = 'Filter by Tag';
  $handler->display->display_options['filters']['tid_i18n']['expose']['operator'] = 'tid_i18n_op';
  $handler->display->display_options['filters']['tid_i18n']['expose']['identifier'] = 'tagid';
  $handler->display->display_options['filters']['tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['tid_i18n']['vocabulary'] = 'sample_vocab';
  /* Filter criterion: Content: Status (field_project_status) */
  $handler->display->display_options['filters']['field_project_status_value']['id'] = 'field_project_status_value';
  $handler->display->display_options['filters']['field_project_status_value']['table'] = 'field_data_field_project_status';
  $handler->display->display_options['filters']['field_project_status_value']['field'] = 'field_project_status_value';
  $handler->display->display_options['filters']['field_project_status_value']['group'] = 2;
  $handler->display->display_options['filters']['field_project_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_status_value']['expose']['operator_id'] = 'field_project_status_value_op';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['operator'] = 'field_project_status_value_op';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Area of Work (field_area_of_work) */
  $handler->display->display_options['filters']['field_area_of_work_target_id']['id'] = 'field_area_of_work_target_id';
  $handler->display->display_options['filters']['field_area_of_work_target_id']['table'] = 'field_data_field_area_of_work';
  $handler->display->display_options['filters']['field_area_of_work_target_id']['field'] = 'field_area_of_work_target_id';
  $handler->display->display_options['filters']['field_area_of_work_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_area_of_work_target_id']['group'] = 3;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'area_of_work' => 'area_of_work',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 3;

  /* Display: Experience map */
  $handler = $view->new_display('block', 'Experience map', 'experience_map_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'for use on the experience hub page';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'gmap';
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
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = 'Showing @total stories';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'status links';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div class="status-filter">-
<?php 
  $outputQueryArr=array(\'areaid\'=>(isset($_REQUEST[\'areaid\'])?check_plain($_REQUEST[\'areaid\']):\'All\'),\'tagid\'=>(isset($_REQUEST[\'tagid\'])?check_plain($_REQUEST[\'tagid\']):\'All\'));
  if(isset($_REQUEST[\'display\'])) {
  	$outputQueryArr[\'display\'] = check_plain($_REQUEST[\'display\']);
  }
  $outputAttributesArr = array(\'class\'=>array(\'activefilter\'));

  if (isset($_REQUEST[\'status\']) && $_REQUEST[\'status\'] == \'now\')  {
    $outputQueryArrTmp = $outputQueryArr;
    $outputAttributesArr[\'class\']=array(\'activefilter\');
  } else {
    $outputQueryArrTmp = $outputQueryArr+array(\'status\'=>\'now\');
    $outputAttributesArr[\'class\']=array();
  }
  print  l(  t(\'On now\',array(), array(\'context\' => \'QMA\')), current_path(), array(\'query\' => $outputQueryArrTmp,\'attributes\'=>$outputAttributesArr));
  
  if (isset($_REQUEST[\'status\']) && $_REQUEST[\'status\'] == \'future\')  {
    $outputQueryArrTmp = $outputQueryArr;
    $outputAttributesArr[\'class\']=array(\'activefilter\');
  } else {
    $outputQueryArrTmp = $outputQueryArr+array(\'status\'=>\'future\');
    $outputAttributesArr[\'class\']=array();
  }
  print  l(  t(\'Future\',array(), array(\'context\' => \'QMA\')), current_path(), array(\'query\' => $outputQueryArrTmp,\'attributes\'=>$outputAttributesArr));
  
  if (isset($_REQUEST[\'status\']) && $_REQUEST[\'status\'] == \'past\')  {
    $outputQueryArrTmp = $outputQueryArr;
    $outputAttributesArr[\'class\']=array(\'activefilter\');
  } else {
    $outputQueryArrTmp = $outputQueryArr+array(\'status\'=>\'past\');
    $outputAttributesArr[\'class\']=array();
  }
  print  l(  t(\'Past\',array(), array(\'context\' => \'QMA\')), current_path(), array(\'query\' => $outputQueryArrTmp,\'attributes\'=>$outputAttributesArr));
?>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['label'] = 'map/list links';
  $handler->display->display_options['header']['area_1']['empty'] = TRUE;
  $handler->display->display_options['header']['area_1']['content'] = '<?php 
  $outputQueryArr=array(\'areaid\'=>(isset($_REQUEST[\'areaid\'])?check_plain($_REQUEST[\'areaid\']):\'All\'),\'tagid\'=>(isset($_REQUEST[\'tagid\'])?check_plain($_REQUEST[\'tagid\']):\'All\'),\'status\'=>(isset($_REQUEST[\'status\'])?check_plain($_REQUEST[\'status\']):\'All\'));
  if(isset($_REQUEST[\'display\']) && $_REQUEST[\'display\']==\'map\') {
	print \'<p>\'.t(\'View\',array(), array(\'context\' => \'QMA\')).\': \'.l(t(\'List\',array(), array(\'context\' => \'QMA\')), current_path(), array(\'query\' => $outputQueryArr, \'fragment\'=>\'all-project-listing\')).\' | \'.t(\'Map\',array(), array(\'context\' => \'QMA\')).\'</p>\';  	
  } else {
  	$outputQueryArr[\'display\'] = \'map\';
  	print \'<p>\'.t(\'View\',array(), array(\'context\' => \'QMA\')).\': \'.t(\'List\',array(), array(\'context\' => \'QMA\')).\' | \'.l(t(\'Map\',array(), array(\'context\' => \'QMA\')), current_path(), array(\'query\' => $outputQueryArr, \'fragment\'=>\'all-project-listing\')).\'</p>\';
  }
?>';
  $handler->display->display_options['header']['area_1']['format'] = 'php_code';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '[gmap ]';
  $handler->display->display_options['empty']['area']['format'] = 'gmap_macro_expander';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
    2 => 'AND',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Area of Work (field_area_of_work) (entityreference filter) */
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['id'] = 'field_area_of_work_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['table'] = 'field_data_field_area_of_work';
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['field'] = 'field_area_of_work_target_id_entityreference_filter';
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['group'] = 1;
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['expose']['operator_id'] = 'field_area_of_work_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['expose']['operator'] = 'field_area_of_work_target_id_entityreference_filter_op';
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['expose']['identifier'] = 'areaid';
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_area_of_work_target_id_entityreference_filter']['reference_display'] = 'projects_by_area:entityreference_1';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 2;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $handler->display->display_options['filters']['type']['group'] = 2;
  /* Filter criterion: Content: Has taxonomy term (translated) */
  $handler->display->display_options['filters']['tid_i18n']['id'] = 'tid_i18n';
  $handler->display->display_options['filters']['tid_i18n']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid_i18n']['field'] = 'tid_i18n';
  $handler->display->display_options['filters']['tid_i18n']['group'] = 2;
  $handler->display->display_options['filters']['tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['tid_i18n']['expose']['operator_id'] = 'tid_i18n_op';
  $handler->display->display_options['filters']['tid_i18n']['expose']['label'] = 'Filter by Tag';
  $handler->display->display_options['filters']['tid_i18n']['expose']['operator'] = 'tid_i18n_op';
  $handler->display->display_options['filters']['tid_i18n']['expose']['identifier'] = 'tagid';
  $handler->display->display_options['filters']['tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    9 => 0,
    10 => 0,
    7 => 0,
    8 => 0,
    11 => 0,
  );
  $handler->display->display_options['filters']['tid_i18n']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['tid_i18n']['vocabulary'] = 'sample_vocab';
  /* Filter criterion: Content: Status (field_project_status) */
  $handler->display->display_options['filters']['field_project_status_value']['id'] = 'field_project_status_value';
  $handler->display->display_options['filters']['field_project_status_value']['table'] = 'field_data_field_project_status';
  $handler->display->display_options['filters']['field_project_status_value']['field'] = 'field_project_status_value';
  $handler->display->display_options['filters']['field_project_status_value']['group'] = 2;
  $handler->display->display_options['filters']['field_project_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_project_status_value']['expose']['operator_id'] = 'field_project_status_value_op';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['operator'] = 'field_project_status_value_op';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['field_project_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    7 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: Content: Area of Work (field_area_of_work) */
  $handler->display->display_options['filters']['field_area_of_work_target_id']['id'] = 'field_area_of_work_target_id';
  $handler->display->display_options['filters']['field_area_of_work_target_id']['table'] = 'field_data_field_area_of_work';
  $handler->display->display_options['filters']['field_area_of_work_target_id']['field'] = 'field_area_of_work_target_id';
  $handler->display->display_options['filters']['field_area_of_work_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_area_of_work_target_id']['group'] = 2;
  $handler->display->display_options['block_description'] = 'Experience map';

  /* Display: Projects By Work Area Block */
  $handler = $view->new_display('block', 'Projects By Work Area Block', 'block');
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['label'] = 'hub links';
  $handler->display->display_options['footer']['area']['content'] = '<?php 
//print the links to pre filtered experience hub page

//first we need to look up the hub page that matches the current language
$query = new EntityFieldQuery();
		
// This assumes there will only be a single hub for each language.
$query->entityCondition(\'entity_type\', \'node\')
	->propertyCondition(\'language\', !2) //n.b using drupal token for value
	->propertyCondition(\'type\', \'areas_hub\')
	->propertyCondition(\'status\', 1)
	->range(0, 1);

$result = $query->execute();

if (!empty($result[\'node\'])) {
	$hub_node = array_shift($result[\'node\']);


  	print \'<p>\'.t(\'View on a \',array(), array(\'context\' => \'QMA\')).l(t(\'Map\',array(), array(\'context\' => \'QMA\')), \'node/\'.$hub_node->nid, array(\'query\' => array(\'areaid\'=>!1,\'display\'=>\'map\'))).\'</p>\';
}
?>';
  $handler->display->display_options['footer']['area']['format'] = 'php_code';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'project' => 'project',
  );

  /* Display: Entity Reference for area filter */
  $handler = $view->new_display('entityreference', 'Entity Reference for area filter', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'a  view to provide option list to the area filter used on the all projects and areas display';
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
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'area_of_work' => 'area_of_work',
  );
  $export['projects_by_area'] = $view;

  return $export;
}
