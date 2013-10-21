<?php
/**
 * @file
 */

/**
 * Overview form of all components for this webform.
 */
function uom_webform_remedy_form($form, $form_state, $node) {
  $form['#tree'] = TRUE;
  $form['#node'] = $node;

  $form['remedy_note'] = array(
    '#markup' => t('The webform component <em>form_keys</em> should match the BSM Remedy form element names.'),
  );

  $form['remedy'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send the contents of this form to BSM Remedy'),
    '#options' => array(0, 1),
    '#description' => t('When checked, this webform will submit its data to BSM Remedy.'),
    '#default_value' => $node->webform['remedy']['remedy'],
  );

  $form['remedy_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Remedy form URL'),
    '#default_value' => $node->webform['remedy']['remedy_url'],
    '#description' => t('The BSM Remedy form processor to send the results of this webform to.'),
  );

  $form['remedy_method'] = array(
    '#type' => 'select',
    '#title' => t('Remedy request type'),
    '#default_value' => $node->webform['remedy']['remedy_method'],
    '#description' => t('The HTTP request method to use for the submission.'),
    '#options' => array('POST' => t('POST'), 'GET' => t('GET')),
  );

  $form['actions'] = array(
    '#type' => 'actions',
    '#tree' => FALSE,
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
    '#submit' => array('uom_webform_remedy_form_submit'),
  );

  return $form;
}

/**
 * Validate handler for uom_webform_remedy_form().
 */
function uom_webform_remedy_form_validate($form, $form_state) {
  $values = $form_state['values'];

  if (!empty($values['remedy_url']) && !valid_url($values['remedy_url'])) {
    form_set_error('remedy_url', t('You must enter a valid URL'));
  }
  else if (!empty($values['remedy']) && !valid_url($values['remedy_url'])) {
    form_set_error('remedy_url', t('You must enter a valid URL'));
  }
}

/**
 * Submit handler for uom_webform_remedy_form().
 */
function uom_webform_remedy_form_submit($form, &$form_state) {
  $node = $form['#node'];

  $node->webform['remedy'] = array(
    'remedy' => $form_state['values']['remedy'],
    'remedy_url' => $form_state['values']['remedy_url'],
    'remedy_method' => $form_state['values']['remedy_method'],
  );
  node_save($node);
  drupal_set_message(t('BSM Remedy settings for %title saved.', array('%title' => $node->title)));
}
