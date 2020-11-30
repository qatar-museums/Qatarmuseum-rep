<?php
/**
 * @file
 * qma_news.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_news_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer blog_tags vocabulary terms'.
  $permissions['administer blog_tags vocabulary terms'] = array(
    'name' => 'administer blog_tags vocabulary terms',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'vppr',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'create news_article content'.
  $permissions['create news_article content'] = array(
    'name' => 'create news_article content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create news_hub content'.
  $permissions['create news_hub content'] = array(
    'name' => 'create news_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any news_article content'.
  $permissions['delete any news_article content'] = array(
    'name' => 'delete any news_article content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any news_hub content'.
  $permissions['delete any news_hub content'] = array(
    'name' => 'delete any news_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own news_article content'.
  $permissions['delete own news_article content'] = array(
    'name' => 'delete own news_article content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own news_hub content'.
  $permissions['delete own news_hub content'] = array(
    'name' => 'delete own news_hub content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in blog_tags'.
  $permissions['delete terms in blog_tags'] = array(
    'name' => 'delete terms in blog_tags',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any news_article content'.
  $permissions['edit any news_article content'] = array(
    'name' => 'edit any news_article content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any news_hub content'.
  $permissions['edit any news_hub content'] = array(
    'name' => 'edit any news_hub content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own news_article content'.
  $permissions['edit own news_article content'] = array(
    'name' => 'edit own news_article content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own news_hub content'.
  $permissions['edit own news_hub content'] = array(
    'name' => 'edit own news_hub content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in blog_tags'.
  $permissions['edit terms in blog_tags'] = array(
    'name' => 'edit terms in blog_tags',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(),
    'module' => 'comment',
  );

  return $permissions;
}
