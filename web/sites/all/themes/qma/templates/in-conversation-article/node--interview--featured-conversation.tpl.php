<div class="featured-conversation">

  <div class="title-container">
    <p class="date-text"><?php print $display_date; ?></p>
    <h2><?php print $title; ?></h2>
    <p class="role"><?php print render($content['field_interviewee_role'][0]['#markup']); ?></p>
  </div> <!-- close date square -->

  <div class="filter_image">
    <?php print render($content['field_teaser_image']); ?>
    <canvas width="455" height="455"></canvas>
    <div class="hover-text">
      <?php print render($content['field_teaser_text']); ?>
    </div>
  </div>

</div>