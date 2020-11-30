<?php
/**
 * @file
 * qma_in_conversation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_in_conversation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create interview content'.
  $permissions['create interview content'] = array(
    'name' => 'create interview content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create interview_hub content'.
  $permissions['create interview_hub content'] = array(
    'name' => 'create interview_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any interview content'.
  $permissions['delete any interview content'] = array(
    'name' => 'delete any interview content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any interview_hub content'.
  $permissions['delete any interview_hub content'] = array(
    'name' => 'delete any interview_hub content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own interview content'.
  $permissions['delete own interview content'] = array(
    'name' => 'delete own interview content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own interview_hub content'.
  $permissions['delete own interview_hub content'] = array(
    'name' => 'delete own interview_hub content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any interview content'.
  $permissions['edit any interview content'] = array(
    'name' => 'edit any interview content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any interview_hub content'.
  $permissions['edit any interview_hub content'] = array(
    'name' => 'edit any interview_hub content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own interview content'.
  $permissions['edit own interview content'] = array(
    'name' => 'edit own interview content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own interview_hub content'.
  $permissions['edit own interview_hub content'] = array(
    'name' => 'edit own interview_hub content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  return $permissions;
}
