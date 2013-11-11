<?php
/**
 * @file
 * uom_ldap.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uom_ldap_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|user|user|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '3',
    'children' => array(
      0 => 'group_misc',
      1 => 'group_profile_contact',
      2 => 'group_profile_fae',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'classes' => ' group-details field-group-accordion',
        'effect' => 'bounceslide',
      ),
    ),
  );
  $export['group_details|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_misc|user|user|form';
  $field_group->group_name = 'group_misc';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Preferences',
    'weight' => '8',
    'children' => array(
      0 => 'field_profile_hide',
      1 => 'field_sort_weight',
      2 => 'redirect',
      3 => 'account',
      4 => 'timezone',
      5 => 'wysiwyg',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Preferences',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-misc field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_misc|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_contact|user|user|form';
  $field_group->group_name = 'group_profile_contact';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Contact details',
    'weight' => '5',
    'children' => array(
      0 => 'field_profile_display_name',
      1 => 'field_profile_phone',
      2 => 'field_profile_position',
      3 => 'field_profile_room',
      4 => 'field_profile_title',
      5 => 'field_profile_profile',
      6 => 'field_profile_images',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Contact details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-profile-contact field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_profile_contact|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_fae|user|user|form';
  $field_group->group_name = 'group_profile_fae';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_details';
  $field_group->data = array(
    'label' => 'Find an Expert',
    'weight' => '7',
    'children' => array(
      0 => 'field_fae_resource',
      1 => 'field_person_type',
      2 => 'field_person_area',
      3 => 'field_person_supervision',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Find an Expert',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-profile-fae field-group-accordion-item',
        'description' => 'Only fill out information for academic staff that need Find an Expert data displayed on their user profile.',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_profile_fae|user|user|form'] = $field_group;

  return $export;
}
