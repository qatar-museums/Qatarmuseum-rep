<?php
/**
 * @file
 * qma_education_content_types.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_education_content_types_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer own qma_education_event_registration registration'.
  $permissions['administer own qma_education_event_registration registration'] = array(
    'name' => 'administer own qma_education_event_registration registration',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer qma_education_event_registration registration'.
  $permissions['administer qma_education_event_registration registration'] = array(
    'name' => 'administer qma_education_event_registration registration',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer registration'.
  $permissions['administer registration'] = array(
    'name' => 'administer registration',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'administer registration states'.
  $permissions['administer registration states'] = array(
    'name' => 'administer registration states',
    'roles' => array(),
    'module' => 'registration',
  );

  // Exported permission: 'administer registration types'.
  $permissions['administer registration types'] = array(
    'name' => 'administer registration types',
    'roles' => array(),
    'module' => 'registration',
  );

  // Exported permission: 'create education_hub content'.
  $permissions['create education_hub content'] = array(
    'name' => 'create education_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create education_institution content'.
  $permissions['create education_institution content'] = array(
    'name' => 'create education_institution content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create education_prog content'.
  $permissions['create education_prog content'] = array(
    'name' => 'create education_prog content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create education_resource content'.
  $permissions['create education_resource content'] = array(
    'name' => 'create education_resource content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create education_resource_hub content'.
  $permissions['create education_resource_hub content'] = array(
    'name' => 'create education_resource_hub content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create qma_education_event_registration registration'.
  $permissions['create qma_education_event_registration registration'] = array(
    'name' => 'create qma_education_event_registration registration',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'create qma_education_event_registration registration other anonymous'.
  $permissions['create qma_education_event_registration registration other anonymous'] = array(
    'name' => 'create qma_education_event_registration registration other anonymous',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'create qma_education_event_registration registration other users'.
  $permissions['create qma_education_event_registration registration other users'] = array(
    'name' => 'create qma_education_event_registration registration other users',
    'roles' => array(),
    'module' => 'registration',
  );

  // Exported permission: 'delete any education_hub content'.
  $permissions['delete any education_hub content'] = array(
    'name' => 'delete any education_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any education_institution content'.
  $permissions['delete any education_institution content'] = array(
    'name' => 'delete any education_institution content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any education_prog content'.
  $permissions['delete any education_prog content'] = array(
    'name' => 'delete any education_prog content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any education_resource content'.
  $permissions['delete any education_resource content'] = array(
    'name' => 'delete any education_resource content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any education_resource_hub content'.
  $permissions['delete any education_resource_hub content'] = array(
    'name' => 'delete any education_resource_hub content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any qma_education_event_registration registration'.
  $permissions['delete any qma_education_event_registration registration'] = array(
    'name' => 'delete any qma_education_event_registration registration',
    'roles' => array(
      'Content Manager' => 'Content Manager',
      'Education Data Access' => 'Education Data Access',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'delete own education_hub content'.
  $permissions['delete own education_hub content'] = array(
    'name' => 'delete own education_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own education_institution content'.
  $permissions['delete own education_institution content'] = array(
    'name' => 'delete own education_institution content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own education_prog content'.
  $permissions['delete own education_prog content'] = array(
    'name' => 'delete own education_prog content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own education_resource content'.
  $permissions['delete own education_resource content'] = array(
    'name' => 'delete own education_resource content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own education_resource_hub content'.
  $permissions['delete own education_resource_hub content'] = array(
    'name' => 'delete own education_resource_hub content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own qma_education_event_registration registration'.
  $permissions['delete own qma_education_event_registration registration'] = array(
    'name' => 'delete own qma_education_event_registration registration',
    'roles' => array(
      'Content Manager' => 'Content Manager',
      'Education Data Access' => 'Education Data Access',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'delete terms in age_groups'.
  $permissions['delete terms in age_groups'] = array(
    'name' => 'delete terms in age_groups',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in programme_type'.
  $permissions['delete terms in programme_type'] = array(
    'name' => 'delete terms in programme_type',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in topics'.
  $permissions['delete terms in topics'] = array(
    'name' => 'delete terms in topics',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any education_hub content'.
  $permissions['edit any education_hub content'] = array(
    'name' => 'edit any education_hub content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any education_institution content'.
  $permissions['edit any education_institution content'] = array(
    'name' => 'edit any education_institution content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any education_prog content'.
  $permissions['edit any education_prog content'] = array(
    'name' => 'edit any education_prog content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any education_resource content'.
  $permissions['edit any education_resource content'] = array(
    'name' => 'edit any education_resource content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any education_resource_hub content'.
  $permissions['edit any education_resource_hub content'] = array(
    'name' => 'edit any education_resource_hub content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own education_hub content'.
  $permissions['edit own education_hub content'] = array(
    'name' => 'edit own education_hub content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own education_institution content'.
  $permissions['edit own education_institution content'] = array(
    'name' => 'edit own education_institution content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own education_prog content'.
  $permissions['edit own education_prog content'] = array(
    'name' => 'edit own education_prog content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own education_resource content'.
  $permissions['edit own education_resource content'] = array(
    'name' => 'edit own education_resource content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own education_resource_hub content'.
  $permissions['edit own education_resource_hub content'] = array(
    'name' => 'edit own education_resource_hub content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit qma_education_event_registration registration state'.
  $permissions['edit qma_education_event_registration registration state'] = array(
    'name' => 'edit qma_education_event_registration registration state',
    'roles' => array(),
    'module' => 'registration',
  );

  // Exported permission: 'edit terms in age_groups'.
  $permissions['edit terms in age_groups'] = array(
    'name' => 'edit terms in age_groups',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in programme_type'.
  $permissions['edit terms in programme_type'] = array(
    'name' => 'edit terms in programme_type',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in topics'.
  $permissions['edit terms in topics'] = array(
    'name' => 'edit terms in topics',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'education data access'.
  $permissions['education data access'] = array(
    'name' => 'education data access',
    'roles' => array(
      'Education Data Access' => 'Education Data Access',
    ),
    'module' => 'qma_education',
  );

  // Exported permission: 'update any qma_education_event_registration registration'.
  $permissions['update any qma_education_event_registration registration'] = array(
    'name' => 'update any qma_education_event_registration registration',
    'roles' => array(
      'Education Data Access' => 'Education Data Access',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'update own qma_education_event_registration registration'.
  $permissions['update own qma_education_event_registration registration'] = array(
    'name' => 'update own qma_education_event_registration registration',
    'roles' => array(
      'Education Data Access' => 'Education Data Access',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'view own qma_education_event_registration registration'.
  $permissions['view own qma_education_event_registration registration'] = array(
    'name' => 'view own qma_education_event_registration registration',
    'roles' => array(
      'Content Manager' => 'Content Manager',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'registration',
  );

  // Exported permission: 'view qma_education_event_registration registration'.
  $permissions['view qma_education_event_registration registration'] = array(
    'name' => 'view qma_education_event_registration registration',
    'roles' => array(
      'Content Manager' => 'Content Manager',
      'Education Data Access' => 'Education Data Access',
    ),
    'module' => 'registration',
  );

  return $permissions;
}
