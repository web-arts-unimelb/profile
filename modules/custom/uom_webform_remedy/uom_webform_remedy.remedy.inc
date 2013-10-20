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

    dpm($form, '$form');
    dpm($form_state, '$form_state');
    dpm($node, '$node');

  $form['remedy'] = array(
    '#type' => 'checkbox',
    '#title' => t('Post the contents of this form to BSM Remedy'),
    '#options' => array(0, 1),
    '#required' => TRUE,
    '#description' => t('When checked, this webform will submit its data to BSM Remedy.'),
  );

  $form['remedy_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Remedy form URL'),
    '#required' => TRUE,
    '#default_value' => (TRUE) ? '' : 'http://servicedesk.unimelb.edu.au',
    '#description' => 

  return $form;
}
