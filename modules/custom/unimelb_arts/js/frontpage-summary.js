
(function ($) {

/**
 * Auto-hide summary textarea if empty and show hide and unhide links.
 */
Drupal.behaviors.frontpageSummary = {
  attach: function (context, settings) {

    var init = $('.field-type-text-with-summary div.text-format-wrapper > fieldset.filter-wrapper input').val();

		// Backup plan
    if(typeof init === 'undefined') {
      init = 'full_html';
    }

    if(version_compare($().jquery, '1.7.0', '>')) {
      $(".text-summary-wrapper select > option[value=" + init + "]").prop("selected", true);
      $(this).closest('.text-format-wrapper').val(init);
    }
    else {
      var widget = $('.text-summary-wrapper select', $(this).closest('.text-format-wrapper').val());
      widget.val(init);
    }

    $('.field-type-text-with-summary div.text-format-wrapper > fieldset.filter-wrapper select').change(function() {
       var value = $(this).val();
       $('.text-summary-wrapper select', $(this).closest('.text-format-wrapper')).val(value);
    });

    $('.text-summary', context).once('text-summary', function () {
      var $widget = $(this).closest('div.field-type-text-with-summary');
      var $summaries = $widget.find('div.text-summary-wrapper');

      $summaries.once('text-summary-wrapper').each(function(index) {
        var $summary = $(this);
        var $summaryLabel = $summary.find('label:first');
        var $full = $widget.find('.text-full').eq(index).closest('.form-item');
        var $fullLabel = $full.find('label:first');

        // Create a placeholder label when the field cardinality is
        // unlimited or greater than 1.
        if ($fullLabel.length == 0) {
          $fullLabel = $('<label></label>').prependTo($full);
        }

        // Setup the edit/hide summary link.
        var $link = $('<span class="field-edit-link">(<a class="link-edit-summary" href="#">' + Drupal.t('Hide front page summary') + '</a>)</span>').toggle(
          function () {
            $summary.hide();
            $(this).find('a').html(Drupal.t('Edit front page summary')).end().appendTo($fullLabel);
            return false;
          },
          function () {
            $summary.show();
            $(this).find('a').html(Drupal.t('Hide front page summary')).end().appendTo($summaryLabel);
            return false;
          }
        ).appendTo($summaryLabel);

        // If no summary is set, hide the summary field.
        if ($(this).find('.text-summary').val() == '') {
          $link.click();
        }
        return;
      });
    });
  }
};

})(jQuery);
