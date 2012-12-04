<?php
/**
 * @file
 * staff_arts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function staff_arts_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function staff_arts_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function staff_arts_node_info() {
  $items = array(
    'staff' => array(
      'name' => t('Staff'),
      'base' => 'node_content',
      'description' => t('A <em>Staff</em> node holds basic contact information about staff members, which is displayed on staff and contact pages.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
