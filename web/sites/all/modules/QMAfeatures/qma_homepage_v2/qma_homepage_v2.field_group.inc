<?php
/**
 * @file
 * qma_homepage_v2.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function qma_homepage_v2_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaser|node|qma_homepage|form';
  $field_group->group_name = 'group_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'qma_homepage';
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
      'label' => 'Teaser',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-teaser field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_teaser|node|qma_homepage|form'] = $field_group;

  return $export;
}
