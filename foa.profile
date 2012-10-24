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
  $site = array_shift(explode('.', $site));
  $form['site_information']['site_name']['#default_value'] = t('Faculty of Arts @site', array('@site' => $site));
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
    'display_name' => st('Enable blocks'),
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
    'title' => st('Customising University of Melbourne theme blocks'),
    'operations' => array(),
  );

  // Put each of the frontpage view blocks in their regions.
  for ($i = 1; $i <= 12; $i++) {
    $batch['operations'][] = array('foa_profile_frontpage_block', array($i));
  }

  // Create a jQuerymenu.
  $batch['operations'][] = array('foa_profile_jquerymenu', array());

  // Create a jQuerymenu block for the frontend theme.
  $batch['operations'][] = array('foa_profile_jquerymenu_block', array('theme_default', 'navigation'));

  // Create a disabled jQuerymenu block for the admin theme.
  $batch['operations'][] = array('foa_profile_jquerymenu_block', array('admin_theme', -1));

  // Cleanup mess.
  $batch['operations'][] = array('foa_profile_cleanup', array());

  return $batch;
}

/**
 * Put a frontpage view block in its region.
 *
 * Called by batch API.
 */
function foa_profile_frontpage_block($delta, &$context) {
  // Put this frontpage view block in its region.
  db_update('block')
    ->fields(array(
      'status' => 1,
      'region' => 'home_column_' . $delta,
    ))
    ->condition('module', 'views')
    ->condition('delta', 'front_page-block_' . $delta)
    ->condition('theme', variable_get('theme_default', 'unimelb'))
    ->execute();
  $context['results'] = __FUNCTION__;
  $context['message'] = t('Enabled frontpage view block @delta', array('@delta' => $delta));
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
 * Create and place the jQuerymenu navigation block.
 *
 * Called by batch API.
 */
function foa_profile_jquerymenu_block($theme, $region, &$context) {
  db_insert('block')
    ->fields(array(
      'module' => 'jquerymenu',
      'delta'  => variable_get('foa_jquerymenu', 0),
      'theme'  => variable_get($theme, 'unimelb'),
      'status' => (int) ($region != -1),
      'weight' => 0,
      'region' => $region,
      'pages'  => '',
      'cache'  => -1,
    ))
    ->execute();

  $context['results'] = __FUNCTION__;
  $context['message'] = t('Created jQuerymenu block for %theme', array('%theme' => variable_get($theme, 'unimelb')));
}

/**
 * Clean up temporary variables.
 *
 * Called by batch API.
 */
function foa_profile_cleanup(&$context) {
  variable_del('foa_jquerymenu');

  $context['results'] = __FUNCTION__;
  $context['message'] = t('Cleaned up temporary variables');
}
