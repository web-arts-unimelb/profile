<?php
/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function foa_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with part of the server name.
  $site = strtoupper(strtr($_SERVER['SERVER_NAME'], array('www.' => '')));
  $form['site_information']['site_name']['#default_value'] = array_shift(explode('.', $site));
  $form['site_information']['site_mail']['#default_value'] = 'arts-webmaster@lists.unimelb.edu.au';

  // Add a default email address and username,
  $form['admin_account']['account']['name']['#default_value'] = 'test-site-admin';
  $form['admin_account']['account']['mail']['#default_value'] = 'arts-webmaster@lists.unimelb.edu.au';

  // Select the country and timezone.
  $form['server_settings']['site_default_country']['#default_value'] = 'AU';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'Australia/Melbourne';

  // Do not auto-detect timezone, so the above default remains.
  unset($form['server_settings']['date_default_timezone']['#attributes']);

  // Disable update notifications by default.
  unset($form['update_notifications']['update_status_module']['#default_value']);
}

/**
 * Implements hook_install_tasks().
 */
function foa_install_tasks(&$install_state) {
  $tasks['foa_profile_tasks'] = array(
    'display_name' => st('Customise site'),
    'display' => TRUE,
    'type' => 'batch',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
  );
  return $tasks;
}

/**
 * Helper that returns a batch API definition containing the
 * functions to be run to enable blocks.
 *
 * This is invoked as final install task.
 */
function foa_profile_tasks() {

  $batch = array(
    'title' => st('Customising your new Faculty of Arts website'),
    'operations' => array(),
  );

  // Enable theme.
  $batch['operations'][] = array('foa_profile_enable_theme', array());

  // Create a jQuerymenu.
  $batch['operations'][] = array('foa_profile_jquerymenu', array());

  // Make a list of blocks :-)

  // Grab theme info for the blocks.
  $theme_default = variable_get('theme_default', 'unimelb');
  $theme_admin = variable_get('admin_theme', 'rubik');

  // Put each of the frontpage view blocks in their regions.
  for ($i = 1; $i <= 12; $i++) {
    $blocks[] = array(
      'module' => 'views',
      'delta' => 'front_page-block_' . $i,
      'theme' => $theme_default,
      'region' => 'home_column_' . $i,
      'status' => 1,
      'visibility' => 1,
      'pages' => '<front>'
    );
  }

  // Create a jQuerymenu block for the frontend theme.
  $blocks[] = array(
    'module' => 'jquerymenu',
    'delta' => variable_get('foa_jquerymenu', 0),
    'theme' => $theme_default,
    'region' => 'navigation',
    'status' => 1,
    'visibility' => 0,
    'pages' => '<front>',
    'title' => t('Home'),
  );

  // Create a disabled jQuerymenu block for the admin theme.
  $blocks[] = array(
    'module' => 'jquerymenu',
    'delta' => variable_get('foa_jquerymenu', 0),
    'theme' => $theme_admin,
    'region' => 'navigation',
  );

  // Put the news block on the front page.
  $blocks[] = array(
    'module' => 'views',
    'delta' => 'news-block',
    'theme' => $theme_default,
    'region' => 'sidebar_right',
    'status' => 1,
    'visibility' => 0,
    'pages' => '<front>'
  );

  // Put the events block on the front page.
  $blocks[] = array(
    'module' => 'views',
    'delta' => 'events-block',
    'theme' => $theme_default,
    'region' => 'sidebar_right',
    'status' => 1,
    'visibility' => 0,
    'pages' => '<front>'
  );

  // Put the slider block on the front page.
  $blocks[] = array(
    'module' => 'views',
    'delta' => 'slider-block',
    'theme' => $theme_default,
    'region' => 'slider',
    'status' => 1,
    'visibility' => 1,
    'pages' => '<front>',
  );

  // Batch all those blocks into the system.
  foreach ($blocks as $block) {
    $batch['operations'][] = array('_foa_profile_block', array($block));
  }

  // Set some miscellaneous system variables.
  $batch['operations'][] = array('foa_profile_variables', array());

  // Cleanup mess.
  $batch['operations'][] = array('foa_profile_cleanup', array());

  return $batch;
}

/**
 * Enable the `unimelb' theme.
 */
function foa_profile_enable_theme(&$context) {
  // Themes.
  $default_theme = variable_get('theme_default', 'unimelb');

  db_update('system')
    ->fields(array('status' => 1))
    ->condition('type', 'theme')
    ->condition('name', $default_theme)
    ->execute();

  $context['results'] = __FUNCTION__;
  $context['message'] = t('Enabled Faculty of Arts theme');
}

/**
 * Create the jQuerymenu navigation block.
 *
 * Called by batch API.
 */
function foa_profile_jquerymenu(&$context) {
  // Create a `navigation' jQuerymenu.
  $mid = db_insert('jquerymenus')->fields(array('menu_name' => 'main-menu'))->execute();
  variable_set('foa_jquerymenu', $mid);

  $context['results'] = __FUNCTION__;
  $context['message'] = t('Created a jQuerymenu for %menu', array('%menu' => 'Main menu'));
}

/**
 * Set required variables.
 *
 * Called by batch API.
 */
function foa_profile_variables(&$context) {
  // No automagic nodequeue views.
  variable_set('nodequeue_view_per_queue', 0);

  // Collapse module groups on module page.
  variable_set('admin_menu_tweak_modules', 1);

  // Collapse module groups on permissions page.
  variable_set('admin_menu_tweak_permissions', 1);

  // Tweak update module settings.
  // Check for security updates once a week but do not send emails about it.
  variable_set('update_check_disabled', 0);
  variable_set('update_check_frequency', 7);
  variable_set('update_notification_threshold', 'security');
  variable_del('update_notify_emails');

  $context['results'] = __FUNCTION__;
  $context['message'] = t('Tweaked system variables');
}

/**
 * Clean up temporary variables.
 *
 * Called by batch API.
 */
function foa_profile_cleanup(&$context) {
  variable_del('foa_jquerymenu');

  // Put back the original error level.
  $error_level = variable_get('foa_error_level', 1);
  variable_set('error_level', $error_level);
  variable_del('foa_error_level');

  $context['results'] = __FUNCTION__;
  $context['message'] = t('Cleaned up temporary variables');
}

/**
 * Helper to insert a new entry in the {block} table.
 *
 * Avoids the lack of feature-included views blocks being
 * present when the profile tasks run.
 *
 * @param $block
 *   A keyed array containing the block information.
 */
function _foa_profile_block($block, &$context) {
  // Set some defaults.
  $default = array(
    'module' => '',
    'delta' => 0,
    'theme' => variable_get('theme_default', 'unimelb'),
    'status' => 0,
    'weight' => 0,
    'region' => -1,
    'custom' => 0,
    'visibility' => 0,
    'pages' => '',
    'title' => '',
    'cache' => DRUPAL_NO_CACHE,
  );

  $block += $default;

  // Oogly. It seems that depending on feature version, the blocks may or may
  // not get created as intended. Catch the AlreadyExists error and run an
  // update query in that case.
  try {
    db_insert('block')
      ->fields($block)
      ->execute();
  } catch (Exception $e) {
    db_update('block')
      ->fields($block)
      ->condition('module', $block['module'])
      ->condition('delta', $block['delta'])
      ->condition('theme', $block['theme'])
      ->execute();
  }

  $context['results'] = __FUNCTION__;
  $context['message'] = t('Added %theme block @delta in @region', array('%theme' => $block['theme'], '@delta' => $block['delta'], '@region' => $block['region']));
}
