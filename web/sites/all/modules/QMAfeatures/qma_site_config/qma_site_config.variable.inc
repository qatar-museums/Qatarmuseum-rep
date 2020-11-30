<?php
/**
 * @file
 * qma_site_config.variable.inc
 */

/**
 * Implements hook_variable_realm_default_variables().
 */
function qma_site_config_variable_realm_default_variables() {
$realm_variables = array();
  $realm_variables['language']['ar'] = array(
  'site_frontpage' => 'node/3846',
  'site_name' => 'متاحف قطر',
  'site_slogan' => '',
);
  $realm_variables['language']['en'] = array(
  'site_frontpage' => 'node/3841',
  'site_name' => 'Qatar Museums',
  'site_slogan' => '',
);

return $realm_variables;
}
