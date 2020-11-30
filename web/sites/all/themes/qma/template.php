<?php

/**
 * @file
 * Contains theme override functions and preprocess functions for the Boron theme.
 */

/**
 * Implements hook_css_alter().
 */
function qma_css_alter(&$css) {
  unset($css[drupal_get_path('module', 'field_collection') . '/field_collection.theme.css']);
  unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
  unset($css[drupal_get_path('module', 'system') . '/system.theme.css']);
  unset($css[drupal_get_path('module', 'system') . '/system.theme-rtl.css']);
  unset($css[drupal_get_path('module', 'poll') . '/poll.css']);
  unset($css[drupal_get_path('module', 'search') . '/search.css']);
}

/**
 * Changes the default meta content-type tag to the shorter HTML5 version
 */
function qma_html_head_alter(&$head_elements) {
  $head_elements['system_meta_content_type']['#attributes'] = array(
    'charset' => 'utf-8'
  );
}

/**
 * Changes the search form to use the HTML5 "search" input attribute
 */
function qma_preprocess_search_block_form(&$vars) {
  // $vars['search_form'] = str_replace('type="text"', 'type="search"', $vars['search_form']);
}

/**
 * Uses RDFa attributes if the RDF module is enabled
 * Lifted from Adaptivetheme for D7, full credit to Jeff Burnz
 * ref: http://drupal.org/node/887600
 */
function qma_preprocess_html(&$vars) {
  // Ensure that the $vars['rdf'] variable is an object.
  if (!isset($vars['rdf']) || !is_object($vars['rdf'])) {
    $vars['rdf'] = new StdClass();
  }

  if (module_exists('rdf')) {
    $vars['doctype'] = '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML+RDFa 1.1//EN">' . "\n";
    $vars['rdf']->version = 'version="HTML+RDFa 1.1"';
    $vars['rdf']->namespaces = $vars['rdf_namespaces'];
    $vars['rdf']->profile = ' profile="' . $vars['grddl_profile'] . '"';
  } else {
    $vars['doctype'] = '<!DOCTYPE html>' . "\n";
    $vars['rdf']->version = '';
    $vars['rdf']->namespaces = '';
    $vars['rdf']->profile = '';
  }


 // use the $html5shiv variable in their html.tpl.php
  $element = array(
    'element' => array(
    '#tag' => 'script',
    '#value' => '',
    '#attributes' => array(
      'src' => '//html5shiv.googlecode.com/svn/trunk/html5.js',
     ),
   ),
 );

 $shimset = theme_get_setting('boron_shim');
 $script = theme('html_tag', $element);
 //If the theme setting for adding the html5shim is checked, set the variable.
 if ($shimset == 1) { $vars['html5shim'] = "\n<!--[if lt IE 9]>\n" . $script . "<![endif]-->\n"; }

  $respond = array(
    'element' => array(
      '#tag' => 'script',
      '#attributes' => array( // Set up an array of attributes inside the tag
        'src' => '/' . drupal_get_path('theme', 'qma') . '/js/respond.min.js',
      ),
      '#value' => '',

    ),
  );

  $script = theme('html_tag', $respond);
  $vars['respond'] = "\n<!--[if lt IE 9]>\n" . $script . "<![endif]-->\n";

  $selectivizr = array(
    'element' => array(
      '#tag' => 'script',
      '#attributes' => array( // Set up an array of attributes inside the tag
        'src' => '/' . drupal_get_path('theme', 'qma') . '/js/selectivizr.min.js',
      ),
      '#value' => '',
    ),
  );

  $script = theme('html_tag', $selectivizr);
  $vars['selectivizr'] = "\n<!--[if lt IE 9]>\n" . $script . "<![endif]-->\n";

}

/**
* pass an array of menu objects and return as an array of links
* cut down implementation of menu_navigation_links to allow us
* to retrieve menu links irrespective of current page
* e.g menu_tree_page_data does not return for 404 page
*/
function qma_menu_to_links_array($menuArr) {
  $links = array();

  foreach ($menuArr as $item) {
    if (!$item['link']['hidden']) {
      $class = '';
      $l = $item['link']['localized_options'];
      $l['href'] = $item['link']['href'];
      $l['title'] = $item['link']['title'];

      // Keyed with the unique mlid to generate classes in theme_links().
      $links['menu-' . $item['link']['mlid'] . $class] = $l;
    }
  }
  return $links;
}

/**
 * Implements hook_preprocess_page().
 */
function qma_preprocess_page(&$variables) {
  $status = drupal_get_http_header("status");

  if($status == "404 Not Found") {
    $variables['theme_hook_suggestions'][] = 'page__404';
     //navigation not available to this page as it isn't a real page so we  have to manually load it here
    $main_menu = (menu_tree_all_data('main-menu'));
    $variables['main_menu'] = qma_menu_to_links_array($main_menu);


    $footer_menu_1 = qma_menu_to_links_array((menu_tree_all_data('menu-behind-the-scenes')));
    $footer_menu_2 = qma_menu_to_links_array((menu_tree_all_data('menu-using-this-website')));

    //footer menus are even more complex as we have to theme them as if they were blocks contained in a region
    //in order to match the implementation on other pages.
    $variables['page']['footer'] = '<div class="region region-footer">';
    $variables['page']['footer'] .= '<section id="block-menu-menu-behind-the-scenes" class="block block-menu">';
    $variables['page']['footer'] .= theme('links__system_secondary_menu', array(
          'links' => $footer_menu_1,
          'heading' => array(
            'text' => t('Behind the scenes', array(), array('context'=>'QMA')),
            'level' => 'h2',
          ),
        ));
    $variables['page']['footer'] .= '</div>';

    $variables['page']['footer'] .= '<section id="block-menu-menu-using-this-website" class="block block-menu">';
    $variables['page']['footer'] .= theme('links__system_secondary_menu', array(
          'links' => $footer_menu_2,
          'heading' => array(
            'text' => t('Using this website', array(), array('context'=>'QMA')),
            'level' => 'h2',
          ),
        ));
    $variables['page']['footer'] .= '</div>';
    $variables['page']['footer'] .= '</div>';




    //get the last non-numeric portion of the url as a best guess at what the user
    //may have been looking for (pathauto generates human readable urls)
    $argsArr = arg();
    $final_arg = array_pop($argsArr);

    while(is_numeric($final_arg)) {
      $final_arg = array_pop($argsArr);
    }
    $variables['url_search'] = check_plain(str_replace('-', ' ',$final_arg));

  }

  if (!empty($variables['node']) && !empty($variables['node']->type)) {

    //allow page level template overrides on a per node type basis
    $variables['theme_hook_suggestions'][] = 'page__node__' . $variables['node']->type;

    //Populate breadcrumb for content types that do not appear in the menu structure
    //by assigning their related hub page to the breadcrumb
    switch($variables['node']->type) {
      case 'interview':
        $hubType='interview_hub';
        break;
      case 'news_article':
        $hubType='news_hub';
        break;
      case 'press_release':
        $hubType='press_room';
        break;
      case 'area_of_work':
      case 'project':
        $hubType='areas_hub';
        break;
      default:
        $hubType=FALSE;
    }

    if($hubType) {
      $query = new EntityFieldQuery();

      // This assumes there will only be a single hub for each language.
      $query->entityCondition('entity_type', 'node')
        ->propertyCondition('language', $variables['node']->language)
        ->propertyCondition('type', $hubType)
        ->propertyCondition('status', 1)
        ->range(0, 1);

      $result = $query->execute();

      if (!empty($result['node'])) {
        $hub_node = array_shift($result['node']);
        $hub_node = node_load($hub_node->nid);

        $breadcrumb = drupal_get_breadcrumb(); //this will always just be 'home' for unassigned items


        //lookup the parent of the hub page to allow for hub pages not at top level
        //n.b we would need to add a loop/recursion here if we needed to support more than one level of nesting
        $item = menu_link_get_preferred('node/'.$hub_node->nid);
        if ( $item['plid'] ) {
          $parent = menu_link_load($item['plid']);
          $breadcrumb[] = l($parent['title'],$parent['href']);
        }

        $breadcrumb[] = l($hub_node->title, 'node/'.$hub_node->nid);

        drupal_set_breadcrumb($breadcrumb);
      }
    }

    $variables['membership_link'] = '';
    $query = new EntityFieldQuery();

    // This assumes there will only be a single hub for each language.
    $query->entityCondition('entity_type', 'node')
      ->propertyCondition('language', $variables['node']->language)
      ->propertyCondition('type', 'membership_page')
      ->propertyCondition('status', 1)
      ->range(0, 1);

    $result = $query->execute();

    if (!empty($result['node'])) {
      $hub_node = array_shift($result['node']);
      $variables['membership_link'] = l(t('Become a member', array(), array('context' => 'QMA')), 'node/'.$hub_node->nid);
      $variables['membership_link'] .= ' ' . t('or', array(), array('context' => 'QMA')) . ' ';
      $variables['membership_link'] .= l(t('Sign in', array(), array('context' => 'QMA')), "node/{$hub_node->nid}", array('fragment' => 'signin'));
    }
  }

  if (isset($variables['node']) && $variables['node']->type === 'pattern_generator') {
    $variables['share_block'] = module_invoke('qma_forms', 'block_view', 'qma_forms_pattern_mail');
  }

}

