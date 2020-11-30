<?php
/**
 * @file
 * qma_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function qma_roles_user_default_roles() {
  $roles = array();

  // Exported role: Content Editor.
  $roles['Content Editor'] = array(
    'name' => 'Content Editor',
    'weight' => 6,
  );

  // Exported role: Content Manager.
  $roles['Content Manager'] = array(
    'name' => 'Content Manager',
    'weight' => 7,
  );

  // Exported role: Education Department Staff.
  $roles['Education Department Staff'] = array(
    'name' => 'Education Department Staff',
    'weight' => 5,
  );

  // Exported role: Educator Staff.
  $roles['Educator Staff'] = array(
    'name' => 'Educator Staff',
    'weight' => 4,
  );

  // Exported role: Member.
  $roles['Member'] = array(
    'name' => 'Member',
    'weight' => 2,
  );

  // Exported role: Member Data Exporter.
  $roles['Member Data Exporter'] = array(
    'name' => 'Member Data Exporter',
    'weight' => 9,
  );

  // Exported role: Press.
  $roles['Press'] = array(
    'name' => 'Press',
    'weight' => 3,
  );

  return $roles;
}
