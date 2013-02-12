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
    foreach ($this->view->display_handler->get_handlers('filter') as $filter => $handler) {
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
  }

  function render($empty = FALSE) {
    $filter = $this->options['filter'];

    if ($empty && $this->options['empty']) {
      if (!empty($this->view->exposed_input[$filter])) {
        $query = db_select('search_index', 's')
          ->distinct()
          ->range(0,5)
          ->fields('s', array('word'))
          ->condition('s.type', 'node')
          ->orderBy('s.score', 'DESC');

        $or = db_or();
        $words = explode(' ', $this->view->exposed_input[$filter]);
        foreach ($words as $word) {
          $word = db_like($word);
          $or->condition('s.word', '%%' . $word . '%%', 'LIKE');
        }
        $query->condition($or);

        $result = $query->execute();

        $suggestions = array();
        while($record = $result->fetchAssoc()) {
          $suggestions[] = $record['word'];
        }
        return t('No awards were found, you might want to try searching for: %suggestions',
          array('%suggestions' => implode(', ', $suggestions)));
      }
    }
  }

}
