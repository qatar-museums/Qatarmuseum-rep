<div class="<?php print $variables['active_form'] ?>">
  <?php if ($variables['active_form'] === 'register'): ?>
    <h1>
      <?php print t('Our Membership Programme<br/>-<br/>Sign Up', array(), array('context' => 'QMA'));?>
    </h1>
    <div id="register-form" class="membership-half-width">
      <?php print render($variables['register_form']);?>
    </div>
  <?php else: ?>
    <h1>
      <?php print t('Please log in', array(), array('context' => 'QMA'));?>
    </h1>
    <div id="login-form" class="membership-half-width">
      <?php print render($variables['login_form']);?>
    </div>
  <?php endif; ?>
</div>