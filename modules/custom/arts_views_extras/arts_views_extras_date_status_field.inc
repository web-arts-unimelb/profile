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

      // Only date fields.
      if ($handler->field_info['module'] != 'date') {
        continue;
      }

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
      $dates = $values->{$this->options['status_date_field']}[0]['raw'];

      // Convert the dates and check if time() is between them.
      $start = strtotime($dates['value']);
      $end   = strtotime($dates['value2']);
      $now   = time();

      // If there are dates and now is in the correct range, we're open and
      // otherwise closed. If no dates, return empty.
      if ($start <= $now && $now <= $end) {
        return t('Open');
      }
      else {
        return t('Closed');
      }
    }

    return t('');
  }
}
