<?php

/**
 * @file
 * qma_membership_code.pages.inc
 */


/**
 * Page callback function for membership page.
 */
function qma_membership_code_membership_card() {
  global $user;
  $user_wrapper = entity_metadata_wrapper('user', user_load($user->uid));

  $content = array();

  $content['wrapper'] = array(
    '#prefix' => '<div class="membership-card">',
    '#suffix' => '</div>',
  );

  $content['wrapper']['image'] = array(
    '#theme' => 'image',
    '#path' => drupal_get_path('module', 'qma_membership_code') . '/images/membership-card.png',
  );

  $content['wrapper']['membership_number'] = array(
    '#prefix' => '<div class="membership-card-number">',
    '#markup' => qma_membership_code_membership_number($user->uid),
    '#suffix' => '</div>',
  );

  $content['wrapper']['membership_name'] = array(
    '#prefix' => '<div class="membership-card-name">',
    '#markup' => $user_wrapper->field_first_name->value() . ' ' . $user_wrapper->field_last_name->value(),
    '#suffix' => '</div>',
  );

  return $content;
}