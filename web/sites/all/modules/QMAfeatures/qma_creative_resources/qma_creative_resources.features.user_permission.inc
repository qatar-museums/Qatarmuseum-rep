<?php
/**
 * @file
 * qma_creative_resources.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_creative_resources_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create creative_resource content'.
  $permissions['create creative_resource content'] = array(
    'name' => 'create creative_resource content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create creative_resource_hub content'.
  $permissions['create creative_resource_hub content'] = array(
    'name' => 'create creative_resource_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any creative_resource content'.
  $permissions['delete any creative_resource content'] = array(
    'name' => 'delete any creative_resource content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any creative_resource_hub content'.
  $permissions['delete any creative_resource_hub content'] = array(
    'name' => 'delete any creative_resource_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own creative_resource content'.
  $permissions['delete own creative_resource content'] = array(
    'name' => 'delete own creative_resource content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own creative_resource_hub content'.
  $permissions['delete own creative_resource_hub content'] = array(
    'name' => 'delete own creative_resource_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in creative_resource_tags'.
  $permissions['delete terms in creative_resource_tags'] = array(
    'name' => 'delete terms in creative_resource_tags',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any creative_resource content'.
  $permissions['edit any creative_resource content'] = array(
    'name' => 'edit any creative_resource content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any creative_resource_hub content'.
  $permissions['edit any creative_resource_hub content'] = array(
    'name' => 'edit any creative_resource_hub content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own creative_resource content'.
  $permissions['edit own creative_resource content'] = array(
    'name' => 'edit own creative_resource content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own creative_resource_hub content'.
  $permissions['edit own creative_resource_hub content'] = array(
    'name' => 'edit own creative_resource_hub content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in creative_resource_tags'.
  $permissions['edit terms in creative_resource_tags'] = array(
    'name' => 'edit terms in creative_resource_tags',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
