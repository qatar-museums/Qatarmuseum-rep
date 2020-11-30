/* global Drupal, jq191, FastClick, jQuery, Select, Masonry */

(function ($) {

    "use strict";

    $(document).ready(function(){   
        

        // are we on IE10? horrible hack but needed for styling purposes
        function IE(v) {
            var r = new RegExp('msie' + (!isNaN(v) ? ('\\s' + v) : ''), 'i');
            return r.test(navigator.userAgent);
        }

        if(IE(10)) {
            $('html').addClass('ie-10');
        }

        document.addEventListener("touchstart", function(){}, true);

        /*** slider handling has to go in the document.ready ***/

        if($('.cbp-fwslider').length > 0) {

            // for the image gallery
            if($('.image-gallery').length > 0) {

                if($(window).width() > 568 || $('html').hasClass('no-touch')) {

                    $('.cbp-fwslider .gallery-image img').each(function() {

                        var data_large = $(this).attr('data-large-src');
                        $(this).attr('src', data_large);

                    }).closest('.cbp-fwslider').css('visibility', 'visible').cbpFWSlider();

                } else {
                    // if we don't need to swap the image srcs then just show it and slide it
                    $('.cbp-fwslider').css('visibility', 'visible').cbpFWSlider();

                }

                // move the nav controls to where we want them
                $('.cbp-fwslider nav').addClass('slider-controls').appendTo($('.gallery-controls-container')).show();

                // initialise the counter
                $('.gallery-count span.total').html($('.cbp-fwslider ul li').length);
                $('.gallery-count').show();

            } else {
                // if we don't have to do anything fancy (featured news slider) then just show it, as long as we aint on ie8
                // in which case we show them as a stacked list
                if(!$('html').hasClass('lt-ie9')) {

                    $('.cbp-fwslider').cbpFWSlider();

                    // move the nav controls to where we want them
                    $('.cbp-fwslider nav').addClass('slider-controls').appendTo($('.featured-news')).show();

                    // we need to apply specific styles to the slider if there are only 3 items in it
                    if($('.cbp-fwslider ul .views-row').length === 3) {
                        $('.featured-news').addClass('three-items');
                    }

                }
            }

        }
   /**
 * ASLAM CODE STARTS
 * 
 */
$("#edit-between-date-filter-2 .form-radio").each(function(){
        if($(this).prop('checked')){
            if($(this).val()=="3"){
                $("#edit-between-date-filter-value-wrapper").show();        
            }
        }
    });
   /* $("#edit-between-date-filter-2 .form-radio").each(function(){
        if($(this).prop('checked')){
            if($(this).val()=="3"){
                $("#edit-between-date-filter-value .form-item-between-date-filter-value-date").show();


        
            }
        }
    });*/
    /**
 * ASLAM CODE ENDS
 * 
 */
   

    });

    $(window).load(function() {

        /* Remove html5 video class in safari */
        if (navigator.userAgent.indexOf('Safari') !== -1 && navigator.userAgent.indexOf('Chrome') === -1) {
            $('html').addClass('safari').removeClass('video');
        }

        /* Do some custom evaluation of video support */
        if ($('html').hasClass('video')) {
            var headerVideo = $('header video')[0] ? $('header video')[0] : undefined;

            try {
                headerVideo.pause();
            }
            catch (e) {
                // If we encounter an error something is wrong with video support.
                $('html').removeClass('video');
            }
        }

        /*** header ***/

        if($('header').length > 0) {
            /*
            // Deal with opening the menu on mobile
            $('.mobile-menu').click(function(event) {
                if($('html').hasClass('touch') && ($(window).width() < 1024)) { // else click (tap) the header to open it

                    event.preventDefault();

                    $('header').toggleClass('open');

                    $('header').find('.site-nav').fadeToggle('fast');
                    $('.region-header-search').fadeToggle('fast');

                }
            });
            */
           

            // header search bar fanciness
            $('.site-header .form-submit').click(function(event) {

                var form = $('.site-header form');

                // animate the width of the search form input box when the user first clicks on
                // the submit button. Give the element focus once the animation has completed
                if(!form.hasClass('open') && ($(window).width() > 1024)) {
                    event.preventDefault();
                    form.toggleClass('open');
                    var search = form.find('input[type="text"]');
                    search.animate({
                        width: '20em',
                    }, 300, function() {
                        search.focus();
                    });
                }

            });

        } /*** end header ***/

        /*** Homepage ***/

        // handle random image showing
        function swapImages(){
            // we -1 here because we don't want the last homepage-box, which contains the logo
            var rando_index = Math.floor(Math.random() * ($('.homepage-collection .homepage-box').length - 1));

            var box_to_swap = $('.homepage-collection .homepage-box:eq('+rando_index+')');

            // we don't want to swap the images inside a hovered box so go to the next one (if poss) or the previous one
            if (box_to_swap.hasClass('hovered')) {
                box_to_swap = (box_to_swap.next().length) ? box_to_swap.next() : box_to_swap.previous();
            }

            // now find the currently showing image, the next one to show, fade it in, fade out the old one.
            var old_front = box_to_swap.find('.homepage-box-image.front');
            var new_front = (old_front.next().length) ? old_front.next() : box_to_swap.find('.homepage-box-image:first');

            // logo checking. we only want to show one box with the logo at a time.
            if(new_front.hasClass('logo-container')) {
                // then check if a logo-container currently being shown?
                if($('.homepage-box .logo-container.front').length) {
                    // yes? then pick a non logo homepage box to show
                    new_front = box_to_swap.find('.homepage-box-image:first');

                } else {
                    // now pick random logo image
                    var logo_index = Math.floor(Math.random() * 8) + 1;

                    // and swap the src
                    new_front.find('img').attr('src', '/sites/all/themes/qma/images/logo_blocks/logo'+logo_index+'.png');
                }
            }

            new_front.fadeTo(250, 1).addClass('front');
            old_front.fadeTo(250, 0).removeClass('front');

        }

        if($('body').hasClass('node-type-homepage')) {

            // add hover class to hovered homepage-box
            if($('html').hasClass('no-touch')) {

                // handle link clicking
                $('.homepage-box').click(function(event) {
                    event.preventDefault();

                    var $link = $(this).find('a'),
                        url = $link.attr('href');

                    if ($link.attr('target') === '_blank') {
                      window.open(url);
                    }
                    else {
                      window.location = url;
                    }
                });

                $('.homepage-box').hover(function() {

                    $(this).addClass('hovered');

                    if($(this).find('.front.logo-container').length > 0) {
                        var old_front = $(this).find('.homepage-box-image.front');
                        var new_front = (old_front.next().length) ? old_front.next() : $(this).find('.homepage-box-image:first');
                        new_front.fadeTo(250, 1).addClass('front');
                        old_front.fadeTo(250, 0).removeClass('front');
                    }

                }, function() {
                    $(this).removeClass('hovered');
                });

            } else if ($('html').hasClass('touch')) {
                $('.homepage-box a').bind('touchstart', function(event) {
                    event.stopPropagation();
                });

                $('.homepage-box').bind('touchstart', function() {
                    var that = $(this);

                    if($(this).find('.front.logo-container').length > 0) {
                        var old_front = $(this).find('.homepage-box-image.front');
                        var new_front = (old_front.next().length) ? old_front.next() : $(this).find('.homepage-box-image:first');
                        new_front.fadeTo(250, 1).addClass('front');
                        old_front.fadeTo(250, 0).removeClass('front');
                    } else {
                        $('.homepage-box').each(function() {
                            if($(this)[0] !== that[0]) {
                                $(this).removeClass('hovered');
                            }
                        });
                    }

                    that.toggleClass('hovered');

                });
            }

            if($(window).width() > 568) {
                setInterval(swapImages, 1000);
            }

        }

        /*** end homepage ***/

        /*** landing page fading hero ***/

        if($('body').hasClass('node-type-landing-page') || $('body').hasClass('node-type-areas-hub')) {

            $('.colour-fade').delay(500).fadeOut(2500);

        }

        /*** end landing page fading hero ***/

        /*** pattern generator gallery ***/

        if($('.node-pattern-gallery').length > 0) {

            $('.gallery-image:not(.link-square)').click(function() {

                var clicked_square = $(this);
                var old_clicked_square = $('.gallery-image.clicked');

                var container = clicked_square.closest('.pattern-row').next('.large-pattern-container');
                var data_large = clicked_square.find('img').attr('data-large-src');

                clicked_square.addClass('clicked');

                $('.large-pattern-container').animate({
                    'height': 0
                }, 'medium', function() {

                    $('.large-pattern-container.open').removeClass('open');

                    if (clicked_square[0] !== old_clicked_square[0]) {

                        var large_image = container.find('img');

                        // fade out the old image, load the new one, fade in the new image.
                        large_image.fadeOut('fast').attr('src', data_large).load(function(){
                            $(this).fadeIn('fast');
                        });

                        container.addClass('open');

                        var height = '0px';

                        if (container.hasClass('open')) {
                            if ($(window).width() > 767) {
                                height = '670px';
                            }
                            else {
                                height = '340px';
                            }

                        }

                        container.animate({
                            'height': height
                        }, 'medium');

                        $('html,body').animate({
                            'scrollTop': clicked_square.offset().top
                        }, 'medium');

                    }

                    old_clicked_square.removeClass('clicked');

                });

            });

        }

        /*** end pattern generator gallery ***/

        /*** experience page ***/

        if($('.node-type-areas-hub').length > 0) {
            // handle link clicking
            if($('html').hasClass('no-touch')) {

                $('.views-row').click(function() {
                    window.location = $(this).find('a').attr('href');
                });

            } else if ($('html').hasClass('touch')) {

                $('.views-row a').bind('touchstart', function(event) {
                    event.stopPropagation();
                });

                $('.views-row').bind('touchstart', function() {
                    var that = $(this);
                    $('.views-row').each(function() {
                        if($(this)[0] !== that[0]) {
                            $(this).removeClass('hovered');
                        }
                    });
                    that.toggleClass('hovered');

                });
            }
        }


        /*** generic hub page ***/

        if($('.grid-four').length > 0) {
            // handle link clicking
            if ($('html').hasClass('touch') && $(window).width() > 567) {

                $('.grid-four a').click(function(event) {
                    event.preventDefault();
                });

                $('.grid-four .filter_image.hovered').click(function(event) {
                    event.preventDefault();
                    window.location = $(this).find('a').attr('href');
                });

                $('.grid-four .filter_image').bind('click', function() {
                    var that = $(this);
                    $('.grid-four .filter_image').each(function() {
                        if($(this)[0] !== that[0]) {
                            $(this).removeClass('hovered');
                        }
                    });
                    that.toggleClass('hovered');

                });
            }
        }

        /*** tweet/instagram hovering ***/

        if($('.project-social-container').length > 0) {
            var zInd = 10;
            $(".tweet-item, .instagram-item").mouseover(function(){
                zInd+=1;
                $(this).css('zIndex', zInd);
            });
        }

        /*** message handling ****/
        $('.messages').click(function() {
            // some messages we want to stay on click
            if(!$(this).find('.krumo-root').length) {
                $(this).fadeOut('fast');
            }
        });

        $('.sm-link a').hover(function() {
            $(this).closest('.sm-link').toggleClass('hover');
        });

    });

})((jq191));

