<?php
/**
 * @file
 * staff_arts.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function staff_arts_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'staff_lists';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Staff lists';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'staff',
      'display' => 'page',
      'args' => 'office-of-the-dean',
      'title' => 'Office of the Dean',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'staff',
      'display' => 'page',
      'args' => 'associate-and-assistant-deans',
      'title' => 'Associate and Assistant Deans',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'staff',
      'display' => 'page',
      'args' => 'school-heads-and-managers',
      'title' => 'School Heads and Managers',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'staff',
      'display' => 'page',
      'args' => 'office-of-graduate-studies',
      'title' => 'Office of Graduate Studies',
      'weight' => '-97',
      'type' => 'view',
    ),
    4 => array(
      'vid' => 'staff',
      'display' => 'page',
      'args' => 'arts-student-centre',
      'title' => 'Arts Student Centre',
      'weight' => '-96',
      'type' => 'view',
    ),
    5 => array(
      'vid' => 'staff',
      'display' => 'page',
      'args' => 'arts-business-centre',
      'title' => 'Arts Business Centre',
      'weight' => '-95',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'accordion';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array(
    'history' => 1,
    'jquery_ui' => array(
      'autoHeight' => 0,
      'collapsible' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Arts Business Centre');
  t('Arts Student Centre');
  t('Associate and Assistant Deans');
  t('Office of Graduate Studies');
  t('Office of the Dean');
  t('School Heads and Managers');
  t('Staff lists');

  $export['staff_lists'] = $quicktabs;

  return $export;
}
