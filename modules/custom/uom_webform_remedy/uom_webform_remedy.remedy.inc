<?php
/**
 * @file
 */

/**
 * Overview form of all components for this webform.
 */
function uom_webform_remedy_form($form, $form_state, $node) {
  // $form['#tree'] = FALSE;
  $form['#node'] = $node;

  $form['remedy_note'] = array(
  );

  $form['remedy'] = array(
    '#type' => 'checkbox',
    '#title' => t('Send the contents of this form to BSM Remedy'),
    '#description' => t('When checked, this webform will submit its data to BSM Remedy.'),
    '#options' => array(0, 1),
    '#default_value' => $node->webform['remedy']['remedy'],
  );

  $form['set'] = array(
    '#type' => 'fieldset',
    '#title' => t('Remedy options'),
    '#description' => t('Please enter the BSM Remedy form processor details. Note that on each webform component, the <strong>form_key</strong> value <em>must</em> match the BSM Remedy form element name.'),
    '#collapsible' => TRUE,
    '#states' => array(
      'expanded' => array(
        '[name="remedy"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['set']['remedy_group'] = array(
    '#type' => 'textfield',
    '#title' => t('Remedy Group'),
    '#description' => t('When checked, this webform will submit its data to BSM Remedy.'),
    '#default_value' => $node->webform['remedy']['remedy_group'],
    '#size' => 32,
    '#maxsize' => 32,
  );

  $form['set']['remedy_method'] = array(
    '#type' => 'select',
    '#title' => t('Remedy request type'),
    '#description' => t('The HTTP request method to use for the submission.'),
    '#options' => array('POST' => t('POST'), 'GET' => t('GET')),
    '#default_value' => $node->webform['remedy']['remedy_method'],
  );

  $form['set']['remedy_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Remedy form URL'),
    '#description' => t('The BSM Remedy form processor to send the results of this webform to.'),
    '#default_value' => $node->webform['remedy']['remedy_url'],
  );

  $form['set']['remedy_return_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Remedy return URL'),
    '#description' => t('The BSM Remedy form that the processor should read its response from.'),
    '#default_value' => $node->webform['remedy']['remedy_return_url'],
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
  else if (!empty($values['remedy']) && empty($values['remedy_group'])) {
    form_set_error('remedy_group', t('You must enter a Remedy Group code'));
  }
  else if (!empty($values['remedy']) && !valid_url($values['remedy_return_url'])) {
    form_set_error('remedy_return_url', t('You must enter a valid return URL'));
  }
}

/**
 * Submit handler for uom_webform_remedy_form().
 */
function uom_webform_remedy_form_submit($form, &$form_state) {
  $node = $form['#node'];

  $node->webform['remedy'] = array(
    'remedy' => $form_state['values']['remedy'],
    'remedy_group' => $form_state['values']['remedy_group'],
    'remedy_url' => $form_state['values']['remedy_url'],
    'remedy_return_url' => $form_state['values']['remedy_return_url'],
    'remedy_method' => $form_state['values']['remedy_method'],
  );
  node_save($node);
  drupal_set_message(t('BSM Remedy settings for %title saved.', array('%title' => $node->title)));
}
