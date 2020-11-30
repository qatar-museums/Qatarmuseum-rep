<?php
/**
 * @file
 * qma_instagram.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function qma_instagram_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function qma_instagram_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function qma_instagram_image_default_styles() {
  $styles = array();

  // Exported image style: instagram_image_square.
  $styles['instagram_image_square'] = array(
    'name' => 'instagram_image_square',
    'label' => 'instagram_image_square',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 254,
          'height' => 254,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: instagram_square_large.
  $styles['instagram_square_large'] = array(
    'name' => 'instagram_square_large',
    'label' => 'Instagram Square Large (390px)',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 390,
          'height' => 390,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
