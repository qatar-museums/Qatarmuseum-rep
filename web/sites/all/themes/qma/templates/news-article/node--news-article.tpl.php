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
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> generic-page"<?php print $attributes; ?>>

  <div class="container"<?php print $content_attributes; ?>>

    <div class="generic-center-column">

      <?php print $news_hub_link; ?>

      <h1><?php print $title; ?></h1>

      <div class="intro-text">
          <?php if ($display_date): ?>
            <div class="news-meta">
              <?php print $display_date; ?>
              <?php print render($jump_link); ?>
            </div>
          <?php else: ?>
            <div class="news-meta">
              <?php print render($content['field_news_date']); ?>
              <?php print render($jump_link); ?>
            </div>
          <?php endif; ?>
      </div>

      <div class="container">
        <div class="share-links-wrapper">
          <?php include(drupal_get_path('theme', 'qma').'/templates/includes/blog-sharing-links.tpl.php'); ?>
        </div>
      </div>

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

  <div class="container blog-pager">
    <div class="pager-inner">
      <div class="prev-blog blog-pager-link">
        <div class="prev-text">
          <?php print render($content['simple_pager']['previous']) ?>
        </div>
      </div>
      <div class="next-blog blog-pager-link">
        <div class="next-text">
          <?php print render($content['simple_pager']['next']) ?>
        </div>
      </div>
    </div>
  </div>

  <!-- Comment form -->
  <?php if ($content['comments']): ?>
  <div class="full-width grey comments">
    <div class="container">
      <div class="comment-center-column content-form">
        <?php print render($content['comments']); ?>
      </div>
    </div>
  </div>
  <?php endif; ?>
  <!--  End comment form-->

  <div class="container"<?php print $content_attributes; ?>>

      <?php if($content['field_news_tags']): ?>
        <div class="news-tags full-width">
          <h2><?php print t('Find other articles on our blog', array(), array('context' => 'QMA')); ?></h2>
          <?php print render($content['field_news_tags']); ?>
        </div>
      <?php endif; ?>

      <?php if($news_list): ?>
        <div class="news-view-list">
          <h2><?php print t('You might also like', array(), array('context' => 'QMA')); ?></h2>
          <?php print $news_list; ?>
        </div>
      <?php endif; ?>



  </div> <!-- /.content -->

</article> <!-- /.node -->
