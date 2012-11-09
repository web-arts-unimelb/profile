<?php
/**
 * @file unimelb_arts.module.inc
 * Defines Drupal hooks and functions that would be wiped from the module
 * file by a `drush feature update'.
 */

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 */
function unimelb_arts_form_node_form_alter(&$form, &$form_state, $form_id) {
  $form['body'][$form['language']['#value']][0]['summary']['#title'] = t('Front page summary');
  $form['body'][$form['language']['#value']][0]['summary']['#description'] = t('The front page summary is displayed only on the front page. You can leave it blank for any @node that does not display on the front page.', array('@node' => $form['type']['#value']));
  $form['body'][$form['language']['#value']][0]['summary']['#attached']['js'][0] = drupal_get_path('module', 'unimelb_arts') . '/js/frontpage-summary.js';

  // Hide these WYSIWYG buttons on the summary field.
  drupal_add_css('#edit-body-' . $form['language']['#value'] .'-0-summary-value_wysiwyg_fields_field_shared_images { display: none; }', 'inline');
  drupal_add_css('#edit-body-' . $form['language']['#value'] .'-0-summary-value_wysiwyg_fields_field_shared_attachments { display: none; }', 'inline');

  // Modify field label for image uploader in wysiwyg
  if(isset($form['field_shared_images'])) {
    $form['field_shared_images'][$form['language']['#value']]['#file_upload_title'] .= t(" (Press the '+' button above to see more images)");
  }

  // Modify field label for file uploader in wysiwyg
  if(isset($form['field_shared_attachments'])) {
    $form['field_shared_attachments'][$form['language']['#value']]['#file_upload_title'] .= t(" (Press the '+' button above to see more files)");
  }

  // Add a pretty summary to this fieldset tab.
  if (isset($form['field_shared_keywords'])) {
    $form['field_shared_keywords']['#attached'] = array(
      'js' => array(drupal_get_path('module', 'unimelb_arts') . '/js/keywords-summary.js'),
    );
  }

}

/**
 * Implementation of hook_field_widget_form_alter().
 *
 * Add WYSIWYG treatment to textarea summary form items.
 */
function unimelb_arts_field_widget_form_alter(&$element, &$form_state, $context) {
  if (isset($element['summary'])) {
    // Hide the format selector.
    drupal_add_css(drupal_get_path('module', 'unimelb_arts') . '/css/frontpage-summary.css');
    $element['summary']['#type'] = 'text_format';
    if (module_exists('better_formats') && isset($form_state['field']['body']['und']['instance']['settings']['better_formats'])) {
      $element['summary']['#format'] = array_shift(array_filter(array_keys($form_state['field']['body']['und']['instance']['settings']['better_formats']['allowed_formats'])));
    }
    else {
      $element['summary']['#format'] = $element['#format'];
    }
  }
}


/**
 * Implements hook_field_attach_presave().
 */
function unimelb_arts_field_attach_presave($entity_type, $entity) {
  list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);

  foreach (field_info_instances($entity_type, $bundle) as $instance) {
    $field = field_info_field_by_id($instance['field_id']);
    $field_name = $field['field_name'];
    if ($field['type'] == 'text_with_summary' && !empty($entity->$field_name)) {
      $language = $entity->language;
      foreach ($entity->{$field_name}[$language] as $id => &$value) {
        if (is_array($value['summary'])) {
          $value['summary'] = $value['summary']['value'];
        }
      }
    }
  }
}

/**
 * Implements hook_preprocess_html().
 *
 * This function checks the current node for contents in its keywords field
 * and puts those key words in a theme variable, so they can be referenced
 * by other preprocess hooks and by the theme.
 */
function unimelb_arts_preprocess_html(&$variables) {
  $node = menu_get_object();

  // If we're looking at a node and there is data in the keywords field for
  // this node, add that data to a variable that can be used by the theme.
  if (!empty($node->vid) && !empty($node->field_shared_keywords[$node->language])) {
    $tids = $keywords = array();
    foreach ($node->field_shared_keywords[$node->language] as $term) {
      $tids[] = $term['tid'];
    }
    $terms = taxonomy_term_load_multiple($tids);
    foreach ($terms as $term) {
      $keywords[] = $term->name;
    }
    $variables['node_keywords'] = implode(', ', $keywords);
  }
}
