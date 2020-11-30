<?php
/**
 *  Field formatter for the body_elements field collection.
 *  This template is assigned, and it's variables created in qma_preprocess_field
 *  This template is invoked once for the field.
 *  Each repeating instance of the field collection is assigned a row in the $rows array
 *  Each field may be addressed by name in one of these rows and contains 2 array elements 
 *  '#render' & '#raw', the former is the rendered value as controlled by the view mode.
 */
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
	<div class="field-items"<?php print $content_attributes; ?>>
	  <?php foreach($rows as $row): ?>

	  	<?php

				if ($row['field_element_user_quote']['#raw']) {
					$group_class_name = 'group-user-quote';
				} 
				else if ($row['field_element_pull_quote']['#raw']) {
					$group_class_name = 'group-pull-quote';
				}
				else {
					$group_class_name = '';
				}


			?>


			<div class="field-item <?php print $row['#delta'] % 2 ? 'odd' : 'even'; ?><?php print $row['field_element_wide']['#raw']? ' wide-element' : ''; ?><?php print $row['field_element_user_quote_wide']['#raw']? ' wide-user-quote' : ''; ?>">
				<div class="field-collection-view clearfix view-mode-full">
					<div class="entity entity-field-collection-item field-collection-item-field-body-elements clearfix">
						<div class="content">
							<div class="<?php echo $group_class_name; ?>">
								<?php if ($row['field_element_text_title']['#raw']) {
										print '<h3>'.$row['field_element_text_title']['#raw'].'</h3>'; 
								}
								?>
								<?php print $row['field_element_text_area']['#render']; ?>
								<?php print $row['field_element_image']['#render']; ?>
								<?php print $row['field_element_image_caption']['#render']; ?>
								<?php print $row['field_element_video_url']['#render']; ?>
								<?php print $row['field_element_user_quote']['#render']; ?>
								<?php print $row['field_element_user_quote_name']['#render']; ?>
								<?php print $row['field_element_pull_quote']['#render']; ?>
								<?php print $row['field_element_pull_quote_name']['#render']; ?>
							</div>
						</div>
					</div>
				</div>
			</div>
	  <?php endforeach; ?>
	</div>
</div>