<?php
/**
 * @file
 * qma_education_content_types.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function qma_education_content_types_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_eduhub_teaser|node|education_hub|form';
  $field_group->group_name = 'group_eduhub_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'education_hub';
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
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-eduhub-teaser field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_eduhub_teaser|node|education_hub|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_eduinst_instagram|node|education_programme|form';
  $field_group->group_name = 'group_eduinst_instagram';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'education_institution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Instagram Filter',
    'weight' => '8',
    'children' => array(
      0 => 'field_instagram_account_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-eduinst-instagram field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_eduinst_instagram|node|education_programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_eduinst_teaser|node|education_programme|form';
  $field_group->group_name = 'group_eduinst_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'education_institution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaser',
    'weight' => '4',
    'children' => array(
      0 => 'field_teaser_image',
      1 => 'field_teaser_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-eduinst-teaser field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_eduinst_teaser|node|education_programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_eduinst_twitter|node|education_programme|form';
  $field_group->group_name = 'group_eduinst_twitter';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'education_institution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Twitter Feed',
    'weight' => '7',
    'children' => array(
      0 => 'field_twitter_account',
      1 => 'field_twitter_hashtag',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-eduinst-twitter field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_eduinst_twitter|node|education_programme|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_eduprog_teaser|node|education_prog|form';
  $field_group->group_name = 'group_eduprog_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'education_prog';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaser',
    'weight' => '2',
    'children' => array(
      0 => 'field_teaser_image',
      1 => 'field_teaser_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-eduprog-teaser field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_eduprog_teaser|node|education_prog|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_teaser|node|education_resource_hub|form';
  $field_group->group_name = 'group_page_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'education_resource_hub';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaser',
    'weight' => '2',
    'children' => array(
      0 => 'field_teaser_image',
      1 => 'field_teaser_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-teaser field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_page_teaser|node|education_resource_hub|form'] = $field_group;

  return $export;
}
