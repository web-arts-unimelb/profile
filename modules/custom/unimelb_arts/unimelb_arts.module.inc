<?php
/**
 * @file unimelb_arts.module.inc
 * Defines Drupal hooks and functions that would be wiped from the module
 * file by a `drush feature update'.
 */

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function unimelb_arts_form_node_form_alter(&$form, &$form_state, $form_id) {
  $form['body'][$form['language']['#value']][0]['summary']['#title'] = t('Front page summary');
  $form['body'][$form['language']['#value']][0]['summary']['#description'] = t('The front page summary is displayed only on the front page. You can leave it blank for any @node that does not display on the front page.', array('@node' => $form['type']['#value']));
  $form['body'][$form['language']['#value']][0]['summary']['#attached']['js'][0] = drupal_get_path('module', 'unimelb_arts') . '/summary.js';
}
