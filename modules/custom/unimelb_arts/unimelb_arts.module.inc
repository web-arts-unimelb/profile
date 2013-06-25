<?php
/**
 * @file unimelb_arts.module.inc
 * Defines Drupal hooks and functions that would be wiped from the module
 * file by a `drush feature update'.
 */

/**
 * Implements hook_init().
 */
function unimelb_arts_init() {
  drupal_add_css(drupal_get_path('module', 'unimelb_arts') . '/css/unimelb_arts.css');
}

/**
 * Implements hook_permissions().
 *
 * Add in custom permissions to allow more finegrained access access control.
 *
 * @see unimelb_arts_menu_alter()
 * @see unimelb_arts_user_edit_access()
 */
function unimelb_arts_permission() {
  return array(
    'change user settings' => array(
      'title' => t('Change User Settings'),
      'description' => t('Change the way users register with the site.'),
      'restrict access' => TRUE,
    ),
    'administer admin theme' => array(
      'title' => t('Administer admin theme'),
      'restrict access' => TRUE,
    ),
    'change role permissions' => array(
      'title' => t('Change Role Permissions'),
      'description' => t('Change the permissions assigned to roles.'),
      'restrict access' => TRUE,
    ),
    'access help pages' => array(
      'title' => t('Access Help Pages'),
      'description' => t('View the help pages and menu items.'),
    ),
  );
}

/**
 * Implements hook_menu_alter().
 *
 * @see unimelb_arts_user_edit_access()
 */
function unimelb_arts_menu_alter(&$items) {
  // Remove the password reset form.
  $items['user/password']['access callback'] = FALSE;

  // Change the access callback for user edit.
  $items['user/%user/edit']['access callback'] = 'unimelb_arts_user_edit_access';

  // Change the required permission for the User Settings page.
  $items['admin/config/people/accounts']['access arguments'] = array('change user settings');

  // Change the permission for the Permissions page.
  $items['admin/people/permissions']['access arguments'] = array('change role permissions');

  // Change the access callback for the admin theme to its own permission.
  $admin_theme = variable_get('admin_theme', 'rubik');
  $items['admin/appearance/settings/' . $admin_theme]['access callback'] = 'user_access';
  $items['admin/appearance/settings/' . $admin_theme]['access arguments'] = array('administer admin theme');

  // Don't go messing with other themes if you're not a site admin.
  $items['admin/appearance/enable']['access arguments']
    = $items['admin/appearance/disable']['access arguments']
    = $items['admin/appearance/default']['access arguments']
    = array('administer admin theme');

  // Change the permission for the Help pages.
  $items['admin/help']['access arguments'] = array('access help pages');

}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Stop non-site admins for bulk editing site admins.
 */
function unimelb_arts_form_user_admin_account_alter(&$form, $form_state) {
  if (!in_array('site admin', $GLOBALS['user']->roles)) {
    $role = db_select('role', 'r')->fields('r')->condition('name', 'site admin', '=')->execute()->fetchObject();

    unset ($form['options']['operation']['#options']['Add a role to the selected users']['add_role-' . $role->rid]);
    unset ($form['options']['operation']['#options']['Remove a role from the selected users']['remove_role-' . $role->rid]);

    foreach ($form['accounts']['#options'] as $uid => $item) {
      $account = user_load($uid);
      if (in_array('site admin', $account->roles)) {
        unset($form['accounts']['#options'][$uid]);
      }
    }
  }
}

/**
 * Implements hook_form_alter().
 */
