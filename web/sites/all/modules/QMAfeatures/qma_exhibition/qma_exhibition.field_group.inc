<?php
/**
 * @file
 * qma_exhibition.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function qma_exhibition_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_artist|node|exhibition|form';
  $field_group->group_name = 'group_artist';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'exhibition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Artist',
    'weight' => '16',
    'children' => array(
      0 => 'field_artist_image',
      1 => 'field_artist_link',
      2 => 'field_artist_name',
      3 => 'field_artist_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-artist field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_artist|node|exhibition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_blog_home_teaser|node|exhibition_home|form';
  $field_group->group_name = 'group_blog_home_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'exhibition_home';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaser',
    'weight' => '12',
    'children' => array(
      0 => 'field_teaser_image',
      1 => 'field_teaser_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-blog-home-teaser field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_blog_home_teaser|node|exhibition_home|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_exhibition_location|node|exhibition|form';
  $field_group->group_name = 'group_exhibition_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'exhibition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '11',
    'children' => array(
      0 => 'field_exhibition_location',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-exhibition-location field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_exhibition_location|node|exhibition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_exhibition_ticket|node|exhibition|form';
  $field_group->group_name = 'group_exhibition_ticket';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'exhibition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Ticket',
    'weight' => '12',
    'children' => array(
      0 => 'field_ticket_option',
      1 => 'field_ticket_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-exhibition-ticket field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_exhibition_ticket|node|exhibition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publication|node|exhibition|form';
  $field_group->group_name = 'group_publication';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'exhibition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Publication',
    'weight' => '18',
    'children' => array(
      0 => 'field_publication_image',
      1 => 'field_publication_link',
      2 => 'field_publication_name',
      3 => 'field_publication_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-publication field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_publication|node|exhibition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_media_accounts|node|exhibition|form';
  $field_group->group_name = 'group_social_media_accounts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'exhibition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Social Media Accounts',
    'weight' => '19',
    'children' => array(
      0 => 'field_social_media_instagram',
      1 => 'field_social_media_twitter',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-social-media-accounts field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_social_media_accounts|node|exhibition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaser|node|exhibition|form';
  $field_group->group_name = 'group_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'exhibition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaser',
    'weight' => '15',
    'children' => array(
      0 => 'field_teaser_image',
      1 => 'field_teaser_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-teaser field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_teaser|node|exhibition|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_venue|node|exhibition|form';
  $field_group->group_name = 'group_venue';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'exhibition';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Venue',
    'weight' => '17',
    'children' => array(
      0 => 'field_venue_image',
      1 => 'field_venue_link',
      2 => 'field_venue_name',
      3 => 'field_venue_text',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-venue field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_venue|node|exhibition|form'] = $field_group;

  return $export;
}
