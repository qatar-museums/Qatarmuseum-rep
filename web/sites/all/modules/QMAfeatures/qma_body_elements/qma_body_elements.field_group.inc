<?php
/**
 * @file
 * qma_body_elements.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function qma_body_elements_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_element_image|field_collection_item|field_body_elements|form';
  $field_group->group_name = 'group_element_image';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_body_elements';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_element_wrapper';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '4',
    'children' => array(
      0 => 'field_element_image',
      1 => 'field_element_image_caption',
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
  $export['group_element_image|field_collection_item|field_body_elements|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_element_pquote_wrapper|field_collection_item|field_body_elements|form';
  $field_group->group_name = 'group_element_pquote_wrapper';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_body_elements';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '4',
    'children' => array(
      0 => 'group_element_pull_quote',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-element-pquote-wrapper field-group-accordion',
      ),
    ),
  );
  $export['group_element_pquote_wrapper|field_collection_item|field_body_elements|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_element_pull_quote|field_collection_item|field_body_elements|form';
  $field_group->group_name = 'group_element_pull_quote';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_body_elements';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_element_pquote_wrapper';
  $field_group->data = array(
    'label' => 'Pull quote',
    'weight' => '5',
    'children' => array(
      0 => 'field_element_pull_quote',
      1 => 'field_element_pull_quote_name',
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
  $export['group_element_pull_quote|field_collection_item|field_body_elements|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_element_uquote_wrapper|field_collection_item|field_body_elements|form';
  $field_group->group_name = 'group_element_uquote_wrapper';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_body_elements';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '3',
    'children' => array(
      0 => 'group_element_user_quote',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-element-uquote-wrapper field-group-accordion',
      ),
    ),
  );
  $export['group_element_uquote_wrapper|field_collection_item|field_body_elements|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_element_user_quote|field_collection_item|field_body_elements|form';
  $field_group->group_name = 'group_element_user_quote';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_body_elements';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_element_uquote_wrapper';
  $field_group->data = array(
    'label' => 'User quote',
    'weight' => '5',
    'children' => array(
      0 => 'field_element_user_quote',
      1 => 'field_element_user_quote_name',
      2 => 'field_element_user_quote_wide',
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
  $export['group_element_user_quote|field_collection_item|field_body_elements|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_element_video_wrapper|field_collection_item|field_body_elements|form';
  $field_group->group_name = 'group_element_video_wrapper';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_body_elements';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '2',
    'children' => array(
      0 => 'group_video_element',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => '',
      ),
    ),
  );
  $export['group_element_video_wrapper|field_collection_item|field_body_elements|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_element_wrapper|field_collection_item|field_body_elements|form';
  $field_group->group_name = 'group_element_wrapper';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_body_elements';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '1',
    'children' => array(
      0 => 'group_text_element',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => '',
      ),
    ),
  );
  $export['group_element_wrapper|field_collection_item|field_body_elements|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pull_quote|field_collection_item|field_body_elements|default';
  $field_group->group_name = 'group_pull_quote';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_body_elements';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pull quote group',
    'weight' => '5',
    'children' => array(
      0 => 'field_element_pull_quote',
      1 => 'field_element_pull_quote_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Pull quote group',
      'instance_settings' => array(
        'classes' => 'group-pull-quote',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_pull_quote|field_collection_item|field_body_elements|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_text_element|field_collection_item|field_body_elements|form';
  $field_group->group_name = 'group_text_element';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_body_elements';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_element_wrapper';
  $field_group->data = array(
    'label' => 'Text and image element',
    'weight' => '2',
    'children' => array(
      0 => 'field_element_text_area',
      1 => 'field_element_image',
      2 => 'field_element_image_caption',
      3 => 'field_element_text_title',
      4 => 'field_element_wide',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Text and image element',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_text_element|field_collection_item|field_body_elements|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_quote|field_collection_item|field_body_elements|default';
  $field_group->group_name = 'group_user_quote';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_body_elements';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'User quote group',
    'weight' => '6',
    'children' => array(
      0 => 'field_element_user_quote',
      1 => 'field_element_user_quote_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'User quote group',
      'instance_settings' => array(
        'classes' => 'group-user-quote',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_user_quote|field_collection_item|field_body_elements|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_element|field_collection_item|field_body_elements|form';
  $field_group->group_name = 'group_video_element';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_body_elements';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_element_video_wrapper';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '4',
    'children' => array(
      0 => 'field_element_video_url',
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
  $export['group_video_element|field_collection_item|field_body_elements|form'] = $field_group;

  return $export;
}
