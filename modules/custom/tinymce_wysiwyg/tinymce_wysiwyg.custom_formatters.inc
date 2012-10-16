<?php
/**
 * @file
 * tinymce_wysiwyg.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function tinymce_wysiwyg_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'unimel_download_large';
  $formatter->label = 'unimel download large';
  $formatter->description = 'Styles a file field that users can download as per the Unimelb branding.';
  $formatter->mode = 'php';
  $formatter->field_types = 'file';
  $formatter->code = 'foreach ($variables[\'#items\'] as $item) {
  $filepath = file_create_url($item[\'uri\']);
  $filesize = format_size($item[\'filesize\']);
  $filetype = explode(\'.\', $item[\'filename\']);

  $output = l(
    \'<strong>Download</strong>\' . $item[\'filename\'] . \'<em>(\' . $filesize . \')</em>\',
    $filepath,
    array(
      \'attributes\' => array(
        \'class\' => \'icon document large\',
        \'rel\' => $filetype[1],
      ),
      \'html\' => TRUE,
    )
  );
  print $output;
}';
  $formatter->fapi = '';
  $export['unimel_download_large'] = $formatter;

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'unimel_download_small';
  $formatter->label = 'unimel download small';
  $formatter->description = 'Styles a file field that users can download as per the Unimelb branding.';
  $formatter->mode = 'php';
  $formatter->field_types = 'file';
  $formatter->code = 'foreach ($variables[\'#items\'] as $item) {
  $filepath = file_create_url($item[\'uri\']);
  $filesize = format_size($item[\'filesize\']);

  $output = l(
    $item[\'filename\'] . \'<em>(\' . $filesize . \')</em>\',
    $filepath,
    array(
      \'attributes\' => array(
        \'class\' => \'icon document\',
      ),
      \'html\' => TRUE,
    )
  );
  return $output;
}';
  $formatter->fapi = '';
  $export['unimel_download_small'] = $formatter;

  return $export;
}
