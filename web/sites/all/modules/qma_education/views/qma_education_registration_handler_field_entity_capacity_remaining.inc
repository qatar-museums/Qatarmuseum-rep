<?php
/**
 * @file
 * Display remaining slots for a registration entity.
 */


/**
 * Views handler to display the number of spaces remaining for a registration
 * slot.
 *
 * @todo the method of loading the settings and count seems inelegant.
 */
class qma_education_registration_handler_field_entity_capacity_remaining extends views_handler_field_numeric {
  function render($values) {
    $entity_id = $this->get_value($values);
    $table = $this->table;
    $alias = $this->field_alias;

    $startdate = $values->field_field_qma_edu_reg_date[0]['raw']['value'];
    $enddate = $values->field_field_qma_edu_reg_date[0]['raw']['value2'];
    $settings = registration_entity_settings('node', $values->node_registration_nid);

    $slots_available = (int) qma_education_registration_event_count('node', $values->node_registration_nid, $startdate, $enddate);
    $slots_booked = $settings['capacity'] - $slots_available;

    $values->$alias = $slots_booked;
    return parent::render($values);
  }
}
