<?php
/**
 * @file
 */

/**
 * Implements hook_views_data_alter().
 */
function staff_arts_views_data_alter(&$data) {
  $data['taxonomy_term_data']['description']['sort'] = array(
    'handler' => 'views_handler_sort',
  );
}
