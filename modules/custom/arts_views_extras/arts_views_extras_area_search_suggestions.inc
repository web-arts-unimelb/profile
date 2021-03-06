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
    $options['match'] = array('default' => MATCH_LEVENSHTEIN);
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

    // Matching algorithm.
    $form['match'] = array(
      '#title' => t('Match'),
      '#description' => t('Select the PHP function to use to calculate string similarity for output order.'),
      '#type' => 'select',
      '#options' => array(
        MATCH_LEVENSHTEIN => t('levenshtein() - O(L1*L2)'),
        MATCH_SIMILAR_TEXT => t('similar_text() - O(N^3)'),
      ),
      '#default_value' => $this->options['match'],
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

    // Calculate relevancy using the preferred algorithm.
    while($record = $result->fetchAssoc()) {
      foreach ($words as $word) {
        // Filter out the literal words we searched for to begin with.
        if ($word == $record['word']) {
          continue;
        }
        if ($this->options['match'] == MATCH_SIMILAR_TEXT) {
          similar_text($record['word'], $word, $match);
          $match = 100 - $match;
        }
        else {
          $match = levenshtein($record['word'], $word);
        }
        $suggestions[$record['word']] = $match;
      }
    }

    // Sort the list of suggestions by reverse match distance, so closer
    // is at the top.
    arsort($suggestions);

    // Remove duplicates and return.
    return array_splice(array_unique(array_keys($suggestions)), 0, $this->options['limit']);
  }

}
