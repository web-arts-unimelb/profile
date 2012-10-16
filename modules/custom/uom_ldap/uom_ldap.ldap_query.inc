<?php
/**
 * @file
 * uom_ldap.ldap_query.inc
 */

/**
 * Implements hook_default_ldap_query().
 */
function uom_ldap_default_ldap_query() {
  $export = array();

  $qid = new stdClass();
  $qid->disabled = FALSE; /* Edit this to true to make a default qid disabled initially */
  $qid->api_version = 1;
  $qid->qid = 'arts_staff';
  $qid->name = 'Arts Staff';
  $qid->sid = 'centaur';
  $qid->status = TRUE;
  $qid->base_dn_str = 'ou=people,o=unimelb';
  $qid->filter = '(&(ou=Arts))';
  $qid->attributes_str = '';
  $qid->sizelimit = 0;
  $qid->timelimit = 0;
  $qid->deref = FALSE;
  $qid->scope = TRUE;
  $export['arts_staff'] = $qid;

  return $export;
}
