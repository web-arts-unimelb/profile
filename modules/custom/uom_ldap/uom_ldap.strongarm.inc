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
      'centaur' => 'centaur',
    ),
    'authenticationMode' => 1,
    'loginConflictResolve' => 2,
    'acctCreation' => 4,
    'loginUIUsernameTxt' => 'Your University username',
    'loginUIPasswordTxt' => 'University password',
    'ldapUserHelpLinkUrl' => NULL,
    'ldapUserHelpLinkText' => 'Logon Help',
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

  return $export;
}