/**
 * Implements hook_process_node().
 */
function qma_preprocess_node(&$variables) {
  $node = $variables['node'];
  $view_mode = $variables['view_mode'];

  qma_add_sharing_links($variables);

  // Set up template suggestions for non-standard view modes
  if ($variables['view_mode'] !== 'full') {
    $variables['theme_hook_suggestions'][] = 'node__' . $node->type . '__' . $view_mode;
  }

  $header_image_types = array(
    'education_hub',
    'project',
    'area_of_work',
    'interview',
    'generic_page',
    'areas_hub',
    'landing_page',
    'news_article',
    'creative_resource_hub',
    'exhibition_home',
    'event'
   );

  if (in_array($node->type, $header_image_types)) {
    $image_data = field_get_items('node', $node, 'field_hero_image');
    $image_data = array_shift($image_data);

    // hardcoded for the bespoke sheika page
    if ((int) $node->nid === 95 || (int) $node->nid === 680) {
      $main_image_style = 'hero_image_shallow';
      $variables['custom_class'] = 'bespoke-page';
    }
    else {
      $main_image_style = 'hero_image';
      $variables['custom_class'] = 'generic-page';
    }

    $hero_image_path = image_style_url($main_image_style, $image_data['uri']);
    $mobile_hero_image_path = image_style_url('hero_image_mobile', $image_data['uri']);

    if ($variables['view_mode'] === 'full') {
      // grim addition of inline css to the head of the page, so we can have two different images for the hero container
      $css_string = '@media all and (min-width: 569px) {.hero-container{
        background-image: url("'.$hero_image_path.'");}}
        @media all and (max-width: 568px) {.hero-container{background-image: url("'.$mobile_hero_image_path.'");}}
        .lt-ie9 .hero-container {background-image: url("'.$hero_image_path.'"); background-position: top center;}';

      drupal_add_css($css_string, 'inline');
    }

    // check for image gallery
    $variables['has_image_gallery'] = TRUE;

    if (isset($node->field_image_gallery) && count($node->field_image_gallery) === 0) {
      hide($variables['content']['field_image_gallery']);
      $variables['has_image_gallery'] = FALSE;
    }

  }

  if (($node->type === 'landing_page' || $node->type === 'areas_hub') && $view_mode === 'full') {
    if (count(menu_get_active_trail()) < 3) {
      $variables['is_top_level'] = true;
    } else {
      $variables['is_top_level'] = false;
    }
  }

  // get the list of child pages
  if ($node->type == 'landing_page' && $view_mode == 'full') {
    $variables['child_pages'] = views_embed_view('child_pages_by_menu','child_pages_block', $node->nid, $node->language);
  }

  // Streamline view mode templates once and for all! Set the node teaser
  // template to have a high precedence for these node types.
  $teaser_override_types = array(
    'creative_resource_hub',
    'education_hub',
    'education_resource_hub',
    'generic_page',
    'interview_hub',
    'landing_page',
    'news_hub',
    'pattern_gallery',
    'pattern_generator',
    'press_room',
  );

  if ($view_mode === 'teaser' && in_array($node->type, $teaser_override_types)) {
    $variables['theme_hook_suggestions'][] = 'node__teaser';
  }

  $function = __FUNCTION__ . '_' . $node->type;
  if (function_exists($function)) {
    $function($variables);
  }
}

/**
 * Delegated node preprocess function for areas_hub.
 */
function qma_preprocess_node_areas_hub(&$variables) {
  $node = $variables['node'];
  // add the all projects listing to the experience page
  if ($variables['view_mode'] == 'full') {
    if(isset($_REQUEST['display'])&&$_REQUEST['display']=='map') {
      $variables['all_projects'] = views_embed_view('projects_by_area','experience_map_block', $node->language);
    } else {
      $variables['all_projects'] = views_embed_view('projects_by_area','all_projects_and_areas', $node->language);
    }
  }
}


/**
 * Delegated node preprocess function for area_of_work.
 */
function qma_preprocess_node_area_of_work(&$variables) {
  $node = $variables['node'];
// add the projects by area view block to the area of work template
  if ($variables['view_mode'] == 'full') {
    $variables['content']['instagram_block'] = '';
    $variables['content']['twitter_block'] = '';

    $variables['project_listing'] = views_embed_view('projects_by_area','block', $node->nid, $node->language);
    $variables['interview_area'] = views_embed_view('interviews','latest_area_interview', $node->nid, $node->language);

    $instagram_account = _qma_get_instagram_account_filter($node);
    $twitter_account = _qma_get_twitter_account_filter($node);
    $twitter_tag = _qma_get_twitter_tag_filter($node);

    //remove tests as we are supplying default fallback accounts for now
    $variables['content']['instagram_block'] = views_embed_view('project_instagram', 'block', $instagram_account);
    $variables['content']['twitter_block'] = views_embed_view('qma_tweets', 'block_1', $twitter_account, $twitter_tag);
  }

  // for the experience hub, add the area of work title as a class so we can style it fancy
  if ($variables['view_mode'] == 'experience_teaser') {
    $variables['title_as_class'] = get_translated_title($node);
  }
}

/**
 *  Delegated node preprocess function for landing pages.
 */
function qma_preprocess_node_landing_page(&$variables) {
  $node = $variables['node'];
  // for the experience hub, add the area of work title as a class so we can style it fancy

  if ($variables['view_mode'] == 'full') {
    $variables['title_as_class'] = get_translated_title($node);
  }

}

/**
 * Delegated node preprocess function for generic page.
 */
function qma_preprocess_node_generic_page(&$variables) {
  $node = $variables['node'];

  if ($variables['view_mode'] == 'full') {
    $node_wrapper = entity_metadata_wrapper('node', $node);

    $variables['display_social_media'] = !!$node_wrapper->field_display_social_media->value();

    if ($variables['display_social_media']) {
      $variables['content']['instagram_block'] = '';
      $variables['content']['twitter_block'] = '';

      $instagram_account = _qma_get_instagram_account_filter($node);
      $twitter_account = _qma_get_twitter_account_filter($node);
      $twitter_tag = _qma_get_twitter_tag_filter($node);

      $variables['content']['instagram_block'] = views_embed_view('project_instagram', 'block', $instagram_account);
      $variables['content']['twitter_block'] = views_embed_view('qma_tweets', 'block_1');
    }
  }
}

/**
 * Delegated node preprocess function for project.
 */
function qma_preprocess_node_project(&$variables) {

  $node = $variables['node'];


  // get the list of news articles for the project page
  if ($variables['view_mode'] == 'full') {
    $variables['content']['instagram_block'] = '';
    $variables['content']['twitter_block'] = '';

    $node_wrapper = entity_metadata_wrapper('node', $node);

    $subjectTags = $node_wrapper->field_project_sample_tags->raw();
    $subjectTags = implode('+', $subjectTags); //concatonate into format expected by view argument handler

    $variables['news_list'] = views_embed_view('news','news_by_tag_block', $node->language, $subjectTags);

    $instagram_account = _qma_get_instagram_account_filter($node);
    $twitter_account = _qma_get_twitter_account_filter($node);
    $twitter_tag = _qma_get_twitter_tag_filter($node);

   //remove tests as we are supplying default fallback accounts for now
   // if ($instagram_account) {
      $variables['content']['instagram_block'] = views_embed_view('project_instagram', 'block', $instagram_account);
   // }
   // if ($twitter_account) {
      $variables['content']['twitter_block'] = views_embed_view('qma_tweets', 'block_1', $twitter_account, $twitter_tag);
   // }
  }


  // for the experience hub page, work out if a project is 'new' or not.
  if ($variables['view_mode'] == 'experience_teaser') {
    // the image size changes depending on whether it's new, a highlight or neither.
    // so we need to load in teaser images here, get the right image style, and then pass to the template

    $image_style = 'experience_hub_small'; // our default style

    if($node->created > strtotime(date('Y-m-d',strtotime('-10 days'))) ) {
      $variables['new_class'] = 'new-project';

      $image_style = 'experience_hub_medium'; // if it is new, then up the image size

    } else {
      $variables['new_class'] = '';
    }

    // now work out which size teaser image we want
    $node_wrapper = entity_metadata_wrapper('node', $node);

    // is it a highlight or not?
    $variables['highlight_class'] = ($node_wrapper->field_highlight_flag->value() == '1') ? 'highlight' : '';

    if($variables['highlight_class']) {
      $image_style = 'experience_hub_large';
    }

    // now load in the correct teaser image with the required image style
    $image_data = $node_wrapper->field_teaser_image->value();
    $variables['teaser_image_path'] = image_style_url($image_style, $image_data['uri']);

  }
}

