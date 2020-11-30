<?php
/**
 * @file
 * qma_whats_on.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_whats_on_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create whats_on content'.
  $permissions['create whats_on content'] = array(
    'name' => 'create whats_on content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any whats_on content'.
  $permissions['delete any whats_on content'] = array(
    'name' => 'delete any whats_on content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own whats_on content'.
  $permissions['delete own whats_on content'] = array(
    'name' => 'delete own whats_on content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any whats_on content'.
  $permissions['edit any whats_on content'] = array(
    'name' => 'edit any whats_on content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own whats_on content'.
  $permissions['edit own whats_on content'] = array(
    'name' => 'edit own whats_on content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
