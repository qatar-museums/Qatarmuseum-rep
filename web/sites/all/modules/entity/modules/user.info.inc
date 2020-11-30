<?php

/**
 * @file
 * Provides info about the user entity.
 */

/**
 * Implements hook_entity_property_info() on top of user module.
 *
 * @see entity_entity_property_info()
 */
function entity_metadata_user_entity_property_info() {
  $info = array();
  // Add meta-data about the user properties.
  $properties = &$info['user']['properties'];

  $properties['uid'] = array(
    'label' => t("User ID"),
    'type' => 'integer',
    'description' => t("The unique ID of the user account."),
    'schema field' => 'uid',
  );
  $properties['name'] = array(
    'label' => t("Name"),
    'description' => t("The login name of the user account."),
    'getter callback' => 'entity_metadata_user_get_properties',
    'setter callback' => 'entity_property_verbatim_set',
    'sanitize' => 'filter_xss',
    'required' => TRUE,
    'access callback' => 'entity_metadata_user_properties_access',
    'schema field' => 'name',
  );
  $properties['pass'] = array(
    'label' => t("Password"),
    'description' => t("The user's password (write only)."),
    'getter callback' => 'entity_metadata_user_get_properties',
    'setter callback' => 'entity_metadata_user_set_properties',
    'required' => TRUE,
    'access callback' => 'entity_metadata_user_properties_access',
    'schema field' => 'pass',
  );
  $properties['mail'] = array(
    'label' => t("Email"),
    'description' => t("The email address of the user account."),
    'setter callback' => 'entity_property_verbatim_set',
    'validation callback' => 'valid_email_address',
    'required' => TRUE,
    'access callback' => 'entity_metadata_user_properties_access',
    'schema field' => 'mail',
  );
  $properties['url'] = array(
    'label' => t("URL"),
    'description' => t("The URL of the account profile page."),
    'getter callback' => 'entity_metadata_user_get_properties',
    'type' => 'uri',
    'computed' => TRUE,
  );
  $properties['edit_url'] = array(
    'label' => t("Edit URL"),
    'description' => t("The url of the account edit page."),
    'getter callback' => 'entity_metadata_user_get_properties',
    'type' => 'uri',
    'computed' => TRUE,
  );
  $properties['last_access'] = array(
    'label' => t("Last access"),
    'description' => t("The date the user last accessed the site."),
    'getter callback' => 'entity_metadata_user_get_properties',
    'type' => 'date',
    'access callback' => 'entity_metadata_user_properties_access',
    'schema field' => 'access',
  );
  $properties['last_login'] = array(
    'label' => t("Last login"),
    'description' => t("The date the user last logged in to the site."),
    'getter callback' => 'entity_metadata_user_get_properties',
    'type' => 'date',
    'access callback' => 'entity_metadata_user_properties_access',
    'schema field' => 'login',
  );
  $properties['created'] = array(
    'label' => t("Created"),
    'description' => t("The date the user account was created."),
    'type' => 'date',
    'schema field' => 'created',
    'setter permission' => 'administer users',
  );
  $properties['roles'] = array(
    'label' => t("User roles"),
    'description' => t("The roles of the user."),
    'type' => 'list<integer>',
    'getter callback' => 'entity_metadata_user_get_properties',
    'setter callback' => 'entity_metadata_user_set_properties',
    'options list' => 'entity_metadata_user_roles',
    'access callback' => 'entity_metadata_user_properties_access',
  );
  $properties['status'] = array(
    'label' => t("Status"),
    'description' => t("Whether the user is active or blocked."),
    'setter callback' => 'entity_property_verbatim_set',
    // Although the status is expected to be boolean, its schema suggests
    // it is an integer, so we follow the schema definition.
    'type' => 'integer',
    'options list' => 'entity_metadata_user_status_options_list',
    'access callback' => 'entity_metadata_user_properties_access',
    'schema field' => 'status',
  );
  $properties['theme'] = array(
    'label' => t("Default theme"),
    'description' => t("The user's default theme."),
    'getter callback' => 'entity_metadata_user_get_properties',
    'setter callback' => 'entity_property_verbatim_set',
    'access callback' => 'entity_metadata_user_properties_access',
    'schema field' => 'theme',
  );
  $properties['timezone'] = array(
    'label' => t("Time zone"),
    'description' => t("The user's time zone."),
    'options list' => 'entity_property_timezone_options',
    'getter callback' => 'entity_metadata_user_get_properties',
    'setter callback' => 'entity_property_verbatim_set',
    'access callback' => 'entity_metadata_user_properties_access',
    'schema field' => 'timezone',
  );
  $properties['picture'] = array(
    'label' => t("Picture"),
    'description' => t("The user's picture."),
    'type' => 'file',
    'getter callback' => 'entity_metadata_user_get_properties',
    'setter callback' => 'entity_property_verbatim_set',
    'access callback' => 'entity_metadata_user_properties_access',
    'validation callback' => 'entity_metadata_user_validate_picture',
    'schema field' => 'picture',
  );
  $properties['signature'] = array(
    'label' => t("Signature"),
    'description' => t("The user's signature."),
    'type' => 'text_formatted',
    'getter callback' => 'entity_metadata_user_get_properties',
    'setter callback' => 'entity_metadata_user_set_properties',
    'access callback' => 'entity_metadata_user_properties_access',
    'property info' => entity_property_user_signature_info(),
    'auto creation' => 'entity_property_create_array',
  );
  return $info;
}

