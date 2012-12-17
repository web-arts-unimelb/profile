<?php
/**
 * @file unimelb_arts.views.inc
 * Routines and hooks to mess with views.
 */

/**
 * Implements hook_views_pre_render().
 */
function unimelb_arts_views_pre_render(&$view) {
  // If a view uses a taxonomy term argument *and* needs argument substitution then
  // translate the argument string into the actual peroprly capitalised term name
  // rather than hoping the arguments transform works out okay.
  if (!empty($view->args)
    && (!empty($view->argument['tid']) || (!empty($view->relationship['term_node_tid'])))
    && (!empty($view->build_info['substitutions']))) {
      $replacements = array();

      // Fast query.
      $terms = db_query('SELECT name FROM {taxonomy_term_data}');
      foreach ($terms as $term) {
        $replacements[strtolower($term->name)] = $replacements[strtr(strtolower($term->name), array(' ' => '-'))] = check_plain($term->name);
      }

      foreach ($view->build_info['substitutions'] as $key => $value) {
        $view->build_info['substitutions'][$key] = strtr($value, $replacements);
      }
  }
}
