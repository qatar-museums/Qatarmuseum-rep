<?php
/**
 * @file
 * qma_site_config.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function qma_site_config_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = array(
    'instance' => 'global',
    'config' => array(
      'title' => array(
        'value' => '[current-page:title] | [site:name]',
      ),
      'description' => array(
        'value' => '',
      ),
      'abstract' => array(
        'value' => '',
      ),
      'keywords' => array(
        'value' => '',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
          'noimageindex' => 0,
          'notranslate' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
      ),
      'standout' => array(
        'value' => '',
      ),
      'generator' => array(
        'value' => '',
      ),
      'copyright' => array(
        'value' => '',
      ),
      'image_src' => array(
        'value' => '',
      ),
      'canonical' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
      ),
      'publisher' => array(
        'value' => '',
      ),
      'author' => array(
        'value' => '',
      ),
      'original-source' => array(
        'value' => '',
      ),
      'revisit-after' => array(
        'value' => '',
        'period' => '',
      ),
      'fb:admins' => array(
        'value' => '',
      ),
      'fb:app_id' => array(
        'value' => '',
      ),
      'og:site_name' => array(
        'value' => '[site:name]',
      ),
      'og:title' => array(
        'value' => '[current-page:title]',
      ),
      'og:description' => array(
        'value' => '',
      ),
      'og:type' => array(
        'value' => 'article',
      ),
      'og:image' => array(
        'value' => '',
      ),
      'og:image:secure_url' => array(
        'value' => '',
      ),
      'og:url' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'og:latitude' => array(
        'value' => '',
      ),
      'og:longitude' => array(
        'value' => '',
      ),
      'og:street-address' => array(
        'value' => '',
      ),
      'og:locality' => array(
        'value' => '',
      ),
      'og:region' => array(
        'value' => '',
      ),
      'og:postal-code' => array(
        'value' => '',
      ),
      'og:country-name' => array(
        'value' => '',
      ),
      'og:email' => array(
        'value' => '',
      ),
      'og:phone_number' => array(
        'value' => '',
      ),
      'og:fax_number' => array(
        'value' => '',
      ),
      'og:locale' => array(
        'value' => '',
      ),
      'og:video' => array(
        'value' => '',
      ),
      'og:video:secure_url' => array(
        'value' => '',
      ),
      'og:video:width' => array(
        'value' => '',
      ),
      'og:video:height' => array(
        'value' => '',
      ),
      'og:video:type' => array(
        'value' => '',
      ),
      'twitter:card' => array(
        'value' => 'summary',
      ),
      'twitter:site' => array(
        'value' => '',
      ),
      'twitter:site:id' => array(
        'value' => '',
      ),
      'twitter:creator' => array(
        'value' => '',
      ),
      'twitter:creator:id' => array(
        'value' => '',
      ),
      'twitter:url' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'twitter:title' => array(
        'value' => '[site:name]',
      ),
      'twitter:description' => array(
        'value' => '[site:slogan]',
      ),
      'twitter:image' => array(
        'value' => '',
      ),
      'twitter:image:width' => array(
        'value' => '',
      ),
      'twitter:image:height' => array(
        'value' => '',
      ),
      'twitter:image0' => array(
        'value' => '',
      ),
      'twitter:image1' => array(
        'value' => '',
      ),
      'twitter:image2' => array(
        'value' => '',
      ),
      'twitter:image3' => array(
        'value' => '',
      ),
      'twitter:player' => array(
        'value' => '',
      ),
      'twitter:player:width' => array(
        'value' => '',
      ),
      'twitter:player:height' => array(
        'value' => '',
      ),
      'twitter:player:stream' => array(
        'value' => '',
      ),
      'twitter:player:stream:content_type' => array(
        'value' => '',
      ),
      'twitter:app:id:iphone' => array(
        'value' => '',
      ),
      'twitter:app:id:ipad' => array(
        'value' => '',
      ),
      'twitter:app:id:googleplay' => array(
        'value' => '',
      ),
      'twitter:app:url:iphone' => array(
        'value' => '',
      ),
      'twitter:app:url:ipad' => array(
        'value' => '',
      ),
      'twitter:app:country' => array(
        'value' => '',
      ),
      'twitter:app:url:googleplay' => array(
        'value' => '',
      ),
      'twitter:label1' => array(
        'value' => '',
      ),
      'twitter:data1' => array(
        'value' => '',
      ),
      'twitter:label2' => array(
        'value' => '',
      ),
      'twitter:data2' => array(
        'value' => '',
      ),
    ),
  );

  // Exported Metatag config instance: global:403.
  $config['global:403'] = array(
    'instance' => 'global:403',
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
      'twitter:description' => array(
        'value' => '',
      ),
      'twitter:title' => array(
        'value' => '[site:name]',
      ),
      'twitter:url' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: global:404.
  $config['global:404'] = array(
    'instance' => 'global:404',
    'config' => array(
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
      'twitter:description' => array(
        'value' => '',
      ),
      'twitter:title' => array(
        'value' => '[site:name]',
      ),
      'twitter:url' => array(
        'value' => '[site:url]',
      ),
    ),
  );

  // Exported Metatag config instance: global:frontpage.
  $config['global:frontpage'] = array(
    'instance' => 'global:frontpage',
    'disabled' => TRUE,
    'config' => array(
      'title' => array(
        'value' => '[site:name]',
      ),
      'canonical' => array(
        'value' => '[site:url]',
      ),
      'shortlink' => array(
        'value' => '[site:url]',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:title' => array(
        'value' => '[site:name]',
      ),
      'og:url' => array(
        'value' => '[site:url]',
      ),
      'twitter:description' => array(
        'value' => '',
      ),
    ),
  );

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:field_teaser_text]',
      ),
      'og:title' => array(
        'value' => '[node:title]',
      ),
      'og:description' => array(
        'value' => '[node:field_teaser_text]',
      ),
      'og:image' => array(
        'value' => '[node:field_teaser_image]',
      ),
      'twitter:card' => array(
        'value' => 'photo',
      ),
      'twitter:title' => array(
        'value' => '[node:title]',
      ),
      'twitter:description' => array(
        'value' => '[node:field_teaser_text]',
      ),
      'twitter:image' => array(
        'value' => '[node:field_teaser_image]',
      ),
    ),
  );

  return $config;
}
