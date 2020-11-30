<?php
/**
 * @file
 * qma_twitter_handling.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function qma_twitter_handling_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'qma_tweets';
  $view->description = 'Displays Twitter.com status messages for users who have associated Twitter accounts.';
  $view->tag = '';
  $view->base_table = 'twitter';
  $view->human_name = 'QMA Tweets';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Tweets */
  $handler = $view->new_display('default', 'Tweets', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'profile_image_url' => 'profile_image_url',
    'text' => 'text',
    'created_time' => 'text',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'profile_image_url' => array(
      'sortable' => 0,
      'separator' => '',
    ),
    'text' => array(
      'sortable' => 0,
      'separator' => ' &#8212; ',
    ),
    'created_time' => array(
      'sortable' => 0,
      'separator' => '',
    ),
  );
  /* Field: Twitter: Profile image */
  $handler->display->display_options['fields']['profile_image_url']['id'] = 'profile_image_url';
  $handler->display->display_options['fields']['profile_image_url']['table'] = 'twitter_account';
  $handler->display->display_options['fields']['profile_image_url']['field'] = 'profile_image_url';
  $handler->display->display_options['fields']['profile_image_url']['label'] = '';
  /* Field: Twitter: Message text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'twitter';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['link_urls'] = 1;
  $handler->display->display_options['fields']['text']['link_usernames'] = 1;
  $handler->display->display_options['fields']['text']['link_hashtags'] = 1;
  /* Field: Twitter: Created time */
  $handler->display->display_options['fields']['created_time']['id'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['table'] = 'twitter';
  $handler->display->display_options['fields']['created_time']['field'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['label'] = '';
  $handler->display->display_options['fields']['created_time']['date_format'] = 'time ago';
  /* Sort criterion: Twitter: Created time */
  $handler->display->display_options['sorts']['created_time']['id'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['table'] = 'twitter';
  $handler->display->display_options['sorts']['created_time']['field'] = 'created_time';
  $handler->display->display_options['sorts']['created_time']['order'] = 'DESC';
  /* Contextual filter: Twitter: Tag */
  $handler->display->display_options['arguments']['tag']['id'] = 'tag';
  $handler->display->display_options['arguments']['tag']['table'] = 'twitter_tags';
  $handler->display->display_options['arguments']['tag']['field'] = 'tag';
  $handler->display->display_options['arguments']['tag']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tag']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tag']['default_argument_options']['argument'] = 'NationalDay';
  $handler->display->display_options['arguments']['tag']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tag']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tag']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tag']['limit'] = '0';
  /* Filter criterion: Twitter: Protected status */
  $handler->display->display_options['filters']['protected']['id'] = 'protected';
  $handler->display->display_options['filters']['protected']['table'] = 'twitter_account';
  $handler->display->display_options['filters']['protected']['field'] = 'protected';
  $handler->display->display_options['filters']['protected']['value'] = 0;
  $handler->display->display_options['filters']['protected']['group'] = '0';
  $handler->display->display_options['filters']['protected']['expose']['operator'] = FALSE;

  /* Display: Tweets Raw */
  $handler = $view->new_display('page', 'Tweets Raw', 'page_all_tweets');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tweets';
  $handler->display->display_options['display_description'] = 'Lists tweets within a table.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'twitter_id' => 'twitter_id',
    'profile_image_url' => 'profile_image_url',
    'name' => 'name',
    'screen_name' => 'screen_name',
    'follow' => 'follow',
    'text' => 'text',
    'created_time' => 'created_time',
    'web_intents' => 'web_intents',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'twitter_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'profile_image_url' => array(
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
    'screen_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'follow' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'text' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created_time' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'web_intents' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Twitter: Twitter status message ID */
  $handler->display->display_options['fields']['twitter_id']['id'] = 'twitter_id';
  $handler->display->display_options['fields']['twitter_id']['table'] = 'twitter';
  $handler->display->display_options['fields']['twitter_id']['field'] = 'twitter_id';
  $handler->display->display_options['fields']['twitter_id']['label'] = '';
  $handler->display->display_options['fields']['twitter_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['twitter_id']['element_label_colon'] = FALSE;
  /* Field: Twitter: Profile image */
  $handler->display->display_options['fields']['profile_image_url']['id'] = 'profile_image_url';
  $handler->display->display_options['fields']['profile_image_url']['table'] = 'twitter_account';
  $handler->display->display_options['fields']['profile_image_url']['field'] = 'profile_image_url';
  $handler->display->display_options['fields']['profile_image_url']['label'] = '';
  /* Field: Twitter: Full name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'twitter_account';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'https://twitter.com/[screen_name]';
  $handler->display->display_options['fields']['name']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Twitter: Login name */
  $handler->display->display_options['fields']['screen_name']['id'] = 'screen_name';
  $handler->display->display_options['fields']['screen_name']['table'] = 'twitter';
  $handler->display->display_options['fields']['screen_name']['field'] = 'screen_name';
  $handler->display->display_options['fields']['screen_name']['label'] = '';
  $handler->display->display_options['fields']['screen_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['screen_name']['alter']['path'] = 'https://twitter.com/[screen_name] ';
  $handler->display->display_options['fields']['screen_name']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['screen_name']['alter']['prefix'] = '@';
  $handler->display->display_options['fields']['screen_name']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['screen_name']['element_label_colon'] = FALSE;
  /* Field: Twitter: Follow */
  $handler->display->display_options['fields']['follow']['id'] = 'follow';
  $handler->display->display_options['fields']['follow']['table'] = 'twitter';
  $handler->display->display_options['fields']['follow']['field'] = 'follow';
  $handler->display->display_options['fields']['follow']['label'] = '';
  $handler->display->display_options['fields']['follow']['element_label_colon'] = FALSE;
  /* Field: Twitter: Message text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'twitter';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['link_urls'] = 1;
  $handler->display->display_options['fields']['text']['link_usernames'] = 1;
  $handler->display->display_options['fields']['text']['link_hashtags'] = 1;
  /* Field: Twitter: Created time */
  $handler->display->display_options['fields']['created_time']['id'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['table'] = 'twitter';
  $handler->display->display_options['fields']['created_time']['field'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['label'] = '';
  $handler->display->display_options['fields']['created_time']['date_format'] = 'time ago';
  /* Field: Twitter: Web Intents */
  $handler->display->display_options['fields']['web_intents']['id'] = 'web_intents';
  $handler->display->display_options['fields']['web_intents']['table'] = 'twitter';
  $handler->display->display_options['fields']['web_intents']['field'] = 'web_intents';
  $handler->display->display_options['fields']['web_intents']['label'] = '';
  $handler->display->display_options['fields']['web_intents']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'tweets-raw';

  /* Display: QMA Tweets Block */
  $handler = $view->new_display('block', 'QMA Tweets Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'text' => 'text',
    'created_time' => 'created_time',
  );
  $handler->display->display_options['row_options']['separator'] = ' &#8212; ';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Twitter: Twitter status message ID */
  $handler->display->display_options['fields']['twitter_id']['id'] = 'twitter_id';
  $handler->display->display_options['fields']['twitter_id']['table'] = 'twitter';
  $handler->display->display_options['fields']['twitter_id']['field'] = 'twitter_id';
  $handler->display->display_options['fields']['twitter_id']['label'] = '';
  $handler->display->display_options['fields']['twitter_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['twitter_id']['element_label_colon'] = FALSE;
  /* Field: Twitter: Formatted tweet */
  $handler->display->display_options['fields']['formatted_tweet']['id'] = 'formatted_tweet';
  $handler->display->display_options['fields']['formatted_tweet']['table'] = 'twitter';
  $handler->display->display_options['fields']['formatted_tweet']['field'] = 'formatted_tweet';
  $handler->display->display_options['fields']['formatted_tweet']['label'] = '';
  $handler->display->display_options['fields']['formatted_tweet']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['formatted_tweet']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Twitter: Login name */
  $handler->display->display_options['arguments']['screen_name']['id'] = 'screen_name';
  $handler->display->display_options['arguments']['screen_name']['table'] = 'twitter_account';
  $handler->display->display_options['arguments']['screen_name']['field'] = 'screen_name';
  $handler->display->display_options['arguments']['screen_name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['screen_name']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['screen_name']['default_argument_options']['code'] = '$returnArr = array();
if (arg(0) == \'node\' && is_numeric(arg(1))) { //check we are on a node page
	$node = node_load(arg(1));
	if(isset($node->field_twitter_account[LANGUAGE_NONE])) { //does it have a field to restrict by account
		foreach ($node->field_twitter_account[LANGUAGE_NONE] as $twAccArr) {
			$returnArr[] = $twAccArr[\'value\'];
		}
	}
}

if (count($returnArr)) {
	return implode(\'+\', $returnArr); //multivalued field, concatonate together with + to act as OR operator
} else {
	return \'none\';
}';
  $handler->display->display_options['arguments']['screen_name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['screen_name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['screen_name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['screen_name']['limit'] = '0';
  $handler->display->display_options['arguments']['screen_name']['break_phrase'] = TRUE;
  /* Contextual filter: Twitter: Tag */
  $handler->display->display_options['arguments']['tag']['id'] = 'tag';
  $handler->display->display_options['arguments']['tag']['table'] = 'twitter_tags';
  $handler->display->display_options['arguments']['tag']['field'] = 'tag';
  $handler->display->display_options['arguments']['tag']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tag']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['tag']['default_argument_options']['code'] = '$returnArr = array();
if (arg(0) == \'node\' && is_numeric(arg(1))) { //check we are on a node page
	$node = node_load(arg(1));
	if(isset($node->field_twitter_hashtag[LANGUAGE_NONE])) { //does it have a field to restrict by account
		foreach ($node->field_twitter_hashtag[LANGUAGE_NONE] as $twHashArr) {
			$returnArr[] = $twHashArr[\'value\'];
		}
	}
}

if (count($returnArr)) {
	return implode(\'+\', $returnArr); //multivalued field, concatonate together with + to act as OR operator
} else {
	return \'all\';
}';
  $handler->display->display_options['arguments']['tag']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tag']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tag']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tag']['limit'] = '0';
  $handler->display->display_options['arguments']['tag']['break_phrase'] = TRUE;
  $handler->display->display_options['block_description'] = 'QMA Tweets';

  /* Display: QMA Tweets Project Block */
  $handler = $view->new_display('block', 'QMA Tweets Project Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'tweet-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'text' => 'text',
  );
  $handler->display->display_options['row_options']['separator'] = ' &#8212; ';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Twitter: Tweet Language */
  $handler->display->display_options['fields']['lang']['id'] = 'lang';
  $handler->display->display_options['fields']['lang']['table'] = 'twitter';
  $handler->display->display_options['fields']['lang']['field'] = 'lang';
  $handler->display->display_options['fields']['lang']['label'] = '';
  $handler->display->display_options['fields']['lang']['element_label_colon'] = FALSE;
  /* Field: Twitter: Message text */
  $handler->display->display_options['fields']['text']['id'] = 'text';
  $handler->display->display_options['fields']['text']['table'] = 'twitter';
  $handler->display->display_options['fields']['text']['field'] = 'text';
  $handler->display->display_options['fields']['text']['label'] = '';
  $handler->display->display_options['fields']['text']['element_type'] = 'div';
  $handler->display->display_options['fields']['text']['element_class'] = 'tweet-text';
  $handler->display->display_options['fields']['text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['text']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['text']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['text']['link_urls'] = 1;
  $handler->display->display_options['fields']['text']['link_usernames'] = 1;
  $handler->display->display_options['fields']['text']['link_hashtags'] = 1;
  $handler->display->display_options['fields']['text']['hashtags_url'] = 'https://twitter.com/search?q=%23';
  $handler->display->display_options['fields']['text']['link_attributes'] = 1;
  /* Field: Twitter: Login name */
  $handler->display->display_options['fields']['screen_name']['id'] = 'screen_name';
  $handler->display->display_options['fields']['screen_name']['table'] = 'twitter';
  $handler->display->display_options['fields']['screen_name']['field'] = 'screen_name';
  $handler->display->display_options['fields']['screen_name']['label'] = '';
  $handler->display->display_options['fields']['screen_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['screen_name']['alter']['text'] = '@[screen_name]';
  $handler->display->display_options['fields']['screen_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['screen_name']['alter']['path'] = 'www.twitter.com/[screen_name]';
  $handler->display->display_options['fields']['screen_name']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['screen_name']['element_type'] = 'div';
  $handler->display->display_options['fields']['screen_name']['element_class'] = 'tweet-user';
  $handler->display->display_options['fields']['screen_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['screen_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['screen_name']['element_default_classes'] = FALSE;
  /* Field: Twitter: Created time */
  $handler->display->display_options['fields']['created_time']['id'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['table'] = 'twitter';
  $handler->display->display_options['fields']['created_time']['field'] = 'created_time';
  $handler->display->display_options['fields']['created_time']['label'] = '';
  $handler->display->display_options['fields']['created_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_time']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_time']['custom_date_format'] = 'j F Y';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Twitter: Login name */
  $handler->display->display_options['arguments']['screen_name']['id'] = 'screen_name';
  $handler->display->display_options['arguments']['screen_name']['table'] = 'twitter_account';
  $handler->display->display_options['arguments']['screen_name']['field'] = 'screen_name';
  $handler->display->display_options['arguments']['screen_name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['screen_name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['screen_name']['default_argument_options']['argument'] = 'Qatar_Museums';
  $handler->display->display_options['arguments']['screen_name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['screen_name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['screen_name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['screen_name']['limit'] = '0';
  $handler->display->display_options['arguments']['screen_name']['break_phrase'] = TRUE;
  /* Contextual filter: Twitter: Tag */
  $handler->display->display_options['arguments']['tag']['id'] = 'tag';
  $handler->display->display_options['arguments']['tag']['table'] = 'twitter_tags';
  $handler->display->display_options['arguments']['tag']['field'] = 'tag';
  $handler->display->display_options['arguments']['tag']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['tag']['default_argument_options']['code'] = '$returnArr = array();
if (arg(0) == \'node\' && is_numeric(arg(1))) { //check we are on a node page
	$node = node_load(arg(1));
	if(isset($node->field_twitter_hashtag[LANGUAGE_NONE])) { //does it have a field to restrict by account
		foreach ($node->field_twitter_hashtag[LANGUAGE_NONE] as $twHashArr) {
			$returnArr[] = $twHashArr[\'value\'];
		}
	}
}

if (count($returnArr)) {
	return implode(\'+\', $returnArr); //multivalued field, concatonate together with + to act as OR operator
} else {
	return \'all\';
}';
  $handler->display->display_options['arguments']['tag']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tag']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tag']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tag']['limit'] = '0';
  $handler->display->display_options['arguments']['tag']['break_phrase'] = TRUE;
  $handler->display->display_options['block_description'] = 'QMA Tweets';
  $export['qma_tweets'] = $view;

  return $export;
}
