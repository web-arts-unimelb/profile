<?php
/**
 * @file
 */

/**
 * Implements hook_views_query_alter().
 */
function uom_ldap_views_query_alter(&$view, &$query) {
  if ($view->name == 'staff') {
    // Override the staff list view. Sort items without weight to the bottom of the list.
    foreach ($query->orderby as &$field) {
      // Sort *no* weight to the bottom, not the top.
      if (strpos($field['field'], 'taxonomy_term_data_') === 0) {
        $field['field'] = 'IFNULL(' . $field['field'] . ', 999)';
      }
    }
    // Remove the temp var.
    unset($field);
  }
}

/**
 * Implements hook_views_post_execute().
 */
function uom_ldap_views_post_execute(&$view) {
  if ($view->name == 'staff' && $view->current_display == 'page') {
    // Hide study area listing if a staff type was selected.
    if (!empty($view->exposed_raw_input['field_person_type_tid'])) {
      unset($view->result);
    }
    // Hide staff type listing if a study area was selected.
    if (!empty($view->exposed_raw_input['field_person_area_tid'])) {
      unset($view->attachment_after);
    }
  }
}
