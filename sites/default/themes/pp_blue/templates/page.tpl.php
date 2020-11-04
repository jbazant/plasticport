<?php
/**
 * Created by PhpStorm.
 * User: jiri.bazant
 * Date: 10.06.16
 * Time: 7:43
 */
$theme_path = drupal_get_path('theme', 'pp_blue');

include($theme_path . '/templates/inc/header.php');
?>

<main id="content">

    <div class="info-strip">
        <div class="info-strip__top">
            <div class="container">
                <h1 class="info-strip__heading">
                    <?php print $title; ?>
                </h1>
            </div>
        </div>
        <?php if ($breadcrumb): ?>
            <div class="info-strip__bottom">
                <div class="container"><?php print $breadcrumb; ?></div>
            </div>
        <?php endif; ?>
    </div>

    <?php if ($messages): ?>
        <div id="messages">
            <div class="section clearfix">
                <?php print $messages; ?>
            </div>
        </div> <!-- /.section, /#messages -->
    <?php endif; ?>

    <?php if ($page['featured']): ?>
        <div id="featured" class="container">
            <div class="section clearfix">
                <?php print render($page['featured']); ?>
            </div>
        </div> <!-- /.section, /#featured -->
    <?php endif; ?>
    <?php if ($tabs): ?><?php print render($tabs); ?><?php endif; ?>
    <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
    <?php print render($page['content']); ?>
    <?php print render($page['footer']); ?>
</main>

<?php include($theme_path . '/templates/inc/footer.php'); ?>
