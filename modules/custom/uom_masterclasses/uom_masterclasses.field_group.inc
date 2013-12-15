<?php
/**
 * @file
 * uom_masterclasses.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uom_masterclasses_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shared_media|node|masterclass|form';
  $field_group->group_name = 'group_shared_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'masterclass';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Insert Media',
    'weight' => '7',
    'children' => array(
      0 => 'field_shared_attachments',
      1 => 'field_shared_images',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Insert Media',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-shared-media field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_shared_media|node|masterclass|form'] = $field_group;

  return $export;
}
