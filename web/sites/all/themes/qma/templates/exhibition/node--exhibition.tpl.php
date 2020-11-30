<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: whether submission information should be displayed.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="container">
  

  
    <div class="generic-center-column">
      <?php print $exhibition_hub_link;?>
      <div class="exhibition-title-container">
        <h1><?php print render($title) ?></h1>
      </div>

      <!-- Exhibition details -->
      <div class="exhibition-details">

        <div class="exhibition-details__date">
          <h4><?php print render($content['field_display_date_override'][0]['#markup']); ?></h4>
        </div>

        <div class="exhibition-details__venue">
          <span class="exhibition-label"><?php print t('Location: '); ?></span>
          <span><?php print render($content['field_exhibition_location']); ?></span>
        </div>

        <?php if($content['field_ticket_option']): ?>
        <div class="exhibition-details__ticket">
          <span class="exhibition-label"><?php print t('Cost: ');?></span>
          <span><?php print render($content['field_ticket_option']); ?></span>
        </div>

        <?php endif; ?>
      </div>
      <!-- /Exhibition details -->

      <?php if (isset($content['field_description'])): ?>
        <div class="exhibition-description">
          <?php print render($content['field_description']); ?>
        </div>
      <?php endif; ?>

      <div class="content container no-padding-bottom exhibition-container exhibition-hero">
        <?php print render($content['field_hero_image']); ?>
      </div>

    </div>
  </div>

  <?php if (isset($content['field_artist_name']) && isset($content['field_artist_text'])): ?>
    <div class="container content no-padding-bottom exhibition-container">
      <div class="wide-promo wide-promo--exhib">

        <div class="content">
        <?php if (isset($content['field_artist_image'])): ?>
          <div class="exhibition-image filter_image">
            <?php print render($content['field_artist_image']); ?>
          </div>
        <?php endif; ?>
        </div>

        <div class="exhibition-text title-container">
          <h3><?php print render($content['field_artist_name']); ?></h3>
          <?php print render($content['field_artist_text']); ?>
          <?php print render($content['field_artist_link']); ?>
        </div>
      </div>

    </div>
  <?php endif; ?>


  <?php if (isset($content['field_venue_name']) AND isset($content['field_venue_text'])): ?>
    <div class="container content no-padding-bottom exhibition-container">
      <div class="wide-promo wide-promo--exhib">

        <div class="content">
        <?php if (isset($content['field_venue_image'])): ?>
          <div class="exhibition-image filter_image">
            <?php print render($content['field_venue_image']); ?>
          </div>
        <?php endif; ?>
         
        </div>

        <div class="exhibition-text title-container">
          <h3><?php print render($content['field_venue_name']); ?></h3>
          <?php print render($content['field_venue_text']); ?>
          <?php print render($content['field_venue_link']); ?>
        </div>
      </div>
    </div>
  <?php endif; ?>


  <?php if (isset($content['field_publication_name']) AND isset($content['field_publication_text'])): ?>
    <div class="container content no-padding-bottom exhibition-container">
      <div class="wide-promo wide-promo--exhib">

        <div class="content">
        <?php if (isset($content['field_publication_image'])): ?>
          <div class="exhibition-image filter_image">
            <?php print render($content['field_publication_image']); ?>
          </div>
        <?php endif; ?>
        </div>
       

        <div class="exhibition-text title-container">
          <h3><?php print render($content['field_publication_name']); ?></h3>
          <?php print render($content['field_publication_text']); ?>
          <?php print render($content['field_publication_link']); ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  
  <div class="content container repeating-body-content"<?php print $content_attributes; ?>>
    <?php print render($content['field_body_elements']); ?>
  </div>
 </div> <!-- /.content -->

  <?php if ($has_image_gallery): ?>

  <div class="full-width image-gallery">

    <div class="container gallery-controls-container">

      <div class="gallery-count">

        <span class="current"><?php print t('1', array(), array('context' => 'QMA')); ?></span>
        <span class="of"><?php print t('of', array(), array('context' => 'QMA')); ?></span>
        <span class="total"></span>

      </div>

    </div>

    <?php print render($content['field_image_gallery']); ?>

  </div>

  <?php endif; ?>

  <?php if($news_list): ?>
      
    <?php print $news_list; ?>

  <?php endif; ?>  

  <div class="full-width grey">
    <div class="container"<?php print $content_attributes; ?>>
      <h2><?php print t('Your Tweets<br/>And Pictures', array(), array('context' => 'QMA')); ?></h2>

      <div class="project-social-container">
        <?php print render($content['instagram_block']); ?>
        <?php print render($content['twitter_block']); ?>
      </div>
    </div>
  </div>

</article> <!-- /.node -->
