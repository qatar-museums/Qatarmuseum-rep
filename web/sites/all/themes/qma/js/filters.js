/* global Drupal, jq191 */

(function ($) {

  "use strict";

  $(window).load(function() {

    /**
     * Create the overlay canvases.
     * These are left off the DOM as they are not interacted with.
     */
    function create_over(r, g, b, width, height) {
      // this is at the biggest size we will be using the filter hover state
      var over_canvas = $('<canvas class="over_canvas" width="'+width+'" height="'+height+'"></canvas>');

      var context = over_canvas[0].getContext('2d');
      context.fillStyle = 'rgb('+r+','+g+','+b+')';
      context.fillRect(0, 0, width, height);

      return over_canvas;
    }

    /* turns any image into a gray scale version */
    function bwImage(image_src, canvas) {
      var context = canvas.getContext('2d');
      var x = 0;
      var y = 0;

      var imageObj = new Image();
      imageObj.src = image_src;

      // Prevent the image from scaling down to default proportions
      imageObj.width = canvas.width;
      imageObj.height = canvas.height;

      try {
        context.drawImage(imageObj, x, y);

        var imageData = context.getImageData(x, y, imageObj.width, imageObj.height);

        var data = imageData.data;

        for (var i = 0; i < data.length; i += 4) {
          var brightness = 0.34 * data[i] + 0.5 * data[i + 1] + 0.16 * data[i + 2];
          // red
          data[i] = brightness;
          // green
          data[i + 1] = brightness;
          // blue
          data[i + 2] = brightness;
        }

        // overwrite original image
        context.putImageData(imageData, x, y);
      }
      catch (e) {
        return false;
      }
    }

    function create_filter(overlay, underlay, block_colour, blendType) {
      // Likely an 'offscreen' (not in the DOM) canvas
      var over = overlay[0].getContext('2d');

      // (B/W version of the image)
      var under = underlay.getContext('2d');

      // Blend all of 'over' onto 'under' only if we want to
      if (!block_colour) {
        over.blendOnto(under, blendType);
        return true;
      }
      else {
        var colour_data = over.getImageData(0, 0, 1, 1).data;
        under.fillStyle = 'rgb('+colour_data[0]+','+colour_data[1]+','+colour_data[2]+')';
        under.fillRect(0, 0, 595, 395);
        return true;
      }
    }

    // create the overlay canvases
    var standard_width = 600;
    var standard_height = 600;

    var yellow_canvas = create_over(250, 255, 30, standard_width, standard_height);
    var blue_canvas = create_over(121, 170, 250, standard_width, standard_height);
    var pink_canvas = create_over(236, 59, 137, standard_width, standard_height);
    var orange_canvas = create_over(255, 194, 0, standard_width, standard_height);

    var over_array = [yellow_canvas, blue_canvas, pink_canvas, orange_canvas];

    $('.no-touch .filter_image').hover(function() {

      // Check if we're on the new news hub page and if so don't apply the canvas overlay to the image
      // This is neccesary as the teasers lower down the page are using the same template. The header images are fluid
      // width and therefore will not work with the fixed size canvas overlay (width + height) hav to be in the HTML attributes
      if ($(this).parents('.header-section').length > 0 && $(this).parents('.node-news-hub').length > 0) {
        return;
      }

      var image_el = $(this).find('img');
      var image_src = image_el.attr('src');

      var canvas = $(this).find('canvas')[0];

      // turn it b/w
      bwImage(image_src, canvas);

      // apply a random colour filter
      var index = Math.floor(Math.random() * over_array.length);

      // if we have a block colour class, we only want the flat colour as a hover state
      var block_colour = ($(this).hasClass('block-colour')) ? true : false;

      create_filter(over_array[index], canvas, block_colour, 'screen');
    });


    // handle the top level landing page canvases
    if ($('canvas.colour-fade').length > 0) {
      if($(window).width() > 568) {

        var container = $('.hero-container');
        // get the image src without the 'url'. firefox automatically wraps it in "" but chrome does not.
        var image_src = container.css('background-image').replace('url(', '').replace(')', '').replace('"', '').replace('"', '');

        var canvas = $('canvas.colour-fade')[0];

        // turn it b/w
        bwImage(image_src, canvas);

        // apply the appropriate coloured canvas
        var over_canvas = false;

        if (container.hasClass('experience')) {
          over_canvas = create_over(236, 59, 137, 1174, 544);
        }
        else if (container.hasClass('create')) {
          over_canvas = create_over(255, 194, 0, 1174, 544);
        }
        else if (container.hasClass('connect')) {
          over_canvas = create_over(121, 170, 250, 1174, 544);
        }
        else { // default to pink
          over_canvas = create_over(236, 59, 137, 1174, 544);
        }

        // create the multiply filters
        if (create_filter(over_canvas, canvas, false, 'multiply')) {
          // once the canvas has rendered, fade out the block colour that is there at the moment
          $('.block-color-filler').fadeTo(2500, 0);
        }
      }
      else {
        // stops the block colour from showing when coming from mobile to desktop
        $('.block-color-filler').hide();
      }
    }

    // handle the click through event
    $('.filter_image canvas, .filter_image .hover-text').on('click', function(event) {
      event.preventDefault();
      var href = '';

      // creative resources have to be handled slightly different
      if ($(this).closest('.node-creative-resource').length > 0) {
        href = $(this).closest('.node-creative-resource').find('.cr-url a').attr('href');
      }
      else {
        href = $(this).closest('.filter_image').find('a').attr('href');
      }

      if (href) {
        window.location = href;
      }
      else {
        return false;
      }
    });
  });

})((jq191));