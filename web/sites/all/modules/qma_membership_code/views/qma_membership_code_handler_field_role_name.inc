<?php

/**
 * @file
 * Definition of qma_membership_code_handler_field_user_roles_name.
 */

/**
 * Field handler to provide a list of roles.
 *
 * @ingroup qma_membership_code_field_handlers
 */
class qma_membership_code_handler_field_role_name extends views_handler_field_prerender_list {
  function construct() {
    parent::construct();
    $this->additional_fields['uid'] = array('table' => 'users', 'field' => 'uid');
  }

  function query() {
    $this->add_additional_fields();
    $this->field_alias = $this->aliases['uid'];
  }

  function pre_render(&$values) {
    $uids = array();
    $this->items = array();

    foreach ($values as $result) {
      $uids[] = $this->get_value($result, NULL, TRUE);
    }

    if ($uids) {
      $result = db_query("SELECT u.uid, u.rid, r.name FROM {role} r INNER JOIN {users_roles} u ON u.rid = r.rid WHERE u.uid IN (:uids) ORDER BY r.name", array(':uids' => $uids));

      foreach ($result as $role) {
        $this->items[$role->uid][$role->name]['role'] = check_plain($role->name);
        $this->items[$role->uid][$role->name]['rid'] = $role->rid;
      }
    }
  }

  function render_item($count, $item) {
    return $item['role'];
  }
}
