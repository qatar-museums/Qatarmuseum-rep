<?php /*Added logic in this template to add numbering to questions */ ?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <div class="field-items"<?php print $content_attributes; ?>>
  	<?php $questionCount = 0; ?>
    <?php foreach ($items as $delta => $item): ?>
    	<?php if (isset($item['entity']['field_collection_item'])): // this template applies in a nested way to the field collection items and their contained fields so we need this test to ensure we output appropriately for each?>
   			<?php $fcArr = reset($item['entity']['field_collection_item']); //use reset to get the first item as we don't know the key in advance ?>
   			<?php $wrapperClass = (isset($fcArr['field_interview_user_name'])?'user-submitted':''); ?>
    		<div class="<?php print $wrapperClass;?> question">
    			<?php if(isset($fcArr['field_interview_question'])): ?>
    				<?php $questionCount++;?>
    				<h2 class="number"><span class="hide-content"><?php print t('Question '); ?></span><?php print t(str_pad($questionCount, 2, "0", STR_PAD_LEFT), array(), array('context' => 'QMA')); //take  the integer value, pad it with leading zero and pass to translate function?></h2> 
    			<?php endif;?>
      			<?php print render($item); ?>
      		</div>
      	<?php else: ?>
      		<div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></div>
    	<?php endif; ?>
    <?php endforeach; ?>
  </div>
</div>
