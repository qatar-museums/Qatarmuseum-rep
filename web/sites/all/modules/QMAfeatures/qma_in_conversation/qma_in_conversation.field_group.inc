<?php
/**
 * @file
 * qma_in_conversation.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function qma_in_conversation_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_conversation_outro|node|interview_hub|form';
  $field_group->group_name = 'group_conversation_outro';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'interview_hub';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Don\'t miss a word',
    'weight' => '6',
    'children' => array(
      0 => 'field_conversation_outro_col_1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-conversation-outro field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_conversation_outro|node|interview_hub|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interview_hub_teaser|node|interview_hub|form';
  $field_group->group_name = 'group_interview_hub_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'interview_hub';
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
        'description' => 'Teaser text and image do not appear on the content page itself. They are used when this item of content is referenced on other pages, particularly hub pages.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_interview_hub_teaser|node|interview_hub|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interview_image|field_collection_item|field_interview_question_answer|form';
  $field_group->group_name = 'group_interview_image';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_interview_question_answer';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_interview_wrapper';
  $field_group->data = array(
    'label' => 'Add Image',
    'weight' => '8',
    'children' => array(
      0 => 'field_interview_image',
      1 => 'field_interview_image_caption',
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
  $export['group_interview_image|field_collection_item|field_interview_question_answer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interview_question|field_collection_item|field_interview_question_answer|form';
  $field_group->group_name = 'group_interview_question';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_interview_question_answer';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_question_answer_wrapper';
  $field_group->data = array(
    'label' => 'Add question',
    'weight' => '3',
    'children' => array(
      0 => 'field_interview_answer',
      1 => 'field_interview_question',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-interview-question field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_interview_question|field_collection_item|field_interview_question_answer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interview_quote_wrapper|field_collection_item|field_interview_question_answer|form';
  $field_group->group_name = 'group_interview_quote_wrapper';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_interview_question_answer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '4',
    'children' => array(
      0 => 'group_interview_quote',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-interview-quote-wrapper field-group-accordion',
      ),
    ),
  );
  $export['group_interview_quote_wrapper|field_collection_item|field_interview_question_answer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interview_quote|field_collection_item|field_interview_question_answer|form';
  $field_group->group_name = 'group_interview_quote';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_interview_question_answer';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_interview_quote_wrapper';
  $field_group->data = array(
    'label' => 'Add pull quote',
    'weight' => '11',
    'children' => array(
      0 => 'field_quote',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-interview-quote field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_interview_quote|field_collection_item|field_interview_question_answer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interview_skip_wrapper|field_collection_item|field_interview_question_answer|form';
  $field_group->group_name = 'group_interview_skip_wrapper';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_interview_question_answer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '6',
    'children' => array(
      0 => 'group_interview_video_skip',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-interview-skip-wrapper field-group-accordion',
      ),
    ),
  );
  $export['group_interview_skip_wrapper|field_collection_item|field_interview_question_answer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interview_teaser|node|interview|form';
  $field_group->group_name = 'group_interview_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'interview';
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
        'description' => 'Teaser quote and image do not appear on the content page itself. They are used when this item of content is referenced on other pages, particularly the In Conversation listing.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_interview_teaser|node|interview|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interview_user_wrapper|field_collection_item|field_interview_question_answer|form';
  $field_group->group_name = 'group_interview_user_wrapper';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_interview_question_answer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '5',
    'children' => array(
      0 => 'group_interview_user',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-interview-user-wrapper field-group-accordion',
      ),
    ),
  );
  $export['group_interview_user_wrapper|field_collection_item|field_interview_question_answer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interview_user|field_collection_item|field_interview_question_answer|form';
  $field_group->group_name = 'group_interview_user';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_interview_question_answer';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_interview_user_wrapper';
  $field_group->data = array(
    'label' => 'User submitted question',
    'weight' => '11',
    'children' => array(
      0 => 'field_interview_user_location',
      1 => 'field_interview_user_name',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-interview-user field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_interview_user|field_collection_item|field_interview_question_answer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interview_video_skip|field_collection_item|field_interview_question_answer|form';
  $field_group->group_name = 'group_interview_video_skip';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_interview_question_answer';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_interview_skip_wrapper';
  $field_group->data = array(
    'label' => 'Add video skip link',
    'weight' => '10',
    'children' => array(
      0 => 'field_interview_video_position',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-interview-video-skip field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_interview_video_skip|field_collection_item|field_interview_question_answer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_interview_wrapper|field_collection_item|field_interview_question_answer|form';
  $field_group->group_name = 'group_interview_wrapper';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_interview_question_answer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '2',
    'children' => array(
      0 => 'group_interview_image',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-interview-wrapper field-group-accordion',
      ),
    ),
  );
  $export['group_interview_wrapper|field_collection_item|field_interview_question_answer|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pull_quote|field_collection_item|field_interview_question_answer|default';
  $field_group->group_name = 'group_pull_quote';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_interview_question_answer';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Pull quote group',
    'weight' => '4',
    'children' => array(
      0 => 'field_quote',
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
  $export['group_pull_quote|field_collection_item|field_interview_question_answer|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_question_answer_wrapper|field_collection_item|field_interview_question_answer|form';
  $field_group->group_name = 'group_question_answer_wrapper';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_interview_question_answer';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '1',
    'children' => array(
      0 => 'group_interview_question',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-question-answer-wrapper field-group-accordion',
      ),
    ),
  );
  $export['group_question_answer_wrapper|field_collection_item|field_interview_question_answer|form'] = $field_group;

  return $export;
}
