(function ($) {
    "use strict";

    /**
     * PP Order module behavior
     * @type {{attach: attach, attachmentImagesInit: attachmentImagesInit, aspCheck: aspCheck}}
     */
    Drupal.behaviors.pp_order = {

        /**
         * Attach behavior
         * @param context
         * @param settings
         */
        attach: function (context, settings) {
            this.aspCheck(context, settings);
            this.attachmentCallbackInit(context, settings);
        },


        /**
         * Shows attachment preview image and ledges variants, when appropiate attachment is chosen
         * @param context
         * @param settings
         */
        attachmentCallbackInit: function (context, settings) {
            var imgCallback = function (v) {
                    $('.img-attachment-preview', context).hide();
                    //TODO docasne vypnuto
                    //$('#img-attachment-preview-' + v, context).show();
                },
                ledgeCallback = function (v) {
                    if (v == 'over') {
                        $('#edit-ledge-collapsible', context)
                            .attr('disabled', 'disabled')
                            .parent()
                            .addClass('form-disabled')
                        ;
                    }
                    else {
                        $('#edit-ledge-collapsible', context)
                            .attr('disabled', false)
                            .parent()
                            .removeClass('form-disabled')
                        ;
                    }

                    //uncheck radio if is disabled
                    $('input[name="ledge"]:disabled', context).attr('checked', false);
                },
                curr = $('input[name="attachment"]:checked', context)
            ;

            $('input[name="attachment"]', context)
                .not('.pp_order_initialized')
                .addClass('.pp_order_initialized')
                .click(function () {
                    var v = $(this).val();
                    imgCallback(v);
                    ledgeCallback(v);
                })
            ;

            // run it for current state if possible
            if (curr.length) {
                imgCallback(curr.val());
                ledgeCallback(curr.val());
            }
        },

        
        /**
         * Tries to check that form is not filled by some curl bot
         *
         * Make sure that user has JS, or is able to fill value by given instructions
         * @param context
         * @param settings
         */
        aspCheck: function (context, settings) {
            $('#edit-js-check', context)
                .not('.pp_order_initialized')
                .addClass('.pp_order_initialized')
                .each(function() {
                    $(this).val('Anti-spam kontrola').closest('div').hide();
                })
            ;
        }
    };
})(jQuery);
