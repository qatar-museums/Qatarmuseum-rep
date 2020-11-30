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
<!--Facebook load sdk-->
<div id="fb-root"></div>
<script>(function(d, s, id) {
  var js, fjs = d.getElementsByTagName(s)[0];
  if (d.getElementById(id)) return;
  js = d.createElement(s); js.id = id;
  js.src = "//connect.facebook.net/en_US/all.js#xfbml=1";
  fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));</script>
<!--end Facebook load sdk-->

<article id="node-<?php print $node->nid; ?>" class="<?php print $custom_class; ?> <?php print $classes; ?>"<?php print $attributes; ?>>

  <div class="node-hero-wrapper">

    <div class="instagram-slider">
      <?php print $instagram_slider; ?>
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

  <div class="content container"<?php print $content_attributes; ?>>
    
		<div class='social-media-col twitter-feed'>
			<h3><?php print t('Twitter', array(), array('context' => 'QMA'));?></h3>
      
      <div class="sm-container">
 	      <a class="twitter-timeline"  href="https://twitter.com/<?php print $node->field_twitter_account_link[LANGUAGE_NONE][0]['value']; ?>"  data-widget-id="<?php print $node->field_twitter_widget_id['und'][0]['value']; ?>" lang="<?php print $node->language;?>">Tweets by @ <?php print $node->field_twitter_account_link[LANGUAGE_NONE][0]['value']; ?></a>
       	<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0];if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src="//platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
      </div>

      <span class="sm-link twitter"><?php print l(t('Follow us on Twitter', array(), array('context' => 'QMA')),'https://twitter.com/'.$node->field_twitter_account_link['und'][0]['value']);?></span>
    </div>

    <div class='social-media-col youtube-feed'>
     	<h3><?php print t('YouTube', array(), array('context' => 'QMA'));?></h3>

   		<div class="sm-container">
        <?php print render($content['field_youtube_embed']); ?>
      </div>

      <span class="sm-link youtube"><?php print l(t('Visit our YouTube channel', array(), array('context' => 'QMA')), 'http://www.youtube.com/user/'.$node->field_youtube_channel['und'][0]['value']);?></span>
   	</div>
      	
   	<div class='social-media-col facebook-feed'>
   		<h3><?php print t('Facebook', array(), array('context' => 'QMA'));?></h3>

      <div class="sm-container">
        <div class="fb-like-box" data-href="https://www.facebook.com/<?php print $node->field_facebook_page['und'][0]['value']; ?>" data-width="322" data-height="517" data-colorscheme="light" data-show-faces="false" data-header="false" data-stream="true" data-show-border="true"></div>
      </div>

      <?php $fbLangDomain = ($node->language=='ar'?'ar-ar':'www'); //link to appropriate language version of facebook ?>
      <span class="sm-link facebook"><?php print l(t('Connect with us on Facebook', array(), array('context' => 'QMA')),'https://'.$fbLangDomain.'.facebook.com/'.$node->field_facebook_page['und'][0]['value']);?></span>
    </div>
	    
  </div> <!-- /.content -->

         

</article> <!-- /.node -->
