<?php
/**
 * @file
 * uom_ldap.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uom_ldap_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "ldap_authorization" && $api == "ldap_authorization") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "ldap_query" && $api == "ldap_query") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "ldap_servers" && $api == "ldap_servers") {
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
function uom_ldap_views_api() {
  return array("version" => "3.0");
}
