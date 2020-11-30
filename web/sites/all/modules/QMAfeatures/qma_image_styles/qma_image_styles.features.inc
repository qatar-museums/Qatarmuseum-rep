<?php
/**
 * @file
 * qma_image_styles.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function qma_image_styles_image_default_styles() {
  $styles = array();

  // Exported image style: 100x100_scale_crop.
  $styles['100x100_scale_crop'] = array(
    'name' => '100x100_scale_crop',
    'label' => '100x100_scale_crop',
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
          'width' => 100,
          'height' => 100,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: content_image.
  $styles['content_image'] = array(
    'name' => 'content_image',
    'label' => 'Content Image (662px wide)',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 662,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: exhibition_teaser.
  $styles['exhibition_teaser'] = array(
    'name' => 'exhibition_teaser',
    'label' => 'Exhibition teaser',
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
          'width' => 525,
          'height' => 353,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: experience_hub_large.
  $styles['experience_hub_large'] = array(
    'name' => 'experience_hub_large',
    'label' => 'Experience hub large (400 x 400)',
    'effects' => array(
      14 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: experience_hub_medium.
  $styles['experience_hub_medium'] = array(
    'name' => 'experience_hub_medium',
    'label' => 'Experience hub medium (300 x 300)',
    'effects' => array(
      15 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: experience_hub_small.
  $styles['experience_hub_small'] = array(
    'name' => 'experience_hub_small',
    'label' => 'Experience hub small (200 x 200)',
    'effects' => array(
      16 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_large.
  $styles['gallery_large'] = array(
    'name' => 'gallery_large',
    'label' => 'Gallery Large (600px height)',
    'effects' => array(
      4 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 600,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_medium.
  $styles['gallery_medium'] = array(
    'name' => 'gallery_medium',
    'label' => 'Gallery Medium (400px height)',
    'effects' => array(
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 400,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: gallery_small.
  $styles['gallery_small'] = array(
    'name' => 'gallery_small',
    'label' => 'Gallery Small (640px width - retina)',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 640,
          'height' => 528,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: generic_hub_teaser_small.
  $styles['generic_hub_teaser_small'] = array(
    'name' => 'generic_hub_teaser_small',
    'label' => 'generic_hub_teaser_small (254 x 258)',
    'effects' => array(
      13 => array(
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
          'height' => 258,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_image.
  $styles['hero_image'] = array(
    'name' => 'hero_image',
    'label' => 'Hero image (1174px x 544px)',
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
          'width' => 1174,
          'height' => 544,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_image_mobile.
  $styles['hero_image_mobile'] = array(
    'name' => 'hero_image_mobile',
    'label' => 'Hero image mobile (568px wide)',
    'effects' => array(
      8 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 568,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hero_image_shallow.
  $styles['hero_image_shallow'] = array(
    'name' => 'hero_image_shallow',
    'label' => 'Hero Image Shallow (1174 x 375)',
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
          'width' => 1174,
          'height' => 374,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: homepage_square.
  $styles['homepage_square'] = array(
    'name' => 'homepage_square',
    'label' => 'Homepage square (392 x 392)',
    'effects' => array(
      17 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 392,
          'height' => 392,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: latest_interview.
  $styles['latest_interview'] = array(
    'name' => 'latest_interview',
    'label' => 'Latest Interview (455 x 455)',
    'effects' => array(
      11 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 455,
          'height' => 455,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: pattern_image_gallery.
  $styles['pattern_image_gallery'] = array(
    'name' => 'pattern_image_gallery',
    'label' => 'Pattern image gallery (235 x 235)',
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
          'width' => 235,
          'height' => 235,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: pattern_image_gallery_large.
  $styles['pattern_image_gallery_large'] = array(
    'name' => 'pattern_image_gallery_large',
    'label' => 'Pattern image gallery large (650 x 650)',
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
          'width' => 650,
          'height' => 650,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: promo_image.
  $styles['promo_image'] = array(
    'name' => 'promo_image',
    'label' => 'Promo image (322px x 322px)',
    'effects' => array(
      12 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 322,
          'height' => 322,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: repeating_body_image.
  $styles['repeating_body_image'] = array(
    'name' => 'repeating_body_image',
    'label' => 'Repeating Body Image (526px wide)',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 526,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: triangle_100x100.
  $styles['triangle_100x100'] = array(
    'name' => 'triangle_100x100',
    'label' => 'triangle_100x100',
    'effects' => array(
      5 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 498,
        ),
        'weight' => 1,
      ),
      6 => array(
        'label' => 'Image mask',
        'help' => ' Choose the file image you wish to use as a mask, and apply it to the canvas.',
        'effect callback' => 'canvasactions_imagemask_effect',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_imagemask_form',
        'summary theme' => 'canvasactions_imagemask_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_imagemask',
        'data' => array(
          'path' => 'sites/all/themes/corolla/qma-images/compositing/triangle-mask500.gif',
        ),
        'weight' => 2,
      ),
      7 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_effect',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 0,
          'ypos' => 0,
          'alpha' => 100,
          'path' => 'sites/all/themes/corolla/qma-images/compositing/triangle-border.png',
        ),
        'weight' => 3,
      ),
      8 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 100,
          'height' => 100,
          'upscale' => 0,
        ),
        'weight' => 4,
      ),
    ),
  );

  // Exported image style: triangle_200x200.
  $styles['triangle_200x200'] = array(
    'name' => 'triangle_200x200',
    'label' => 'triangle_200x200',
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
          'width' => 500,
          'height' => 498,
        ),
        'weight' => 1,
      ),
      3 => array(
        'label' => 'Image mask',
        'help' => ' Choose the file image you wish to use as a mask, and apply it to the canvas.',
        'effect callback' => 'canvasactions_imagemask_effect',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_imagemask_form',
        'summary theme' => 'canvasactions_imagemask_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_imagemask',
        'data' => array(
          'path' => 'sites/all/themes/corolla/qma-images/compositing/triangle-mask500.gif',
        ),
        'weight' => 2,
      ),
      4 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_effect',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 0,
          'ypos' => 0,
          'alpha' => 100,
          'path' => 'sites/all/themes/corolla/qma-images/compositing/triangle-border.png',
        ),
        'weight' => 3,
      ),
      10 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 200,
          'height' => 198,
        ),
        'weight' => 4,
      ),
    ),
  );

  // Exported image style: triangle_500x500.
  $styles['triangle_500x500'] = array(
    'name' => 'triangle_500x500',
    'label' => 'triangle_500x500',
    'effects' => array(
      11 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 498,
        ),
        'weight' => 1,
      ),
      12 => array(
        'label' => 'Image mask',
        'help' => ' Choose the file image you wish to use as a mask, and apply it to the canvas.',
        'effect callback' => 'canvasactions_imagemask_effect',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_imagemask_form',
        'summary theme' => 'canvasactions_imagemask_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_imagemask',
        'data' => array(
          'path' => 'sites/all/themes/corolla/qma-images/compositing/triangle-mask500.gif',
        ),
        'weight' => 2,
      ),
      13 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_effect',
        'dimensions passthrough' => TRUE,
        'form callback' => 'canvasactions_file2canvas_form',
        'summary theme' => 'canvasactions_file2canvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 0,
          'ypos' => 0,
          'alpha' => 100,
          'path' => 'sites/all/themes/corolla/qma-images/compositing/triangle-border.png',
        ),
        'weight' => 3,
      ),
      14 => array(
        'label' => 'Define canvas',
        'help' => 'Define the size of the working canvas and background color, this controls the dimensions of the output image.',
        'effect callback' => 'canvasactions_definecanvas_effect',
        'dimensions callback' => 'canvasactions_definecanvas_dimensions',
        'form callback' => 'canvasactions_definecanvas_form',
        'summary theme' => 'canvasactions_definecanvas_summary',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => '',
          ),
          'under' => 1,
          'exact' => array(
            'width' => '',
            'height' => '',
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 4,
      ),
    ),
  );

  return $styles;
}
