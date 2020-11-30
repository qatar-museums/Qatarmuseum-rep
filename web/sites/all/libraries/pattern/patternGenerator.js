(function (Drupal, $) {

  "use strict";

  $(window).load(function() {

    var $patternDownloadOverlay = $('.pattern-overlay.pattern-download'),
        $patternShareOverlay = $('.pattern-overlay.pattern-share'),
        messageText = Drupal.settings.qmaForms.messageText || '';

    /**
     * Returns base64 image data for the pattern canvas.
     * Trims the image to exclude the controls.
     */
    function getCanvasImageData() {
      var canvasX = 0, // set the offset and size of our canvas
          canvasY = 0,
          canvasWidth = 650,
          canvasHeight = 650,
          OScanvasElement = $('.pattern-generator-wrapper canvas'), // identify the on screen canvas
          tempCanvas = document.createElement("canvas"), // create a new canvas element
          tempContext = tempCanvas.getContext("2d"); // grab the context of this canvas

      tempCanvas.width = canvasWidth;
      tempCanvas.height = canvasHeight;

      // draw the on screen canvas onto the temp canvas
      tempContext.drawImage(OScanvasElement[0], canvasX, canvasY, canvasWidth, canvasHeight, 0, 0, canvasWidth, canvasHeight);

      return tempCanvas.toDataURL('image/png');
    }

    /**
     * Populate and display popover to download pattern.
     */
    function downloadImage(clickEventObj) {
      var data = getCanvasImageData();

      // bring up a cover to hold our new image
      $patternDownloadOverlay.find('img.pattern').attr('src', data);

      var docHeight = $(document).height(); //grab the height of the page
      var scrollTop = $(window).scrollTop(); //grab the px value from the top of the page to where you're scrolling
      $patternDownloadOverlay.css({'height' : docHeight}); //display your popup and set height to the page height
      $('.full-width', $patternDownloadOverlay).css({'top': (scrollTop + 20) + 'px'}); //set the content 20px from the window top
      $patternDownloadOverlay.show();
    }

    /**
     * Populate and display popover to share pattern.
     */
    function shareImage(clickEventObj) {
      var docHeight = $(document).height(), //grab the height of the page
          scrollTop = $(window).scrollTop(); //grab the px value from the top of the page to where you're scrolling

      $patternShareOverlay.css({'height' : docHeight}); //display your popup and set height to the page height
      $('.full-width', $patternShareOverlay).css({'top': (scrollTop + 20) + 'px'}); //set the content 20px from the window top
      $patternShareOverlay.show();
    }

    function closeSharing(clickEventObj) {
      clickEventObj.preventDefault();

      // Fade out, and clear messages and inputs
      $patternShareOverlay.fadeOut(400, function() {
        $('.messages', $patternShareOverlay).remove();
        $('input[type="text"], textarea', $patternShareOverlay).val('');
        $('textarea#edit-message', $patternShareOverlay).val(messageText);
      });
    }


    // Attach events
    $patternDownloadOverlay.click(function(clickEventObj) {
      clickEventObj.preventDefault();
      $(this).hide();
    });

    $patternShareOverlay.click(function(clickEventObj) {
      if ($(clickEventObj.target).is('.full-width, .pattern-overlay, .close')) {
        closeSharing(clickEventObj);
      }
    });

    $('a', $patternDownloadOverlay).click(function(clickEventObj) {
      clickEventObj.preventDefault();
    });

    $('.pattern-generator-wrapper #download').click(function(clickEventObj) {
      clickEventObj.preventDefault();

      if (typeof _gaq !== 'undefined') {
        _gaq.push(['_trackEvent', 'Pattern Generator', 'Download']);
      }

      // show the image as a popup to download
      downloadImage(clickEventObj);
    });

    $('.pattern-generator-wrapper #email').click(function(clickEventObj) {
      clickEventObj.preventDefault();

      if (typeof _gaq !== 'undefined') {
        _gaq.push(['_trackEvent', 'Pattern Generator', 'Email']);
      }

      $('#qma-forms-pattern-mail-form-wrapper input[name="image_data"]').val(getCanvasImageData());
      shareImage(clickEventObj);
    });

    if ($('html').hasClass('no-touch')) {
      $('.pattern-generator-wrapper #pattern-sharing').hover(function(e) {
        e.preventDefault();
        $('#pattern-sharing .inner').show();
        $('#pattern-sharing #share').addClass('hover');
      }, function(e) {
        e.preventDefault();
        $('#pattern-sharing .inner').hide();
        $('#pattern-sharing #share').removeClass('hover');
      });

      $('.pattern-generator-wrapper #pattern-sharing').click(function(e) {
        e.preventDefault();
      });
    }
    else {
      $('.pattern-generator-wrapper #pattern-sharing #share').click(function(e) {
        e.preventDefault();
        $('#pattern-sharing .inner').toggle();
        $('#pattern-sharing #share').toggleClass('hover');
      });
    }


    // Force canvas to resize on window resize.
    $(window).resize(function() {
      window.processingInstance = window.processingInstance || Processing.getInstanceById('__processing0');
      window.processingInstance.calculateScreenSize();
    });

  });

})(Drupal, jQuery);
