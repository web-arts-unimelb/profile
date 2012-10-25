<?php
/**
 * @file
 * unimelb_arts.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function unimelb_arts_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'summary_without_images';
  $formatter->label = 'summary without images';
  $formatter->description = 'Displays the body summary or teaser with images removed.';
  $formatter->mode = 'php';
  $formatter->field_types = 'text, text_long, text_with_summary';
  $formatter->code = '$output = \'\';

foreach ($variables[\'#items\'] as $item) {
  $output .= (!empty($item[\'summary\'])) ? $item[\'summary\'] :  text_summary($item[\'value\']);
}

print preg_replace("/<img[^>]+\\>/i", " ", $output);';
  $formatter->fapi = '';
  $export['summary_without_images'] = $formatter;

  return $export;
}
