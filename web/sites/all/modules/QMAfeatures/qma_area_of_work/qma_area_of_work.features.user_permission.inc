<?php
/**
 * @file
 * qma_area_of_work.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_area_of_work_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create area_of_work content'.
  $permissions['create area_of_work content'] = array(
    'name' => 'create area_of_work content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any area_of_work content'.
  $permissions['delete any area_of_work content'] = array(
    'name' => 'delete any area_of_work content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own area_of_work content'.
  $permissions['delete own area_of_work content'] = array(
    'name' => 'delete own area_of_work content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any area_of_work content'.
  $permissions['edit any area_of_work content'] = array(
    'name' => 'edit any area_of_work content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own area_of_work content'.
  $permissions['edit own area_of_work content'] = array(
    'name' => 'edit own area_of_work content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