function unimelb_arts_form_alter(&$form, $form_state, $form_id) {
  if ($form_id == 'user_profile_form' || $form_id == 'user_register_form') {
    // Only site admins can create more site admins.
    if (!in_array('site admin', $GLOBALS['user']->roles)) {
      $role = db_select('role', 'r')->fields('r')->condition('name', 'site admin', '=')->execute()->fetchObject();
      unset ($form['account']['roles']['#options'][$role->rid]);
    }
  }
}

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

  // Add a UI element to easily add external direction to a node.
  if (module_exists('redirect') && isset($form['redirect'])) {
    $form['redirect']['external'] = _unimelb_arts_redirect_external($form['nid']['#value']);
    if (empty($form['redirect']['external']['list']['#rows'])) {
      $form['redirect']['external_actions'] = array(
        '#theme' => 'links',
        '#links' => array(
          'external' => array(
            'title' => t('Add URL redirect from this node'),
            'href' => 'admin/config/search/redirect/add',
            'query' => array(
              'source' => 'node/' . $form['nid']['#value'],
              'language' => $form['language']['#value'],
            ) + drupal_get_destination(),
          ),
        ),
        '#attributes' => array(
          'class' => array('action-links'),
        ),
      );
    }
  }

  // Add a pretty summary to the structure fieldset tab.
  if (isset($form['field_shared_tags'])) {
    $form['field_shared_tags']['#attached'] = array(
      'js' => array(drupal_get_path('module', 'unimelb_arts') . '/js/tags-summary.js'),
    );
  }

  // Add a pretty summary to the keywords fieldset tab.
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
      $formats = array_filter(array_keys($form_state['field']['body']['und']['instance']['settings']['better_formats']['allowed_formats']));
      $element['summary']['#format'] = array_shift($formats);
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
        if (isset($value['summary']) && is_array($value['summary'])) {
          $value['summary'] = $value['summary']['value'];
        }
      }
    }
  }
}

/**
 * Implements hook_token_info().
 */
function unimelb_arts_token_info() {
  $node['arts-event-path'] = array(
    'name' => t('Arts: Event Path'),
    'description' => t('The URL path for the date this event will be held.'),
  );
  $node['arts-event-path-day'] = array(
    'name' => t('Arts: Event Day'),
    'description' => t('The numeric day of the month this event will be held.'),
  );
  $node['arts-event-path-month'] = array(
    'name' => t('Arts: Event Month'),
    'description' => t('The numeric month for the date this event will be held.'),
  );
  $node['arts-event-path-year'] = array(
    'name' => t('Arts: Event Year'),
    'description' => t('The full year for the date this event will be held.'),
  );
  $node['arts-tag-path'] = array(
    'name' => t('Arts: Tag Path'),
    'description' => t('The path created by adding up the paths on all tags on this node.'),
  );

  return array(
    'tokens' => array(
      'node' => $node,
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function unimelb_arts_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $url_options = array('absolute' => TRUE);
  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
    $langcode = $options['language']->language;
  }
  else {
    $langcode = NULL;
  }
  $sanitize = !empty($options['sanitize']);

  $replacements = array();

  if ($type == 'node' && !empty($data['node'])) {
    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'arts-event-path':
          $path = _unimelb_arts_date_token($data['node'], '%Y/%m/%d', $langcode);
          $replacements[$original] = ($sanitize) ? check_plain($path) : $path;
          break;

        case 'arts-event-path-day':
          $path = _unimelb_arts_date_token($data['node'], '%d', $langcode);
          $replacements[$original] = ($sanitize) ? check_plain($path) : $path;
          break;

        case 'arts-event-path-month':
          $path = _unimelb_arts_date_token($data['node'], '%m', $langcode);
          $replacements[$original] = ($sanitize) ? check_plain($path) : $path;
          break;

        case 'arts-event-path-year':
          $path = _unimelb_arts_date_token($data['node'], '%Y', $langcode);
          $replacements[$original] = ($sanitize) ? check_plain($path) : $path;
          break;

        case 'arts-tag-path':
          $path = _unimelb_arts_tag_path($data['node'], $langcode);
          $replacements[$original] = ($sanitize) ? check_plain($path) : $path;
          break;
      }
    }
  }

  return $replacements;
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

/**
 * Helper to load external redirects for a given page.
 *
 * @param $nid
 *   A valid node nid.
 *
 * @return
 *   A redirect object if one is found or FALSE if none exist.
 *
 * @see unimelb_arts_form_node_form_alter()
 * @see redirect_load_by_source()
 * @see redirect_list_table()
 */
