<?php
/**
 * Created by PhpStorm.
 * User: jiri.bazant
 * Date: 08.12.17
 * Time: 23:23
 */

$theme_path = drupal_get_path('theme', 'pp_blue');
?>
<?php print $user_picture; ?>

<?php if ($display_submitted): ?>
    <span class="submitted"><?php print $date; ?> — <?php print $name; ?></span>
<?php endif; ?>


<?php
// We hide the comments and links now so that we can render them later.
hide($content['comments']);
hide($content['links']);
?>
<section class="l-detail">
    <div class="container">
        <aside class="l-detail__aside">
            <?php print render($content['field_image']) ?>
        </aside>
        <div class="l-detail__content">
            <h2 class="heading--primary l-detail__heading"><?php print $title; ?></h2>
            <?php print render($content['body']); ?>
        </div>
    </div>
</section>


<?php if (!empty($content['links']['terms'])): ?>
    <?php print render($content['links']['terms']); ?>
<?php endif; ?>

<?php if (!empty($content['links'])): ?>
    <?php print render($content['links']); ?>
<?php endif; ?>


<?php print render($content['comments']); ?>
