<?php
/**
 * @file
 * uom_ldap.ldap_servers.inc
 */

/**
 * Implements hook_default_ldap_servers().
 */
function uom_ldap_default_ldap_servers() {
  $export = array();

  $ldap_servers_conf = new stdClass();
  $ldap_servers_conf->disabled = FALSE; /* Edit this to true to make a default ldap_servers_conf disabled initially */
  $ldap_servers_conf->api_version = 1;
  $ldap_servers_conf->sid = 'staff_ad1';
  $ldap_servers_conf->name = 'Staff AD Server';
  $ldap_servers_conf->status = TRUE;
  $ldap_servers_conf->ldap_type = 'ad';
  $ldap_servers_conf->address = 'ldaps://ad1.unimelb.edu.au';
  $ldap_servers_conf->port = 636;
  $ldap_servers_conf->tls = FALSE;
  $ldap_servers_conf->bind_method = TRUE;
  $ldap_servers_conf->binddn = 'cn=100us-WebLDAP,ou=Local Accounts,ou=100,ou=Business Units,dc=unimelb,dc=edu,dc=au';
  $ldap_servers_conf->bindpw = 'changeme';
  $ldap_servers_conf->basedn = array(
    0 => 'dc=unimelb,dc=edu,dc=au',
  );
  $ldap_servers_conf->user_attr = 'cn';
  $ldap_servers_conf->account_name_attr = '';
  $ldap_servers_conf->mail_attr = 'mail';
  $ldap_servers_conf->mail_template = '';
  $ldap_servers_conf->allow_conflicting_drupal_accts = FALSE;
  $ldap_servers_conf->unique_persistent_attr = '';
  $ldap_servers_conf->user_dn_expression = '';
  $ldap_servers_conf->ldap_to_drupal_user = '';
  $ldap_servers_conf->testing_drupal_username = '';
  $ldap_servers_conf->group_object_category = '';
  $ldap_servers_conf->search_pagination = FALSE;
  $ldap_servers_conf->search_page_size = 1000;
  $ldap_servers_conf->weight = 0;
  $export['staff_ad1'] = $ldap_servers_conf;

  return $export;
}