/**
 * Delegated node preprocess function for exhibition_home.
 *
 * On an exhibition home page the content type fields will be rendered
 * with a listing of exhibition teasers below. This is a rendered block
 * from the Current Exhibitions view. Current exhibitions are included in
 * this view on the basis of the exhibition state taxonomy tag.
 *
 * An alternative past exhibitions page is rendered if an exhibition home page
 * is rendered with a URL parameter referring to the 'Closed' exhibition state tag
 *
 * Tag links are in the form of 'path?filter=XXX' and are created by the
 * qma_news_taxonomy_term_uri() function in qma_news.module.
 *
 * Since this deals with user input (content extracted from the url) it needs to
 * use check_plain to avoid any surprises.
 *
 * This function borrows heavily from qma_preprocess_node_news_hub() below.
 *
 */
function qma_preprocess_node_exhibition_home(&$variables) {
  // Get the node.
  $node = $variables['node'];

  // Initialise template control variables.
  $variables['current_exhibitions_view'] = false;
  $variables['past_exhibitions_view'] = false;
  $variables['past_exhibitions_link'] = false;
  $variables['no_results'] = false;

  // For past exhibitions, use a simple flag on ?status=past (with translation)
  $query = drupal_get_query_parameters();
  $past = isset($query['status']) && ($query['status'] === t('past'));


  // If there is a term id and the user is viewing the full node get display
  // results based on term id. Display all results otherwise.
  if ($past && $variables['view_mode'] == 'full') {
    // Get the rendered past exhibitions bew (listing all exhibitions with the taxonomy term "Closed")
    $variables['past_exhibitions_view'] = TRUE;

    $variables['content']['past_exhibitions_view'] = views_embed_view('past_exhibitions', 'past_exhibition_block', $node->language);
  }
  else {
    // Display the current exhibitions page
    if ($variables['view_mode'] == 'full') {

      // Indicate features that should appear on the page template.
      $variables['current_exhibitions_view'] = true;
      $variables['past_exhibitions_link'] = true;

      // Assign view content to template variables.
      $variables['content']['current_exhibitions_view'] = views_embed_view('current_exhibitions', 'current_exhibitions_block', $node->language);

      // Construct the URL for a link to the closed exhibitions to pass through the render array
      // Get the URL to this page but with the term id for 'Closed' appended to the URL
      $past_exhibitions_url = url('node/' . $node->nid, array(
        'absolute' => TRUE,
        'query' => array(
          'status' => t('past')
        )
      ));

      $variables['content']['past_exhibitions_link'] = l(t('Previous exhibitions', array(), array('context' => 'QMA')), $past_exhibitions_url, array('class' => 'past-events'));
      $variables['content']['footer_past_exhibitions_link'] = l(t('Explore our past exhibitions', array(), array('context' => 'QMA')), $past_exhibitions_url, array('class' => 'past-events'));

    }

  }

}

/**
 * Delegated node preprocess function for news_hub.
 *
 * This function has two facets. Displays a featured blog post and a list of
 * all available posts or displays a filtered list of blog posts based on tags.
 * Tag links are in the form of 'path?filter=XXX' and are created by the
 * qma_news_taxonomy_term_uri() function in qma_news.module.
 *
 * Since this deals with user input (content extracted from the url) it needs to
 * use check_plain to avoid any surprises.
 *
 */
function qma_preprocess_node_news_hub(&$variables) {

  // Get the node.
  $node = $variables['node'];

  // Get the term id and associated term. Make sure check_plain is used, essentially
  // this is user input (coming from the url).
  $query = drupal_get_query_parameters();
  $term_id = isset($query['filter']) ? check_plain($query['filter']): null;
  $term = taxonomy_term_load($term_id);


  // Get 'News' view.
  $view = views_get_view('news');

  // Initialise template control variables.
  $variables['news_featured_list'] = false;
  $variables['news_list'] = false;
  $variables['no_results'] = false;
  $variables['blog_tags_list'] = false;

  // if there is a term id and the user is viewing the full node check display
  // results based on term id. Display all results otherwise.
  if ($term_id && $variables['view_mode'] == 'full') {

    // Get back link.
    $text = '<span>' . t('Our Blog', array(), array('context' => 'QMA')) . '</span>';

    $path = 'node/' . $node->nid;

    $attributes = array(
      'html'=>TRUE,
      'attributes' => array(
        'class' => array('back-to-parent'),
      ),
    );

    // Create back link at top of page.
    $variables['news_hub_link'] = l($text, $path, $attributes);

    // Get view preview so we know if we there are results or not.
    $preview = $view->preview('hub_block_all', array($node->language, $term->tid));

    if ($view->result) {

      // If there are results indicate there is a news list.
      $variables['news_list'] = true;

      // Create title
      $variables['content']['page-title'] = array(
        '#markup' => t('Blog posts about: %tag', array('%tag' => $term->name), array('context' => 'QMA')),
      );

      // Assign content to template variables.
      $variables['content']['news_list'] = $preview;

    }
    // If term id but no results, display a no-results message.
    else {

      // The view does not have results.
      $variables['no_results'] = true;

      // Create page title.
      $variables['content']['page-title'] = array(
        '#prefix' => '<h1>',
        '#markup' => t('Our blog', array(), array('context' => 'QMA')),
        '#suffix' => '</h1>',
      );

      // Assign no results message to template variable.
      $variables['content']['no_results'] = array(
        '#markup' => t('No results available', array(), array('context' => 'QMA'))
      );

    }

  }

  // Display all results otherwise.
  else {

    // If the full page is requested without a term id
    if ($variables['view_mode'] == 'full') {

      // Get view preview so we know if we there are results or not.
      $preview = $view->preview('hub_block_all', array($node->language, $term->tid));

      if ($view->result) {
        $total_blogs = $view->total_rows;

        $variables['content']['teasers_subtitle'] = array(
          '#prefix' => '<h2>',
          '#markup' => t('Dive into @num blog articles', array('@num' => $total_blogs), array('context' => 'QMA')),
          '#suffix' => '</h2>',
        );
      }

      // Indicate features that should appear on the page template.
      $variables['news_featured_list'] = true;
      $variables['news_list'] = true;
      $variables['blog_tags_list'] = true;

      // Create the page title
      $variables['content']['page-title'] = array(
        '#prefix' => '<h1>',
        '#markup' => t('Our blog', array(), array('context' => 'QMA')),
        '#suffix' => '</h1>',
      );

      // Assign view content to template variables.
      $variables['content']['news_featured_list'] = views_embed_view('news', 'hub_featured_block', $node->language);
      $variables['content']['news_list'] = views_embed_view('news', 'hub_block', $node->language);
      $variables['content']['blog_tags_list'] = views_embed_view('blog_tags_list', 'blog_tags_block', $node->language);

    }

  }

}

/**
 * Delegated node preprocess function for news_article.
 */
function qma_preprocess_node_news_article(&$variables) {

  global $base_url;
  global $language;

  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node);

  // Add specified in the UI read more link.
  $read_more_link_text = $node_wrapper->field_read_more_link->value();
  $variables['content']['read_more'] = array(
    '#type' => 'link',
    '#title' => !empty($read_more_link_text) ? $read_more_link_text : t('Read more', array(), array('context' => 'QMA')),
    '#href' => $base_url . '/' . $language->language . '/' . drupal_get_path_alias('node/' . $node->nid),
  );

  // Add highlight text in the UI.
  $highlight_text = $node_wrapper->field_highlight_text->value();
  $variables['content']['highlight_text'] = array(
    '#markup' => !empty($highlight_text) ? $highlight_text : t('Don\'t miss', array(), array('context' => 'QMA')),
  );

  // sort out the date for displaying on the news article page
  $date_override = $node_wrapper->field_news_date_override->value();
  // if we have the override, use it, else use the default
  if($date_override) {
    $variables['display_date'] = $date_override;
  }
