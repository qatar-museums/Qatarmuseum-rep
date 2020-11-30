<header id="header" class="site-header" role="banner">


<div class="site-banner">

      <?php print render($page['info_bar']); ?>

</div>
  <div class="header-span">

    <div class="container">
<p id="skip-link" class="hide-content"><em><a href="#content"><?php echo t("Jump to content", array(), array('context' => 'QMA')); ?></a></em> &darr;</p>
      <div class="logo-container">
        <p class="site-title"><a href="<?php print url('<front>'); ?>"><?php print $site_name;?></a></p>

      <a class="image-logo logo" href="<?php print url('<front>'); ?>"><img src="<?php print $logo; ?>" alt="Qatar museums home page " width="272" height="169"/></a></div>

      <nav id="site-nav-sidr" class="site-nav">
        <?php print render($page['header_menu']); ?>
      </nav>

      <div class="language-switcher">
        <?php print render($page['header']); ?>
      </div>

      <a id="mobile-menu-sidr" class="mobile-menu" href="#site-nav-sidr" ><span class="element-invisible" aria-hidden="true">mobile menu</span></a>
      

      <!-- header search form -->
      <?php print render($page['header_search']); ?>

      <?php if ($main_menu): ?>
        
      <?php endif; ?>

    </div>

  </div> <!-- close header span -->

  <?php //print render($breadcrumb); ?>

</header> <!-- /#header -->

<script>
jQuery(document).ready(function() {
  //jQuery('#mobile-menu-sidr').sidr();

  jQuery('#mobile-menu-sidr').sidr({
    name: 'responsive-main-navigation',
    renaming: false,
    displace: true,
    source: '#site-nav-sidr',
    onOpen: sidrOpen,
    onOpenEnd: sidrOpenEnd,
    onClose: sidrClose
  });

  // Close on resize
  jQuery(window).resize(function() {
    jQuery.sidr('close' , 'responsive-main-navigation');
  });

  function sidrOpen() {
    jQuery('.responsive-menu-overlay').addClass('active');
  }

  function sidrOpenEnd() {
    jQuery('.responsive-menu-overlay').on('click', function() {
      jQuery(this).removeClass('active');
        jQuery.sidr('close' , 'responsive-main-navigation');
    });
  }

  function sidrClose() {
    jQuery('.responsive-menu-overlay').removeClass('active');
  }

  // Multilevel menu navigation in Sidr menu
  jQuery('.sidr').find('li.expanded').each(function(index, menuItem) {
    jQuery(this).find('> a, > .nolink').on('click', function(event) {
      event.preventDefault();
      jQuery(this).toggleClass('active');
      jQuery(menuItem).find('> ul.menu').toggleClass('open');
    })
  });



});
</script>
