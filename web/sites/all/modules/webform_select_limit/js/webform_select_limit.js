/**
 * @file
 * Disables select options and radio buttons if they can no longer be selected.
 */

(function ($, Drupal) {
  'use strict';
  Drupal.webformSelectLimit = Drupal.webformSelectLimit || {};

  // Passed an object with an array of values, the function will disable the select options.
  Drupal.webformSelectLimit.disableSelectOptions = function (elements) {
    $.each(elements, function (field, options) {
      $.each(options, function (key, option) {
        $('[name*="' + field + '"]')
          .find('option[value="' + option + '"]')
          .attr('disabled', 'disabled');
      });
    });
  };

  // Passed an object with an array of values, the function will disable the radio buttons.
  Drupal.webformSelectLimit.disableRadioButtons = function (elements) {
    $.each(elements, function (field, options) {
      $.each(options, function (key, option) {
        $('input[name*="' + field + '"][value="' + option + '"]')
          .attr('disabled', 'true');
      });
    });
  };

  // Passed an object with an array of values, the function will disable the radio buttons.
  Drupal.webformSelectLimit.disableCheckboxes = function (elements) {
    $.each(elements, function (field, options) {
      $.each(options, function (key, option) {
        $('input[name*="' + field + '"][value="' + option + '"]')
          .attr('disabled', 'true');
      });
    });
  };

  Drupal.behaviors.webformSelectLimit = {
    attach: function (context, settings) {
      var selects = settings.webformSelectLimit.select;
      var radios = settings.webformSelectLimit.radios;
      var checkboxes = settings.webformSelectLimit.checkboxes;
      if (typeof selects !== 'undefined') {
        Drupal.webformSelectLimit.disableSelectOptions(selects);
      }
      if (typeof radios !== 'undefined') {
        Drupal.webformSelectLimit.disableRadioButtons(radios);
      }
      if (typeof  checkboxes !== 'undefined') {
        Drupal.webformSelectLimit.disableCheckboxes(checkboxes);
      }
    }
  };
})(jQuery, Drupal);