//  else {
//    $variables['display_date'] = date('d F Y', $node_wrapper->field_news_date->value());
//  }

  if ($variables['view_mode'] == 'full') {
    // Build the string for the anchor link down to the comments
    // Check if the news/blog article has comments and if so count them to put in the link string
    $comment_count = $variables['comment_count'];

    // Check it's not null
    if($comment_count) {
      // Does the link text need to be plural
      if(intval($comment_count) > 1) {
        $link_str = t('Jump to @comment_count comments', array('@comment_count' => $comment_count));
      } else {
        $link_str = t('Jump to @comment_count comment', array('@comment_count' => $comment_count));
      }

      // Add to the render array
      $variables['jump_link'] = array(
        '#type' => 'link',
        '#title' => $link_str,
        '#href' => current_path(),
        '#options' => array(
          'fragment' => 'comment-1',
          'attributes' => array('class' => array('comment-jump-link')),
          'html' => TRUE,
          ),
      );
    }

    // get the list of news articles for the related news section of a news article page
    $subjectTags = $node_wrapper->field_project_sample_tags->raw();
    $subjectTags = implode('+', $subjectTags); //concatonate into format expected by view argument handler
    $variables['news_list'] = views_embed_view('news','related_news_block', $node->language, $subjectTags, $node->nid);


    //look up news hub so we can construct a link without having to hardcode the url
    //and retrieve the outro section common to all news pages from the news hub page where it is content managed
    $variables['news_hub_link'] = '';
    $node->content['news_outro_section'] = NULL;

    $query = new EntityFieldQuery();

    // This assumes there will only be a single conversation hub for each language.
    $query->entityCondition('entity_type', 'node')
      ->propertyCondition('language', $node->language)
      ->propertyCondition('type', 'news_hub')
      ->propertyCondition('status', 1)
      ->range(0, 1);

    $result = $query->execute();

    if (!empty($result['node'])) {
      $hub_node = array_shift($result['node']);
      $hub_node_wrapper = entity_metadata_wrapper('node', node_load($hub_node->nid));
      $outroValArr = $hub_node_wrapper->field_news_outro_col_1->value();

      $variables['news_outro_section'] = $outroValArr['value'];
      $variables['news_hub_link'] = l('<span>'.t('Our Blog', array(), array('context' => 'QMA')).'</span>','node/'.$hub_node->nid, array('html'=>TRUE,'attributes' => array('class' => 'back-to-parent')));
    }
  }
}

/**
 * Delegated node preprocess function for social media hub.
 */
function qma_preprocess_node_social_media_hub(&$variables) {
  $node = $variables['node'];

  $instagram_account = _qma_get_instagram_account_filter($node);
  $variables['instagram_slider'] = views_embed_view('project_instagram', 'block_2', $instagram_account);

  // Expose Instagram account as a setting for use in AJAX filtering.
  $settings = array('instagram_account' => $instagram_account);
  drupal_add_js($settings, array('type' => 'setting', 'group' => JS_THEME));
}

/**
 * Adds sharing links to the node $variables.
 */
function qma_add_sharing_links(&$variables) {
  $node = $variables['node'];

  $fb_link_opts = array(
    'query' => array(
      'u' => url("node/{$node->nid}", array('absolute' => TRUE)),
    ),
    'external' => TRUE,
  );

  $variables['fb_sharing_link'] = url('http://facebook.com/sharer/sharer.php', $fb_link_opts);

  $tw_link_opts = array(
    'query' => array(
      'status' => url("node/{$node->nid}", array('absolute' => TRUE)),
    ),
    'external' => TRUE,
  );

  $variables['tw_sharing_link'] = url('http://twitter.com/home', $tw_link_opts);
}

/**
 * Implements hook_preprocess_views_view_fields().
 */
function qma_preprocess_views_view_fields(&$variables) {
  $view = $variables['view'];

  if ($view->name === 'project_instagram' && $view->current_display === 'block') {
    $variables['link'] = $variables['fields']['link']->content;
    unset($variables['fields']['link']);

    foreach ($variables['fields'] as $id => $field) {
      if (in_array($id, array('username', 'caption'))) {
        $variables['overlay_fields'][$id] = $field;
        unset($variables['fields'][$id]);
      }
    }
  }

  if ($view->name === 'project_instagram' && in_array($view->current_display, array('block_1', 'block_2'))) {
    foreach ($variables['fields'] as $id => $field) {
      if (in_array($id, array('username', 'caption', 'created_time'))) {
        $variables['overlay_fields'][$id] = $field;
        unset($variables['fields'][$id]);
      }
    }
  }
}

/**
 * Implements hook_views_ajax_data_alter().
 */
function qma_views_ajax_data_alter(&$commands, &$view) {
  if ($view->name === 'press') {
    $commands[] = ajax_command_invoke('#views-exposed-form-press-block .form-item-combine input', 'focus');
    $commands[] = ajax_command_invoke('#views-exposed-form-press-block .form-item-combine input', 'setCursorEnd');
  }

  // Unset auto-scrolling in AJAX views.
  if ($view->name !== 'press') {
    foreach ($commands as $index => $command) {
      if ($command['command'] === 'viewsScrollTop') {
        unset($commands[$index]);
        $commands = array_values($commands);
        break;
      }
    }
  }
}

/**
 * Implements hook_views_pre_view().
 */
function qma_views_pre_view(&$view, &$display_id, &$args) {
  global $language;

  if ($view->name === 'current_exhibitions') {
    xdebug_break();
    $open_term = taxonomy_get_term_by_name('Now open', 'exhibition_status_');
    $translated_open_term = i18n_taxonomy_term_get_translation($open_term, $language->language);
    // @todo get term translation

    $filters = $view->display_handler->get_option('filters');
    $view->display_handler->override_option('filters', $filters);
  }
  elseif ($view->name === 'past_exhibitions') {
    xdebug_break();

    $open_term = taxonomy_get_term_by_name('Now open', 'exhibition_status_');
    $translated_open_term = i18n_taxonomy_term_get_translation($open_term, $language->language);

    $filters = $view->display_handler->get_option('filters');
    $view->display_handler->override_option('filters', $filters);
  }
}

/**
 * Delegated node preprocess function for interview.
 */
function qma_preprocess_node_interview(&$variables) {
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node);

  // sort out the date for displaying on the inconversation article page
  $date_override = $node_wrapper->field_interview_date_override->value();

  // if we have the override, use it, else use the default
  if($date_override) {
    $variables['display_date'] = $date_override;
  } else {
    $variables['display_date'] = date('d F Y', $node_wrapper->field_interview_date->value());
  }

  if ($variables['view_mode'] == 'full') {
    // retrieve the outro section common to all interview (in_conversation) pages from the interview hub page where it is content managed
    $node->content['interview_outro_section'] = NULL;

    $query = new EntityFieldQuery();

    // This assumes there will only be a single conversation hub for each language.
    $query->entityCondition('entity_type', 'node')
      ->propertyCondition('language', $node->language)
      ->propertyCondition('type', 'interview_hub')
      ->propertyCondition('status', 1)
      ->range(0, 1);

    $result = $query->execute();

    if (!empty($result['node'])) {
      $hub_node = array_shift($result['node']);

      $hub_node_wrapper = entity_metadata_wrapper('node', node_load($hub_node->nid));
      $outroValArr = $hub_node_wrapper->field_conversation_outro_col_1->value();

      $variables['interview_outro_section'] = $outroValArr['value'];

    }
  }
}

/**
 * Delegated node preprocess function for interview_hub.
 */
function qma_preprocess_node_interview_hub(&$variables) {
  // get the list of interviews for the hub page
  $node = $variables['node'];
  if ($variables['view_mode'] == 'full') {
    $variables['latest_interview'] = views_embed_view('interviews','latest_interview', $node->language);
    $variables['interview_list'] = views_embed_view('interviews','interview_listing', $node->language);
  }
}


/**
 * Delegated node preprocess function for press_room.
 */
function qma_preprocess_node_press_room(&$variables) {
  $node = $variables['node'];

  // This should always be rendered in English.
  $variables['press_list'] = views_embed_view('press', 'block', 'en');
}

/**
 * Delegated node preprocess function for press_release.
 */
function qma_preprocess_node_press_release(&$variables) {
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $date_override = $node_wrapper->field_display_date->value();

  // if we have the override, use it, else use the default
  if ($date_override) {
    $variables['display_date'] = date('d F Y', $date_override);
  } else {
    $variables['display_date'] = date('d F Y', $node_wrapper->created->raw());
  }

  if ($variables['view_mode'] == 'full') {
    $variables['hub_link'] = '';
    $query = new EntityFieldQuery();

    // This assumes there will only be a single hub for each language.
    $query->entityCondition('entity_type', 'node')
      ->propertyCondition('language', $variables['node']->language)
      ->propertyCondition('type', 'press_room')
      ->propertyCondition('status', 1)
      ->range(0, 1);

    $result = $query->execute();

    if (!empty($result['node'])) {
      $hub_node = array_shift($result['node']);
      $variables['hub_link'] = l(t('See all press releases', array(), array('context' => 'QMA')), 'node/'.$hub_node->nid);
    }
  }
}

/**
 * Delegated node preprocess function for whats_on.
 */
function qma_preprocess_node_whats_on(&$variables) {
  $node = $variables['node'];
  $variables['parent_link'] = '';
  //construct link back to parent item
  if ($variables['view_mode'] == 'full') {
    $item = menu_link_get_preferred('node/'.$node->nid); //get the menu link object for the current page as this includes a reference to the parent
    if ( $item['plid'] ) {
      $parent = menu_link_load($item['plid']); // load the parent menu item, n.b returns the translated version
      $variables['parent_link'] = l('<span>'.t("Back to !parentTitle page", array('!parentTitle'=>$parent['title']), array('context' => 'QMA')).'</span>',$parent['href'], array('html'=>TRUE,'attributes'=>array('class'=>'back-to-parent')));
    }
  }
}

/**
 * Delegated node preprocess function for creative_resources_hub.
 */
