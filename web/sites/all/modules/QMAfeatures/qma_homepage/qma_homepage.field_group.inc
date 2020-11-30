<?php
/**
 * @file
 * qma_homepage.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function qma_homepage_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home_box_outer_wrapper_1|field_collection_item|field_homepage_box|form';
  $field_group->group_name = 'group_home_box_outer_wrapper_1';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_homepage_box';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '2',
    'children' => array(
      0 => 'group_home_box_wrapper_1',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-home-box-outer-wrapper-1 field-group-accordion',
      ),
    ),
  );
  $export['group_home_box_outer_wrapper_1|field_collection_item|field_homepage_box|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home_box_outer_wrapper_2|field_collection_item|field_homepage_box|form';
  $field_group->group_name = 'group_home_box_outer_wrapper_2';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_homepage_box';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '3',
    'children' => array(
      0 => 'group_home_box_wrapper_2',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-home-box-outer-wrapper-2 field-group-accordion',
      ),
    ),
  );
  $export['group_home_box_outer_wrapper_2|field_collection_item|field_homepage_box|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home_box_outer_wrapper_3|field_collection_item|field_homepage_box|form';
  $field_group->group_name = 'group_home_box_outer_wrapper_3';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_homepage_box';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '4',
    'children' => array(
      0 => 'group_home_box_wrapper_3',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-home-box-outer-wrapper-3 field-group-accordion',
      ),
    ),
  );
  $export['group_home_box_outer_wrapper_3|field_collection_item|field_homepage_box|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home_box_wrapper_1|field_collection_item|field_homepage_box|form';
  $field_group->group_name = 'group_home_box_wrapper_1';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_homepage_box';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_home_box_outer_wrapper_1';
  $field_group->data = array(
    'label' => 'Option 1',
    'weight' => '8',
    'children' => array(
      0 => 'field_home_box_image_1',
      1 => 'field_home_box_link_1',
      2 => 'field_home_box_text_1',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-home-box-wrapper-1 field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_home_box_wrapper_1|field_collection_item|field_homepage_box|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home_box_wrapper_2|field_collection_item|field_homepage_box|form';
  $field_group->group_name = 'group_home_box_wrapper_2';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_homepage_box';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_home_box_outer_wrapper_2';
  $field_group->data = array(
    'label' => 'Option 2',
    'weight' => '4',
    'children' => array(
      0 => 'field_home_box_link_2',
      1 => 'field_home_box_image_2',
      2 => 'field_home_box_text_2',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_home_box_wrapper_2|field_collection_item|field_homepage_box|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home_box_wrapper_3|field_collection_item|field_homepage_box|form';
  $field_group->group_name = 'group_home_box_wrapper_3';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_homepage_box';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_home_box_outer_wrapper_3';
  $field_group->data = array(
    'label' => 'Option 3',
    'weight' => '17',
    'children' => array(
      0 => 'field_home_box_link_3',
      1 => 'field_home_box_image_3',
      2 => 'field_home_box_text_3',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-home-box-wrapper-3 field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_home_box_wrapper_3|field_collection_item|field_homepage_box|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaser|node|homepage|form';
  $field_group->group_name = 'group_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
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
        'description' => 'Teaser text and image do not appear on the content page itself. They are used when this item of content is referenced on other pages, particularly hub pages. They also control the information displayed when this page is shared via social media or included in search engine results.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_teaser|node|homepage|form'] = $field_group;

  return $export;
}
