<?php
/**
 * @file
 */

/**
 * Implements hook_views_data().
 */
function views_multiple_field_views_data() {
  $data['views']['views_multiple_field'] = array(
    'title' => t('Multiple Fields'),
    'group' => t('Faculty of Arts'),
    'help' => t('Process multiple field values into one.'),
    'field' => array(
      'help' => t('Process multiple field values into one.'),
      'handler' => 'views_multiple_field_handler_field',
    ),
  );
  return $data;
}
