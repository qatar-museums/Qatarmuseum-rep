<?php
/**
 * @file
 * qma_site_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_site_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'assign Content Editor role'.
  $permissions['assign Content Editor role'] = array(
    'name' => 'assign Content Editor role',
    'roles' => array(),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Content Manager role'.
  $permissions['assign Content Manager role'] = array(
    'name' => 'assign Content Manager role',
    'roles' => array(),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Member role'.
  $permissions['assign Member role'] = array(
    'name' => 'assign Member role',
    'roles' => array(),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Press role'.
  $permissions['assign Press role'] = array(
    'name' => 'assign Press role',
    'roles' => array(),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign all roles'.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'view location directory'.
  $permissions['view location directory'] = array(
    'name' => 'view location directory',
    'roles' => array(),
    'module' => 'location',
  );

  // Exported permission: 'view node location table'.
  $permissions['view node location table'] = array(
    'name' => 'view node location table',
    'roles' => array(),
    'module' => 'location',
  );

  // Exported permission: 'view node map'.
  $permissions['view node map'] = array(
    'name' => 'view node map',
    'roles' => array(),
    'module' => 'gmap_location',
  );

  // Exported permission: 'view user location details'.
  $permissions['view user location details'] = array(
    'name' => 'view user location details',
    'roles' => array(),
    'module' => 'gmap_location',
  );

  // Exported permission: 'view user location table'.
  $permissions['view user location table'] = array(
    'name' => 'view user location table',
    'roles' => array(),
    'module' => 'location',
  );

  // Exported permission: 'view user map'.
  $permissions['view user map'] = array(
    'name' => 'view user map',
    'roles' => array(),
    'module' => 'gmap_location',
  );

  return $permissions;
}
