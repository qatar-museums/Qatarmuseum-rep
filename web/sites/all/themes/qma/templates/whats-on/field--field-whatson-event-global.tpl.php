<?php
/**
 *  Field formatter for the whatson-event field collection.
 *  This template is assigned, and it's variables created in qma_preprocess_field
 *  This template is invoked once for the field.
 *  Each repeating instance of the field collection is assigned a row in the $rows array
 *  Each field may be addressed by name in one of these rows and contains 2 array elements 
 *  '#render' & '#raw', the former is the rendered value as controlled by the view mode.
 *  Each row also has a unique '#delta' value.
 */
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
	<div class="field-items"<?php print $content_attributes; ?>>
	  <?php foreach($rows as $row): ?>

			<div class="field-item <?php print $row['#delta'] % 2 ? 'odd' : 'even'; ?>">
				<div class="field-collection-view clearfix view-mode-full">
					<div class="entity entity-field-collection-item whats-on-events clearfix">
						<div class="content">
							<div class="views-row">
								
								<div class="teaser-image">
									<?php print $row['field_event_image']['#render']; ?>
								</div>

								<div class="teaser-text ">
									
									<?php
										if ($row['field_event_link']['#raw']) {

											// determine if we open the link in a new window or not

											$target = '';
											if(isset($row['field_event_link']['#raw']['attributes']['target'])) {
												$target = 'target="_blank"';
											}

											print '<h4><a href="'.$row['field_event_link']['#raw']['url'].'" '.$target.' >'.$row['field_event_title']['#raw'].'</a></h4>';	
										} else {
											print '<h4>'.$row['field_event_title']['#raw'].'</h4>';	
										}

									?>
									
									<?php print $row['field_event_description']['#render']; ?>
									<?php print $row['field_event_location']['#render']; ?>
									<?php print $row['display_date']; ?>

								</div>

							</div>
						</div>
					</div>
				</div>
			</div>
	  <?php endforeach; ?>
	</div>
</div>