function qma_preprocess_node_creative_resource_hub(&$variables) {
  $node = $variables['node'];
  // add the all projects listing to the experience page
  if ($variables['view_mode'] == 'full') {
    if(isset($_REQUEST['display'])&&$_REQUEST['display']=='list') {
      $variables['resources_list'] = views_embed_view('creative_resources','creative_list_block', $node->language);
    } else {
      $variables['resources_list'] = views_embed_view('creative_resources','creative_map_block', $node->language);
    }
  }
}


function qma_preprocess_search_result(&$variables) {
  $variables['info'] = '';
}


/**
 * Delegated node preprocess function for exhibition
 */
function qma_preprocess_node_exhibition(&$variables) {
  global $language;
  $node = $variables['node'];
  $view_mode = $variables['view_mode'];

  if ($view_mode === 'teaser') {
    $variables['node_teaser_link'] = 'node/' . $node->nid;
    $variables['node_teaser_target'] = '_self';
    $external_links = field_get_items('node', $node, 'field_external_link');

    if (!empty($external_links)) {
      $variables['node_teaser_link'] = $external_links[0]['url'];

      if (isset($external_links[0]['attributes']['target'])) {
        $variables['node_teaser_target'] = $external_links[0]['attributes']['target'];
      }
    }
  }
  elseif ($view_mode === 'full') {
    // Load exhibitions homepage based on language
    // We assume there will only ever be one
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'exhibition_home')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyCondition('language', $language->language)
      ->range(0, 1);
    $result = $query->execute();

    // Set a placeholder value for the hub link
    $variables['exhibition_hub_link'] = '';

    if (!empty($result['node'])) {
      $nids = array_keys($result['node']);
      $text = '<span>' . t('All Exhibitions', array(), array('context' => 'QMA')) . '</span>';
      $path = 'node/' . $nids[0];

      $attributes = array(
        'html'=> TRUE,
        'attributes' => array(
          'class' => array('back-to-parent'),
        ),
      );

      // Create back link at top of page.
      $variables['exhibition_hub_link'] = l($text, $path, $attributes);
    }

    // Twitter / Instagram wall
    $variables['content']['instagram_block'] = '';
    $variables['content']['twitter_block'] = '';

    $instagram_account = _qma_get_instagram_account_filter($node);
    $twitter_account = _qma_get_twitter_account_filter($node);
    $twitter_tag = _qma_get_twitter_tag_filter($node);

    //remove tests as we are supplying default fallback accounts for now
    $variables['content']['instagram_block'] = views_embed_view('project_instagram', 'block', $instagram_account);
    $variables['content']['twitter_block'] = views_embed_view('qma_tweets', 'block_1', $twitter_account, $twitter_tag);
  }
}


/**
*  Implements hook preprocess field
*/
function qma_preprocess_field(&$variables) {
  // Set default values
  $node = FALSE;
  $variables['gallery_images'] = array();
  $field_name = isset($variables['element']['#field_name']) ? $variables['element']['#field_name'] : '';

  // We need to get the relevant node. First try and retrieve the node from the
  // field so that it loads the correct information for workbench drafts.
  if (isset($variables['element']['#object'])) {
    $node = $variables['element']['#object'];
  }
  elseif (arg(0) === 'node' && is_numeric(arg(1))) {
    $nid = arg(1);
    $node = node_load($nid);
  }

  $gallery_ctypes = array(
    'education_institution',
    'area_of_work',
    'generic_page',
    'news_article',
    'project',
  );

  // get the image paths of the gallery image so we can handle the responsive images
  if ($node && in_array($node->type, $gallery_ctypes)) {
    if ($variables['element']['#field_name'] === 'field_image_gallery') {
      // create a variable of the slideshow to be output in field--field-image-gallery.tpl.php
      $field_image_gallery = field_get_items('node', $node, 'field_image_gallery');

      foreach ($field_image_gallery as $key => $gallery) {
        $collection = entity_revision_load('field_collection_item', $gallery['revision_id']);

        $gallery_image_data = field_get_items('field_collection_item', $collection, 'field_gallery_image');
        $gallery_image_data = array_shift($gallery_image_data);

        $gallery_caption_data = field_get_items('field_collection_item', $collection, 'field_gallery_caption');
        $gallery_caption_data = array_shift($gallery_caption_data);

        // make the array of small and large image sizes and the image's caption.
        $small_image_src = image_style_url('gallery_small', $gallery_image_data['uri']);

        list($width, $height, $type, $attr) = getimagesize($small_image_src); //this is inefficient as it is retrieving over the network, would be better to convert to local path.
        $variables['gallery_images'][$key]['small'] = $small_image_src;
        $variables['gallery_images'][$key]['small_width'] = $width;
        $variables['gallery_images'][$key]['small_height'] = $height;

        $large_image_src = image_style_url('gallery_large', $gallery_image_data['uri']);
        list($width, $height, $type, $attr) = getimagesize($large_image_src); //this is inefficient as it is retrieving over the network, would be better to convert to local path.
        $variables['gallery_images'][$key]['large'] = $large_image_src;
        $variables['gallery_images'][$key]['large_width'] = $width;
        $variables['gallery_images'][$key]['large_height'] = $height;

        $variables['gallery_images'][$key]['caption'] = $gallery_caption_data ? $gallery_caption_data['safe_value'] : '';
      }
    }
  }

  // we need both a large and small image style for the pattern gallery field collection
  if ($node && $node->type === 'pattern_gallery') {
    if ($variables['element']['#field_name'] === 'field_pattern_gallery_images') {
      $gallery_images = field_get_items('node', $node, 'field_pattern_gallery_images');

      foreach ($gallery_images as $key => $gallery) {
        $variables['gallery_images'][$key]['small'] = image_style_url('pattern_image_gallery', $gallery['uri']);
        $variables['gallery_images'][$key]['large'] = image_style_url('pattern_image_gallery_large', $gallery['uri']);
      }
      //setup link back to pattern generator page

      // This assumes there will only be a single pattern generator for each language.
      // we could get the parent id with a menu lookup instead but in this instance this seems more robust
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'node')
        ->propertyCondition('language', $node->language)
        ->propertyCondition('type', 'pattern_generator')
        ->propertyCondition('status', 1)
        ->range(0, 1);

      $result = $query->execute();

      if (!empty($result['node'])) {
        $hub_node = array_shift($result['node']);
        $variables['pattern_generator_link'] = l('<h4>'.t('Try Making Your Own', array(), array('context' => 'QMA')).'</h4>', 'node/'.$hub_node->nid, array('html'=>true));

      }
    }
  }


 // To deal with the difficulties of theming field collections (cascading inheritance)
  // We override at the field level to assign a custom template
  // We then add the child collections and their child fields to the variables array for this template
  if ($variables['element']['#field_name'] == 'field_body_elements' || $variables['element']['#field_name'] == 'field_whatson_event' || $variables['element']['#field_name'] == 'field_homepage_box') {
    $fieldName = $variables['element']['#field_name'];
    $variables['theme_hook_suggestions'][] = 'field__'.$fieldName.'_global';
    rows_from_field_collection($variables, $fieldName); //n.b $variables passed by reference

    if ($variables['element']['#field_name'] == 'field_body_elements') {
      //delta is used to assign odd and even classes used for left/right layout
      //we want to ensure that we always restart on even after a wide element
      $newDelta = 0;
      foreach($variables['rows'] as &$row) {
        $row['#delta'] = $newDelta;
        $newDelta++;
        //to ensure we always have unique delta we test with modulus and double increment rather than simply resetting
        if ($row['field_element_wide']['#raw'] && $newDelta % 2){
          $newDelta++;
        }
      }
    }

    if ($variables['element']['#field_name'] == 'field_whatson_event') {
      foreach($variables['rows'] as $rowInx => &$row) {
        //if a text override is available then display it in place of the auto formatted dates
        if (isset($row['field_event_date_override']['#raw']) && trim($row['field_event_date_override']['#raw'])!='') {
          $row['display_date'] = $row['field_event_date_override']['#render'];
        } else {
          $row['display_date'] = $row['field_event_dates']['#render'];
        }

        //if the current date is after the end date of the event then suppress from display
        /* remove this functionality for now -- may be re-enabled on request at some later date
        if ($row['field_event_dates']['#raw']['value2'] + (60*60*24) < time()) { // + 24 hours in seconds as stored date is from 00:00 hours and we want to ensure display on the closing day of the event
          unset ($variables['rows'][$rowInx]);  //n.b use of unset within foreach loop, even when passed by reference appears to be safe
        }
        */
      }
    }

  }

  // Identify if the field belongs to a blog tag taxonomy term
  if ($variables['element']['#field_name'] == 'field_news_tags') {

    // Add a relevant class.
    $variables['classes_array'][] = 'blog-tags';

    // Return to speed things up
    return;
  }

  $homepage_field_collections = array(
    'field_home_slideshow',
    'field_home_primary_features',
    'field_home_secondary_features'
  );

  if (in_array($field_name, $homepage_field_collections)) {
    $variables['element']['#prefix'] = '';
    $variables['element']['#suffix'] = '';
    return;
  }

  $homepage_linked_fields = array(
    'field_home_feature_title',
    'field_home_feature_thumbnail',
  );

  if (in_array($field_name, $homepage_linked_fields)) {
    $entity_wrapper = entity_metadata_wrapper($variables['element']['#entity_type'], $variables['element']['#object']);
    $link = $entity_wrapper->field_home_feature_link->value();
    $variables['link_url'] = $link['url'];
    return;
  }

}

