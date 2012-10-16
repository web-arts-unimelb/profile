<?php
/**
 * @file
 * tinymce_wysiwyg.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function tinymce_wysiwyg_filter_default_formats() {
  $formats = array();

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'wysiwyg_fields' => array(
        'weight' => '50',
        'status' => '1',
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
