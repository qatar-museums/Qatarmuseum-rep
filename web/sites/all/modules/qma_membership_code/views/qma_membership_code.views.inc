<?php

/**
 * @file
 * qma_membership_code.views.inc 
 */


/**
 * Implements hook_views_data_alter().
 *
 * Adds the ability to filter on a role by name, rather than rid.
 */
function qma_membership_code_views_data_alter(&$data) {
  $data['role']['table']['group']  = t('User');

  $data['role']['name'] = array(
    'title' => t('Roles (by name)'),
    'help' => t('Roles that a user belongs to.'),
    'field' => array(
      'handler' => 'qma_membership_code_handler_field_role_name',
      'no group by' => TRUE,
    ),
    'filter' => array(
      'handler' => 'qma_membership_code_handler_filter_role_name',
      'numeric' => TRUE,
      'allow empty' => TRUE,
    ),
    'argument' => array(
      'handler' => 'qma_membership_code_handler_argument_role_name',
      'name table' => 'role',
      'name field' => 'name',
      'empty field name' => t('No role'),
      'zero is null' => TRUE,
      'numeric' => TRUE,
    ),
  );
}