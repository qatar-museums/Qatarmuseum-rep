/**
 * Initiate the homepage slideshow.
 *
 * @type {{attach: attach}}
 */
(function ($) {
  Drupal.behaviors.QMAHomeSlider = {
    attach: function(context, settings) {
      $('.homepage-slideshow__wrapper').slick({
        rtl: ($('html').prop('dir') === 'rtl'),
        swipe: $('html').hasClass('touch'),
        arrows: false
      });

      $('.homepage-slideshow__next').on('click', function(e) {
        e.preventDefault();
        $('.homepage-slideshow__wrapper').slick('slickNext');
      });

      $('.homepage-slideshow__prev').on('click', function(e) {
        e.preventDefault();
        $('.homepage-slideshow__wrapper').slick('slickPrev');
      });
    }
  };
})(jq191);
