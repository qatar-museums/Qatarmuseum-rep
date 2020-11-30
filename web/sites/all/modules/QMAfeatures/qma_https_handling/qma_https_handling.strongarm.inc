<?php
/**
 * @file
 * qma_https_handling.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function qma_https_handling_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_debug';
  $strongarm->value = 0;
  $export['securepages_debug'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_enable';
  $strongarm->value = '1';
  $export['securepages_enable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_forms';
  $strongarm->value = 'user_login
user_login_block
qma_forms_interview_question_form
qma_forms_press_question_form
qma_forms_resource_question_form';
  $export['securepages_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_ignore';
  $strongarm->value = '';
  $export['securepages_ignore'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_pages';
  $strongarm->value = 'batch*
batch/*
node/add*
node/*/edit
node/*/delete
node/*/moderation
node/*/moderation/*
user
user/*
admin
admin/*
our-membership-programme
imce*
import/*';
  $export['securepages_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_secure';
  $strongarm->value = '1';
  $export['securepages_secure'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_switch';
  $strongarm->value = TRUE;
  $export['securepages_switch'] = $strongarm;

  return $export;
}
