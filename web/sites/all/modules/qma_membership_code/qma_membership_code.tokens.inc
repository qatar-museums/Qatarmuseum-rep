<?php

/**
 * @file
 * qma_membership_code.tokens.inc
 */


/**
 * Implements hook_token_info().
 */
function qma_membership_code_token_info() {
  $info = array();

  $info['tokens']['user']['membership-number'] = array(
    'name' => t('Membership number', array(), array('context' => 'QMA')),
    'description' => t('The membership number generated from the uid', array(), array('context' => 'QMA'))
  );

  return $info;
}

/**
 * Implements hook_tokens().
 */
function qma_membership_code_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  if ($type === 'user' && !empty($data['user'])) {
    $user = $data['user'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'membership-number':
          $replacements[$original] = qma_membership_code_membership_number($user->uid);
          break;
      }
    }
  }

  return $replacements;
}
