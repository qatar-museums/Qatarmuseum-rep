<?php
/**
 * @file
 * qma_exhibition.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_exhibition_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer exhibition_status_ vocabulary terms'.
  $permissions['administer exhibition_status_ vocabulary terms'] = array(
    'name' => 'administer exhibition_status_ vocabulary terms',
    'roles' => array(),
    'module' => 'vppr',
  );

  // Exported permission: 'create exhibition content'.
  $permissions['create exhibition content'] = array(
    'name' => 'create exhibition content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create exhibition_home content'.
  $permissions['create exhibition_home content'] = array(
    'name' => 'create exhibition_home content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any exhibition content'.
  $permissions['delete any exhibition content'] = array(
    'name' => 'delete any exhibition content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any exhibition_home content'.
  $permissions['delete any exhibition_home content'] = array(
    'name' => 'delete any exhibition_home content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own exhibition content'.
  $permissions['delete own exhibition content'] = array(
    'name' => 'delete own exhibition content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own exhibition_home content'.
  $permissions['delete own exhibition_home content'] = array(
    'name' => 'delete own exhibition_home content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in exhibition_status_'.
  $permissions['delete terms in exhibition_status_'] = array(
    'name' => 'delete terms in exhibition_status_',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any exhibition content'.
  $permissions['edit any exhibition content'] = array(
    'name' => 'edit any exhibition content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any exhibition_home content'.
  $permissions['edit any exhibition_home content'] = array(
    'name' => 'edit any exhibition_home content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own exhibition content'.
  $permissions['edit own exhibition content'] = array(
    'name' => 'edit own exhibition content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own exhibition_home content'.
  $permissions['edit own exhibition_home content'] = array(
    'name' => 'edit own exhibition_home content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in exhibition_status_'.
  $permissions['edit terms in exhibition_status_'] = array(
    'name' => 'edit terms in exhibition_status_',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'moderate exhibition state from draft to needs_review'.
  $permissions['moderate exhibition state from draft to needs_review'] = array(
    'name' => 'moderate exhibition state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate exhibition state from needs_review to draft'.
  $permissions['moderate exhibition state from needs_review to draft'] = array(
    'name' => 'moderate exhibition state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate exhibition state from needs_review to published'.
  $permissions['moderate exhibition state from needs_review to published'] = array(
    'name' => 'moderate exhibition state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate exhibition state from published to needs_review'.
  $permissions['moderate exhibition state from published to needs_review'] = array(
    'name' => 'moderate exhibition state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate exhibition_home state from draft to needs_review'.
  $permissions['moderate exhibition_home state from draft to needs_review'] = array(
    'name' => 'moderate exhibition_home state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate exhibition_home state from needs_review to draft'.
  $permissions['moderate exhibition_home state from needs_review to draft'] = array(
    'name' => 'moderate exhibition_home state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate exhibition_home state from needs_review to published'.
  $permissions['moderate exhibition_home state from needs_review to published'] = array(
    'name' => 'moderate exhibition_home state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate exhibition_home state from published to needs_review'.
  $permissions['moderate exhibition_home state from published to needs_review'] = array(
    'name' => 'moderate exhibition_home state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  return $permissions;
}
