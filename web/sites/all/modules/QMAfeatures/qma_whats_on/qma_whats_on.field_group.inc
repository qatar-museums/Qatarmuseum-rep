<?php
/**
 * @file
 * qma_whats_on.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function qma_whats_on_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_details|field_collection_item|field_whatson_event|form';
  $field_group->group_name = 'group_event_details';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_whatson_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event Details',
    'weight' => '1',
    'children' => array(
      0 => 'field_event_image',
      1 => 'field_event_description',
      2 => 'field_event_location',
      3 => 'field_event_dates',
      4 => 'field_event_date_override',
      5 => 'field_event_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Event Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-event-details field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_event_details|field_collection_item|field_whatson_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaser|node|whats_on|form';
  $field_group->group_name = 'group_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'whats_on';
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
  $export['group_teaser|node|whats_on|form'] = $field_group;

  return $export;
}
