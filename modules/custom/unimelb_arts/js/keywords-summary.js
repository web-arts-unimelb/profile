/**
 * @file
 * Attaches behaviors for the Keywords field.
 */

(function ($) {

Drupal.behaviors.keywordsFieldSummaries = {
  attach: function (context) {
    $('fieldset.group-shared-metadata', context).drupalSetSummary(function (context) {
      // Cut the string, split the keywords into an array, trim all elements.
      var keywords = $.map($('.form-item-field-shared-keywords-und input').val().substring(0,52).split(','), $.trim);

      // Add an ellipsis if the actual string is longer than the summary.
      if ($('.form-item-field-shared-keywords-und input').val().length > 52) {
        keywords.push('…');
      }

      // Return a pretty summary.
      return keywords[0] != '' ?
        Drupal.t('Keywords: @keywords', { '@keywords': keywords.join(', ') }) :
        Drupal.t('Default keywords');
    });
  }
};

})(jQuery);
