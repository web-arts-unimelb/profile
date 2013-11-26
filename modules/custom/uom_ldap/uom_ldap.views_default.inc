<?php
/**
 * @file
 * uom_ldap.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uom_ldap_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'staff';
  $view->description = 'Provides a flexible list of staff members.';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Staff';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Our staff';
  $handler->display->display_options['css_class'] = 'grouped-staff-list';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_person_area_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_person_type_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'nothing_1',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'field_award_study_area' => 'field_award_study_area',
    'field_person_type' => 'field_person_type',
    'nothing_1' => 'nothing_1',
    'uid' => 'uid',
    'mail' => 'mail',
    'field_profile_phone' => 'field_profile_phone',
    'field_profile_display_name' => 'field_profile_display_name',
    'field_profile_position' => 'field_profile_position',
    'nothing' => 'nothing',
    'draggableviews' => 'draggableviews',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_award_study_area' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_person_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_display_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_position' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'draggableviews' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: User: Subject area (field_person_area) */
  $handler->display->display_options['relationships']['field_person_area_tid']['id'] = 'field_person_area_tid';
  $handler->display->display_options['relationships']['field_person_area_tid']['table'] = 'field_data_field_person_area';
  $handler->display->display_options['relationships']['field_person_area_tid']['field'] = 'field_person_area_tid';
  $handler->display->display_options['relationships']['field_person_area_tid']['label'] = 'Subject area';
  /* Relationship: User: Staff type (field_person_type) */
  $handler->display->display_options['relationships']['field_person_type_tid']['id'] = 'field_person_type_tid';
  $handler->display->display_options['relationships']['field_person_type_tid']['table'] = 'field_data_field_person_type';
  $handler->display->display_options['relationships']['field_person_type_tid']['field'] = 'field_person_type_tid';
  $handler->display->display_options['relationships']['field_person_type_tid']['label'] = 'Staff type';
  /* Field: Content: Area of study */
  $handler->display->display_options['fields']['field_award_study_area']['id'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['field'] = 'field_award_study_area';
  $handler->display->display_options['fields']['field_award_study_area']['label'] = '';
  $handler->display->display_options['fields']['field_award_study_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_award_study_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_award_study_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_award_study_area']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_award_study_area']['delta_offset'] = '0';
  /* Field: User: Staff type */
  $handler->display->display_options['fields']['field_person_type']['id'] = 'field_person_type';
  $handler->display->display_options['fields']['field_person_type']['table'] = 'field_data_field_person_type';
  $handler->display->display_options['fields']['field_person_type']['field'] = 'field_person_type';
  $handler->display->display_options['fields']['field_person_type']['label'] = '';
  $handler->display->display_options['fields']['field_person_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_person_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_person_type']['delta_offset'] = '0';
  /* Field: Grouping field */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Grouping field';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_award_study_area] [field_person_type]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['text'] = '<strong>Email:</strong> [mail]';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  /* Field: User: Phone */
  $handler->display->display_options['fields']['field_profile_phone']['id'] = 'field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['table'] = 'field_data_field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['field'] = 'field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['label'] = '';
  $handler->display->display_options['fields']['field_profile_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['text'] = '<strong>Phone:</strong> [field_profile_phone]';
  $handler->display->display_options['fields']['field_profile_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_phone']['type'] = 'unimelb_html5_phone_link';
  /* Field: User: Display name */
  $handler->display->display_options['fields']['field_profile_display_name']['id'] = 'field_profile_display_name';
  $handler->display->display_options['fields']['field_profile_display_name']['table'] = 'field_data_field_profile_display_name';
  $handler->display->display_options['fields']['field_profile_display_name']['field'] = 'field_profile_display_name';
  $handler->display->display_options['fields']['field_profile_display_name']['label'] = 'Staff member';
  $handler->display->display_options['fields']['field_profile_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_profile_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_profile_display_name']['element_class'] = 'staff-name';
  $handler->display->display_options['fields']['field_profile_display_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_display_name']['element_default_classes'] = FALSE;
  /* Field: User: Position */
  $handler->display->display_options['fields']['field_profile_position']['id'] = 'field_profile_position';
  $handler->display->display_options['fields']['field_profile_position']['table'] = 'field_data_field_profile_position';
  $handler->display->display_options['fields']['field_profile_position']['field'] = 'field_profile_position';
  $handler->display->display_options['fields']['field_profile_position']['element_class'] = 'staff-position';
  $handler->display->display_options['fields']['field_profile_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_position']['element_default_classes'] = FALSE;
  /* Field: Contact info */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Contact info';
  $handler->display->display_options['fields']['nothing']['label'] = 'Contact';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<strong>Email:</strong> [mail]<br />
    [field_profile_phone]';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'staff-contact';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Draggableviews: User */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'users';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = 'Weight';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['handler'] = 'draggableviews_handler_fieldapi';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['draggableviews_handler_fieldapi'] = array(
    'field' => 'field_data_field_sort_weight:field_sort_weight_value',
  );
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight_1']['id'] = 'weight_1';
  $handler->display->display_options['sorts']['weight_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight_1']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight_1']['relationship'] = 'field_person_area_tid';
  $handler->display->display_options['sorts']['weight_1']['expose']['label'] = 'Weight';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_person_type_tid';
  /* Sort criterion: User: Sort weight (field_sort_weight) */
  $handler->display->display_options['sorts']['field_sort_weight_value']['id'] = 'field_sort_weight_value';
  $handler->display->display_options['sorts']['field_sort_weight_value']['table'] = 'field_data_field_sort_weight';
  $handler->display->display_options['sorts']['field_sort_weight_value']['field'] = 'field_sort_weight_value';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Do not show on staff lists (field_profile_hide) */
  $handler->display->display_options['filters']['field_profile_hide_value']['id'] = 'field_profile_hide_value';
  $handler->display->display_options['filters']['field_profile_hide_value']['table'] = 'field_data_field_profile_hide';
  $handler->display->display_options['filters']['field_profile_hide_value']['field'] = 'field_profile_hide_value';
  $handler->display->display_options['filters']['field_profile_hide_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_profile_hide_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: User: Display name (field_profile_display_name) */
  $handler->display->display_options['filters']['field_profile_display_name_value']['id'] = 'field_profile_display_name_value';
  $handler->display->display_options['filters']['field_profile_display_name_value']['table'] = 'field_data_field_profile_display_name';
  $handler->display->display_options['filters']['field_profile_display_name_value']['field'] = 'field_profile_display_name_value';
  $handler->display->display_options['filters']['field_profile_display_name_value']['operator'] = 'not empty';
  /* Filter criterion: Content: Area of study (field_award_study_area) */
  $handler->display->display_options['filters']['field_award_study_area_tid']['id'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['table'] = 'field_data_field_award_study_area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['field'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['value'] = array(
    5 => '5',
    6 => '6',
    7 => '7',
    8 => '8',
    9 => '9',
    10 => '10',
    11 => '11',
    12 => '12',
    13 => '13',
  );
  $handler->display->display_options['filters']['field_award_study_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['operator_id'] = 'field_award_study_area_tid_op';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['label'] = 'Filter by study area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['operator'] = 'field_award_study_area_tid_op';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['identifier'] = 'field_award_study_area_tid';
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_award_study_area_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_award_study_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_award_study_area_tid']['vocabulary'] = 'study_area';
  $handler->display->display_options['filters']['field_award_study_area_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_award_study_area_tid']['error_message'] = FALSE;
  /* Filter criterion: User: Staff type (field_person_type) */
  $handler->display->display_options['filters']['field_person_type_tid']['id'] = 'field_person_type_tid';
  $handler->display->display_options['filters']['field_person_type_tid']['table'] = 'field_data_field_person_type';
  $handler->display->display_options['filters']['field_person_type_tid']['field'] = 'field_person_type_tid';
  $handler->display->display_options['filters']['field_person_type_tid']['value'] = array(
    14 => '14',
    16 => '16',
    15 => '15',
  );
  $handler->display->display_options['filters']['field_person_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['operator_id'] = 'field_person_type_tid_op';
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['label'] = 'Filter by type';
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['operator'] = 'field_person_type_tid_op';
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['identifier'] = 'field_person_type_tid';
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_person_type_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_person_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_person_type_tid']['vocabulary'] = 'person_type';
  $handler->display->display_options['filters']['field_person_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_person_type_tid']['error_message'] = FALSE;

  /* Display: Academic staff */
  $handler = $view->new_display('page', 'Academic staff', 'academic');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_person_area_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_person_type_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_person_supervision_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_person_area',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'field_person_area' => 'field_person_area',
    'uid' => 'uid',
    'mail' => 'mail',
    'field_profile_phone' => 'field_profile_phone',
    'field_profile_title' => 'field_profile_title',
    'field_profile_display_name' => 'field_profile_display_name',
    'field_profile_position' => 'field_profile_position',
    'nothing' => 'nothing',
    'draggableviews' => 'draggableviews',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_person_area' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_display_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_position' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'draggableviews' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Staff type */
  $handler->display->display_options['fields']['field_person_type']['id'] = 'field_person_type';
  $handler->display->display_options['fields']['field_person_type']['table'] = 'field_data_field_person_type';
  $handler->display->display_options['fields']['field_person_type']['field'] = 'field_person_type';
  $handler->display->display_options['fields']['field_person_type']['label'] = '';
  $handler->display->display_options['fields']['field_person_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_person_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_person_type']['delta_offset'] = '0';
  /* Field: User: Subject area */
  $handler->display->display_options['fields']['field_person_area']['id'] = 'field_person_area';
  $handler->display->display_options['fields']['field_person_area']['table'] = 'field_data_field_person_area';
  $handler->display->display_options['fields']['field_person_area']['field'] = 'field_person_area';
  $handler->display->display_options['fields']['field_person_area']['label'] = '';
  $handler->display->display_options['fields']['field_person_area']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_person_area']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_person_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_area']['empty'] = '[field_person_type] ';
  $handler->display->display_options['fields']['field_person_area']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_person_area']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_person_area']['delta_offset'] = '0';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['text'] = '<strong>Email:</strong> [mail]';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  /* Field: User: Phone */
  $handler->display->display_options['fields']['field_profile_phone']['id'] = 'field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['table'] = 'field_data_field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['field'] = 'field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['label'] = '';
  $handler->display->display_options['fields']['field_profile_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['text'] = '<strong>Phone:</strong> [field_profile_phone]';
  $handler->display->display_options['fields']['field_profile_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_phone']['type'] = 'unimelb_html5_phone_link';
  /* Field: User: Title */
  $handler->display->display_options['fields']['field_profile_title']['id'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['table'] = 'field_data_field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['field'] = 'field_profile_title';
  $handler->display->display_options['fields']['field_profile_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_title']['type'] = 'text_plain';
  /* Field: User: Display name */
  $handler->display->display_options['fields']['field_profile_display_name']['id'] = 'field_profile_display_name';
  $handler->display->display_options['fields']['field_profile_display_name']['table'] = 'field_data_field_profile_display_name';
  $handler->display->display_options['fields']['field_profile_display_name']['field'] = 'field_profile_display_name';
  $handler->display->display_options['fields']['field_profile_display_name']['label'] = 'Staff member';
  $handler->display->display_options['fields']['field_profile_display_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_display_name']['alter']['text'] = '[field_profile_title] [field_profile_display_name]';
  $handler->display->display_options['fields']['field_profile_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_profile_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_profile_display_name']['element_class'] = 'staff-name';
  $handler->display->display_options['fields']['field_profile_display_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_display_name']['element_default_classes'] = FALSE;
  /* Field: User: Position */
  $handler->display->display_options['fields']['field_profile_position']['id'] = 'field_profile_position';
  $handler->display->display_options['fields']['field_profile_position']['table'] = 'field_data_field_profile_position';
  $handler->display->display_options['fields']['field_profile_position']['field'] = 'field_profile_position';
  $handler->display->display_options['fields']['field_profile_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_position']['element_class'] = 'staff-position';
  $handler->display->display_options['fields']['field_profile_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_position']['element_default_classes'] = FALSE;
  /* Field: Contact info */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Contact info';
  $handler->display->display_options['fields']['nothing']['label'] = 'Contact';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<strong>Email:</strong> [mail]<br />
    [field_profile_phone]';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'staff-contact';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Draggableviews: User */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'users';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = 'Weight';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['handler'] = 'draggableviews_handler_fieldapi';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['draggableviews_handler_fieldapi'] = array(
    'field' => 'field_data_field_sort_weight:field_sort_weight_value',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Do not show on staff lists (field_profile_hide) */
  $handler->display->display_options['filters']['field_profile_hide_value']['id'] = 'field_profile_hide_value';
  $handler->display->display_options['filters']['field_profile_hide_value']['table'] = 'field_data_field_profile_hide';
  $handler->display->display_options['filters']['field_profile_hide_value']['field'] = 'field_profile_hide_value';
  $handler->display->display_options['filters']['field_profile_hide_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_profile_hide_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_profile_hide_value']['group'] = 1;
  /* Filter criterion: User: Display name (field_profile_display_name) */
  $handler->display->display_options['filters']['field_profile_display_name_value']['id'] = 'field_profile_display_name_value';
  $handler->display->display_options['filters']['field_profile_display_name_value']['table'] = 'field_data_field_profile_display_name';
  $handler->display->display_options['filters']['field_profile_display_name_value']['field'] = 'field_profile_display_name_value';
  $handler->display->display_options['filters']['field_profile_display_name_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_profile_display_name_value']['group'] = 1;
  /* Filter criterion: User: Subject area (field_person_area) */
  $handler->display->display_options['filters']['field_person_area_tid']['id'] = 'field_person_area_tid';
  $handler->display->display_options['filters']['field_person_area_tid']['table'] = 'field_data_field_person_area';
  $handler->display->display_options['filters']['field_person_area_tid']['field'] = 'field_person_area_tid';
  $handler->display->display_options['filters']['field_person_area_tid']['value'] = array(
    18 => '18',
    16 => '16',
    15 => '15',
    17 => '17',
  );
  $handler->display->display_options['filters']['field_person_area_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_person_area_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_person_area_tid']['expose']['operator_id'] = 'field_person_area_tid_op';
  $handler->display->display_options['filters']['field_person_area_tid']['expose']['label'] = 'Filter by subject area';
  $handler->display->display_options['filters']['field_person_area_tid']['expose']['operator'] = 'field_person_area_tid_op';
  $handler->display->display_options['filters']['field_person_area_tid']['expose']['identifier'] = 'field_person_area_tid';
  $handler->display->display_options['filters']['field_person_area_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_person_area_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_person_area_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_person_area_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_person_area_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_person_area_tid']['vocabulary'] = 'subject_area';
  /* Filter criterion: User: Staff type (field_person_type) */
  $handler->display->display_options['filters']['field_person_type_tid']['id'] = 'field_person_type_tid';
  $handler->display->display_options['filters']['field_person_type_tid']['table'] = 'field_data_field_person_type';
  $handler->display->display_options['filters']['field_person_type_tid']['field'] = 'field_person_type_tid';
  $handler->display->display_options['filters']['field_person_type_tid']['value'] = array(
    19 => '19',
    13 => '13',
    11 => '11',
    12 => '12',
  );
  $handler->display->display_options['filters']['field_person_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_person_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['operator_id'] = 'field_person_type_tid_op';
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['label'] = 'Filter by staff type';
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['operator'] = 'field_person_type_tid_op';
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['identifier'] = 'field_person_type_tid';
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_person_type_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_person_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_person_type_tid']['vocabulary'] = 'person_type';
  /* Filter criterion: User: Supervision (field_person_supervision) */
  $handler->display->display_options['filters']['field_person_supervision_value']['id'] = 'field_person_supervision_value';
  $handler->display->display_options['filters']['field_person_supervision_value']['table'] = 'field_data_field_person_supervision';
  $handler->display->display_options['filters']['field_person_supervision_value']['field'] = 'field_person_supervision_value';
  $handler->display->display_options['filters']['field_person_supervision_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_person_supervision_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_person_supervision_value']['expose']['operator_id'] = 'field_person_supervision_value_op';
  $handler->display->display_options['filters']['field_person_supervision_value']['expose']['label'] = 'Filter by supervision';
  $handler->display->display_options['filters']['field_person_supervision_value']['expose']['operator'] = 'field_person_supervision_value_op';
  $handler->display->display_options['filters']['field_person_supervision_value']['expose']['identifier'] = 'field_person_supervision_value';
  $handler->display->display_options['filters']['field_person_supervision_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_person_supervision_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_person_supervision_value']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['field_person_supervision_value']['group_info']['label'] = 'Supervision (field_person_supervision)';
  $handler->display->display_options['filters']['field_person_supervision_value']['group_info']['identifier'] = 'field_person_supervision_value';
  $handler->display->display_options['filters']['field_person_supervision_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_person_supervision_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['path'] = 'about/staff';

  /* Display: Professional staff */
  $handler = $view->new_display('attachment', 'Professional staff', 'professional');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_person_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'field_person_type' => 'field_person_type',
    'uid' => 'uid',
    'mail' => 'mail',
    'field_profile_phone' => 'field_profile_phone',
    'field_profile_display_name' => 'field_profile_display_name',
    'field_profile_position' => 'field_profile_position',
    'nothing' => 'nothing',
    'draggableviews' => 'draggableviews',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_person_type' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_display_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_profile_position' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'draggableviews' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No staff match your filter criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'complete_full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Staff type */
  $handler->display->display_options['fields']['field_person_type']['id'] = 'field_person_type';
  $handler->display->display_options['fields']['field_person_type']['table'] = 'field_data_field_person_type';
  $handler->display->display_options['fields']['field_person_type']['field'] = 'field_person_type';
  $handler->display->display_options['fields']['field_person_type']['label'] = '';
  $handler->display->display_options['fields']['field_person_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_person_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_person_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_person_type']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_person_type']['delta_offset'] = '0';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['text'] = '<strong>Email:</strong> [mail]';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  /* Field: User: Phone */
  $handler->display->display_options['fields']['field_profile_phone']['id'] = 'field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['table'] = 'field_data_field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['field'] = 'field_profile_phone';
  $handler->display->display_options['fields']['field_profile_phone']['label'] = '';
  $handler->display->display_options['fields']['field_profile_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_profile_phone']['alter']['text'] = '<strong>Phone:</strong> [field_profile_phone]';
  $handler->display->display_options['fields']['field_profile_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_phone']['type'] = 'unimelb_html5_phone_link';
  /* Field: User: Display name */
  $handler->display->display_options['fields']['field_profile_display_name']['id'] = 'field_profile_display_name';
  $handler->display->display_options['fields']['field_profile_display_name']['table'] = 'field_data_field_profile_display_name';
  $handler->display->display_options['fields']['field_profile_display_name']['field'] = 'field_profile_display_name';
  $handler->display->display_options['fields']['field_profile_display_name']['label'] = 'Staff member';
  $handler->display->display_options['fields']['field_profile_display_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_profile_display_name']['alter']['path'] = 'user/[uid]';
  $handler->display->display_options['fields']['field_profile_display_name']['element_class'] = 'staff-name';
  $handler->display->display_options['fields']['field_profile_display_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_display_name']['element_default_classes'] = FALSE;
  /* Field: User: Position */
  $handler->display->display_options['fields']['field_profile_position']['id'] = 'field_profile_position';
  $handler->display->display_options['fields']['field_profile_position']['table'] = 'field_data_field_profile_position';
  $handler->display->display_options['fields']['field_profile_position']['field'] = 'field_profile_position';
  $handler->display->display_options['fields']['field_profile_position']['element_class'] = 'staff-position';
  $handler->display->display_options['fields']['field_profile_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_position']['element_default_classes'] = FALSE;
  /* Field: Contact info */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Contact info';
  $handler->display->display_options['fields']['nothing']['label'] = 'Contact';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<strong>Email:</strong> [mail]<br />
    [field_profile_phone]';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'staff-contact';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Draggableviews: User */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'users';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['label'] = 'Weight';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['handler'] = 'draggableviews_handler_fieldapi';
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['draggableviews_handler_fieldapi'] = array(
    'field' => 'field_data_field_sort_weight:field_sort_weight_value',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Do not show on staff lists (field_profile_hide) */
  $handler->display->display_options['filters']['field_profile_hide_value']['id'] = 'field_profile_hide_value';
  $handler->display->display_options['filters']['field_profile_hide_value']['table'] = 'field_data_field_profile_hide';
  $handler->display->display_options['filters']['field_profile_hide_value']['field'] = 'field_profile_hide_value';
  $handler->display->display_options['filters']['field_profile_hide_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_profile_hide_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_profile_hide_value']['group'] = 1;
  /* Filter criterion: User: Staff type (field_person_type) */
  $handler->display->display_options['filters']['field_person_type_tid_1']['id'] = 'field_person_type_tid_1';
  $handler->display->display_options['filters']['field_person_type_tid_1']['table'] = 'field_data_field_person_type';
  $handler->display->display_options['filters']['field_person_type_tid_1']['field'] = 'field_person_type_tid';
  $handler->display->display_options['filters']['field_person_type_tid_1']['operator'] = 'and';
  $handler->display->display_options['filters']['field_person_type_tid_1']['value'] = array(
    12 => '12',
  );
  $handler->display->display_options['filters']['field_person_type_tid_1']['group'] = 1;
  $handler->display->display_options['filters']['field_person_type_tid_1']['type'] = 'select';
  $handler->display->display_options['filters']['field_person_type_tid_1']['vocabulary'] = 'person_type';
  /* Filter criterion: User: Display name (field_profile_display_name) */
  $handler->display->display_options['filters']['field_profile_display_name_value']['id'] = 'field_profile_display_name_value';
  $handler->display->display_options['filters']['field_profile_display_name_value']['table'] = 'field_data_field_profile_display_name';
  $handler->display->display_options['filters']['field_profile_display_name_value']['field'] = 'field_profile_display_name_value';
  $handler->display->display_options['filters']['field_profile_display_name_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_profile_display_name_value']['group'] = 1;
  /* Filter criterion: User: Staff type (field_person_type) */
  $handler->display->display_options['filters']['field_person_type_tid']['id'] = 'field_person_type_tid';
  $handler->display->display_options['filters']['field_person_type_tid']['table'] = 'field_data_field_person_type';
  $handler->display->display_options['filters']['field_person_type_tid']['field'] = 'field_person_type_tid';
  $handler->display->display_options['filters']['field_person_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_person_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['operator_id'] = 'field_person_type_tid_op';
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['label'] = 'Filter by type';
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['operator'] = 'field_person_type_tid_op';
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['identifier'] = 'field_person_type_tid';
  $handler->display->display_options['filters']['field_person_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_person_type_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_person_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_person_type_tid']['vocabulary'] = 'person_type';
  $handler->display->display_options['filters']['field_person_type_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_person_type_tid']['error_message'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'academic' => 'academic',
    'default' => 0,
    'block_1' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $handler->display->display_options['inherit_arguments'] = FALSE;

  /* Display: Profile Gallery */
  $handler = $view->new_display('block', 'Profile Gallery', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Images */
  $handler->display->display_options['fields']['field_profile_images']['id'] = 'field_profile_images';
  $handler->display->display_options['fields']['field_profile_images']['table'] = 'field_data_field_profile_images';
  $handler->display->display_options['fields']['field_profile_images']['field'] = 'field_profile_images';
  $handler->display->display_options['fields']['field_profile_images']['label'] = '';
  $handler->display->display_options['fields']['field_profile_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_images']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_profile_images']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_profile_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_images']['type'] = 'colorbox';
  $handler->display->display_options['fields']['field_profile_images']['settings'] = array(
    'colorbox_node_style' => 'profile_gallery_thumb',
    'colorbox_image_style' => '',
    'colorbox_gallery' => 'post',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'title',
    'colorbox_caption_custom' => '',
  );
  $handler->display->display_options['fields']['field_profile_images']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_profile_images']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  $export['staff'] = $view;

  return $export;
}
