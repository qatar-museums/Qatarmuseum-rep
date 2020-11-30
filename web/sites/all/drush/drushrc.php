<?php

/**
 * @file
 *
 * Drush settings specific for QMA.
 */

// Override the site default language if running as Drush so all output is in 
// English.
$options['variables']['language_default']->language = 'en';