/*** everything below this is to do with the AJAX views and filters on the experience page
It is not pretty.
***/

/*** masonry now its own function pulled out from jquery 1.9.1
because now Drupal views (which uses jquery 1.4.2) knows it exists. ***/

(function ($) {
    "use strict";

    function masonry_init() {
        /*** masonry init ***/
        if ($('#masonry-container').length && $(window).width() > 567) {

            var origin = ($('html').attr('dir') === 'ltr') ? true : false;

            var container = document.querySelector('#masonry-container');
            var msnry = new Masonry( container, {
                columnWidth: 200,
                itemSelector: '.views-row',
                isFitWidth: false,
                stamp: ".experience-view-header",
                isOriginLeft: origin,
            });

        }

    }

    // function to determine whether we show the reset filter or not.
    function show_reset() {
        if($('.node-areas-hub').length > 0) {
            // if there are any of the status filters chosen
            if($('.status-filter .activefilter').length) {
                return true;
            }

            // if any of the area filters are checked that aren't the 'all' value
            if($('#edit-areaid input:checked').val() !== 'All') {
                return true;
            }

        }

        if($('.node-press-room').length > 0) {

            // if the selected value in the drop down is not the 'all' value
            if($('#edit-typeid option:selected').val() !== 'All') {
                return true;
            }

        }

        // if the selected value in the drop down is not the 'all' value
        if($('#edit-tagid option:selected').val() !== 'All') {
            return true;
        }

        return false;

    }

    function reinit_filter_handling() {
/*

        if ($('select').length > 0 && !$('html').hasClass('lt-ie9')) {
            var selects = Select.init();

            for (var i = 0, len = selects.length; i < len; i++) {
                if (selects[i] !== undefined && $(selects[i].select).hasClass('error')) {
                    $(selects[i].target).addClass('error');
                }
            }

            $('a.select-target, a.select-target b').addClass('needsclick');

            /*** experience filters handling *** /

            if($('.view-display-id-all_projects_and_areas').length || $('.view-display-id-experience_map_block').length) {

                $('.views-widget-filter-tid_i18n select').change(function() {

                    // remove all checked attributes from the radio input labels
                    $('.bef-select-as-radios input').removeAttr("checked");
                    // now check the hidden 'all' filter
                    $('.bef-select-as-radios .form-item:first-child input').attr("checked", "checked");
                    $('#edit-submit-projects-by-area').trigger('click');
                });

            }

        }
*/
        if($('.node-areas-hub .view-projects-by-area').length > 0) {

            // make the radio labels 'selected' if need be on page/view load
            $('.bef-select-as-radios input').each(function() {

                $(this).next('label').removeClass('selected');

                if($(this).is(':checked')) {
                    $(this).next('label').addClass('selected');
                }

            });

            $('.bef-select-as-radios label').click(function(event) {
                // if it's already selected, remove it, clear all filters and submit the form
                if($(this).hasClass('selected')) {
                    event.preventDefault();
                    $(this).removeClass('selected');
                    // now unset the select box
                    $('.views-widget-filter-tid_i18n select').val('');

                    // now check the hidden 'all' filter
                    $('.bef-select-as-radios .form-item:first-child label').trigger('click');
                    $('#edit-submit-projects-by-area').trigger('click');

                } else { // if it isn't, we want the select box to clear anyway
                    // now unset the select box
                    $('.views-widget-filter-tid_i18n select').val('');
                }

            });

        }

        $('.experience-view-header .status-filter a').click(function(event) {

            event.preventDefault();

            // because there are 4 radio buttons (including 'all') but only 3 links, we have to offset the index by 1.
            var link_index = -1;

            if($(this).hasClass('activefilter')) {

                $(this).removeClass('activefilter');

            } else {
                link_index = $(this).index();
            }

            $('.views-widget-filter-field_project_status_value .form-item:eq('+(link_index+1)+') input').attr('checked', 'checked');
            $('#edit-submit-projects-by-area').trigger('click');


        });

        //work out if we need to show the reset button or not
        if(show_reset()) {
            $('.view-filters .reset').show();
        }

        // and then handle the click event for the reset button
        $('.view-filters .reset').click(function(event) {

            event.preventDefault();

            // experience page handling
            if($('.view-display-id-all_projects_and_areas').length || $('.view-display-id-experience_map_block').length) {
                // now check the hidden 'all' filters and reset the select box
                $('.bef-select-as-radios .form-item:first-child input[type="radio"]').attr('checked', 'checked');
                $('.views-exposed-form select').val('All');
                $('#edit-submit-projects-by-area').trigger('click');
            }

            // press room handling
            if($('.view-id-press').length) {
                // reset the select boxes
                $('.views-exposed-form select').val('All');
                $('#edit-submit-press').trigger('click');
            }

            // press room handling
            if($('.view-creative-resources').length) {
                // reset the select boxes
                $('.views-exposed-form select').val('All');
                $('#edit-submit-creative-resources').trigger('click');
            }

        });

    }

    // make sure masonry starts when the page loads
    $(window).load(function() {

        if(!$('html').hasClass('lt-ie9')) {
            masonry_init();

            // select box styling using libraries/select/select.js
            reinit_filter_handling();
        }

        /*** poll submission handling ***/

        if($('.node-advpoll').length > 0) {

            $('.node-advpoll .form-radios label').live('click', function() {

                var form = $(this).closest('form');

                form.find('label').removeClass('selected');

                $(this).addClass('selected');

            });

            $('.node-advpoll #message').live('click', function() {
                $(this).fadeOut('fast');
            });

        }

    });

    $(document).ajaxSuccess(function(event, xhr, settings){

        if (settings.url.indexOf('/views/ajax') > -1) {
            masonry_init();
            reinit_filter_handling();
             /**
             * ASLAM CODE STARTS
             * 
             */

                $("#edit-between-date-filter-2 .form-radio").each(function(){
                    if($(this).prop('checked')){
                        if($(this).val()=="3"){
                            $("#edit-between-date-filter-value .form-item-between-date-filter-value-date").show();
                        }
                    }
                });
                /**
             * ASLAM CODE ENDS
             * 
             */
        }

    });

    /*
     * Event handlers for capturing site interactions in Google analytics.
     */

    $('#user-register-form').live('submit', function() {
        _gaq.push(['_trackEvent', 'Membership', 'Register', 'New account created']);
    });

    $('.share-links .twitter a').live('click', function() {
        _gaq.push(['_trackEvent', 'Social', 'Share', 'Twitter link clicked']);
    });

    $('.share-links .facebook a').live('click', function() {
        _gaq.push(['_trackEvent', 'Social', 'Share', 'Facebook link clicked']);
    });

    /**
 * ASLAM CODE STARTS
 * 
 */
 
 $("#edit-between-date-filter-2 input.form-radio").live("click", function(e){
    $("#edit-field-eduprog-repeat-field-date-value-1-1").removeAttr("checked");
    //alert("test");
    if($(this).val()=="3"){
        //alert("if");
	var today = new Date();
	var dd = String(today.getDate()).padStart(2, '0');
	var mm = String(today.getMonth() + 1).padStart(2, '0');
	var yyyy = today.getFullYear();
        $("#edit-between-date-filter-value").show();
       $("#edit-between-date-filter-value #edit-between-date-filter-value-datepicker-popup-0").val(mm + '/' + dd + '/' + yyyy);
    }
    else if($(this).val()=="1"){
         $("#edit-field-eduprog-repeat-field-date-value-1-1").attr("checked","checked");
    }
    else{
        //alert("else");
        $("#ededit-between-date-filter-value").hide();
        $("#edit-between-date-filter-value #edit-between-date-filter-value-datepicker-popup-0").val("");
    }
});
/*$("#edit-between-date-filter-2--12-wrapper input.form-radio").live("click", function(e){
    $("#edit-field-eduprog-repeat-field-date-value-1-1").removeAttr("checked");
    if($(this).val()=="3"){
        //alert("if");
	var today = new Date();
	var dd = String(today.getDate()).padStart(2, '0');
	var mm = String(today.getMonth() + 1).padStart(2, '0');
	var yyyy = today.getFullYear();
        $("#edit-between-date-filter-value-wrapper").show();
       $("#edit-between-date-filter-value-wrapper #edit-between-date-filter-value--7-datepicker-popup-0").val(mm + '/' + dd + '/' + yyyy);
    }
    else if($(this).val()=="1"){
         $("#edit-field-eduprog-repeat-field-date-value-1-1").attr("checked","checked");
    }
    else{
        //alert("else");
        $("#ededit-between-date-filter-value-wrapper").hide();
        $("#edit-between-date-filter-value-wrapper #edit-between-date-filter-value--7-datepicker-popup-0").val("");
    }
});
*//*$("#edit-between-date-filter-2 input.form-radio").live("click", function(e){
        $("#edit-field-eduprog-repeat-field-date-value-1-1").removeAttr("checked");
        if($(this).val()=="3"){
            //alert("if");
		var today = new Date();
		var dd = String(today.getDate()).padStart(2, '0');
		var mm = String(today.getMonth() + 1).padStart(2, '0');
		var yyyy = today.getFullYear();
            $("#edit-between-date-filter-value-wrapper .form-item-between-date-filter-value-date").show();
           $("#edit-between-date-filter-value-wrapper #edit-between-date-filter-value--7-datepicker-popup-0").val(mm + '/' + dd + '/' + yyyy);
        }
        else if($(this).val()=="1"){
             $("#edit-field-eduprog-repeat-field-date-value-1-1").attr("checked","checked");
        }
        else{
            //alert("else");
            $("#ededit-between-date-filter-value-wrapper .form-item-between-date-filter-value-date").hide();
            $("#edit-between-date-filter-value-wrapper #edit-between-date-filter-value--7-datepicker-popup-0").val("");
        }

   });*/
/*
    $("#edit-between-date-filter-2 input.form-radio").live("click", function(e){
        $("#edit-field-eduprog-repeat-field-date-value-1-1").removeAttr("checked");
        if($(this).val()=="3"){
            //alert("if");
            $("#edit-between-date-filter-value .form-item-between-date-filter-value-date").show();
           $("#edit-between-date-filter-value #edit-between-date-filter-value-datepicker-popup-0").val("02/26/2020");
        }
        else if($(this).val()=="1"){
             $("#edit-field-eduprog-repeat-field-date-value-1-1").attr("checked","checked");
        }
        else{
            //alert("else");
            $("#edit-between-date-filter-value .form-item-between-date-filter-value-date").hide();
            $("#edit-between-date-filter-value #edit-between-date-filter-value-datepicker-popup-0").val("");
        }

   });
  */
/*
    $("#edit-between-date-filter-2-1").live("click", function(e){
        if($(this).attr("checked")){
            //alert("twa");
            $("#edit-field-eduprog-repeat-field-date-value-1-1").attr("checked","checked");
        }
        else{
            $("#edit-field-eduprog-repeat-field-date-value-1-1").removeAttr("checked");
        }

    });
*/

 /**
 * ASLAM CODE ENDS
 * 
 */

})(jQuery);
