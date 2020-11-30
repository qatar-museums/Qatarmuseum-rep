/* global Drupal, jQuery */

(function ($) {
    
    "use strict";

    /*** 'random' layout ***/

    function getTop(a) {
        var $vor = $(".random-layout").find(".views-row").eq(a);
        return $vor.position().top;
    }

    function arrangeLayout() {

        var i, f, l, window_width_factor, current_top, previous_top, oneago_top, twoago_top, difference, height;

        window_width_factor = 3;

        $(".random-layout").show().find(".views-row").each(function (int_index) {
            
            l = int_index;
            height = $(this).outerHeight();

            // if we are the top row, then don't change the top value much at all
            if (l < window_width_factor) {

                i = 0 + Math.round(20 + 90 * Math.random());

            }
            else {

                // get positions 
                oneago_top = getTop(l - window_width_factor) + height;

                // only check the 4 before if we can
                if(l > window_width_factor) {
                    twoago_top = getTop(l - (window_width_factor + 1)) + height; // sometimes an item can overlap not just the one above
                } else {
                    twoago_top = 0;
                }

                previous_top = (oneago_top > twoago_top) ? oneago_top : twoago_top;

                current_top = getTop(l);

                // work out the difference
                difference = current_top - previous_top;

                if(difference < 0) { // this would happen if the item above the current one has been pushed down.

                    i = Math.round(20 + 90 * Math.random()) + (difference * -1);

                }
                // then we don't need to worry about an overlap so don't add the difference
                else {

                    i = Math.round(20 + 90 * Math.random());

                }
                
            }
            
            $(this).css("top", i + "px").show();
            
        });
    }

    $(window).load(function() {

        if($('.random-layout').length) {
            /*
            as per snag #21993 this has been turned off here, and the JS file is no longer loaded from the theme info file.
            */
            // arrangeLayout();

        }

    });

    /*** end random layout ***/

})(jQuery);