<?php

/**
 * @file
 * Drupagram views field handlers.
 */

/**
 * Process Instagram-style @usernames and URLs before filtering XSS.
 */
class drupagram_views_handler_field_xss extends views_handler_field {

  function option_definition() {
    $conf = InstagramConf::instance();
    $options = parent::option_definition();
    $options['link_urls'] = array('default' => TRUE);
    $options['link_usernames'] = array('default' => TRUE);
    $options['link_hashtags'] = array('default' => FALSE);
    $options['hashtags_url'] = array('default' => 'http://' . $conf->get('search') . '/search?q=%23');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link_urls'] = array(
      '#title' => t('Link urls to their destinations'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_urls']),
    );
    $form['link_usernames'] = array(
      '#title' => t('Link Instagram @usernames to their Instagram.com urls'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_usernames']),
    );
    $form['link_hashtags'] = array(
      '#title' => t('Link Instagram #hashtags to another url'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_hashtags']),
    );
    $form['hashtags_url'] = array(
      '#type' => 'textfield',
      '#default_value' => $this->options['hashtags_url'],
      '#process' => array('ctools_dependent_process'),
      '#dependency' => array('edit-options-link-hashtags' => array(TRUE)),
    );
  }

  function render($values) {
    $value = $values->{$this->field_alias};
    if (!empty($this->options['link_urls'])) {
      $filter = new stdClass;
      $filter->settings = array(
        'filter_url_length' => 496,
      );
      $value = _filter_url($value, $filter);
    }
    if (!empty($this->options['link_usernames'])) {
      $conf = InstagramConf::instance();
      $value = _drupagram_filter_text($value, '@', 'http://' . $conf->get('host') . '/');
    }
    if (!empty($this->options['link_hashtags']) && valid_url($this->options['hashtags_url'])) {
      $value = _drupagram_filter_text($value, '#', url($this->options['hashtags_url']));
    }
    return filter_xss($value);
  }

}

/**
 * Field handler to re der the image as an image.
 */
class drupagram_views_handler_field_profile_image extends views_handler_field {

  function render($values) {
    $value = $values->{$this->field_alias};
    return theme('image', array('path' => $value));
  }

}

/**
 * Field handler to provide simple renderer that turns a URL into a clickable link.
 */
class drupagram_views_handler_field_caption extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();
    $options['format'] = array('default' => 'unserialized');
    $options['key'] = array('default' => 'text');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['format'] = array(
      '#type' => 'select',
      '#title' => t('Display format'),
      '#description' => t('How should the serialized data be displayed. You can choose a custom array/object key or a print_r on the full output.'),
      '#options' => array(
        'unserialized' => t('Full data'),
        'key' => t('A certain key'),
      ),
      '#default_value' => $this->options['format'],
    );
    $form['key'] = array(
      '#type' => 'select',
      '#title' => t('Which key should be displayed'),
      '#options' => array(
        'text' => t('Caption text'),
        'created_time' => t('Created time'),
        'from' => t('Caption author information'),
        'id' => t('ID'),
      ),
      '#default_value' => $this->options['key'],
      '#dependency' => array('edit-options-format' => array('key')),
    );
  }

  function options_validate(&$form, &$form_state) {
    // Require a key if the format is key.
    if ($form_state['values']['options']['format'] == 'key' && $form_state['values']['options']['key'] == '') {
      form_error($form['key'], t('You have to enter a key if you want to display a key of the data.'));
    }
  }

  function render($values) {
    $value = $this->get_value($values);
    $caption = unserialize($value);

    if ($this->options['format'] == 'unserialized') {
      return theme('drupagram_caption', $caption);
    }
    elseif ($this->options['format'] == 'key' && !empty($this->options['key'])) {
      switch ($this->options['key']) {
        case 'created_time':
          return format_date($caption['created_time']);
          break;
        case 'from':
          return theme('drupagram_account', $caption['from']);
          break;
        default:
          return $this->sanitize_value($caption[$this->options['key']]);
          break;
      }
    }
  }

}

/**
 * Field handler to show data of serialized fields.
 *
 * @ingroup views_field_handlers
 */
