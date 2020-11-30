<?php
/**
 *  Field formatter for the homepage_box field collection.
 *  This template is assigned, and it's variables created in qma_preprocess_field
 *  This template is invoked once for the field.
 *  Each repeating instance of the field collection is assigned a row in the $rows array
 *  Each field may be addressed by name in one of these rows and contains 2 array elements 
 *  '#render' & '#raw', the former is the rendered value as controlled by the view mode.
 */
?>

<div class="<?php print $classes; ?> homepage-collection"<?php print $attributes; ?>>
  <div class="field-items"<?php print $content_attributes; ?>>
    <?php foreach($rows as $row): ?>
        <div class="homepage-box">
        	<h2><?php print $row['field_home_box_title']['#raw']; ?></h2>
          
          <div class="homepage-box-image front">
            <?php print $row['field_home_box_image_1']['#render']; ?>
            <div class="text-container">
              <?php print $row['field_home_box_link_1']['#render']; ?>
              <?php print $row['field_home_box_text_1']['#render']; ?>
            </div>

          </div>
          
          <div class="homepage-box-image">
            <?php print $row['field_home_box_image_2']['#render']; ?>
            
            <div class="text-container">
              <?php print $row['field_home_box_link_2']['#render']; ?>
              <?php print $row['field_home_box_text_2']['#render']; ?>
            </div>

          </div>

          <div class="homepage-box-image">
            <?php print $row['field_home_box_image_3']['#render']; ?>
            
            <div class="text-container">
              <?php print $row['field_home_box_link_3']['#render']; ?>
              <?php print $row['field_home_box_text_3']['#render']; ?>
            </div>

          </div>

          <div class="homepage-box-image logo-container">
            <img src="/sites/all/themes/qma/images/logo_blocks/logo1.png" alt="" />
          </div> 

        </div>
    <?php endforeach; ?>
      <div class="homepage-box tablet-logo-container">
        <img src="/sites/all/themes/qma/images/logo.png" alt="" />
      </div> 
  </div>
</div>