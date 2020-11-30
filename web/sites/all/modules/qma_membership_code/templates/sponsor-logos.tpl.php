<?php

/**
 * @file
 * Default theme implementation to display sponsor logos.
 *
 * Available variables:
 * - $logos: a renderable array of sponsor logos
 */
?>
<div class="sponsor-logos clearfix">
  <div class="sponsor-logos-left">
    <?php print render($logos['left']); ?>
  </div>

  <div class="sponsor-logos-right">
    <?php print render($logos['right']); ?>
  </div>
</div>
