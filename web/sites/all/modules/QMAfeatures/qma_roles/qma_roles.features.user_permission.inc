<?php
/**
 * @file
 * qma_roles.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function qma_roles_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
      'Member Data Exporter' => 'Member Data Exporter',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
      'Member Data Exporter' => 'Member Data Exporter',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access advanced_link autocomplete'.
  $permissions['access advanced_link autocomplete'] = array(
    'name' => 'access advanced_link autocomplete',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'advanced_link',
  );

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access broken links report'.
  $permissions['access broken links report'] = array(
    'name' => 'access broken links report',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'access ckeditor link'.
  $permissions['access ckeditor link'] = array(
    'name' => 'access ckeditor link',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'ckeditor_link',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Member' => 'Member',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'access own broken links report'.
  $permissions['access own broken links report'] = array(
    'name' => 'access own broken links report',
    'roles' => array(),
    'module' => 'linkchecker',
  );

  // Exported permission: 'access qma menu'.
  $permissions['access qma menu'] = array(
    'name' => 'access qma menu',
    'roles' => array(
      'Content Manager' => 'Content Manager',
      'Education Data Access' => 'Education Data Access',
      'Member Data Exporter' => 'Member Data Exporter',
    ),
    'module' => 'qma_custom',
  );

  // Exported permission: 'access qma user export'.
  $permissions['access qma user export'] = array(
    'name' => 'access qma user export',
    'roles' => array(
      'Content Manager' => 'Content Manager',
      'Member Data Exporter' => 'Member Data Exporter',
    ),
    'module' => 'qma_custom',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer ckeditor link'.
  $permissions['administer ckeditor link'] = array(
    'name' => 'administer ckeditor link',
    'roles' => array(),
    'module' => 'ckeditor_link',
  );

  // Exported permission: 'administer content translations'.
  $permissions['administer content translations'] = array(
    'name' => 'administer content translations',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'i18n_node',
  );

  // Exported permission: 'administer elysia_cron'.
  $permissions['administer elysia_cron'] = array(
    'name' => 'administer elysia_cron',
    'roles' => array(),
    'module' => 'elysia_cron',
  );

  // Exported permission: 'administer entity translation'.
  $permissions['administer entity translation'] = array(
    'name' => 'administer entity translation',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: 'administer feeds'.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'administer google analytics'.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'administer honeypot'.
  $permissions['administer honeypot'] = array(
    'name' => 'administer honeypot',
    'roles' => array(),
    'module' => 'honeypot',
  );

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(),
    'module' => 'imce',
  );

  // Exported permission: 'administer linkchecker'.
  $permissions['administer linkchecker'] = array(
    'name' => 'administer linkchecker',
    'roles' => array(),
    'module' => 'linkchecker',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer qma forms'.
  $permissions['administer qma forms'] = array(
    'name' => 'administer qma forms',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'qma_forms',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer workbench'.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(),
    'module' => 'workbench',
  );

  // Exported permission: 'administer workbench moderation'.
  $permissions['administer workbench moderation'] = array(
    'name' => 'administer workbench moderation',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'bypass honeypot protection'.
  $permissions['bypass honeypot protection'] = array(
    'name' => 'bypass honeypot protection',
    'roles' => array(),
    'module' => 'honeypot',
  );

  // Exported permission: 'bypass workbench moderation'.
  $permissions['bypass workbench moderation'] = array(
    'name' => 'bypass workbench moderation',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'Member' => 'Member',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'clear node feeds'.
  $permissions['clear node feeds'] = array(
    'name' => 'clear node feeds',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear user feeds'.
  $permissions['clear user feeds'] = array(
    'name' => 'clear user feeds',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'create qma_homepage content'.
  $permissions['create qma_homepage content'] = array(
    'name' => 'create qma_homepage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'path',
  );

  // Exported permission: 'delete any qma_homepage content'.
  $permissions['delete any qma_homepage content'] = array(
    'name' => 'delete any qma_homepage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'delete own qma_homepage content'.
  $permissions['delete own qma_homepage content'] = array(
    'name' => 'delete own qma_homepage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in sample_vocab'.
  $permissions['delete terms in sample_vocab'] = array(
    'name' => 'delete terms in sample_vocab',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit any qma_homepage content'.
  $permissions['edit any qma_homepage content'] = array(
    'name' => 'edit any qma_homepage content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit link settings'.
  $permissions['edit link settings'] = array(
    'name' => 'edit link settings',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit own qma_homepage content'.
  $permissions['edit own qma_homepage content'] = array(
    'name' => 'edit own qma_homepage content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in sample_vocab'.
  $permissions['edit terms in sample_vocab'] = array(
    'name' => 'edit terms in sample_vocab',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'import node feeds'.
  $permissions['import node feeds'] = array(
    'name' => 'import node feeds',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import user feeds'.
  $permissions['import user feeds'] = array(
    'name' => 'import user feeds',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'moderate advpoll state from draft to needs_review'.
  $permissions['moderate advpoll state from draft to needs_review'] = array(
    'name' => 'moderate advpoll state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate advpoll state from needs_review to draft'.
  $permissions['moderate advpoll state from needs_review to draft'] = array(
    'name' => 'moderate advpoll state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate advpoll state from needs_review to published'.
  $permissions['moderate advpoll state from needs_review to published'] = array(
    'name' => 'moderate advpoll state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate advpoll state from published to needs_review'.
  $permissions['moderate advpoll state from published to needs_review'] = array(
    'name' => 'moderate advpoll state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate area_of_work state from draft to needs_review'.
  $permissions['moderate area_of_work state from draft to needs_review'] = array(
    'name' => 'moderate area_of_work state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate area_of_work state from needs_review to draft'.
  $permissions['moderate area_of_work state from needs_review to draft'] = array(
    'name' => 'moderate area_of_work state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate area_of_work state from needs_review to published'.
  $permissions['moderate area_of_work state from needs_review to published'] = array(
    'name' => 'moderate area_of_work state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate area_of_work state from published to needs_review'.
  $permissions['moderate area_of_work state from published to needs_review'] = array(
    'name' => 'moderate area_of_work state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate areas_hub state from draft to needs_review'.
  $permissions['moderate areas_hub state from draft to needs_review'] = array(
    'name' => 'moderate areas_hub state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate areas_hub state from needs_review to draft'.
  $permissions['moderate areas_hub state from needs_review to draft'] = array(
    'name' => 'moderate areas_hub state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate areas_hub state from needs_review to published'.
  $permissions['moderate areas_hub state from needs_review to published'] = array(
    'name' => 'moderate areas_hub state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate areas_hub state from published to needs_review'.
  $permissions['moderate areas_hub state from published to needs_review'] = array(
    'name' => 'moderate areas_hub state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from draft to needs_review'.
  $permissions['moderate content from draft to needs_review'] = array(
    'name' => 'moderate content from draft to needs_review',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to draft'.
  $permissions['moderate content from needs_review to draft'] = array(
    'name' => 'moderate content from needs_review to draft',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to published'.
  $permissions['moderate content from needs_review to published'] = array(
    'name' => 'moderate content from needs_review to published',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from published to needs_review'.
  $permissions['moderate content from published to needs_review'] = array(
    'name' => 'moderate content from published to needs_review',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate creative_resource state from draft to needs_review'.
  $permissions['moderate creative_resource state from draft to needs_review'] = array(
    'name' => 'moderate creative_resource state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate creative_resource state from needs_review to draft'.
  $permissions['moderate creative_resource state from needs_review to draft'] = array(
    'name' => 'moderate creative_resource state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate creative_resource state from needs_review to published'.
  $permissions['moderate creative_resource state from needs_review to published'] = array(
    'name' => 'moderate creative_resource state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate creative_resource state from published to needs_review'.
  $permissions['moderate creative_resource state from published to needs_review'] = array(
    'name' => 'moderate creative_resource state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate creative_resource_hub state from draft to needs_review'.
  $permissions['moderate creative_resource_hub state from draft to needs_review'] = array(
    'name' => 'moderate creative_resource_hub state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate creative_resource_hub state from needs_review to draft'.
  $permissions['moderate creative_resource_hub state from needs_review to draft'] = array(
    'name' => 'moderate creative_resource_hub state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate creative_resource_hub state from needs_review to published'.
  $permissions['moderate creative_resource_hub state from needs_review to published'] = array(
    'name' => 'moderate creative_resource_hub state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate creative_resource_hub state from published to needs_review'.
  $permissions['moderate creative_resource_hub state from published to needs_review'] = array(
    'name' => 'moderate creative_resource_hub state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_hub state from draft to needs_review'.
  $permissions['moderate education_hub state from draft to needs_review'] = array(
    'name' => 'moderate education_hub state from draft to needs_review',
    'roles' => array(
      'Education Department Staff' => 'Education Department Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_hub state from needs_review to draft'.
  $permissions['moderate education_hub state from needs_review to draft'] = array(
    'name' => 'moderate education_hub state from needs_review to draft',
    'roles' => array(
      'Education Department Staff' => 'Education Department Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_hub state from needs_review to published'.
  $permissions['moderate education_hub state from needs_review to published'] = array(
    'name' => 'moderate education_hub state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_hub state from published to needs_review'.
  $permissions['moderate education_hub state from published to needs_review'] = array(
    'name' => 'moderate education_hub state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_institution state from draft to needs_review'.
  $permissions['moderate education_institution state from draft to needs_review'] = array(
    'name' => 'moderate education_institution state from draft to needs_review',
    'roles' => array(
      'Education Department Staff' => 'Education Department Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_institution state from needs_review to draft'.
  $permissions['moderate education_institution state from needs_review to draft'] = array(
    'name' => 'moderate education_institution state from needs_review to draft',
    'roles' => array(
      'Education Department Staff' => 'Education Department Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_institution state from needs_review to published'.
  $permissions['moderate education_institution state from needs_review to published'] = array(
    'name' => 'moderate education_institution state from needs_review to published',
    'roles' => array(
      'Education Department Staff' => 'Education Department Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_institution state from published to needs_review'.
  $permissions['moderate education_institution state from published to needs_review'] = array(
    'name' => 'moderate education_institution state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_prog state from draft to needs_review'.
  $permissions['moderate education_prog state from draft to needs_review'] = array(
    'name' => 'moderate education_prog state from draft to needs_review',
    'roles' => array(
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_prog state from needs_review to draft'.
  $permissions['moderate education_prog state from needs_review to draft'] = array(
    'name' => 'moderate education_prog state from needs_review to draft',
    'roles' => array(
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_prog state from needs_review to published'.
  $permissions['moderate education_prog state from needs_review to published'] = array(
    'name' => 'moderate education_prog state from needs_review to published',
    'roles' => array(
      'Education Department Staff' => 'Education Department Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_prog state from published to needs_review'.
  $permissions['moderate education_prog state from published to needs_review'] = array(
    'name' => 'moderate education_prog state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_resource state from draft to needs_review'.
  $permissions['moderate education_resource state from draft to needs_review'] = array(
    'name' => 'moderate education_resource state from draft to needs_review',
    'roles' => array(
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_resource state from needs_review to draft'.
  $permissions['moderate education_resource state from needs_review to draft'] = array(
    'name' => 'moderate education_resource state from needs_review to draft',
    'roles' => array(
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_resource state from needs_review to published'.
  $permissions['moderate education_resource state from needs_review to published'] = array(
    'name' => 'moderate education_resource state from needs_review to published',
    'roles' => array(
      'Education Department Staff' => 'Education Department Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_resource state from published to needs_review'.
  $permissions['moderate education_resource state from published to needs_review'] = array(
    'name' => 'moderate education_resource state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_resource_hub state from draft to needs_review'.
  $permissions['moderate education_resource_hub state from draft to needs_review'] = array(
    'name' => 'moderate education_resource_hub state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_resource_hub state from needs_review to draft'.
  $permissions['moderate education_resource_hub state from needs_review to draft'] = array(
    'name' => 'moderate education_resource_hub state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_resource_hub state from needs_review to published'.
  $permissions['moderate education_resource_hub state from needs_review to published'] = array(
    'name' => 'moderate education_resource_hub state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate education_resource_hub state from published to needs_review'.
  $permissions['moderate education_resource_hub state from published to needs_review'] = array(
    'name' => 'moderate education_resource_hub state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate generic_page state from draft to needs_review'.
  $permissions['moderate generic_page state from draft to needs_review'] = array(
    'name' => 'moderate generic_page state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate generic_page state from needs_review to draft'.
  $permissions['moderate generic_page state from needs_review to draft'] = array(
    'name' => 'moderate generic_page state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate generic_page state from needs_review to published'.
  $permissions['moderate generic_page state from needs_review to published'] = array(
    'name' => 'moderate generic_page state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate generic_page state from published to needs_review'.
  $permissions['moderate generic_page state from published to needs_review'] = array(
    'name' => 'moderate generic_page state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate homepage state from draft to needs_review'.
  $permissions['moderate homepage state from draft to needs_review'] = array(
    'name' => 'moderate homepage state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate homepage state from needs_review to draft'.
  $permissions['moderate homepage state from needs_review to draft'] = array(
    'name' => 'moderate homepage state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate homepage state from needs_review to published'.
  $permissions['moderate homepage state from needs_review to published'] = array(
    'name' => 'moderate homepage state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate homepage state from published to needs_review'.
  $permissions['moderate homepage state from published to needs_review'] = array(
    'name' => 'moderate homepage state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate interview state from draft to needs_review'.
  $permissions['moderate interview state from draft to needs_review'] = array(
    'name' => 'moderate interview state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate interview state from needs_review to draft'.
  $permissions['moderate interview state from needs_review to draft'] = array(
    'name' => 'moderate interview state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate interview state from needs_review to published'.
  $permissions['moderate interview state from needs_review to published'] = array(
    'name' => 'moderate interview state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate interview state from published to needs_review'.
  $permissions['moderate interview state from published to needs_review'] = array(
    'name' => 'moderate interview state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate interview_hub state from draft to needs_review'.
  $permissions['moderate interview_hub state from draft to needs_review'] = array(
    'name' => 'moderate interview_hub state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate interview_hub state from needs_review to draft'.
  $permissions['moderate interview_hub state from needs_review to draft'] = array(
    'name' => 'moderate interview_hub state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate interview_hub state from needs_review to published'.
  $permissions['moderate interview_hub state from needs_review to published'] = array(
    'name' => 'moderate interview_hub state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate interview_hub state from published to needs_review'.
  $permissions['moderate interview_hub state from published to needs_review'] = array(
    'name' => 'moderate interview_hub state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate landing_page state from draft to needs_review'.
  $permissions['moderate landing_page state from draft to needs_review'] = array(
    'name' => 'moderate landing_page state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate landing_page state from needs_review to draft'.
  $permissions['moderate landing_page state from needs_review to draft'] = array(
    'name' => 'moderate landing_page state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate landing_page state from needs_review to published'.
  $permissions['moderate landing_page state from needs_review to published'] = array(
    'name' => 'moderate landing_page state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate landing_page state from published to needs_review'.
  $permissions['moderate landing_page state from published to needs_review'] = array(
    'name' => 'moderate landing_page state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate membership_page state from draft to needs_review'.
  $permissions['moderate membership_page state from draft to needs_review'] = array(
    'name' => 'moderate membership_page state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate membership_page state from needs_review to draft'.
  $permissions['moderate membership_page state from needs_review to draft'] = array(
    'name' => 'moderate membership_page state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate membership_page state from needs_review to published'.
  $permissions['moderate membership_page state from needs_review to published'] = array(
    'name' => 'moderate membership_page state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate membership_page state from published to needs_review'.
  $permissions['moderate membership_page state from published to needs_review'] = array(
    'name' => 'moderate membership_page state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news_article state from draft to needs_review'.
  $permissions['moderate news_article state from draft to needs_review'] = array(
    'name' => 'moderate news_article state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news_article state from needs_review to draft'.
  $permissions['moderate news_article state from needs_review to draft'] = array(
    'name' => 'moderate news_article state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news_article state from needs_review to published'.
  $permissions['moderate news_article state from needs_review to published'] = array(
    'name' => 'moderate news_article state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news_article state from published to needs_review'.
  $permissions['moderate news_article state from published to needs_review'] = array(
    'name' => 'moderate news_article state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news_hub state from draft to needs_review'.
  $permissions['moderate news_hub state from draft to needs_review'] = array(
    'name' => 'moderate news_hub state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news_hub state from needs_review to draft'.
  $permissions['moderate news_hub state from needs_review to draft'] = array(
    'name' => 'moderate news_hub state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news_hub state from needs_review to published'.
  $permissions['moderate news_hub state from needs_review to published'] = array(
    'name' => 'moderate news_hub state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate news_hub state from published to needs_review'.
  $permissions['moderate news_hub state from published to needs_review'] = array(
    'name' => 'moderate news_hub state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate pattern_gallery state from draft to needs_review'.
  $permissions['moderate pattern_gallery state from draft to needs_review'] = array(
    'name' => 'moderate pattern_gallery state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate pattern_gallery state from needs_review to draft'.
  $permissions['moderate pattern_gallery state from needs_review to draft'] = array(
    'name' => 'moderate pattern_gallery state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate pattern_gallery state from needs_review to published'.
  $permissions['moderate pattern_gallery state from needs_review to published'] = array(
    'name' => 'moderate pattern_gallery state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate pattern_gallery state from published to needs_review'.
  $permissions['moderate pattern_gallery state from published to needs_review'] = array(
    'name' => 'moderate pattern_gallery state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate pattern_generator state from draft to needs_review'.
  $permissions['moderate pattern_generator state from draft to needs_review'] = array(
    'name' => 'moderate pattern_generator state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate pattern_generator state from needs_review to draft'.
  $permissions['moderate pattern_generator state from needs_review to draft'] = array(
    'name' => 'moderate pattern_generator state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate pattern_generator state from needs_review to published'.
  $permissions['moderate pattern_generator state from needs_review to published'] = array(
    'name' => 'moderate pattern_generator state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate pattern_generator state from published to needs_review'.
  $permissions['moderate pattern_generator state from published to needs_review'] = array(
    'name' => 'moderate pattern_generator state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate press_release state from draft to needs_review'.
  $permissions['moderate press_release state from draft to needs_review'] = array(
    'name' => 'moderate press_release state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate press_release state from needs_review to draft'.
  $permissions['moderate press_release state from needs_review to draft'] = array(
    'name' => 'moderate press_release state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate press_release state from needs_review to published'.
  $permissions['moderate press_release state from needs_review to published'] = array(
    'name' => 'moderate press_release state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate press_release state from published to needs_review'.
  $permissions['moderate press_release state from published to needs_review'] = array(
    'name' => 'moderate press_release state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate press_room state from draft to needs_review'.
  $permissions['moderate press_room state from draft to needs_review'] = array(
    'name' => 'moderate press_room state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate press_room state from needs_review to draft'.
  $permissions['moderate press_room state from needs_review to draft'] = array(
    'name' => 'moderate press_room state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate press_room state from needs_review to published'.
  $permissions['moderate press_room state from needs_review to published'] = array(
    'name' => 'moderate press_room state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate press_room state from published to needs_review'.
  $permissions['moderate press_room state from published to needs_review'] = array(
    'name' => 'moderate press_room state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate project state from draft to needs_review'.
  $permissions['moderate project state from draft to needs_review'] = array(
    'name' => 'moderate project state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate project state from needs_review to draft'.
  $permissions['moderate project state from needs_review to draft'] = array(
    'name' => 'moderate project state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate project state from needs_review to published'.
  $permissions['moderate project state from needs_review to published'] = array(
    'name' => 'moderate project state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate project state from published to needs_review'.
  $permissions['moderate project state from published to needs_review'] = array(
    'name' => 'moderate project state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate promo state from draft to needs_review'.
  $permissions['moderate promo state from draft to needs_review'] = array(
    'name' => 'moderate promo state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate promo state from needs_review to draft'.
  $permissions['moderate promo state from needs_review to draft'] = array(
    'name' => 'moderate promo state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate promo state from needs_review to published'.
  $permissions['moderate promo state from needs_review to published'] = array(
    'name' => 'moderate promo state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate promo state from published to needs_review'.
  $permissions['moderate promo state from published to needs_review'] = array(
    'name' => 'moderate promo state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate qma_homepage state from draft to needs_review'.
  $permissions['moderate qma_homepage state from draft to needs_review'] = array(
    'name' => 'moderate qma_homepage state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate qma_homepage state from needs_review to draft'.
  $permissions['moderate qma_homepage state from needs_review to draft'] = array(
    'name' => 'moderate qma_homepage state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate qma_homepage state from needs_review to published'.
  $permissions['moderate qma_homepage state from needs_review to published'] = array(
    'name' => 'moderate qma_homepage state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate qma_homepage state from published to needs_review'.
  $permissions['moderate qma_homepage state from published to needs_review'] = array(
    'name' => 'moderate qma_homepage state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate social_media_hub state from draft to needs_review'.
  $permissions['moderate social_media_hub state from draft to needs_review'] = array(
    'name' => 'moderate social_media_hub state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate social_media_hub state from needs_review to draft'.
  $permissions['moderate social_media_hub state from needs_review to draft'] = array(
    'name' => 'moderate social_media_hub state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate social_media_hub state from needs_review to published'.
  $permissions['moderate social_media_hub state from needs_review to published'] = array(
    'name' => 'moderate social_media_hub state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate social_media_hub state from published to needs_review'.
  $permissions['moderate social_media_hub state from published to needs_review'] = array(
    'name' => 'moderate social_media_hub state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate whats_on state from draft to needs_review'.
  $permissions['moderate whats_on state from draft to needs_review'] = array(
    'name' => 'moderate whats_on state from draft to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate whats_on state from needs_review to draft'.
  $permissions['moderate whats_on state from needs_review to draft'] = array(
    'name' => 'moderate whats_on state from needs_review to draft',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate whats_on state from needs_review to published'.
  $permissions['moderate whats_on state from needs_review to published'] = array(
    'name' => 'moderate whats_on state from needs_review to published',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate whats_on state from published to needs_review'.
  $permissions['moderate whats_on state from published to needs_review'] = array(
    'name' => 'moderate whats_on state from published to needs_review',
    'roles' => array(),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'publish any content'.
  $permissions['publish any content'] = array(
    'name' => 'publish any content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'publish editable content'.
  $permissions['publish editable content'] = array(
    'name' => 'publish editable content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'Member' => 'Member',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'user',
  );

  // Exported permission: 'submit latitude/longitude'.
  $permissions['submit latitude/longitude'] = array(
    'name' => 'submit latitude/longitude',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'location',
  );

  // Exported permission: 'submit translations to localization server'.
  $permissions['submit translations to localization server'] = array(
    'name' => 'submit translations to localization server',
    'roles' => array(),
    'module' => 'l10n_client',
  );

  // Exported permission: 'toggle field translatability'.
  $permissions['toggle field translatability'] = array(
    'name' => 'toggle field translatability',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate any entity'.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate content'.
  $permissions['translate content'] = array(
    'name' => 'translate content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(),
    'module' => 'locale',
  );

  // Exported permission: 'translate node entities'.
  $permissions['translate node entities'] = array(
    'name' => 'translate node entities',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(),
    'module' => 'i18n_string',
  );

  // Exported permission: 'unlock node feeds'.
  $permissions['unlock node feeds'] = array(
    'name' => 'unlock node feeds',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock user feeds'.
  $permissions['unlock user feeds'] = array(
    'name' => 'unlock user feeds',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unpublish any content'.
  $permissions['unpublish any content'] = array(
    'name' => 'unpublish any content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'unpublish editable content'.
  $permissions['unpublish editable content'] = array(
    'name' => 'unpublish editable content',
    'roles' => array(
      'Content Manager' => 'Content Manager',
    ),
    'module' => 'publishcontent',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(),
    'module' => 'googleanalytics',
  );

  // Exported permission: 'use on-page translation'.
  $permissions['use on-page translation'] = array(
    'name' => 'use on-page translation',
    'roles' => array(),
    'module' => 'l10n_client',
  );

  // Exported permission: 'use text format editor_html'.
  $permissions['use text format editor_html'] = array(
    'name' => 'use text format editor_html',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
      'Member' => 'Member',
      'Press' => 'Press',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format php_code'.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'use workbench_moderation my drafts tab'.
  $permissions['use workbench_moderation my drafts tab'] = array(
    'name' => 'use workbench_moderation my drafts tab',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'use workbench_moderation needs review tab'.
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view all unpublished content'.
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation history'.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation messages'.
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Content Editor' => 'Content Editor',
      'Content Manager' => 'Content Manager',
      'Education Department Staff' => 'Education Department Staff',
      'Educator Staff' => 'Educator Staff',
      'Member Data Exporter' => 'Member Data Exporter',
    ),
    'module' => 'system',
  );

  return $permissions;
}
