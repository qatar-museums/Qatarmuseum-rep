<?php

/**
 * @file
 * Definition of qma_membership_code_handler_argument_users_roles_name.
 */

/**
 * Allow role ID(s) as argument.
 *
 * @ingroup qma_membership_code_field_handlers
 */
class qma_membership_code_handler_argument_role_name extends views_handler_argument_many_to_one {
  function title_query() {
    $titles = array();

    $result = db_query("SELECT name FROM {role} WHERE name IN (:names)", array(':names' => $this->value));
    foreach ($result as $term) {
      $titles[] = check_plain($term->name);
    }
    return $titles;
  }
}
