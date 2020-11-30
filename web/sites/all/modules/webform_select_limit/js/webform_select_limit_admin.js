(function ($, Drupal) {
  Drupal.webformSelectAdmin = Drupal.webformSelectAdmin || {};

  /**
   * Simply populates the limit textarea with the options specified in the webform
   * options textarea. Each option is added on a new line with a pipe. This removes
   * the need for the user to manually add the option.
   *
   * @param textarea
   *  The limit textarea to populate.
   * @param options
   *  The webform options already added.
   */
  Drupal.webformSelectAdmin.populateEmptyLimits = function(textarea, options) {
    var values = Drupal.webformSelectAdmin.getOptions(options),
      string = '';

    for (var i = 0; i < values.length; i++) {
      if (i != values.length - 1) {
        string = string + values[i] + "|\n";
      }
      else {
        string = string + values[i] + "|";
      }
    }

    textarea.val(string);
  };

  /**
   * Populates the limit textarea with newly added webform options.
   *
   * @param textarea
   *  The limit textarea to populate.
   * @param limitOptions
   *  The limit options already added.
   * @param webformOptions
   *  The webform select options already added.
   */
  Drupal.webformSelectAdmin.updateNewLimits = function(textarea, limitOptions, webformOptions) {
    var newOptions = Drupal.webformSelectAdmin.filterOptions(limitOptions, webformOptions),
      string = textarea.val();

    if (newOptions.length > 0) {
      // Add a new line first.
      string = string + "\n";

      // Now add each option.
      for (var i = 0; i < newOptions.length; i++) {
        if (i != newOptions.length - 1) {
          string = string + newOptions[i] + "|\n";
        }
        else {
          string = string + newOptions[i] + "|";
        }
      }
    }

    textarea.val(string);
  };

  /**
   * Compares the webform options with the limit options and returns anything new.
   *
   * @param limitOptions
   *  The limit options already added.
   * @param webformOptions
   *  The webform select options already added.
   *
   * @returns {Array.<T>}
   *  The new webform options which aren't yet in the limit textarea.
   */
  Drupal.webformSelectAdmin.filterOptions = function(limitOptions, webformOptions) {
    var limitOptionKeys = Drupal.webformSelectAdmin.getOptions(limitOptions),
      webformOptionKeys = Drupal.webformSelectAdmin.getOptions(webformOptions);

    // Go through all webform options and check if a corresponding limit is set.
    return webformOptionKeys.filter(function(obj) { return limitOptionKeys.indexOf(obj) == -1; });
  };

  /**
   * Generates an array of option keys from a generated list of options. These
   * could be from the webform select options or limit options already added. Both
   * use the same keys, or at least should.
   *
   * @param options
   *  An array of strings in the form "safe_key|Some readable option".
   *
   * @returns {Array}
   *  An array containing only the "safe_key" aspect of the string.
   */
  Drupal.webformSelectAdmin.getOptions = function(options) {
    var options_array = [];
    $.each(options, function(key, option) {
      var option_split = option.split('|');

      // Only add it if there is actually a string.
      if (option_split[0].length) {
        options_array.push(option_split[0]);
      }
    });

    return options_array;
  };

  Drupal.behaviors.webformSelectAdmin = {
    attach: function (context) {
      $('.webform-select-limit-copy-options', context).click(function (e) {
        // Prevent the button from submitting the form.
        e.preventDefault();

        var $options_textarea = $('.form-item-extra-items textarea[name="extra[items]"]', context),
          $limit_textarea = $('.form-item-extra-webform-select-limit-webform-select-limit-value textarea[name="extra[webform_select_limit][webform_select_limit_value]"]', context);

        // Get an array of select options already added to the form.
        var $webform_options = $options_textarea
          .val()
          .split("\n");

        // Get an array of select option limits if any have been added.
        var $limit_options = $limit_textarea
          .val()
          .split("\n");

        // No limit options have been added to the form yet so just populate the textarea.
        if ($webform_options.length > 0 && $limit_options < 1) {
          Drupal.webformSelectAdmin.populateEmptyLimits($limit_textarea, $webform_options);
        }
        else {
          Drupal.webformSelectAdmin.updateNewLimits($limit_textarea, $limit_options, $webform_options);
        }
      });
    }
  };
})(jQuery, Drupal);