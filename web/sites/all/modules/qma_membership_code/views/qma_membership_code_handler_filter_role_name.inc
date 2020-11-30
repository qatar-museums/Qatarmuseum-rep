<?php

/**
 * @file
 * Definition of qma_membership_code_handler_filter_user_roles_name.
 */

/**
 * Filter handler for user roles.
 *
 * @ingroup qma_membership_code_filter_handlers
 */
class qma_membership_code_handler_filter_role_name extends views_handler_filter_many_to_one {
  function get_value_options() {
    $options = array();
    $roles = user_roles(TRUE);
    unset($roles[DRUPAL_AUTHENTICATED_RID]);

    foreach ($roles as $role) {
      $options[$role] = check_plain($role);
    }

    $this->value_options = $options;
  }

  /**
   * Override empty and not empty operator labels to be clearer for user roles.
   */
  function operators() {
    $operators = parent::operators();
    $operators['empty']['title'] = t("Only has the 'authenticated user' role");
    $operators['not empty']['title'] = t("Has roles in addition to 'authenticated user'");
    return $operators;
  }
}
