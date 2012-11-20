<?php
/**
 * @file staff_arts.module.inc
 * Module functions not provided by the feature.
 */

/**
 * Implements hook_init()
 * */
function staff_arts_init() {
  drupal_add_css(drupal_get_path('module', 'staff_arts') . '/css/staff_arts.css');
}

/**
 * Implements hook_element_info_alter().
 */
function staff_arts_element_info_alter(&$type) {
  $type['link_field']['#process'][] = '_staff_arts_link_field_process';
}

/**
 * Process callback.
 *
 * Modify element titles on the building link field in the staff node type.
 */
function _staff_arts_link_field_process($element, $form_state, $complete_form) {
  if ($element['#field_name'] == 'field_staff_building') {
    $element['title']['#title'] = t('Building name');
    $element['url']['#title'] = t('Map link');
  }
  return $element;
}
