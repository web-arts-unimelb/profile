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
  if ($module == "ldap_query" && $api == "ldap_query") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "ldap_servers" && $api == "ldap_servers") {
    return array("version" => "1");
  }
}
