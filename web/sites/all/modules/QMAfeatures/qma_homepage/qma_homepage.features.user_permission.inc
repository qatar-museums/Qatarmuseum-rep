<?php
/**
 * @file
 * qma_homepage.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_homepage_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create homepage content'.
  $permissions['create homepage content'] = array(
    'name' => 'create homepage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any homepage content'.
  $permissions['delete any homepage content'] = array(
    'name' => 'delete any homepage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own homepage content'.
  $permissions['delete own homepage content'] = array(
    'name' => 'delete own homepage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any homepage content'.
  $permissions['edit any homepage content'] = array(
    'name' => 'edit any homepage content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own homepage content'.
  $permissions['edit own homepage content'] = array(
    'name' => 'edit own homepage content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
