<?php

/**
 * @file
 * qma_forms.admin.inc
 */


/** 
 * Admin form for qma_forms email.
 */
function qma_forms_email_admin_form($form, &$form_state) {
  $form = array();

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Interview question notification e-mail address', array(), array('context' => 'QMA')),
    '#description' => t('The e-mail address that new questions will be sent to.', array(), array('context' => 'QMA')),
    '#default_value' => variable_get('qma_forms_admin_email', ''),
  );
  
  $form['press_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Press question notification e-mail address', array(), array('context' => 'QMA')),
    '#description' => t('The e-mail address that new questions will be sent to.', array(), array('context' => 'QMA')),
    '#default_value' => variable_get('qma_forms_admin_press_email', ''),
  );
  
  $form['resource_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Creative resource question notification e-mail address', array(), array('context' => 'QMA')),
    '#description' => t('The e-mail address that new questions will be sent to.', array(), array('context' => 'QMA')),
    '#default_value' => variable_get('qma_forms_admin_resource_email', ''),
  );

  $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => t('Save', array(), array('context' => 'QMA')),
    '#weight' => 99,
  );

  return $form;
}

/** 
 * Admin form validation function.
 */
function qma_forms_email_admin_form_validate($form, &$form_state) {
  $email = trim($form_state['values']['email']);
  $press_email = trim($form_state['values']['press_email']);
  $resource_email = trim($form_state['values']['resource_email']);

  if (empty($email)) {
    form_set_error('email', t('Please enter a value for the interview notification e-mail address', array(), array('context' => 'QMA')));
  }
  
  if (empty($press_email)) {
    form_set_error('press_email', t('Please enter a value for the press notification e-mail address', array(), array('context' => 'QMA')));
  }
  
    if (empty($resource_email)) {
    form_set_error('resource_email', t('Please enter a value for the creative resource notification e-mail address', array(), array('context' => 'QMA')));
  }

  if (!preg_match('/.+@.+/', $email)) {
    form_set_error('email', t('Please enter a valid e-mail address for interview notifications', array(), array('context' => 'QMA')));
  }
  
  if (!preg_match('/.+@.+/', $press_email)) {
    form_set_error('press_email', t('Please enter a valid e-mail address for press notifications', array(), array('context' => 'QMA')));
  }
  
   if (!preg_match('/.+@.+/', $resource_email)) {
    form_set_error('resource_email', t('Please enter a valid e-mail address for creative resource notifications', array(), array('context' => 'QMA')));
  }
}

/** 
 * Admin form submission function.
 */
function qma_forms_email_admin_form_submit($form, &$form_state) {
  variable_set('qma_forms_admin_email', filter_xss($form_state['values']['email']));
  variable_set('qma_forms_admin_press_email', filter_xss($form_state['values']['press_email']));
  variable_set('qma_forms_admin_resource_email', filter_xss($form_state['values']['resource_email']));
}
