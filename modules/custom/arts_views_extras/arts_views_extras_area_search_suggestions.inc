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
    $options['prefix'] = array('default' => '');
    $options['filter'] = array('default' => '');
    $options['limit'] = array('default' => 5);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['prefix'] = array(
      '#type' => 'textfield',
      '#title' => t('Prefix'),
      '#description' => t('A prefix (or title) to show in front of the search suggestions.'),
      '#default_value' => $this->options['prefix'],
    );

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

    $limits = array();
    for ($i = 1; $i <= 10; $i++) {
      $limits[$i] = $i;
    }
    // List of fields, pick one.
    $form['limit'] = array(
      '#title' => t('Limit'),
      '#description' => t('Limit the number of suggestions to display.'),
      '#type' => 'select',
      '#options' => $limits,
      '#default_value' => $this->options['limit'],
    );

  }

  function render($empty = FALSE) {
    $filter = $this->options['filter'];

    if ($empty) {
      if (!empty($this->view->exposed_input[$filter])) {

        // Grab suggestions.
        $suggestions = $this->soundexes($this->view->exposed_input[$filter]);

        if (!empty($suggestions)) {
          $last = array_pop($suggestions);
          return t('@prefix@thing %suggestions%last.', array(
            '@prefix' => $this->options['prefix'],
            '@thing' => !empty($this->options['prefix']) ? ': ' : '',
            '%suggestions' => implode(', ', $suggestions),
            '%last' => ' or ' . $last,
          ));
        }

        return '';
      }
    }
  }

  /**
   * Look for similar sounding words in the search index table.
   */
  function soundexes($filter) {
    $suggestions = array();

    $query = db_select('search_index', 's')
      ->distinct()
      ->range(0, $this->options['limit'])
      ->fields('s', array('word'))
      ->condition('s.type', 'node')
      ->orderBy('s.score', 'DESC');

    // Add a soundex compare (OR) for each word in the filter.
    $or = db_or();
    $words = explode(' ', $filter);
    foreach ($words as $word) {
      $or->where('STRCMP(SOUNDEX(s.word), SOUNDEX(:word)) = 0', array(':word' => $word));
    }
    $query->condition($or);

    $result = $query->execute();

    // Calculate relevancy using levenshtein().
    while($record = $result->fetchAssoc()) {
      foreach ($words as $word) {
        // Filter out the literal words we searched for to begin with.
        if ($word == $record['word']) {
          continue;
        }
        $lev = levenshtein($record['word'], $word);
        $suggestions[$lev] = $record['word'];
      }
    }

    // Sort the list of suggestions by reverse levenshtein distance, so closer
    // is at the top.
    krsort($suggestions);

    // Remove duplicates and return.
    return array_unique($suggestions);
  }

}
