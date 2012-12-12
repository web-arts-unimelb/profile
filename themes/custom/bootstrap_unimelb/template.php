<?php
/**
 * Theme preprocessors and overrides for bootstrap_unimelb.
 */

/**
 * Implements hook_preprocess_html().
 */
function bootstrap_unimelb_preprocess_html(&$vars) {
  // Add class to override injector logo.
  array_unshift($vars['classes_array'], 'logo');
  $vars['classes_array'][] = 'blue';
}
/**
 * Preprocess variables for page.tpl.php
 *
 * @see page.tpl.php
 */
function bootstrap_unimelb_preprocess_page(&$variables) {
  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['columns'] = 3;
  }
  elseif (!empty($variables['page']['sidebar_first'])) {
    $variables['columns'] = 2;
  }
  elseif (!empty($variables['page']['sidebar_second'])) {
    $variables['columns'] = 2;
  }
  else {
    $variables['columns'] = 1;
  }

  // Our custom search because its cool :)
  $variables['search'] = FALSE;
  if(theme_get_setting('toggle_search') && module_exists('search'))
    $variables['search'] = drupal_get_form('_twitter_bootstrap_search_form');

  // Primary nav
  $variables['primary_nav'] = FALSE;
  if($variables['main_menu']) {
    // Build links
    $tree = menu_tree_page_data(variable_get('menu_main_links_source', 'main-menu'));
    $variables['main_menu'] = twitter_bootstrap_menu_navigation_links($tree);

    // Build list
    $variables['primary_nav'] = theme('twitter_bootstrap_links', array(
      'links' => $variables['main_menu'],
      'attributes' => array(
        'id' => 'main-menu',
        'class' => array('nav'),
      ),
      'heading' => array(
        'text' => t('Main menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      ),
    ));
  }
  // Secondary nav
  $variables['secondary_nav'] = FALSE;
  if($variables['secondary_menu']) {
    $secondary_menu = menu_load(variable_get('menu_secondary_links_source', 'user-menu'));

    // Build links
    $tree = menu_tree_page_data($secondary_menu['menu_name']);
    $variables['secondary_menu'] = twitter_bootstrap_menu_navigation_links($tree);

    // Build list
    $variables['secondary_nav'] = theme('twitter_bootstrap_btn_dropdown', array(
      'links' => $variables['secondary_menu'],
      'label' => $secondary_menu['title'],
      'type' => 'default',
      'attributes' => array(
        'id' => 'user-menu',
        'class' => array('pull-right'),
      ),
      'heading' => array(
        'text' => t('Secondary menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      ),
    ));
  }

  // Replace tabs with dropw down version
  $variables['tabs']['#primary'] = _twitter_bootstrap_local_tasks($variables['tabs']['#primary']);
}
