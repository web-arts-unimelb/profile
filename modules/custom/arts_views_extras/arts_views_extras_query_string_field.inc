<?php

/**
 * A handler to provide a field that show Open or Closed depending on a date field.
 *
 * @ingroup views_field_handlers
 */
class arts_views_extras_query_string_field extends views_handler_field {

  /**
   * Implements views_object#option_definition().
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['query_string'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Implements views_handler#options_form().
   */
  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    $form['query_string'] = array(
      '#type' => 'textfield',
      '#title' => t('Query string'),
      '#description' => t('Enter the query string variable to provide in this field.'),
      '#options' => $fields,
      '#required' => TRUE,
      '#default_value' => $this->options['query_string']
    );
  }

  /**
   * Implements views_handler_field#query().
   *
   * @see views_php_views_pre_execute()
   * @see http://www.thinkgeek.com/product/8b8c/
   */
  function query() {
    // Meh.
  }

  /**
   * Implements views_handler_field#render().
   */
  function render($values) {
    $value = NULL;

    // Do not check if the actual $_GET variable is empty, the filter should be
    // able to provide the variable name at any time.
    if (!empty($this->options['query_string'])) {
      $value = filter_xss($this->options['query_string']) . '=' . filter_xss($_GET[$this->options['query_string']]);
    }

    return $value;
  }
}
