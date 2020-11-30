INTRODUCTION
------------

The Webform Select Limit module provides a webform validator to
prevent submissions of webforms where the option in the select list has
already been submitted a set number of times.

An example of this being used could be a booking form where a maximum of
two people can select a certain time slot.

An additional configuration option allows for the ability to disable options
which are not available any longer.

This validator is used for webform select components.


REQUIREMENTS
------------

This module requires the following modules:

 * Webform Validation (https://drupal.org/project/webform_validation)


INSTALLATION
------------

 * Install as you would normally install a contributed Drupal module. See:
   https://drupal.org/documentation/install/modules-themes/modules-7
   for further information.


CONFIGURATION
-------------

 * Create a Webform, add select components and configure. Found within this
   form is a fieldset, select option limitation, which provides the following
   options:

   - Enable select option limitation

     This option allows the component to use the validator. The component must
     still be added to the validator added in the next step.

   - Select option limitation number (required if enabled)

     This is where you set the number of times the individual options can be
     submitted. Alternatively you can provide a catch all setting to set a single
     limit across all form values.

   - Select option limitation error message (optional)

     Provides the ability to enter a component specific error message. If this
     is not set then a default message will be displayed.

   - Disable unavailable options in select list (optional)

     Will disable the unavailable options using javascript, preventing the user
     from selecting it.

 * Select the form validation menu link and add the "Maximum number of select
   option submissions" validator. Select the webform components to validate
   and save. Validation will only happen if the component has the "enable select
   option limitation" option set.

 * Submit the Webform and see the magic happen.
