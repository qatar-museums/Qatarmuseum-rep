<?php
/**
 * @file
 * qma_membership.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_membership_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create membership_page content'.
  $permissions['create membership_page content'] = array(
    'name' => 'create membership_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any membership_page content'.
  $permissions['delete any membership_page content'] = array(
    'name' => 'delete any membership_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own membership_page content'.
  $permissions['delete own membership_page content'] = array(
    'name' => 'delete own membership_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any membership_page content'.
  $permissions['edit any membership_page content'] = array(
    'name' => 'edit any membership_page content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own membership_page content'.
  $permissions['edit own membership_page content'] = array(
    'name' => 'edit own membership_page content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
