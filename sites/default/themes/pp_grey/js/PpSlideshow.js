
Drupal.behaviors.PpSlideshow = {
	attach: function(context, settings) {
        var links = jQuery(".slideshow_links", context);
        if (links.length && links.tabs) {
            jQuery(".slideshow_links", context).tabs(".slideshow_images div", {
                // enable "cross-fading" effect
                effect: 'fade',
                fadeOutSpeed: "slow",

                // start from the beginning after the last tab
                rotate: true
            // use the slideshow plugin. It accepts its own configuration
            }).slideshow({
                autoplay: true,
                interval: 5000,
                clickable: false
            });
        }
	}		
}
