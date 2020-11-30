<?php

/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>

<div class="pattern-gallery">
	
	<div class="pattern-row">

	<?php
	// we want the pattern row div to be closed every 5 items
	$count = 1;

	foreach($gallery_images as $img_src): ?>
		
		<div class="gallery-image">

			<img src="<?php print $img_src['small']; ?>" alt="" data-large-src="<?php print $img_src['large']; ?>" />
			
		</div>

		<?php if($count % 5 == 0): ?>
			</div>
			<div class="large-pattern-container">
				<img src="/sites/all/themes/qma/images/placeholder.gif" alt="" />
			</div>
			<div class="pattern-row">
		<?php endif; ?>

	<?php 
	$count++;
	endforeach; ?>

		<div class="gallery-image link-square desktop">
			<?php print $pattern_generator_link; ?>
		</div>

	</div>

	<div class="large-pattern-container">
		<img src="/sites/all/themes/qma/images/placeholder.gif" alt="" />
	</div>

	<div class="mobile-link mobile">
		<?php print $pattern_generator_link; ?>
	</div>

</div>


