<?php
/**
 * @file
 * qma_pattern_generator.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_pattern_generator_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create pattern_gallery content'.
  $permissions['create pattern_gallery content'] = array(
    'name' => 'create pattern_gallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create pattern_generator content'.
  $permissions['create pattern_generator content'] = array(
    'name' => 'create pattern_generator content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any pattern_gallery content'.
  $permissions['delete any pattern_gallery content'] = array(
    'name' => 'delete any pattern_gallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any pattern_generator content'.
  $permissions['delete any pattern_generator content'] = array(
    'name' => 'delete any pattern_generator content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own pattern_gallery content'.
  $permissions['delete own pattern_gallery content'] = array(
    'name' => 'delete own pattern_gallery content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own pattern_generator content'.
  $permissions['delete own pattern_generator content'] = array(
    'name' => 'delete own pattern_generator content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any pattern_gallery content'.
  $permissions['edit any pattern_gallery content'] = array(
    'name' => 'edit any pattern_gallery content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any pattern_generator content'.
  $permissions['edit any pattern_generator content'] = array(
    'name' => 'edit any pattern_generator content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own pattern_gallery content'.
  $permissions['edit own pattern_gallery content'] = array(
    'name' => 'edit own pattern_gallery content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own pattern_generator content'.
  $permissions['edit own pattern_generator content'] = array(
    'name' => 'edit own pattern_generator content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
