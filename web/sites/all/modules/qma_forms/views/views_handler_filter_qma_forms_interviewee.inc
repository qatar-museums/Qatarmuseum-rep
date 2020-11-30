<?php

/**
 * @file
 * Definition of views_handler_filter_qma_forms_interviewee.
 */

/**
 * Filter by interviewee name.
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_qma_forms_interviewee extends views_handler_filter_in_operator {
  function get_value_options() {
    if (isset($this->value_options)) {
      return;
    }

    $this->value_options = array();
    $interviewees = qma_forms_get_interviewees();

    foreach ($interviewees as $interviewee) {
      $this->value_options[$interviewee] = $interviewee;
    }
  }
}
