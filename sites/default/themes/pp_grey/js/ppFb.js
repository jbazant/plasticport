

Drupal.behaviors.PpFb = {
    attach: function(context, settings) {
        this.fbLikeInit(document, 'script', 'facebook-jssdk');
    },

    fbLikeInit: function(d, s, id) {
        var js, fjs = d.getElementsByTagName(s)[0];
        if (d.getElementById(id)) return;
        js = d.createElement(s); js.id = id;
        js.src = "//connect.facebook.net/cs_CZ/all.js#xfbml=1";
        fjs.parentNode.insertBefore(js, fjs);
    }
}