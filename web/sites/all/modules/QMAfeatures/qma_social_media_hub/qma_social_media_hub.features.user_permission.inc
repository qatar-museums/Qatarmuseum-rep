<?php
/**
 * @file
 * qma_social_media_hub.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_social_media_hub_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create social_media_hub content'.
  $permissions['create social_media_hub content'] = array(
    'name' => 'create social_media_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any social_media_hub content'.
  $permissions['delete any social_media_hub content'] = array(
    'name' => 'delete any social_media_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own social_media_hub content'.
  $permissions['delete own social_media_hub content'] = array(
    'name' => 'delete own social_media_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any social_media_hub content'.
  $permissions['edit any social_media_hub content'] = array(
    'name' => 'edit any social_media_hub content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own social_media_hub content'.
  $permissions['edit own social_media_hub content'] = array(
    'name' => 'edit own social_media_hub content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
