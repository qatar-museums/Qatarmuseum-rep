<?php
/**
 * @file
 * qma_press.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_press_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create press_release content'.
  $permissions['create press_release content'] = array(
    'name' => 'create press_release content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create press_room content'.
  $permissions['create press_room content'] = array(
    'name' => 'create press_room content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any press_release content'.
  $permissions['delete any press_release content'] = array(
    'name' => 'delete any press_release content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any press_room content'.
  $permissions['delete any press_room content'] = array(
    'name' => 'delete any press_room content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own press_release content'.
  $permissions['delete own press_release content'] = array(
    'name' => 'delete own press_release content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own press_room content'.
  $permissions['delete own press_room content'] = array(
    'name' => 'delete own press_room content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in press_tags'.
  $permissions['delete terms in press_tags'] = array(
    'name' => 'delete terms in press_tags',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any press_release content'.
  $permissions['edit any press_release content'] = array(
    'name' => 'edit any press_release content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any press_room content'.
  $permissions['edit any press_room content'] = array(
    'name' => 'edit any press_room content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own press_release content'.
  $permissions['edit own press_release content'] = array(
    'name' => 'edit own press_release content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own press_room content'.
  $permissions['edit own press_room content'] = array(
    'name' => 'edit own press_room content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in press_tags'.
  $permissions['edit terms in press_tags'] = array(
    'name' => 'edit terms in press_tags',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
