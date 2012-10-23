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
  $form['body'][$form['language']['#value']][0]['summary']['#attached']['js'][0] = drupal_get_path('module', 'unimelb_arts') . '/frontpage-summary.js';
}

/**
 * Implementation of hook_field_widget_form_alter().
 *
 * Add WYSIWYG treatment to textarea summary form items.
 */
function unimelb_arts_field_widget_form_alter(&$element, &$form_state, $context) {
  if (isset($element['summary'])) {
    // Hide the format selector.
    drupal_add_css(drupal_get_path('module', 'unimelb_arts') . '/frontpage-summary.css');
    $element['summary']['#type'] = 'text_format';
    if (module_exists('better_formats')) {
      $element['summary']['#format'] = array_shift(array_filter(array_keys($form_state['field']['body']['und']['instance']['settings']['better_formats']['allowed_formats'])));
    }
    else {
      $element['summary']['#format'] = $element['#format'];
    }
  }
}

/**
 * Implements hook_field_attach_presave().
 */
function unimelb_arts_field_attach_presave($entity_type, $entity) {
  list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);

  foreach (field_info_instances($entity_type, $bundle) as $instance) {
    $field = field_info_field_by_id($instance['field_id']);
    $field_name = $field['field_name'];
    if ($field['type'] == 'text_with_summary' && !empty($entity->$field_name)) {
      $language = $entity->language;
      foreach ($entity->{$field_name}[$language] as $id => &$value) {
        if (is_array($value['summary'])) {
          $value['summary'] = $value['summary']['value'];
        }
      }
    }
  }
}
