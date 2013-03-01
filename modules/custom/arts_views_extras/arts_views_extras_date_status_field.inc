<?php

/**
 * A handler to provide a field that show Open or Closed depending on a date field.
 *
 * @ingroup views_field_handlers
 */
class arts_views_extras_date_status_field extends views_handler_field {

  /**
   * Implements views_object#option_definition().
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['status_date_field'] = array('default' => FALSE);
    return $options;
  }

  /**
   * Implements views_handler#options_form().
   */
  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
      // Not self!
      if ($field == $this->field) {
        continue;
      }

dpm($field);

      $title = (empty($handler->options['ui_name']))
        ? t('@group: @title', array('@group' => $handler->definition['group'], '@title' => $handler->definition['title']))
        : $handler->options['ui_name'];
      $fields[$handler->handler_type . '_' . $field] = check_plain($title);
    }

    $form['status_date_field'] = array(
      '#type' => 'select',
      '#title' => t('Source field'),
      '#description' => t('Choose the source date field to use.'),
      '#options' => $fields,
      '#required' => TRUE,
      '#default_value' => $this->options['status_date_field']
    );
  }

  /**
   * Implements views_handler_field#query().
   *
   * @see views_php_views_pre_execute()
   */
  function query() {
    // Provide a field alias but don't actually alter the query.
    // $this->field_alias = 'views_multiple_field_' . $this->position;
  }

  /**
   * Implements views_handler_field#render().
   */
  function render($values) {
    $value = NULL;
    $items = array();

    if (!empty($this->options['status_date_field'])) {
      foreach ($values->{$this->options['status_date_field']} as $item) {
        $items[] = check_plain($item['rendered']['#markup']);
      }
    }

    return $items;
  }
}
