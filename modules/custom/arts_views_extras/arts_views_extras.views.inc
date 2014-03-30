<?php
/**
 * @file
 */

/**
 * Implements hook_views_data().
 */
function arts_views_extras_views_data() {
  $data['views']['views_multiple_field'] = array(
    'title' => t('Multiple Fields'),
    'group' => t('Faculty of Arts'),
    'help' => t('Process multiple field values into one.'),
    'field' => array(
      'help' => t('Process multiple field values into one.'),
      'handler' => 'views_multiple_field_handler_field',
    ),
  );

  $data['views']['arts_views_extras_area_search_suggestions'] = array(
    'title' => t('Search suggestions'),
    'group' => t('Faculty of Arts'),
    'help' => t('Provide search suggestions for the area.'),
    'area' => array(
      'help' => t('Provide search suggestions for the area.'),
      'handler' => 'arts_views_extras_area_search_suggestions',
    ),
  );

  $data['views']['arts_views_extras_date_status_field'] = array(
    'title' => t('Status by Date'),
    'group' => t('Faculty of Arts'),
    'help' => t('Provide open of closed status through a date field value.'),
    'field' => array(
      'help' => t('Provide open of closed status through a date field value.'),
      'handler' => 'arts_views_extras_date_status_field',
    ),
  );

  $data['views']['arts_views_extras_query_string_field'] = array(
    'title' => t('Query String'),
    'group' => t('Faculty of Arts'),
    'help' => t('Provide a query string value as a field.'),
    'field' => array(
      'help' => t('Provide a query string value as a field.'),
      'handler' => 'arts_views_extras_query_string_field',
    ),
  );

  return $data;
}

/*
// hook_form_alter
function arts_views_extras_form_alter(&$form, &$form_state, $form_id) {
	if($form_id == 'views_exposed_form') {	
		if(isset($form['field_award_application_date_value'])) {
			$options = array(
				'any' => '- Any -',
		  	'open_soon' => 'Open soon',
		  	'open' => 'Open',
		  	'close' => 'Close',
		  );
		
			$tmp_array = array(
				'#type' => 'select',
				'#options' => $options,
				'#default_value' => 'any',
			);
			
			$form['field_award_application_date_value']['value'] = $tmp_array;
    }
	}
}


// hook_views_query_alter
function arts_views_extras_views_query_alter(&$view, &$query) {
	
	if($view->name == 'awards') {
		if(isset($view->exposed_raw_input['field_award_application_date_value'])) {
			$open_date_status = $view->exposed_raw_input['field_award_application_date_value']['value'];
			
			foreach ($query->where as $key_1 => &$condition_group) {
			  foreach ($condition_group['conditions'] as $key_2 => &$condition) {
			  
			  	// Sample string
					//$dummy_field_name = "DATE_FORMAT(field_data_field_award_application_date.field_award_application_date_value, '%Y-%m-%d') = :field_data_field_award_application_date_field_award_application_date_value";
					
					$needle = 'field_data_field_award_application_date.field_award_application_date_value';
			    if (strstr($condition['field'], $needle)) {
			    	if($open_date_status == 'any') {
			    		unset($query->where[$key_1]['conditions'][$key_2]);
			    	} 
			    	elseif($open_date_status == 'open_soon') {
			    	
					  	$the_field = "DATE_FORMAT(field_data_field_award_application_date.field_award_application_date_value, '%Y-%m-%d') > :field_data_field_award_application_date_field_award_application_date_value";
					  	
					  	$today = date('Y-m-d');
					  
					  	$the_value =  array(':field_data_field_award_application_date_field_award_application_date_value' => $today);
					  
					  	$condition = array(
						    'field' => $the_field,
						    'value' => $the_value,
						    'operator' => 'formula',
						  );
						  
			    	}
			    	elseif($open_date_status == 'open') {
			    	
			    		$today = date('Y-m-d');
			    		
			    		$the_value =  array(':field_data_field_award_application_date_field_award_application_date_value' => $today);
			    	
			    		// Greater
							$the_field = "DATE_FORMAT(field_data_field_award_application_date.field_award_application_date_value, '%Y-%m-%d') <= :field_data_field_award_application_date_field_award_application_date_value";

			    		$condition = array(
						    'field' => $the_field,
						    'value' => $the_value,
						    'operator' => 'formula',
						  );
			    		
			    		
			    		// Less
			    		$the_field_2 = "DATE_FORMAT(field_data_field_award_application_date.field_award_application_date_value2, '%Y-%m-%d') >= :field_data_field_award_application_date_field_award_application_date_value";
			    		
			    		$new_condition = array(
						    'field' => $the_field_2,
						    'value' => $the_value,
						    'operator' => 'formula',
						  );
			    		
			    		$new_key = $key_2 + 1;
			    		$query->where[$key_1]['conditions'][$new_key] = $new_condition;
			    		
			    	}
			    	elseif($open_date_status == 'close') {
			    	
			    		$the_field = "DATE_FORMAT(field_data_field_award_application_date.field_award_application_date_value2, '%Y-%m-%d') < :field_data_field_award_application_date_field_award_application_date_value";
					  	
					  	$today = date('Y-m-d');
					  
					  	$the_value =  array(':field_data_field_award_application_date_field_award_application_date_value' => $today);
					  
					  	$condition = array(
						    'field' => $the_field,
						    'value' => $the_value,
						    'operator' => 'formula',
						  );
						  
			    	}
			    
			    	//dsm($open_date_status);
			    	//dsm($query->where);
			 
			    }
			  }
			}

		}
	}
}
*/


