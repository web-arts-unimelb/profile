<?php
/**
 * @file
 * staff_arts.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function staff_arts_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'staff';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Staff';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_staff_unit',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'staff-list';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_staff_unit' => 'field_staff_unit',
    'field_staff_building' => 'field_staff_building',
    'field_staff_mail' => 'field_staff_mail',
    'title' => 'title',
    'field_staff_position' => 'field_staff_position',
    'field_staff_phone' => 'field_staff_phone',
    'field_staff_room' => 'field_staff_room',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_staff_unit' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_staff_building' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_staff_mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_staff_position' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_staff_phone' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_staff_room' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Unit */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['ui_name'] = 'Unit';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'terms';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'units' => 'units',
    'keywords' => 0,
    'tags' => 0,
  );
  /* Field: Content: Unit */
  $handler->display->display_options['fields']['field_staff_unit']['id'] = 'field_staff_unit';
  $handler->display->display_options['fields']['field_staff_unit']['table'] = 'field_data_field_staff_unit';
  $handler->display->display_options['fields']['field_staff_unit']['field'] = 'field_staff_unit';
  $handler->display->display_options['fields']['field_staff_unit']['label'] = '';
  $handler->display->display_options['fields']['field_staff_unit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_staff_unit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_unit']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_staff_unit']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_staff_unit']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_staff_unit']['delta_reversed'] = TRUE;
  /* Field: Content: Building */
  $handler->display->display_options['fields']['field_staff_building']['id'] = 'field_staff_building';
  $handler->display->display_options['fields']['field_staff_building']['table'] = 'field_data_field_staff_building';
  $handler->display->display_options['fields']['field_staff_building']['field'] = 'field_staff_building';
  $handler->display->display_options['fields']['field_staff_building']['label'] = '';
  $handler->display->display_options['fields']['field_staff_building']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_staff_building']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_building']['click_sort_column'] = 'url';
  /* Field: Content: Mail */
  $handler->display->display_options['fields']['field_staff_mail']['id'] = 'field_staff_mail';
  $handler->display->display_options['fields']['field_staff_mail']['table'] = 'field_data_field_staff_mail';
  $handler->display->display_options['fields']['field_staff_mail']['field'] = 'field_staff_mail';
  $handler->display->display_options['fields']['field_staff_mail']['label'] = '';
  $handler->display->display_options['fields']['field_staff_mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_staff_mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_mail']['type'] = 'email_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'mailto:[field_staff_mail]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = 'Send an email to [title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_staff_position']['id'] = 'field_staff_position';
  $handler->display->display_options['fields']['field_staff_position']['table'] = 'field_data_field_staff_position';
  $handler->display->display_options['fields']['field_staff_position']['field'] = 'field_staff_position';
  $handler->display->display_options['fields']['field_staff_position']['type'] = 'text_plain';
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_staff_phone']['id'] = 'field_staff_phone';
  $handler->display->display_options['fields']['field_staff_phone']['table'] = 'field_data_field_staff_phone';
  $handler->display->display_options['fields']['field_staff_phone']['field'] = 'field_staff_phone';
  $handler->display->display_options['fields']['field_staff_phone']['type'] = 'unimelb_html5_phone_link';
  $handler->display->display_options['fields']['field_staff_phone']['settings'] = array(
    'relationship' => 'none',
    'ui_name' => '',
    'custom_label' => 0,
    'label' => '',
    'element_label_colon' => 0,
    'exclude' => 0,
    'element_type_enable' => 0,
    'element_type' => '',
    'element_class_enable' => 0,
    'element_class' => '',
    'element_label_type_enable' => 0,
    'element_label_type' => '',
    'element_label_class_enable' => 0,
    'element_label_class' => '',
    'element_wrapper_type_enable' => 0,
    'element_wrapper_type' => '',
    'element_wrapper_class_enable' => 0,
    'element_wrapper_class' => '',
    'element_default_classes' => 0,
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'absolute' => 0,
      'replace_spaces' => 0,
      'external' => 0,
      'path_case' => 'none',
      'link_class' => '',
      'alt' => '',
      'rel' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 0,
      'ellipsis' => 0,
      'more_link' => 0,
      'more_link_text' => '',
      'more_link_path' => '',
      'html' => 0,
      'strip_tags' => 0,
      'preserve_tags' => '',
      'trim_whitespace' => 0,
      'nl2br' => 0,
    ),
    'empty' => '',
    'empty_zero' => 0,
    'hide_empty' => 0,
    'hide_alter_empty' => 0,
    'click_sort_column' => '',
    'type' => '',
    'field_api_classes' => 0,
  );
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_staff_room']['id'] = 'field_staff_room';
  $handler->display->display_options['fields']['field_staff_room']['table'] = 'field_data_field_staff_room';
  $handler->display->display_options['fields']['field_staff_room']['field'] = 'field_staff_room';
  $handler->display->display_options['fields']['field_staff_room']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_staff_room']['alter']['text'] = '[field_staff_room] [field_staff_building]';
  $handler->display->display_options['fields']['field_staff_room']['type'] = 'text_plain';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Family name (field_staff_family_name) */
  $handler->display->display_options['sorts']['field_staff_family_name_value']['id'] = 'field_staff_family_name_value';
  $handler->display->display_options['sorts']['field_staff_family_name_value']['table'] = 'field_data_field_staff_family_name';
  $handler->display->display_options['sorts']['field_staff_family_name_value']['field'] = 'field_staff_family_name_value';
  /* Sort criterion: Content: Given name (field_staff_given_name) */
  $handler->display->display_options['sorts']['field_staff_given_name_value']['id'] = 'field_staff_given_name_value';
  $handler->display->display_options['sorts']['field_staff_given_name_value']['table'] = 'field_data_field_staff_given_name';
  $handler->display->display_options['sorts']['field_staff_given_name_value']['field'] = 'field_staff_given_name_value';
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['arguments']['name']['path_case'] = 'lower';
  $handler->display->display_options['arguments']['name']['transform_dash'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Unit */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['ui_name'] = 'Unit';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'terms';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'units' => 'units',
    'keywords' => 0,
    'tags' => 0,
  );
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 0;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'slider' => 0,
    'front_page' => 0,
    'schools' => 0,
    'about' => 0,
    'research' => 0,
    'office_of_graduate_studies' => 0,
    'coursework_students' => 0,
    'staff_list' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Unit */
  $handler->display->display_options['fields']['field_staff_unit']['id'] = 'field_staff_unit';
  $handler->display->display_options['fields']['field_staff_unit']['table'] = 'field_data_field_staff_unit';
  $handler->display->display_options['fields']['field_staff_unit']['field'] = 'field_staff_unit';
  $handler->display->display_options['fields']['field_staff_unit']['label'] = '';
  $handler->display->display_options['fields']['field_staff_unit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_staff_unit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_unit']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_staff_unit']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_staff_unit']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_staff_unit']['delta_reversed'] = TRUE;
  /* Field: Content: Building */
  $handler->display->display_options['fields']['field_staff_building']['id'] = 'field_staff_building';
  $handler->display->display_options['fields']['field_staff_building']['table'] = 'field_data_field_staff_building';
  $handler->display->display_options['fields']['field_staff_building']['field'] = 'field_staff_building';
  $handler->display->display_options['fields']['field_staff_building']['label'] = '';
  $handler->display->display_options['fields']['field_staff_building']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_staff_building']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_building']['click_sort_column'] = 'url';
  /* Field: Content: Mail */
  $handler->display->display_options['fields']['field_staff_mail']['id'] = 'field_staff_mail';
  $handler->display->display_options['fields']['field_staff_mail']['table'] = 'field_data_field_staff_mail';
  $handler->display->display_options['fields']['field_staff_mail']['field'] = 'field_staff_mail';
  $handler->display->display_options['fields']['field_staff_mail']['label'] = '';
  $handler->display->display_options['fields']['field_staff_mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_staff_mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_mail']['type'] = 'email_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'mailto:[field_staff_mail]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = 'Send an email to [title]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_staff_position']['id'] = 'field_staff_position';
  $handler->display->display_options['fields']['field_staff_position']['table'] = 'field_data_field_staff_position';
  $handler->display->display_options['fields']['field_staff_position']['field'] = 'field_staff_position';
  $handler->display->display_options['fields']['field_staff_position']['type'] = 'text_plain';
  /* Field: Content: Phone */
  $handler->display->display_options['fields']['field_staff_phone']['id'] = 'field_staff_phone';
  $handler->display->display_options['fields']['field_staff_phone']['table'] = 'field_data_field_staff_phone';
  $handler->display->display_options['fields']['field_staff_phone']['field'] = 'field_staff_phone';
  $handler->display->display_options['fields']['field_staff_phone']['type'] = 'unimelb_html5_phone_link';
  $handler->display->display_options['fields']['field_staff_phone']['settings'] = array(
    'relationship' => 'none',
    'ui_name' => '',
    'custom_label' => 0,
    'label' => '',
    'element_label_colon' => 0,
    'exclude' => 0,
    'element_type_enable' => 0,
    'element_type' => '',
    'element_class_enable' => 0,
    'element_class' => '',
    'element_label_type_enable' => 0,
    'element_label_type' => '',
    'element_label_class_enable' => 0,
    'element_label_class' => '',
    'element_wrapper_type_enable' => 0,
    'element_wrapper_type' => '',
    'element_wrapper_class_enable' => 0,
    'element_wrapper_class' => '',
    'element_default_classes' => 0,
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'absolute' => 0,
      'replace_spaces' => 0,
      'external' => 0,
      'path_case' => 'none',
      'link_class' => '',
      'alt' => '',
      'rel' => '',
      'prefix' => '',
      'suffix' => '',
      'target' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 0,
      'ellipsis' => 0,
      'more_link' => 0,
      'more_link_text' => '',
      'more_link_path' => '',
      'html' => 0,
      'strip_tags' => 0,
      'preserve_tags' => '',
      'trim_whitespace' => 0,
      'nl2br' => 0,
    ),
    'empty' => '',
    'empty_zero' => 0,
    'hide_empty' => 0,
    'hide_alter_empty' => 0,
    'click_sort_column' => '',
    'type' => '',
    'field_api_classes' => 0,
  );
  /* Field: Content: Room */
  $handler->display->display_options['fields']['field_staff_room']['id'] = 'field_staff_room';
  $handler->display->display_options['fields']['field_staff_room']['table'] = 'field_data_field_staff_room';
  $handler->display->display_options['fields']['field_staff_room']['field'] = 'field_staff_room';
  $handler->display->display_options['fields']['field_staff_room']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_staff_room']['alter']['text'] = '[field_staff_room] [field_staff_building]';
  $handler->display->display_options['fields']['field_staff_room']['type'] = 'text_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['position']['order'] = 'DESC';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Family name (field_staff_family_name) */
  $handler->display->display_options['sorts']['field_staff_family_name_value']['id'] = 'field_staff_family_name_value';
  $handler->display->display_options['sorts']['field_staff_family_name_value']['table'] = 'field_data_field_staff_family_name';
  $handler->display->display_options['sorts']['field_staff_family_name_value']['field'] = 'field_staff_family_name_value';
  /* Sort criterion: Content: Given name (field_staff_given_name) */
  $handler->display->display_options['sorts']['field_staff_given_name_value']['id'] = 'field_staff_given_name_value';
  $handler->display->display_options['sorts']['field_staff_given_name_value']['table'] = 'field_data_field_staff_given_name';
  $handler->display->display_options['sorts']['field_staff_given_name_value']['field'] = 'field_staff_given_name_value';
  $handler->display->display_options['path'] = 'about/staff-list/%';
  $handler->display->display_options['menu']['title'] = 'Staff';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Attachment */
  $handler = $view->new_display('attachment', 'Attachment', 'attachment_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Unit */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['ui_name'] = 'Unit';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'terms';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'units' => 'units',
    'keywords' => 0,
    'tags' => 0,
  );
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['relationship'] = 'term_node_tid';
  $handler->display->display_options['relationships']['parent']['required'] = TRUE;
  /* Relationship: Nodequeue: Queue */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 0;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'slider' => 0,
    'front_page' => 0,
    'schools' => 0,
    'about' => 0,
    'research' => 0,
    'office_of_graduate_studies' => 0,
    'coursework_students' => 0,
    'staff_list' => 0,
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Nodequeue: Position */
  $handler->display->display_options['sorts']['position']['id'] = 'position';
  $handler->display->display_options['sorts']['position']['table'] = 'nodequeue_nodes';
  $handler->display->display_options['sorts']['position']['field'] = 'position';
  $handler->display->display_options['sorts']['position']['relationship'] = 'nodequeue_rel';
  $handler->display->display_options['sorts']['position']['order'] = 'DESC';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Family name (field_staff_family_name) */
  $handler->display->display_options['sorts']['field_staff_family_name_value']['id'] = 'field_staff_family_name_value';
  $handler->display->display_options['sorts']['field_staff_family_name_value']['table'] = 'field_data_field_staff_family_name';
  $handler->display->display_options['sorts']['field_staff_family_name_value']['field'] = 'field_staff_family_name_value';
  /* Sort criterion: Content: Given name (field_staff_given_name) */
  $handler->display->display_options['sorts']['field_staff_given_name_value']['id'] = 'field_staff_given_name_value';
  $handler->display->display_options['sorts']['field_staff_given_name_value']['table'] = 'field_data_field_staff_given_name';
  $handler->display->display_options['sorts']['field_staff_given_name_value']['field'] = 'field_staff_given_name_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'parent';
  $handler->display->display_options['arguments']['name']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  $handler->display->display_options['arguments']['name']['path_case'] = 'lower';
  $handler->display->display_options['arguments']['name']['transform_dash'] = TRUE;
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $export['staff'] = $view;

  return $export;
}
