<?php
/**
 * @file
 * qma_instagram.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_instagram_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add drupagram accounts'.
  $permissions['add drupagram accounts'] = array(
    'name' => 'add drupagram accounts',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'drupagram',
  );

  // Exported permission: 'import own media'.
  $permissions['import own media'] = array(
    'name' => 'import own media',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'drupagram',
  );

  // Exported permission: 'make drupagram accounts global'.
  $permissions['make drupagram accounts global'] = array(
    'name' => 'make drupagram accounts global',
    'roles' => array(),
    'module' => 'drupagram',
  );

  // Exported permission: 'use global drupagram account'.
  $permissions['use global drupagram account'] = array(
    'name' => 'use global drupagram account',
    'roles' => array(),
    'module' => 'drupagram',
  );

  return $permissions;
}
