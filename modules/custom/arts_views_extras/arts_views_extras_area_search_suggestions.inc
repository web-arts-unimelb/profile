<?php

/**
 * @file
 */

/**
 * Views area search terms handler.
 */
class arts_views_extras_area_search_suggestions extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();
    $options['filter'] = array('default' => '');
    $options['empty'] = array('default' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Get a list of the available exposed filters.
    $options = array();
    foreach ($this->view->display_handler->get_handlers('field') as $filter => $handler) {
      $options[$filter] = $handler->ui_name();
    }

    // List of fields, pick one.
    $form['filter'] = array(
      '#title' => t('Filter'),
      '#description' => t('Select the filter whose value should be used as search term.'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => $this->options['filter'],
    );

    $form['empty'] = array(
      '#type' => 'checkbox',
      '#title' => t('Only offer suggestions if the field has not returned any items'),
      '#default_value' => $this->options['empty'],
    );

    dpm($form);
  }

  function render($empty = FALSE) {
    $filter = $this->options['filter'];

    if (!$empty || !empty($this->options['empty'])) {
      return t('Foobar!');
    }
    return t('Minge');
  }

}
