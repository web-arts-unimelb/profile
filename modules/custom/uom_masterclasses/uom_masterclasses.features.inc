<?php
/**
 * @file
 * uom_masterclasses.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uom_masterclasses_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function uom_masterclasses_node_info() {
  $items = array(
    'masterclass' => array(
      'name' => t('Masterclass'),
      'base' => 'node_content',
      'description' => t('Use the <em>masterclass</em> type to add masterclasses.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
