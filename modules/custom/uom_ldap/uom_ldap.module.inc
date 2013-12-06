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

		//test
		//dsm($view);

    // Load the professional staff tid, we'll need it.
    $tid = &drupal_static(__FUNCTION__);
    if (empty($tid)) {
      $tid = db_query("SELECT t.tid FROM {taxonomy_term_data} t INNER JOIN {taxonomy_vocabulary} v ON (t.vid = v.vid AND v.machine_name = 'person_type') WHERE t.name = :name", array(':name' => t('Professional')))->fetchField();
    }

    // Main page display, only ever list academic staff.
		// NOTE: $view->current_display as 'academic' or 'profesional' or both
    if ($view->current_display == 'academic') {
			//test 
      //watchdog("current_display_academic", '<pre>'. print_r($view->exposed_raw_input, true). "</pre>");

      // Did we want to only see professionals? Hide the academic view.
      if ($view->exposed_raw_input['field_person_type_tid'] == $tid) {
				if( empty($view->exposed_raw_input['field_person_area_tid']) && 
						empty($view->exposed_raw_input['field_person_supervision_value'])
				) {
					// Professional filter is selected, hide the filter result from academic view, but show
        	// the result from attachment.
					unset($view->result);
					unset($view->field['draggableviews']); // Remove save button
				}

				if(!empty($view->exposed_raw_input['field_person_area_tid']) || !empty($view->exposed_raw_input['field_person_supervision_value'])) {
					unset($view->field['draggableviews']); // Remove save button
				}

				// We need to return early and let the default view to handle filtering.
        return;
      }

			// It is save to remove all professional staff
      foreach ($view->result as $i => $result) {
        $wrapper = entity_metadata_wrapper('user', $result->_field_data['uid']['entity']);
        // Remove all professionals.
        foreach ($wrapper->field_person_type->value() as $term) {
          if ($term->tid == $tid) {
            unset($view->result[$i]);
            continue;
          }
          $type = $wrapper->field_person_type->value();
          $area = $wrapper->field_person_area->value();
        }
        // Remove everyone who has neither a subject area nor a staff type.
        if (empty($result->_field_data['uid']['entity']->field_person_type) && empty($result->_field_data['uid']['entity']->field_person_area)) 			 {
          unset($view->result[$i]);
          continue;
        }

        // Always remove professionals from the academic view.
				if(isset($result->field_data_field_person_type_field_person_type_tid)) {
        	if ($result->field_data_field_person_type_field_person_type_tid == $tid) {
          	unset($view->result[$i]);
          	continue;
       		}
				}
      }

      if (!empty($view->exposed_raw_input['field_person_area_tid'])) {
        // Remove rows from output if the selected staff type filter is not their current group.
        foreach ($view->result as $i => $result) {
          if (!in_array($result->field_data_field_person_area_field_person_area_tid, $view->exposed_raw_input['field_person_area_tid'])) {
            unset($view->result[$i]);
            continue;
          }
          // And remove professional from this display as well. They have an attachment.
          if ($result->field_data_field_person_area_field_person_area_tid == $tid) {
            unset($view->result[$i]);
            continue;
          }
        }

        // Remove the attachment with professional staff, an academic type was selected!
        $view->attachment_after = '';
      }

      // Hide the professional staff attachment if filtering on supervision.
      if (!empty($view->exposed_raw_input['field_person_supervision_value'])) {
         $view->attachment_after = '';
      }
    }

    // dpm($view->exposed_raw_input, 'input');

    // Nothing at all if anything is selected that isn't "Professional".
    if ($view->current_display == 'professional') {

			//test
			//watchdog("current_display_prof", '<pre>'. print_r($view->exposed_raw_input, true). "</pre>");

      if ((!empty($view->exposed_raw_input['field_person_area_tid']) || !empty($view->exposed_raw_input['field_person_supervision_value']) || 
      (!empty($view->exposed_raw_input['field_person_type_tid']) && $view->exposed_raw_input['field_person_type_tid'] != 'All' && $view->exposed_raw_input['field_person_type_tid'] != $tid))) {
        $view->result = array();
      }
    }

		// If no view result for academic view and professional view, hide save button
		//watchdog("current_display_prof", '<pre>'. print_r($view->result, true). "</pre>");
		if(is_array($view->result) && count($view->result) == 0) {
			unset($view->field['draggableviews']); // Remove save button
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


/**
 * Implements hook_user_presave().
 */
function uom_ldap_user_presave(&$edit, $account, $category) {
	if(
			isset($account->field_profile_title) && 
			isset($edit['field_profile_title']['und'][0]['value'])
	) {
		$edit['field_profile_title']['und'][0]['value'] = ucwords(strtolower($edit['field_profile_title']['und'][0]['value']));
  }
}
