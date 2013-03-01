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

  return $data;
}
