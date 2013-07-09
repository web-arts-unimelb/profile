(function ($) {
  Drupal.behaviors.bootstrap_unimelb = {
    attach: function(context, settings) {
			/* Youtube demension hack */
			if(jQuery.browser.msie)
  		{
    		var default_width = 640;
    		var default_height = 360;
    
    		$('.video-container').width(default_width);
    		$('.video-container').height(default_height);
				$('.video-container').css("padding-bottom", "0px");
				

    		$('.video-container object').width(default_width);
    		$('.video-container object').height(default_height);

    		$('.video-container iframe').width(default_width);
    		$('.video-container iframe').height(default_height);

    		$('.video-container embed').width(default_width);
    		$('.video-container embed').height(default_height);
  		}
		}
	}
})(jQuery);