/**
* Implements theme_field
* Override output of field_element_text_title to wrap in h2
*/
function qma_field__field_element_text_title($variables) {
  $output = '';
  foreach ($variables['items'] as $delta => $item) {
    $output .= '<h2>' . drupal_render($item) . '</h2>';
  }
  return $output;
}


/**
* Implements theme_field
* Override default output of taxonomy terms so that we can link to prefiltered view rather than default taxonomy page
*/
function qma_field__field_project_sample_tags($variables) {
  $output = '';
  $query = new EntityFieldQuery();

  // This assumes there will only be a single hub for each language.
  $query->entityCondition('entity_type', 'node')
    ->propertyCondition('language', $variables['element']['#object']->language)
    ->propertyCondition('type', 'areas_hub')
    ->propertyCondition('status', 1)
    ->range(0, 1);

  $result = $query->execute();

  if (!empty($result['node'])) {
    $hub_node = array_shift($result['node']);
    $link_nid = $hub_node->nid;
  } else {
    $link_nid = NULL;
  }

  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';

  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . l(drupal_render($item),'node/'.$link_nid, array('query' => array('tagid' => $variables['element']['#items'][$delta]['tid']))) . '</div>';
  }

  $output .= '</div>';

  return $output;
}

/**
* Implements theme_field
* Override default output of taxonomy terms so that we can link to prefiltered view rather than default taxonomy page
*/
function qma_field__field_press_news_type($variables) {

  $query = new EntityFieldQuery();

  // This assumes there will only be a single hub for each language.
  $query->entityCondition('entity_type', 'node')
    ->propertyCondition('language', $variables['element']['#object']->language)
    ->propertyCondition('type', 'press_room')
    ->propertyCondition('status', 1)
    ->range(0, 1);

  $result = $query->execute();

  if (!empty($result['node'])) {
    $hub_node = array_shift($result['node']);
    $link_nid = $hub_node->nid;
  } else {
    $link_nid = NULL;
  }

  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>';
    $output .=  ($link_nid ? l(drupal_render($item),'node/'.$link_nid, array('query' => array('typeid' => $variables['element']['#items'][$delta]['tid']))) : drupal_render($item));
    $output .=  '</div>';
  }
  $output .= '</div>';

  return $output;
}

/**
* Implements theme_field
* Override default output of taxonomy terms so that we can link to prefiltered view rather than default taxonomy page
*/
function qma_field__field_press_tags($variables) {

  $query = new EntityFieldQuery();

  // This assumes there will only be a single hub for each language.
  $query->entityCondition('entity_type', 'node')
    ->propertyCondition('language', $variables['element']['#object']->language)
    ->propertyCondition('type', 'press_room')
    ->propertyCondition('status', 1)
    ->range(0, 1);

  $result = $query->execute();

  if (!empty($result['node'])) {
    $hub_node = array_shift($result['node']);
    $link_nid = $hub_node->nid;
  } else {
    $link_nid = NULL;
  }

  $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
  foreach ($variables['items'] as $delta => $item) {
    $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
    $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>';
    $output .=  ($link_nid ? l(drupal_render($item),'node/'.$link_nid, array('query' => array('tagid' => $variables['element']['#items'][$delta]['tid']))) : drupal_render($item));
    $output .=  '</div>';
  }
  $output .= '</div>';

  return $output;
}


/**
* Implements theme_views_view_field
* Override default output of taxonomy terms so that we can link to prefiltered view rather than default taxonomy page
*/
function qma_views_view_field__field_press_news_type($variables) {
  $output .= '<div class="item-list"' . $variables['content_attributes'] . '><ul>';
  foreach ($variables['row']->field_field_press_news_type as $delta => $item) {
    $output .= '<li>' . l($item['rendered']['#title'],current_path(), array('query' => array('typeid' => $item['raw']['tid']))) . '</li>';
  }
  $output .= '</ul></div>';

  return $output;
}

/**
* Implements theme_views_view_field
* Override default output of taxonomy terms so that we can link to prefiltered view rather than default taxonomy page
*/
function qma_views_view_field__field_press_tags($variables) {
  $output .= '<div class="item-list"' . $variables['content_attributes'] . '><ul>';
  foreach ($variables['row']->field_field_press_tags as $delta => $item) {
    $output .= '<li>' . l($item['rendered']['#title'],current_path(), array('query' => array('tagid' => $item['raw']['tid']))) . '</li>';
  }
  $output .= '</ul></div>';

  return $output;
}


/**
* Implements theme_views_view_field
* Override default output of taxonomy terms so that we can link to prefiltered view rather than default taxonomy page
*/
function qma_views_view_field__field_resource_tags($variables) {
  $output .= '<div class="item-list"' . $variables['content_attributes'] . '><ul>';
  $displayStr = (isset($_REQUEST['display']) ? $_REQUEST['display'] : 'list');
  foreach ($variables['row']->field_field_resource_tags as $delta => $item) {
    $output .= '<li>' . l($item['rendered']['#title'],current_path(), array('query' => array('tagid' => $item['raw']['tid'], 'display' =>$displayStr))) . '</li>';
  }
  $output .= '</ul></div>';

  return $output;
}

/**
* Implements theme_views_view_field
* Override default link output so we can use custom text
*/
function qma_views_view_field__field_resource_website_url($variables) {
  if ($variables['output']) {
    return l(t('View website', array(), array('context' => 'QMA')), $variables['output']);
  } else {
    return '';
  }
}

/**
* Implements theme_field
* Override default link output so we can use custom text
*/
function qma_field__field_resource_website_url($variables) {
  return l(t('View website', array(), array('context' => 'QMA')), $variables['items'][0]['#element']['display_url']);
}


function qma_textarea($element) {
  $element['element']['#resizable'] = false ;
  return theme_textarea($element) ;
}



/**
 * Creates a simple text rows array from a field collections, to be used in a
 * field_preprocess function.
 * Code adapted from http://fourkitchens.com/blog/2013/06/03/better-way-theme-field-collections
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 *
 * @param $field_name
 *   The name of the field being altered.
 *
 * @param $field_array_additions
 *   The function will automatically pick up any fields with a machine name prefixed "field_"
 *   field_array_additions is an optional array of field names with non-standard prefix.
 *
 * @param $view_mode, the view mode who's settings should be used to render the fields (e.g full or teaser)
 */

function rows_from_field_collection(&$vars, $field_name, $field_array_additions = array(), $view_mode='full') {
  $vars['rows'] = array();

  foreach($vars['element']['#items'] as $key => $item) {
    $entity = entity_revision_load('field_collection_item', $item['revision_id']);
    $entityWrapper = entity_metadata_wrapper('field_collection_item', $entity);

    //build list of available fields, n.b assumes all entity properties prefixed "field_" are of field type
    $field_array = array();

    foreach (get_object_vars($entity) as $propertyKey => $propertyVal) {
      if (substr($propertyKey, 0, 6) === 'field_') {
        $field_array[] = $propertyKey;
      }
    }

    $field_array = array_merge($field_array, $field_array_additions);
    $row = array();

    foreach ($field_array as $field){
      $field_collection = field_view_field('field_collection_item', $entity, $field, $view_mode);
      $row[$field]['#render'] = render($field_collection);
      $row[$field]['#raw'] = $entityWrapper->$field->raw();
    }

    $row['#delta'] = $key;
    $vars['rows'][] = $row;
  }
}

function qma_breadcrumb($variables) {
  $output = '';
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {

    array_shift($breadcrumb); //remove link to home from begining of array

    if (!empty($breadcrumb)) {
      $output .= '<div class="breadcrumb"><div class="container"><ul><li class="first"><span>'.t('You are in:', array(), array('context' => 'QMA')).'</span></li><li>' . implode('</li><li>', $breadcrumb) .'</li></ul></div></div>';
    }
    return $output;
  }
}

function qma_file_link($variables) {
  $file = $variables['file'];
  $icon_directory = $variables['icon_directory'];

  $url = file_create_url($file->uri);
  $icon = theme('file_icon', array('file' => $file, 'icon_directory' => $icon_directory));

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
    ),
  );

  // Use the Mimetype as the link text if available.
  $link_text = strtoupper(str_replace('application/', '', $file->filemime));
  $file_size = format_size($file->filesize);

  return '<div class="file">' . l($link_text, $url, $options) . '<span class="filesize">' .strval($file_size). '</span></div>';
}


/**
 * Implementation of theme_date_display_range()
 * Returns HTML for a date element formatted as a range.
 * Overridden here purely to allow us to change the seperator from 'to' to '-'
 */
