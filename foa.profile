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
  $site = strtolower(strtr($_SERVER['SERVER_NAME'], array('www.' => '')));
  $site = ucwords(array_shift(explode('.', $site)));
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
