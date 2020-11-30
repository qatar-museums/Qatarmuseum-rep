<?php
/**
 * @file
 * qma_workbench_view_overrides.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function qma_workbench_view_overrides_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: views_view
  $overrides["views_view.workbench_recent_content.display|block_1|display_options|filters|current"] = array(
    'id' => 'current',
    'table' => 'workbench_moderation_node_history',
    'field' => 'current',
    'value' => 1,
  );
  $overrides["views_view.workbench_recent_content.display|block_1|display_options|filters|status"]["DELETED"] = TRUE;
  $overrides["views_view.workbench_recent_content.display|default|display_options|fields|language"] = array(
    'id' => 'language',
    'table' => 'node',
    'field' => 'language',
  );
  $overrides["views_view.workbench_recent_content.display|default|display_options|fields|published"] = array(
    'id' => 'published',
    'table' => 'workbench_moderation_node_history',
    'field' => 'published',
    'not' => 0,
  );
  $overrides["views_view.workbench_recent_content.display|default|display_options|fields|state"] = array(
    'id' => 'state',
    'table' => 'workbench_moderation_node_history',
    'field' => 'state',
    'machine_name' => 0,
  );
  $overrides["views_view.workbench_recent_content.display|default|display_options|filters|current"] = array(
    'id' => 'current',
    'table' => 'workbench_moderation_node_history',
    'field' => 'current',
    'value' => 1,
  );
  $overrides["views_view.workbench_recent_content.display|default|display_options|filters|published"] = array(
    'id' => 'published',
    'table' => 'workbench_moderation_node_history',
    'field' => 'published',
    'value' => 'All',
    'exposed' => TRUE,
    'expose' => array(
      'operator_id' => '',
      'label' => 'Published',
      'operator' => 'published_op',
      'identifier' => 'published',
      'remember_roles' => array(
        2 => 2,
        1 => 0,
        9 => 0,
        10 => 0,
        7 => 0,
        8 => 0,
        16 => 0,
        11 => 0,
      ),
    ),
  );
  $overrides["views_view.workbench_recent_content.display|default|display_options|filters|status"]["DELETED"] = TRUE;
  $overrides["views_view.workbench_recent_content.display|default|display_options|filters|status_extra"]["DELETED"] = TRUE;
  $overrides["views_view.workbench_recent_content.display|default|display_options|style_options|info|language"] = array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  );
  $overrides["views_view.workbench_recent_content.display|default|display_options|use_ajax"] = TRUE;
  $overrides["views_view.workbench_recent_content.display|page_1|display_options|fields|language"] = array(
    'id' => 'language',
    'table' => 'node',
    'field' => 'language',
  );
  $overrides["views_view.workbench_recent_content.display|page_1|display_options|fields|published"] = array(
    'id' => 'published',
    'table' => 'workbench_moderation_node_history',
    'field' => 'published',
    'not' => 0,
  );
  $overrides["views_view.workbench_recent_content.display|page_1|display_options|fields|state"] = array(
    'id' => 'state',
    'table' => 'workbench_moderation_node_history',
    'field' => 'state',
    'machine_name' => 0,
  );
  $overrides["views_view.workbench_recent_content.display|page_1|display_options|fields|status"]["DELETED"] = TRUE;

 return $overrides;
}
