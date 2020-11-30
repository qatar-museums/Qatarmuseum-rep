<?php
/**
 * @file
 * qma_area_of_work.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function qma_area_of_work_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_area_tags|node|area_of_work|form';
  $field_group->group_name = 'group_area_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area_of_work';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Area Tags',
    'weight' => '4',
    'children' => array(
      0 => 'field_project_sample_tags',
      1 => 'field_prominence',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-area-tags field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_area_tags|node|area_of_work|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_area_teaser|node|area_of_work|form';
  $field_group->group_name = 'group_area_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area_of_work';
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
        'description' => 'Teaser text and image do not appear on the content page itself. They are used when this item of content is referenced on other pages, particularly hub pages. In this instance, the teaser text and image appear on the Experience hub page.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_area_teaser|node|area_of_work|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_instagram_filter|node|area_of_work|form';
  $field_group->group_name = 'group_instagram_filter';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area_of_work';
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
  $export['group_instagram_filter|node|area_of_work|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_twitter_feed|node|programme|form';
  $field_group->group_name = 'group_twitter_feed';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'area_of_work';
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
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_twitter_feed|node|programme|form'] = $field_group;

  return $export;
}
