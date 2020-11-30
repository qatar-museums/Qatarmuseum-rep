(function($){
  /**
   * Disable form input elements when AJAX form is being submitted for press view.
   * We don't need to re-enable them since the whole view is replaced when it's
   * AJAX-ed in.
   *
   * Based on the implementation of auto-submit in ctools/js/auto-submit.js
   */
  Drupal.behaviors.QMAPressView = {
    attach: function(context) {
      var $form = $('form#views-exposed-form-press-block.ctools-auto-submit-full-form', context);

      if (!$form.hasClass('qma-processed')) {
        $form
          .addClass('qma-processed')
          .find('.ctools-auto-submit-click').click(function(e) {
            $form.find('input').each(function(idx, el) {
              $(el)
                .attr('disabled', 'disabled')
                .css('opacity', 0.5)
                .parent().addClass('qma-ajax-loading');
            });
          });
      }
    }
  },

  /**
   * Focus events do not bubble and there is no pure CSS way to ensure that the submenu links
   * remain open when a submenu item receives keyboard focus.
   *
   * When a submenu link receives focus a CSS class is added to the top parent ensuring that the
   * menu remains visible.
   */
  Drupal.behaviors.MenuLinkFocus = {
    attach: function(context) {
      $('.site-nav ul.menu li ul.menu li a', context).bind('focus', function(e) {
        var parentMenuItem = $(e.target).parents('.menu').parents('.menu li');
        $(parentMenuItem).addClass('open-focus');
      });
      $('.site-nav ul.menu li ul.menu li a', context).bind('blur', function(e) {
        var parentMenuItem = $(e.target).parents('.menu').parents('.menu li');
        $(parentMenuItem).removeClass('open-focus');
      });
    },
    detach : function(context) {
      $('.site-nav ul.menu li ul.menu li a', context).unbind('focus blur');
    }
  }

})(jQuery);