class drupagram_views_handler_field_likes extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();
    $options['format'] = array('default' => 'unserialized');
    $options['key'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['format'] = array(
      '#type' => 'select',
      '#title' => t('Display format'),
      '#description' => t('How should the serialized data be displayed. You can choose a custom array/object key or a print_r on the full output.'),
      '#options' => array(
        'unserialized' => t('Full data'),
        'key' => t('A certain key'),
      ),
      '#default_value' => $this->options['format'],
    );
    $form['key'] = array(
      '#type' => 'select',
      '#title' => t('Which key should be displayed'),
      '#options' => array(
        'count' => t('Likes count'),
        'data' => t('Likes detail'),
      ),
      '#default_value' => $this->options['key'],
      '#dependency' => array('edit-options-format' => array('key')),
    );
  }

  function options_validate(&$form, &$form_state) {
    // Require a key if the format is key.
    if ($form_state['values']['options']['format'] == 'key' && $form_state['values']['options']['key'] == '') {
      form_error($form['key'], t('You have to enter a key if you want to display a key of the data.'));
    }
  }

  function render($values) {
    $value = $values->{$this->field_alias};

    if ($this->options['format'] == 'unserialized') {
      $value = (array) unserialize($value);
      return theme('drupagram_likes', $value);
    }
    elseif ($this->options['format'] == 'key' && !empty($this->options['key'])) {
      $value = (array) unserialize($value);
      if ($this->options['key'] == 'count') {
        return check_plain($value[$this->options['key']]);
      }
      elseif ($this->options['key'] == 'data') {
        return theme('drupagram_likes_data', array('data' => $value[$this->options['key']]));
      }
    }

    return $value;
  }

}

/**
 * Field handler to provide simple renderer that turns a URL into a clickable link.
 */
class drupagram_views_handler_field_images extends views_handler_field {

  function option_definition() {
    $conf = InstagramConf::instance();
    $options = parent::option_definition();
    $options['source'] = array('default' => 'thumbnail');
    $options['secure'] = array('default' => FALSE);
    $options['link_to_post'] = array('default' => FALSE);

    if (module_exists('image')) {
      $options['image_style'] = array('default' => '');
    }

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['source'] = array(
      '#title' => t('Image Source'),
      '#type' => 'select',
      '#options' => array(
        'thumbnail' => t('Instagram: Thumbnail'),
        'standard_resolution' => t('Instagram: Standard resolution'),
        'low_resolution' => t('Instagram: Low resolution'),
        'local' => t('Local cache'),
      ),
      '#default_value' => $this->options['source'],
    );
    $form['secure'] = array(
      '#title' => t('Secure request'),
      '#description' => t('If checked, remote source images will be requested via https://'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['secure']),
      '#dependency' => array('edit-options-source' => array('thumbnail', 'standard_resolution', 'low_resolution')),
    );
    if (module_exists('image')) {
      $styles = image_styles();
      $style_options = array('' => t('Default'));
      foreach ($styles as $style) {
        $style_options[$style['name']] = $style['name'];
      }

      $form['image_style'] = array(
        '#title' => t('Image style'),
        '#description' => t('Using <em>Default</em> will use the site-wide image style for user pictures set in the <a href="!account-settings">Account settings</a>.', array('!account-settings' => url('admin/config/people/accounts', array('fragment' => 'edit-personalization')))),
        '#type' => 'select',
        '#options' => $style_options,
        '#default_value' => $this->options['image_style'],
        '#dependency' => array('edit-options-source' => array('local')),
      );
    }
    $form['link_to_post'] = array(
      '#title' => t('Link to post'),
      '#description' => t('If the link field is available, the image field will link to the Instagram post'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_post']),
    );
  }

  function render($values) {
    $value = $values->{$this->field_alias};
    $images = unserialize($value);
    if (!empty($this->options['source'])) {
      $source = $this->options['source'];
    }

    if ($this->options['source'] == 'local') {
      if ($remote = $this->get_value($values)) {
        $images = unserialize($remote);
        $picture = drupagram_local_image($images['standard_resolution']['url']);
        $picture_filepath = $picture->uri;
        if (file_valid_uri($picture_filepath)) {
          if (module_exists('image') && !empty($this->options['image_style'])) {
            $image = theme('image_style', array('style_name' => $this->options['image_style'], 'path' => $picture_filepath));
          }
          else {
            $image = theme('image', array('path' => $picture_filepath));
          }
        }
      }
    }
    else {
      $path = $images[$source]['url'];
      if ($this->options['secure']) {
        $path = str_replace('http://', 'https://', $path);
      }
      $image = theme('image', array('path' => $path));
    }

    if ($this->options['link_to_post'] && isset($values->drupagram_link) && !empty($values->drupagram_link)) {
      return l($image, $values->drupagram_link, array('html' => TRUE, 'attributes' => array('target' => '_blank', 'rel' => 'nofollow')));
    }

    return $image;
  }
}
