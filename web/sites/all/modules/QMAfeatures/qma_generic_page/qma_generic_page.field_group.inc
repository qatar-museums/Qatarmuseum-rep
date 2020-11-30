<?php
/**
 * @file
 * qma_generic_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function qma_generic_page_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_instagram_filter|node|generic_page|form';
  $field_group->group_name = 'group_instagram_filter';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'generic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Instagram filter',
    'weight' => '9',
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
  $export['group_instagram_filter|node|generic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_teaser|node|generic_page|form';
  $field_group->group_name = 'group_page_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'generic_page';
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
        'classes' => 'group-page-teaser field-group-fieldset',
        'description' => 'Teaser text and image do not appear on the content page itself. They are used when this item of content is referenced on other pages, particularly hub pages.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_page_teaser|node|generic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_media_accounts|node|generic_page|form';
  $field_group->group_name = 'group_social_media_accounts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'generic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Media Accounts',
    'weight' => '12',
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
        'description' => 'Entering a social media account here will produce a link <i>to</i> the account\'s page on the relevant social media site.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_social_media_accounts|node|generic_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_twitter_feed|node|generic_page|form';
  $field_group->group_name = 'group_twitter_feed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'generic_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Twitter Feed',
    'weight' => '8',
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
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_twitter_feed|node|generic_page|form'] = $field_group;

  return $export;
}
