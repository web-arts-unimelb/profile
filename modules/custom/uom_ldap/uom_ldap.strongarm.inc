<?php
/**
 * @file
 * uom_ldap.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uom_ldap_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ldap_authentication_conf';
  $strongarm->value = array(
    'sids' => array(
      'staff_ad1' => 'staff_ad1',
    ),
    'authenticationMode' => 1,
    'loginConflictResolve' => 2,
    'acctCreation' => 4,
    'loginUIUsernameTxt' => 'Enter your University of Melbourne username',
    'loginUIPasswordTxt' => 'Enter your University of Melbourne password',
    'ldapUserHelpLinkUrl' => 'http://www.its.unimelb.edu.au/support/accounts/passwords',
    'ldapUserHelpLinkText' => 'ITS Password Help',
    'emailOption' => 3,
    'emailUpdate' => 1,
    'allowOnlyIfTextInDn' => array(),
    'excludeIfTextInDn' => array(),
    'allowTestPhp' => '',
    'excludeIfNoAuthorizations' => NULL,
    'ssoRemoteUserStripDomainName' => NULL,
    'seamlessLogin' => NULL,
    'ldapImplementation' => NULL,
    'cookieExpire' => NULL,
  );
  $export['ldap_authentication_conf'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ldap_profile_conf';
  $strongarm->value = array(
    'ldap_fields' => array(
      0 => 'cn',
      1 => 'mail',
    ),
    'mapping' => array(
      'username' => 'cn',
      'mail' => 'mail',
      'field_profile_display_name' => 'displayname',
      'field_profile_phone' => 'telephonenumber',
      'field_profile_room' => 'physicaldeliveryofficename',
      'field_profile_title' => 'uomtitle',
    ),
    'derivedMapping' => array(
      'field_profile_display_name' => array(
        'derive' => FALSE,
        'derive_value' => '',
      ),
      'field_profile_room' => array(
        'derive' => FALSE,
        'derive_value' => '',
      ),
      'field_profile_phone' => array(
        'derive' => FALSE,
        'derive_value' => '',
      ),
      'field_profile_title' => array(
        'derive' => FALSE,
        'derive_value' => '',
      ),
    ),
  );
  $export['ldap_profile_conf'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ldap_servers_encryption';
  $strongarm->value = 10;
  $export['ldap_servers_encryption'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ldap_servers_require_ssl_for_credentails';
  $strongarm->value = 0;
  $export['ldap_servers_require_ssl_for_credentails'] = $strongarm;

  return $export;
}
