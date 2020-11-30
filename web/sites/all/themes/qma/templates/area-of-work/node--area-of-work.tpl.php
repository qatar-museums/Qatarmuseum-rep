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

  <div class="node-hero-wrapper">

    <div class="hero-container">

      <?php hide($content['field_hero_image']); ?>

    </div>

    <div class="header-area full-width blue">

      <div class="container">

        <div class="title-container">

          <?php if (isset($content['field_subtitle'][0]['#markup'])): ?>
            <h1><?php print $title; ?><br />&ndash;<br /><?php print $content['field_subtitle'][0]['#markup']; ?></h1>
          <?php else: ?>
            <h1><?php print $title; ?></h1>
          <?php endif; ?>
          
        </div>

        <div class="intro-text">

          <?php print render($content['field_intro_text']); ?>      

        </div>

      </div>

    </div>

  </div>

  <div class="content container repeating-body-content"<?php print $content_attributes; ?>>
    
    <?php print render($content['field_body_elements']); ?>
      
  </div> <!-- /.content -->
  <div class="full-width yellow">

    <div class="container">
      
    <h2><?php print t("What We're Doing", array(), array('context' => 'QMA')); ?></h2>

    <div class="grid-three">
      <?php print $project_listing; ?>
    </div>

    </div>
  </div>

  <?php if ($content['field_participation_promo_ref']): ?>

    <div class="content container no-padding-bottom"<?php print $content_attributes; ?>>
      
        <?php print render($content['field_participation_promo_ref']); ?>

    </div>

  <?php endif; ?>

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

    
  <?php print $interview_area; ?>


  <?php //if ($content['instagram_block'] || $content['twitter_block']): // always display as we are supplying default fallback accounts for now ?>

    <div class="full-width grey">

      <div class="container"<?php print $content_attributes; ?>>

        <h2><?php print t('Your Tweets<br/>And Pictures', array(), array('context' => 'QMA')); ?></h2>

        <div class="project-social-container">

          <?php print render($content['instagram_block']); ?>
          <?php print render($content['twitter_block']); ?>

        </div>

      </div>

    </div>

  <?php //endif; ?>
  
    <?php if ($content['field_choose_poll']): ?>

    <div class="full-width orange poll-container">

      <div class="container">

        <?php print render($content['field_choose_poll']); ?>

      </div>

    </div>

  <?php endif; ?>

  <div class="full-width find-out-more">

    <div class="container">

      <div class="column first">
        <?php if(isset($content['field_find_out_more_links'])): ?>
          <h2><?php print t('Find out more', array(), array('context' => 'QMA')); ?></h2>
          <?php print render($content['field_find_out_more_links']); ?>
        <?php endif; ?>
      </div>

      <div class="column">
        <?php if(isset($content['field_project_sample_tags'])): ?>
          <h2><?php print t('See also', array(), array('context' => 'QMA')); ?></h2>
          <?php print render($content['field_project_sample_tags']); ?>
        <?php endif; ?>
      </div>

      <div class="column ie8last last">

        <?php include(drupal_get_path('theme', 'qma').'/templates/includes/sharing-links.tpl.php'); ?>

      </div>

    </div>

  </div>

</article> <!-- /.node -->
