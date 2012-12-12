<?php
/**
 * @file injector.admin.inc
 * Contains the settings form for the injector module.
 */

/**
 * Create the admin form.
 */
function injector_admin_form() {
  $form['injector'] = array(
    '#type' => 'fieldset',
    '#title' => t('Injector settings'),
    '#description' => t('Configure the UoM javascript injector settings.'),
  );

  $options = array(
    INJECTOR_HEADER => t('Enable UoM header overrides.'),
    INJECTOR_STYLES => t('Enable UoM style overrides.'),
  );

  $form['injector']['injector_options'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Injector Options'),
    '#options' => $options,
    '#default_value' => variable_get('injector_options', array()),
  );


  $options = array(
    BLOCK_VISIBILITY_NOTLISTED => t('All pages except those listed'),
    BLOCK_VISIBILITY_LISTED => t('Only the listed pages'),
  );

  $form['injector']['injector_visibility'] = array(
    '#type' => 'radios',
    '#title' => t('Add injector on specific pages'),
    '#options' => $options,
    '#default_value' => variable_get('injector_visibility', BLOCK_VISIBILITY_NOTLISTED),
  );

  $form['injector']['injector_path'] = array(
    '#type' => 'textarea',
    '#title' => t('Pages'),
    '#default_value' => variable_get('injector_path', ''),
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.", array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
  );

  return system_settings_form($form);
}

/**
 * Validator to clean up settings before save.
 */
function injector_admin_form_validate($form, &$form_state) {
  $form_state['values']['injector_options'] = array_filter($form_state['values']['injector_options']);
}
