<?php
/**
 * @file
 * unimelb_arts.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function unimelb_arts_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shared_metadata|node|event|form';
  $field_group->group_name = 'group_shared_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta Tags',
    'weight' => '10',
    'children' => array(
      0 => 'field_shared_keywords',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Meta Tags',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_shared_metadata|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shared_metadata|node|news|form';
  $field_group->group_name = 'group_shared_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta Tags',
    'weight' => '6',
    'children' => array(
      0 => 'field_shared_keywords',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Meta Tags',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_shared_metadata|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shared_metadata|node|page|form';
  $field_group->group_name = 'group_shared_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta Tags',
    'weight' => '8',
    'children' => array(
      0 => 'field_shared_keywords',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_shared_metadata|node|page|form'] = $field_group;

  return $export;
}