function QMA_date_display_range($variables) {
  $date1 = $variables['date1'];
  $date2 = $variables['date2'];
  $timezone = $variables['timezone'];
  $attributes_start = $variables['attributes_start'];
  $attributes_end = $variables['attributes_end'];

  $start_date = '<span class="date-display-start"' . drupal_attributes($attributes_start) . '>' . $date1 . '</span>';
  $end_date = '<span class="date-display-end"' . drupal_attributes($attributes_end) . '>' . $date2 . $timezone . '</span>';

  // If microdata attributes for the start date property have been passed in,
  // add the microdata in meta tags.
  if (!empty($variables['add_microdata'])) {
    $start_date .= '<meta' . drupal_attributes($variables['microdata']['value']['#attributes']) . '/>';
    $end_date .= '<meta' . drupal_attributes($variables['microdata']['value2']['#attributes']) . '/>';
  }

  // Wrap the result with the attributes.
  return t('!start-date - !end-date', array(
    '!start-date' => $start_date,
    '!end-date' => $end_date,
  ), array('context' => 'QMA'));
}

/**
 * Supplied with a non english node, get its title and translate it so we can
 * use the english version of the title as a classname
 *
 * @param $node
 *   The node containing the title we want to translate
 **/

function get_translated_title($node) {

    if($node->language !='en') { //for non english nodes we need to grab the title of their english translation to match the css correctly
      $translationSetArr=translation_node_get_translations($node->tnid);
      $nodeTitle = (isset($translationSetArr['en']->title)?$translationSetArr['en']->title:$node->title);
    } else {
      $nodeTitle = $node->title;
    }

    return strtolower(str_replace('&', '', str_replace(' ', '-', $nodeTitle)));

}

/**
 * Internal function to retrieve the instagram account filter field from a node.
 *
 * @return A non-empty account name string or NULL.
 */
function _qma_get_instagram_account_filter($node) {
  $instagram_account = NULL;
  $node_wrapper = entity_metadata_wrapper('node', $node);

  if (isset($node_wrapper->field_instagram_account_name)) {
    $instagram_account = trim($node_wrapper->field_instagram_account_name->value());
  }

  // Empty strings break the contextual filter, so either return
  return empty($instagram_account) ? NULL : $instagram_account;
}

/**
 * Internal function to retrieve the twitter account filter field from a node.
 *
 * @return A formatted views context argument.
 */
function _qma_get_twitter_account_filter($node) {
  $returnArr = array();
  $node_wrapper = entity_metadata_wrapper('node', $node);

  if (isset($node_wrapper->field_twitter_account)) {
    foreach ($node_wrapper->field_twitter_account->value() as $twAccArr) {
      $returnArr[] = $twAccArr;
    }
  }

  // Empty strings break the contextual filter
  // multivalued field, concatonate together with + to act as OR operator
  return count($returnArr) ? implode('+', $returnArr) : NULL;
}


/**
 * Internal function to retrieve the twitter tag filter field from a node.
 *
 * @return A formatted views context argument.
 */
function _qma_get_twitter_tag_filter($node) {
  $returnArr = array();
  $node_wrapper = entity_metadata_wrapper('node', $node);

  if (isset($node_wrapper->field_twitter_hashtag)) {
    foreach ($node_wrapper->field_twitter_hashtag->value() as $twHashArr) {
      $returnArr[] = $twHashArr;
    }
  }
  // This option is intended to filter down results so return all if not supplied to ignore filter
  // multivalued field, concatonate together with + to act as OR operator
  return count($returnArr) ? implode('+', $returnArr) : 'all';
}

/**
 * Education related.
 */

/**
 * Delegated node preprocess function for education resource.
 */
function qma_preprocess_node_education_resource(&$variables) {
  $node = $variables['node'];

  if ($variables['view_mode'] === 'full') {
    $variables['education_hub'] = '';
    $query = new EntityFieldQuery();

    //This assumes there will only be using a single hub for each language
    $query->entityCondition('entity_type', 'node')
      ->propertyCondition('language', $variables['node']->language)
      ->propertyCondition('type', 'education_resource_hub')
      ->propertyCondition('status', 1)
      ->range(0, 1);

    $result = $query->execute();

    if (!empty($result['node'])) {
      $hub = array_shift($result['node']);
      $variables['education_hub'] = l(t('See all education resources', array(), array('context' => 'QMA')), 'node/' . $hub->nid);
    }
  }
}

/**
 * Delegated node preprocess function for homepage.
 */
function qma_preprocess_node_qma_homepage(&$variables) {
  drupal_add_css(libraries_get_path('slick-carousel') . '/slick/slick.css');
  drupal_add_js(libraries_get_path('slick-carousel') . '/slick/slick.js');
  drupal_add_js(drupal_get_path('theme', 'qma') . '/js/home-behaviors.js');

  $variables['content']['field_home_slideshow']['#prefix'] = '';
  $variables['content']['field_home_slideshow']['#suffix'] = '';

  $variables['slideshow_next_text'] = t('Next slide', array(), array('context' => 'QMA'));
  $variables['slideshow_prev_text'] = t('Previous slide', array(), array('context' => 'QMA'));
}

/**
 * Delegated node preprocess function for education resource hub.
 */
function qma_preprocess_node_education_resource_hub(&$variables) {
  $node = $variables['node'];
  $view_mode = $variables['view_mode'];

  if ($view_mode === 'full') {
    $variables['content']['resource_list']['#markup'] = views_embed_view('qma_edu_resource_listings', 'block_2', $arg);
  }
}

/**
 * Delegated node preprocess function for education institution.
 */
function qma_preprocess_node_education_institution(&$variables) {
  $node = $variables['node'];
  $nid = $node->nid;
  $view_mode = $variables['view_mode'];

  if ($view_mode === 'full') {
    // Create the view, select appropriate display and set filters
    $calendar = views_get_view('qma_edu_repeat_calendar');
    $calendar->set_display();

    global $language_content;

    // Only apply the filter if the language of the node matches the current
    // content language and is published, otherwise the filter will throw an error.
    if ((int) $node->status === 1 && $node->language === $language_content->language) {
      // Create exposed filters array, we include only those filters we care about
      $filters = array(
        'field_eduprog_institution_target_id' => (isset($nid) ? $nid : 'All'),
      );

      $calendar->set_exposed_input($filters);
    }

    // Build the view result and include it in #markup of
    $variables['content']['calendar']['#markup'] = $calendar->preview('block_3', array($node->language));
  }
}
/**
 * Delegated node preprocess function for event and exhibition hub page .
 */
function qma_preprocess_node_event_hub(&$variables) {
  $node = $variables['node'];
  $nid = $node->nid;
  $view_mode = $variables['view_mode'];

  if ($view_mode === 'full') {
    // Create the view, select appropriate display and set filters
    $event_grid = views_get_view('event_grid_view');
    $event_grid->set_display();

    //global $language_content;

    // Only apply the filter if the language of the node matches the current
    // content language and is published, otherwise the filter will throw an error.
   // if ((int) $node->status === 1 && $node->language === $language_content->language) {
      // Create exposed filters array, we include only those filters we care about
     // $filters = array(
        //'include_exhibition' => (isset($nid) ? $nid : 'All'),
      //);

      //$calendar->set_exposed_input($filters);
    //}

    // Build the view result and include it in #markup of
    $variables['content']['event_grid']['#markup'] = $event_grid->preview('block_4', array($node->language));
  }
}
/**function qma_preprocess_node_event_hub(&$variables) {
  $node = $variables['node'];
  $view_mode = $variables['view_mode'];

  switch ($view_mode) {
    case 'full':
      //$variables['listing_title'] = t('Discover more about Education', array(), array('context' => 'QMA'));
      $variables['content']['event_grid']['#markup'] = views_embed_view('event_grid_view', 'block_4', $node->language);
      break;
  }
}
/**
 * Delegated node preprocess function for education hub.
 */
function qma_preprocess_node_education_hub(&$variables) {
  $node = $variables['node'];
  $view_mode = $variables['view_mode'];

  switch ($view_mode) {
    case 'full':
      $variables['listing_title'] = t('Discover more about Education', array(), array('context' => 'QMA'));
      $variables['content']['calendar']['#markup'] = views_embed_view('qma_edu_repeat_calendar', 'block_3', $node->language);
      break;
  }
}

/**
 * Delegated node preprocess function for education programme.
 */
