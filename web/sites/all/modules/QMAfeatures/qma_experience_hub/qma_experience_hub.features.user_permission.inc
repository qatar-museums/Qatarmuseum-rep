<?php
/**
 * @file
 * qma_experience_hub.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_experience_hub_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create areas_hub content'.
  $permissions['create areas_hub content'] = array(
    'name' => 'create areas_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any areas_hub content'.
  $permissions['delete any areas_hub content'] = array(
    'name' => 'delete any areas_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own areas_hub content'.
  $permissions['delete own areas_hub content'] = array(
    'name' => 'delete own areas_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any areas_hub content'.
  $permissions['edit any areas_hub content'] = array(
    'name' => 'edit any areas_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own areas_hub content'.
  $permissions['edit own areas_hub content'] = array(
    'name' => 'edit own areas_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
