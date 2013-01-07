/**
 * @file
 * Attaches behaviors for the Tags field.
 */

(function ($) {

Drupal.behaviors.tagsFieldSummaries = {
  attach: function (context) {
    $('fieldset.group-shared-structure', context).drupalSetSummary(function (context) {
      var tags = [];

      $('#edit-field-shared-tags input:checkbox[checked]').each(function() {
        tags.push($(this).next('label').text().replace(/^\-?/g, ''));
      });

      // Return a pretty summary.
      return tags.length > 0 ?
        Drupal.t('@tags', { '@tags': tags.join(' » ' ) }) : Drupal.t('Not tagged');
    });
  }
};

})(jQuery);
