<?php
/**
 * @file
 * qma_creative_resources.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function qma_creative_resources_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_resource_featured|node|creative_resource|form';
  $field_group->group_name = 'group_resource_featured';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'creative_resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Featured Resource',
    'weight' => '6',
    'children' => array(
      0 => 'field_resource_image',
      1 => 'field_resource_long_description',
      2 => 'field_element_user_quote',
      3 => 'field_element_user_quote_name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Featured Resource',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-resource-featured field-group-fieldset',
        'description' => 'Information in this section will only be displayed if the resource is selected as the featured resource on the Creative Resources page.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_resource_featured|node|creative_resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaser|node|creative_resource_hub|form';
  $field_group->group_name = 'group_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'creative_resource_hub';
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
  $export['group_teaser|node|creative_resource_hub|form'] = $field_group;

  return $export;
}
