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

  <div class="full-width no-padding">

    <div class="pattern-gallery-images">

      <?php print render($content['field_pattern_sample_images']); ?>

    </div>

  </div>

  <div class="node-hero-wrapper">

    <div class="header-area full-width">

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

  <div class="full-width pattern no-padding">

    <div class="pattern-generator-wrapper">
      <p class="ie8-message"><b><?php print t('Please upgrade your browser to use the pattern generator. Chrome, Firefox, Safari and IE9+ are supported. Thank you!', array(), array('context' => 'QMA')); ?></b></p>
      <noscript><p><b><?php print t('Please enable JavaScript in your browser to use the pattern generator. Thank you!', array(), array('context' => 'QMA')); ?></b></p></noscript>
      <script src="/<?php print libraries_get_path('pattern');?>/processing-1.4.1.min.js"></script>
      <script src="/<?php print libraries_get_path('pattern');?>/patternGenerator.js"></script>

      <p class="pattern-message"><b><?php print t('Please view the Pattern Canvas in a browser more than 768px wide', array(), array('context' => 'QMA')); ?></b></p>

      <canvas data-processing-sources="/<?php print libraries_get_path('pattern');?>/pattern.pde" width="1174" height="650"></canvas>

      <div id="pattern-sharing">
        <div class="inner">
          <a id="email" href="#">
            <?php print t('Email', array(), array('context' => 'QMA')); ?>
          </a>

          <a id="download" href="#">
            <?php print t('Download', array(), array('context' => 'QMA')); ?>
          </a>
        </div>

        <a id="share" href="#">
          <?php print t('Share', array(), array('context' => 'QMA')); ?>
        </a>
      </div>

    </div>

  </div>

</article> <!-- /.node -->
