<?php
/**
 * @file
 * qma_education_content_types.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function qma_education_content_types_user_default_roles() {
  $roles = array();

  // Exported role: Education Data Access.
  $roles['Education Data Access'] = array(
    'name' => 'Education Data Access',
    'weight' => 8,
  );

  return $roles;
}
