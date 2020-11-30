<?php
/**
 * @file
 * qma_generic_page.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_generic_page_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create generic_page content'.
  $permissions['create generic_page content'] = array(
    'name' => 'create generic_page content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any generic_page content'.
  $permissions['delete any generic_page content'] = array(
    'name' => 'delete any generic_page content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own generic_page content'.
  $permissions['delete own generic_page content'] = array(
    'name' => 'delete own generic_page content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any generic_page content'.
  $permissions['edit any generic_page content'] = array(
    'name' => 'edit any generic_page content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own generic_page content'.
  $permissions['edit own generic_page content'] = array(
    'name' => 'edit own generic_page content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
