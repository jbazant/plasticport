<?php
/**
 * Created by PhpStorm.
 * User: jiri.bazant
 * Date: 11.12.17
 * Time: 0:01
 */
$theme_path = drupal_get_path('theme', 'pp_blue');
?>
<?php print render($title_prefix); ?>
<?php if ($title): ?>
    <?php print $title; ?>
<?php endif; ?>
<?php print render($title_suffix); ?>
<?php if ($header): ?>
    <section class="l-detail">
        <div class="container">
            <aside class="l-detail__aside"><img src="<?php print url($theme_path . '/img/png/lepidla.png') ?>" width="330" height="335" alt="Lepidla"  class="image-detail" /></aside>
            <div class="l-detail__content">
                <?php print $header; ?>
            </div>
        </div>
    </section>
<?php endif; ?>

<?php if ($exposed): ?>
    <div class="view-filters">
        <?php print $exposed; ?>
    </div>
<?php endif; ?>

<?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
        <?php print $attachment_before; ?>
    </div>
<?php endif; ?>

<?php if ($rows): ?>
    <div class="view-content">
        <?php print $rows; ?>
    </div>
<?php elseif ($empty): ?>
    <div class="view-empty">
        <?php print $empty; ?>
    </div>
<?php endif; ?>

<?php if ($pager): ?>
    <?php print $pager; ?>
<?php endif; ?>

<?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
        <?php print $attachment_after; ?>
    </div>
<?php endif; ?>

<?php if ($more): ?>
    <?php print $more; ?>
<?php endif; ?>

<?php if ($footer): ?>
    <div class="view-footer">
        <?php print $footer; ?>
    </div>
<?php endif; ?>

<?php if ($feed_icon): ?>
    <div class="feed-icon">
        <?php print $feed_icon; ?>
    </div>
<?php endif; ?>

