/* global Drupal, jq191, FastClick, jQuery, Select, Masonry */

(function($) {
    "use strict";

    /** 
     * Adds the AJAX and fade transitions for the Social Media Hub display.
     */
    Drupal.behaviors.QMAInstagram = {
        attach: function(context, settings) {
            this.instagram(this, context, settings);
        },

        /**
         * Initialise the Instagram AJAX and fade effect.
         */
        instagram: function(self, context, settings) {
            if ($('.instagram-slider', context).length) {
                $('.instagram-slider', context).once('ajax', function() {
                    if (typeof Drupal.settings.instagram_account === 'undefined') {
                        return;
                    }

                    if (self.isMobile(self, context)) {
                        return;
                    }

                    var instagram_account = Drupal.settings.instagram_account,
                        ajaxParams = {
                            url: '/' + Drupal.settings.pathPrefix + 'views/ajax',
                            type: 'post',
                            data: {
                                view_name: 'project_instagram',
                                view_display_id: 'block_1',
                            },
                            dataType: 'json',
                            success: function (response, textStatus, jqXHR) {
                                self.processAjax(self, response, context);
                            }
                        };

                    if (instagram_account) {
                        ajaxParams.data.instagram_account = instagram_account;
                    }

                    $.ajax(ajaxParams);
                });
            }
        },

        /**
         * Process the AJAX response and replace the instagram markup.
         */
        processAjax: function(self, response, context) {
            for (var i = 0, len = response.length; i < len; i++) {
                if (response[i].command === 'insert') {
                    var new_content_wrapped = $('<div></div>').html(response[i].data),
                        new_content = new_content_wrapped.contents();

                    $('.view-project-instagram', context).replaceWith(new_content);
                    self.attachFade(self, context);
                }
            }
        },

        /**
         * Set up the fade transition for the Instagram display.
         */
        attachFade: function(self, context) {
            var $wrapper = $('.view-project-instagram', context),
                $activeRow = $('.instagram-row:first-child', $wrapper),
                totalItems = $('.instagram-item', $wrapper).length,
                fadeInterval = 1000,
                lastReplacement = 99,
                lastSource = 99;

            // At a set interval, replace one of the visible Instagram images.
            window.setInterval(function() {
                // Don't transition if someone's viewing the tooltip.
                if ($activeRow.is(':hover')) {
                    return;
                }

                // The screen has been resized - wait until it's bigger.
                if (self.isMobile(self, context)) {
                    return;
                }

                // Pick new, random items from the active row and the pool of
                // replacement items.
                var randomSource = self.generateRandom(2, 0, lastSource),
                    randomReplacement = self.generateRandom(totalItems - 4, 3, lastReplacement);

                lastSource = randomSource;
                lastReplacement = randomReplacement;

                // Get the source and replacement items, and create copies.
                var $activeItem = $($('.instagram-item', $wrapper)[randomSource]),
                    $activeItemClone = $activeItem.clone(),
                    $replacementItem = $($('.instagram-item', $wrapper)[randomReplacement]),
                    $replacementItemClone = $replacementItem.clone();

                $replacementItemClone
                    .hide()
                    .css({
                        position: 'absolute',
                        zIndex: 0,
                        top: 0,
                        left: (33.33333336 * randomSource) + '%'
                    })
                    .insertAfter($activeItem);

                $activeItem.fadeOut(fadeInterval, function(){
                    $activeItem.remove();
                });

                $replacementItemClone.fadeIn(fadeInterval, function() {
                    $replacementItemClone
                        .css({
                            position: 'relative',
                            zIndex: 0,
                            top: 'auto',
                            left: 'auto'
                        });

                    $replacementItem.replaceWith($activeItemClone);
                });
            }, 3000);
        },

        /**
         * Generate a random number in the range 0-max, with an optional offset.
         *
         * If exclude is supplied, this number generated will not be equal to
         * this value.
         */
        generateRandom: function(max, offset, exclude) {
            var random;

            offset = (typeof offset !== 'undefined') ? offset : 0;
            exclude = (typeof exclude !== 'undefined') ? exclude : null;

            do {
                random = Math.floor(Math.random() * (max + 1)) + offset;
            } while (random === exclude);

            return random;
        },

        /**
         * Check if we're using the mobile display. The heuristic used is if we
         * can see less than three instagram images, since screen width checking
         * is affected by the scrollbar.
         */
        isMobile: function(self, context) {
            return $('.instagram-slider .instagram-item:visible', context).length < 3;
        }
    };

})(jQuery);