<?php

/**
 * A handler to provide a field that is constructed by the administrator using PHP.
 *
 * @ingroup views_field_handlers
 */
class views_multiple_field_handler_field extends views_handler_field {

  /**
   * Implements views_object#option_definition().
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['views_multiple_field_field'] = array('default' => FALSE);
    $options['views_multiple_field_separator'] = array('default' => ', ');
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
      $title = (empty($handler->options['ui_name']))
        ? t('@group: @title', array('@group' => $handler->definition['group'], '@title' => $handler->definition['title']))
        : $handler->options['ui_name'];
      $fields[$handler->handler_type . '_' . $field] = check_plain($title);
    }

    $form['views_multiple_field_field'] = array(
      '#type' => 'select',
      '#title' => t('Source field'),
      '#description' => t('Choose the source tags field to use.'),
      '#options' => $fields,
      '#required' => TRUE,
      '#default_value' => $this->options['views_multiple_field_field']
    );

    $form['views_multiple_field_separator'] = array(
      '#type' => 'textfield',
      '#title' => t('Separator'),
      '#description' => t('Choose the list separator to use.'),
      '#default_value' => empty($this->options['views_multiple_field_separator']) ? ', ' : $this->options['views_multiple_field_separator'],
    );
  }

  /**
   * Implements views_handler_field#query().
   *
   * @see views_php_views_pre_execute()
   */
  function query() {
    // Provide a field alias but don't actually alter the query.
    $this->field_alias = 'views_multiple_field_' . $this->position;
  }

  /**
   * Implements views_handler_field#render().
   */
  function render($values) {
    $value = NULL;
    $items = array();
    
    if (!empty($this->options['views_multiple_field_field'])) {
      foreach ($values->{$this->options['views_multiple_field_field']} as $item) {
        $items[] = check_plain($item['rendered']['#markup']);
      }
    }
  
  	return implode($this->options['views_multiple_field_separator'], $items);  
  }
}