function _unimelb_arts_redirect_external($nid = NULL) {
  if (empty($nid)) {
    return FALSE;
  }

  $redirect = redirect_load_by_source('node/' . $nid);
  if(empty($redirect))
    return FALSE;

  $header = array('redirect', 'status_code', 'language', 'count', 'access', 'operations');
  return redirect_list_table(array($redirect->rid => $redirect), $header);
}

/**
 * Helper to create token data from date fields.
 *
 * @param $node
 *   A valid node object.
 * @param $format
 *   A date() format string.
 * @param $langcode
 *   A language code.
 *
 * @return
 *   A string.
 */
function _unimelb_arts_date_token($node, $format, $langcode) {
  if (empty($node->field_event_date[$langcode][0])) {
    return;
  }

  $date = strtotime($node->field_event_date[$langcode][0]['value']);
  return strftime($format, $date);
}

/**
 * Helper to create token data from taxonomy terms.
 *
 * @param $node
 *   A valid node object.
 * @param $langcode
 *   A language code.
 *
 * @return
 *   A string.
 */
function _unimelb_arts_tag_path($node, $langcode) {
  // Haz tags?
  if (isset($node->field_shared_tags) && !empty($node->field_shared_tags[$langcode])) {
    $trees = array();
    foreach ($node->field_shared_tags[$langcode] as $item) {
      $trees[$item['tid']]['depth'] = _unimelb_arts_tag_depth($item['tid']);

      // Loop until we get to the top term.
      $parent = $item['tid'];
      while (!empty($parent)) {
        $trees[$item['tid']]['lineage'][] = $parent;
        $parent = db_query("SELECT parent FROM {taxonomy_term_hierarchy} WHERE tid = :tid", array(':tid' => $parent))->fetchField();
      }
    }

    // Sort, so we can grab the deepest item.
    uasort($trees, '_unimelb_arts_depth_sort');
    $tree = array_shift($trees);

    // Make a pretty path.
    foreach ($tree['lineage'] as $idx => $tid) {
      $term = taxonomy_term_load($tid);
      $tree['path'][] = $term->field_tag_path_token[$langcode][0]['safe_value'];
    }

    // Reverse the path, so we have top -> bottom.
    $path = array_reverse($tree['path']);

    // A tag path token can contain the same snippet as its parent item, we
    // check for that here and remove them, so that path components do not
    // double up.
    if (count($path) > 1) {
      for ($i = 0; $i < count($path) - 1; $i++) {
        $path[$i + 1] = preg_replace('/^' . preg_quote($path[$i]) . '\//', '', $path[$i + 1]);
      }
    }

    return implode('/', $path);
  }
}

/**
 * Helper to calculate the depth of a given taxonomy term.
 *
 * @param $tid
 *   A taxonomy term id.
 *
 * @return
 *   An integer.
 */
function _unimelb_arts_tag_depth($tid) {
  $tree = array();
  $parent = $tid;
  while (!empty($parent)) {
    $tree[] = $parent;
    $parent = db_query("SELECT parent FROM {taxonomy_term_hierarchy} WHERE tid = :tid", array(':tid' => $parent))->fetchField();
  }
  return count($tree);
}

/**
 * Callback helper to sort the term lineage array by depth.
 */
function _unimelb_arts_depth_sort($a, $b) {
  return $a['depth'] < $b['depth'];
}

/**
 * Helper that stops non-site admins from editing site admins.
 *
 * Fall-through to the standard access test if the user is not
 * trying to edit a site admin.
 *
 * @param $account
 *   The user account to be edited.
 *
 * @return
 *   TRUE or FALSE.
 */
function unimelb_arts_user_edit_access($account) {
  if (in_array('site admin',$account->roles) && !in_array('site admin', $GLOBALS['user']->roles)) {
    drupal_set_message(t('You do not have permission to edit site admins'), 'error');
    watchdog('unimelb_arts', '%user tried to edit site admin %account', array('%user' => $GLOBALS['user']->name, '%account' => $account->name), WATCHDOG_INFO);
    return FALSE;
  }
  return user_edit_access($account);
}
