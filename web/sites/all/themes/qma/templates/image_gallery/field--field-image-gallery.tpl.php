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

<div id="cbp-fwslider" class="cbp-fwslider">
	
	<ul>

	<?php foreach($gallery_images as $img_src): ?>

		<li>
	
			<div class="gallery-image">

				<div class="mobile-image" style="background-image: url('<?php print $img_src['small']; ?>');"></div>
				<img src="/sites/all/themes/qma/images/placeholder.gif" alt="" width="<?php print $img_src['large_width']; ?>" 
				height="<?php print $img_src['large_height']; ?>" data-large-src="<?php print $img_src['large']; ?>" />
				
			</div>

			<div class="full-width pink">

				<div class="container">

					<div class="gallery-caption">
						<p class="caption"><?php print $img_src['caption']; ?></p>
					</div>

				</div>

			</div>

		</li>

	<?php endforeach; ?>

	</ul>

</div>


