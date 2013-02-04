<?php
/**
 * @file
 * uom_slider.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function uom_slider_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'banner_link';
  $formatter->label = 'Banner link';
  $formatter->description = 'Extracts the banner image link and displays it by itself.';
  $formatter->mode = 'php';
  $formatter->field_types = 'linkimagefield';
  $formatter->code = 'foreach ($variables[\'#items\'] as $item) {
  if (empty($item[\'url\'])) {
    continue;
  }

  $attributes = array(
    \'title\' => $item[\'title\'],
    \'target\' => $item[\'target\'],
    \'rel\' => $item[\'rel\'],
    \'class\' => $item[\'class\'],
  );

  print url($item[\'url\'], array(\'absolute\' => TRUE, \'attributes\' => $attributes));
}';
  $formatter->fapi = '';
  $export['banner_link'] = $formatter;

  return $export;
}
