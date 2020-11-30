<?php
/**
 * @file
 * qma_twitter_handling.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_twitter_handling_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add authenticated twitter accounts'.
  $permissions['add authenticated twitter accounts'] = array(
    'name' => 'add authenticated twitter accounts',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'twitter',
  );

  // Exported permission: 'add twitter accounts'.
  $permissions['add twitter accounts'] = array(
    'name' => 'add twitter accounts',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'twitter',
  );

  // Exported permission: 'administer twitter accounts'.
  $permissions['administer twitter accounts'] = array(
    'name' => 'administer twitter accounts',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'twitter',
  );

  return $permissions;
}
