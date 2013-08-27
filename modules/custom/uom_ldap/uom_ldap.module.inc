<?php
/**
 * @file
 */

/**
 * hook_views_query_alter().
 */
function uom_ldap_views_query_alter(&$view, &$query) {
  if ($view->name == 'staff') {
    foreach ($query->orderby as &$field) {
      // Sort *no* weight to the bottom, not the top.
      if (strpos($field['field'], 'taxonomy_term_data_') === 0) {
        $field['field'] = 'IFNULL(' . $field['field'] . ', 999)';
      }
    }
    unset($field);
  }
}
