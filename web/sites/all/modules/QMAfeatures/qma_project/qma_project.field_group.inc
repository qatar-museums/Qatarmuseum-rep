<?php
/**
 * @file
 * qma_project.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function qma_project_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_instagram_filter|node|project|form';
  $field_group->group_name = 'group_instagram_filter';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Instagram filter',
    'weight' => '10',
    'children' => array(
      0 => 'field_instagram_account_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Instagram filter',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-instagram-filter field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_instagram_filter|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_primary_link|node|project|form';
  $field_group->group_name = 'group_project_primary_link';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Primary Link',
    'weight' => '15',
    'children' => array(
      0 => 'field_project_primary_link',
      1 => 'field_project_primary_link_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Primary Link',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-project-primary-link field-group-fieldset',
        'description' => 'For linking to the official web presence of the project',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_project_primary_link|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_tags|node|project|form';
  $field_group->group_name = 'group_project_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project Tags',
    'weight' => '4',
    'children' => array(
      0 => 'field_project_sample_tags',
      1 => 'field_highlight_flag',
      2 => 'field_project_macro_loc',
      3 => 'field_project_open_to_public',
      4 => 'field_project_status',
      5 => 'field_area_of_work',
      6 => 'field_prominence',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_project_tags|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_project_teaser|node|project|form';
  $field_group->group_name = 'group_project_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaser',
    'weight' => '3',
    'children' => array(
      0 => 'field_teaser_image',
      1 => 'field_teaser_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Teaser',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-teaser field-group-fieldset',
        'description' => 'Teaser text and image do not appear on the content page itself. They are used when this item of content is referenced on other pages, particularly hub pages.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_project_teaser|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_media_accounts|node|project|form';
  $field_group->group_name = 'group_social_media_accounts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Media Accounts',
    'weight' => '16',
    'children' => array(
      0 => 'field_facebook_page',
      1 => 'field_instagram_account_link',
      2 => 'field_twitter_account_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Social Media Accounts',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-social-media-accounts field-group-fieldset',
        'description' => 'Entering an account here will produce a link <em>to</em> the account\'s page on the relevant social media site.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_social_media_accounts|node|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_twitter_feed|node|project|form';
  $field_group->group_name = 'group_twitter_feed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Twitter Feed',
    'weight' => '9',
    'children' => array(
      0 => 'field_twitter_account',
      1 => 'field_twitter_hashtag',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Twitter Feed',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-twitter-feed field-group-fieldset',
        'description' => 'Enter details here to add a twitter feed to the page',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_twitter_feed|node|project|form'] = $field_group;

  return $export;
}
