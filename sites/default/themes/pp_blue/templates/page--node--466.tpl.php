<?php
/**
 * Todo Rename this to page--front when time comes
 * Created by PhpStorm.
 * User: jiri.bazant
 * Date: 27.12.20
 * Time: 23:20
 */
$theme_path = drupal_get_path('theme', 'pp_blue');

include($theme_path . '/templates/inc/header.php');
?>

<main id="content">
  <h1 class="heading--hp">Brána do světa plastů</h1>

  <?php if ($messages): ?>
    <div id="messages">
      <div class="section clearfix">
        <?php print $messages; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($page['featured']): ?>
    <div id="featured" class="container">
      <div class="section clearfix">
        <?php print render($page['featured']); ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($tabs): ?><?php print render($tabs); ?><?php endif; ?>
  <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>

  <section class="l-home-content">
    <div class="container">
      <?php print render($page['content']); ?>
    </div>
  </section>

  <?php print render($page['footer']); ?>
</main>

<?php include($theme_path . '/templates/inc/footer.php'); ?>
