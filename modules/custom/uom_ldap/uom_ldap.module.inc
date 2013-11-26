<?php
/**
 * @file
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function uom_ldap_form_user_profile_form_alter(&$form, &$form_state) {
  // Require 'administer users' access to see the Find an Expert and Preferences
  // tab groups.
  // @see https://drupal.org/node/1324860
  if (!user_access('administer users') && module_exists('field_group')) {
    field_group_hide_field_groups($form, array('group_profile_fae', 'group_misc'));
  }
}

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
  if ($view->name == 'staff') {

    // Load the professional staff tid, we'll need it.
    $tid = &drupal_static(__FUNCTION__);
    if (empty($tid)) {
      $tid = db_query("SELECT t.tid FROM {taxonomy_term_data} t INNER JOIN {taxonomy_vocabulary} v ON (t.vid = v.vid AND v.machine_name = 'person_type') WHERE t.name = :name", array(':name' => t('Professional')))->fetchField();
    }

    // Main page display, only ever list academic staff.
    if ($view->current_display == 'academic') {
      foreach ($view->result as $i => $result) {
        $wrapper = entity_metadata_wrapper('user', $result->_field_data['uid']['entity']);
        // Remove all professionals.
        foreach ($wrapper->field_person_type->value() as $term) {
          if ($term->tid == $tid) {
            unset($view->result[$i]);
          }
          $type = $wrapper->field_person_type->value();
          $area = $wrapper->field_person_area->value();
        }
        // Remove everyone who has neither a subject area nor a staff type.
        if (empty($result->_field_data['uid']['entity']->field_person_type) && empty($result->_field_data['uid']['entity']->field_person_area)) {
          unset($view->result[$i]);
        }
      }

      // Hide study area listing if 'professional' staff type was selected.
      if (!empty($view->exposed_raw_input['field_person_type_tid'][$tid])) {
        unset($view->result);
      }

      if (!empty($view->exposed_raw_input['field_person_area_tid'])) {
        // Remove rows from output if the selected staff type filter is not their current group.
        foreach ($view->result as $i => $result) {
          if (!in_array($result->field_data_field_person_area_field_person_area_tid, $view->exposed_raw_input['field_person_area_tid'])) {
            unset($view->result[$i]);
          }
          // And remove professional from this display as well. They have an attachment.
          if (in_array($result->field_data_field_person_area_field_person_area_tid, $tid)) {
            unset($view->result[$i]);
          }
        }
        // Remove the attachment with professional staff, an academic type was selected.
        $view->attachment_after = '';
      }

      // Hide the professional staff attachment if filtering on supervision.
      if (!empty($view->exposed_raw_input['field_person_supervision_value'])) {
         $view->attachment_after = '';
      }
    }
    if ($view->current_display == 'professional') {
      // Remove all non-professional staff from the attachment view.
      foreach ($view->result as $i => $result) {
        if ($result->field_data_field_person_type_field_person_type_tid != $tid) {
          unset($view->result[$i]);
        }
      }
    }
  }
}

/**
 * Implements hook_preprocess_views_view_table().
 *
 * Mess with one of the uom_ldap staff list tables.
 */
function uom_ldap_preprocess_views_view_table(&$vars) {
  // Hide the table of 'honorary' staff from output, since it only applies
  // to staff that are tagged with at least one other term as well. However,
  // show them if it is the ONLY selected filter.
  // if ($vars['view']->name == 'staff' && $vars['view']->current_display == 'academic') {
  //   // dpm(__FUNCTION__);
  //   if ($vars['title'] == t('Professional')) {
  //     $vars['options']['empty table'] = 1;
  //   }
  // }
  // $vars['title'] == t('Research only') || $vars['title'] == t('Teaching and Research') || $vars['title'] == t('Honorary'))) {
  // unset ($vars['title'], $vars['header'], $vars['rows']);
  // $vars['options']['empty_table'] = 1;
}
