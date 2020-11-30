<?php
/**
 * @file
 * qma_instagram.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function qma_instagram_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupagram_import';
  $strongarm->value = 0;
  $export['drupagram_import'] = $strongarm;

  return $export;
}