function qma_preprocess_node_education_prog(&$variables) {
  $node = $variables['node'];
  $view_mode = $variables['view_mode'];

  switch ($view_mode) {
    case 'full':
      // Make sure the map view isn't included in other view modes to prevent recursion.
      $variables['content']['map']['#markup'] = views_embed_view('education_programme_map', 'map_block', $node->language, $node->nid);
      $variables['content']['resource_list']['#markup'] = views_embed_view('qma_edu_resource_listings', 'block_1', $node->language);

      $institution = $variables['content']['field_eduprog_institution'][0]['#markup'];
      $variables['content']['intro_institution'] = t('Part of the !institution', array('!institution' => $institution), array('context' => 'QMA'));
      break;
    case 'gmaps_popup':
      if (count($node->location)) {
        $params = array(
          'location' => $node->location,
          'hide' => array(
            'latitude',
            'longitude',
          ),
        );

        $variables['content']['address'] = theme('location', $params);
      }
      break;
    case 'full_width_teaser':
      $link_text = t('View @title', array('@title' => $node->title), array('context' => 'QMA'));
      $variables['links']['more_link'] = l($link_text, 'node/' . $node->nid);
      break;
  }
}
/**
 * Delegated node preprocess function for education programme.
 */
function qma_preprocess_node_event(&$variables) {
  $node = $variables['node'];
  $view_mode = $variables['view_mode'];

  switch ($view_mode) {
    case 'full':
      // Make sure the map view isn't included in other view modes to prevent recursion.
      $variables['content']['map']['#markup'] = views_embed_view('education_programme_map', 'map_block', $node->language, $node->nid);
      $variables['content']['resource_list']['#markup'] = views_embed_view('qma_edu_resource_listings', 'block_1', $node->language);

      $institution = $variables['content']['field_eduprog_institution'][0]['#markup'];
      $variables['content']['intro_institution'] = t('Part of the !institution', array('!institution' => $institution), array('context' => 'QMA'));
        
      /*$variables['content']['intro_institution'] = t('Part of the !institution', array('!institution' => $institution), array('context' => 'QMA'));
      /*$institution = $variables['content']['field_eduprog_institution'][0]['#markup'];
      $variables['content']['intro_institution'] = t('Part of the !institution', array('!institution' => $institution), array('context' => 'QMA'));
      $variables['content']['teasers_subtitle'] = array(
          '#prefix' => '<h2>',
          '#markup' => t('Dive into @num blog articles', array('@num' => $total_blogs), array('context' => 'QMA')),
          '#suffix' => '</h2>',
        );
        */
        $variables['event_hub_link'] = '';

    if (!empty($result['node'])) {
      $nids = array_keys($result['node']);
      $text = '<span>' . t('All Events', array(), array('context' => 'QMA')) . '</span>';
      $path = 'node/' . $nids[0];

      $attributes = array(
        'html'=> TRUE,
        'attributes' => array(
          'class' => array('back-to-parent'),
        ),
      );

      // Create back link at top of page.
      $variables['event_hub_link'] = l($text, $path, $attributes);
    }

      break;
    case 'gmaps_popup':
      if (count($node->location)) {
        $params = array(
          'location' => $node->location,
          'hide' => array(
            'latitude',
            'longitude',
          ),
        );

        $variables['content']['address'] = theme('location', $params);
      }
      break;
    case 'full_width_teaser':
      $link_text = t('View @title', array('@title' => $node->title), array('context' => 'QMA'));
      $variables['links']['more_link'] = l($link_text, 'node/' . $node->nid);
      break;
  }
}
/**
 * Implements theme_field().
 *
 * Override default link output so we can use custom text
 */
function qma_field__field_eduprog_institution($variables) {
  $output = array_shift($variables['items']);
  return $output['#markup'];
}

/**
 * Commenting system overrides.
 */

/**
 * Implements hook_FORM_ID_alter().
 */
function qma_form_comment_node_news_article_form_alter(&$form, &$form_state, $form_id) {

  // Add opt in membership checkbox for anonymous users.
  if (!user_is_logged_in()) {

    $form['membership'] = array(
      '#type' => 'checkbox',
      '#title' => t('I would like to receive more information about Qatar Museums', array(), array('context'=>'QMA')),
      '#default_value' => 0,
    );

    // Add the extra text string
    $form['review_text'] = array(
      '#type' => 'markup',
      '#markup' => t('Please note that when you submit a comment it will be reviewed before it is added to this article.', array(), array('context'=>'QMA')),
      '#prefix' => '<p class="review-text">',
      '#suffix' => '</p>',
    );

    // Update the form label strings
    $form['author']['name']['#title'] = t('My name is', array(), array('context'=>'QMA'));
    $form['author']['mail']['#title'] = t('My email is', array(), array('context'=>'QMA'));
    $comment_body_language = $form['comment_body']['#language'];
    $form['comment_body'][$comment_body_language][0]['#title'] = t('Your comment', array(), array('context'=>'QMA'));

    // Add custom submit handler.
    $form['#submit'][] = 'qma_comment_form_membership_submit';

  }



  // Add protection with honeypot module
  honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));

  // Hide homepage input field.
  $form['author']['homepage']['#access'] = false;

  // Hide preview button
  $form['actions']['preview']['#access'] = false;

  // Set the text for the submit button
  $form['actions']['submit']['#value'] = 'Add your comment';

  // Create left column div and elements within it
  $form['fields_left_col'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('fields-left-col')),
    'comment_body' => $form['comment_body'],
    'membership' => $form['membership']
  );

  // Create right column div and elements within it
  $form['fields_right_col'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('fields-right-col')),
    'author' => $form['author'],
    'subject' => $form['subject'],
    'review_text' => $form['review_text'],
    'actions' => $form['actions'],
  );

  // Create wrapper div and place left and right column divs within it
  $form['field_wrappers_col'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('field-wrappers-col')),
    'field_left_col' => $form['fields_left_col'],
    'field_right_col' => $form['fields_right_col'],
  );

  // If form elements are not hided here they will be rendered twice;
  // once on their own and then again when $form['field_wrappers_col'] is
  // rendered.
  hide($form['fields_left_col']);
  hide($form['fields_right_col']);
  hide($form['actions']);
  hide($form['author']);
  hide($form['membership']);
  hide($form['subject']);
  hide($form['comment_body']);
  hide($form['review_text']);

}

/**
 * Custom comment form submit handler to handle membership checkbox.
 */
function qma_comment_form_membership_submit($form, &$form_state) {

  // If checkbox is checked
  if ($form_state['values']['membership']) {

    // Set some variables.
    global $language;
    $to = $form_state['values']['mail'];
    $from = '"' . t('Qatar Museums', array(), array('context' => 'QMA')) . '" <' . variable_get('smtp_from') .'>';

    // Set email subject and body.
    $params = array();
    $params['subject'] = t('Culture Pass, our free membership programme', array(), array('context' => 'QMA'));
    $params['body'][] = t('Hello,', array(), array('context' => 'QMA'));
    $params['body'][] = t('Thank you for your comment. ', array(), array('context' => 'QMA'));
    $params['body'][] = t('If you have already registered for Culture Pass, our free membership programme, you\'ll know that it draws together the wealth of experiences we offer in our museums and across the city. We invite everyone in Qatar to participate in arts, culture and heritage, and to get creative themselves.', array(), array('context' => 'QMA'));
    $params['body'][] = t('Not a member? Sign up today and download your digital membership card online! Visit www.qm.org.qa/culturepass', array(), array('context' => 'QMA'));
    $params['body'][] = t('Best wishes,', array(), array('context' => 'QMA'));
    $params['body'][] = t('Qatar Museums', array(), array('context' => 'QMA'));

    // Send the email.
    $message = drupal_mail('qma_news', 'membership_checkbox', $to, $language, $params, $from);

  }

}

/**
 * Comment preprocess function.
 */
function qma_preprocess_comment(&$variables) {
  // Get the comment and am entity metadata wrapper on it to simplify life.
  $comment = $variables['comment'];
  $comment_wrapper = entity_metadata_wrapper('comment', $comment);

  // If anonymous user use what she posted.
  if ($comment->uid === '0') {
    $name  = '<span class="user-name">';
    $name .= check_plain($comment->name);
    $name .= '</span>';
  }
  else {
    // Get first name and last name of author.
    $firstname = check_plain($comment_wrapper->author->field_first_name->value());
    $lastname  = check_plain($comment_wrapper->author->field_last_name->value());

    // Create a string with authors full name.
    $name  = '<span class="user-name">';
    $name .= $firstname . ' ' . $lastname;
    $name .= '</span>';
  }

  // Override linked username with just the name of the author.
  $variables['submitted'] = t('!username on !datetime', array('!username' => $name, '!datetime' => $variables['created']));

}

/**
 * Comment wrapper preprocess
 */
function qma_preprocess_comment_wrapper(&$variables) {
  $node = $variables['node'];
  $comment_count = $node->comment_count;

  // If there are comments then add a smaller header next to them saying how many are there
  if($comment_count) {

    // If there are comments then add a string with the number of comments to appear adjacent in the template
    if(intval($comment_count) > 0) {
      $comment_sub_title = t('Comments (@comment_count)', array('@comment_count' => $comment_count));
    }

    $variables['comment_sub_title'] = array(
      '#type' => 'markup',
      '#markup' => $comment_sub_title,
    );

  } else {
    // There are no comments so add a class to help switch the styling
    array_push($variables['classes_array'], 'no-comments');
  }
}

