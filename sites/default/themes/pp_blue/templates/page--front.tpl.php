<?php
/**
 * Created by PhpStorm.
 * User: jiri.bazant
 * Date: 07.06.16
 * Time: 23:20
 */
$theme_path = drupal_get_path('theme', 'pp_blue');

include($theme_path . '/templates/inc/header.php');
?>

<main id="content">
    <h1 class="heading--hp">Brána do světa plastů</h1>

    <section class="l-home-nav">
        <a href="<?= url('/zakazkova-vyroba') ?>" class="l-home-nav__item">
            <div class="l-home-nav__img">
                <picture>
                    <source media="(min-width: 700px)" srcset="<?= url($theme_path . '/img/img-hp-01.jpg') . ', ' . url($theme_path . '/img/img-hp-01-2x.jpg') . ' 2x' ?>">
                    <?= theme('image', array(
                        'path' => $theme_path . '/img/img-hp-mobile-01.jpg',
                        'alt' => "Produkty vizuál",
                        'attributes' => array('srcset' => $directory . '/img/img-hp-01.jpg 2x'),
                    )) ?>
                </picture>
            </div>
            <h2 class="l-home-nav__heading"><span>Zakázková výroba</span></h2>
        </a>
        <a href="<?= url('/produkty') ?>" class="l-home-nav__item">
            <div class="l-home-nav__img">
                <picture>
                    <source media="(min-width: 700px)" srcset="<?= url($theme_path . '/img/img-hp-02.jpg') . ', ' . url($theme_path . '/img/img-hp-02-2x.jpg') . ' 2x' ?>">
                    <?= theme('image', array(
                        'path' => $theme_path . '/img/img-hp-mobile-02.jpg',
                        'alt' => "Produkty vizuál",
                        'attributes' => array('srcset' => $directory . '/img/img-hp-02.jpg 2x'),
                    )) ?>
                </picture>
            </div>
            <h2 class="l-home-nav__heading"><span>Produkty</span></h2>
        </a>
    </section>
    
    <?php if ($messages): ?>
        <div id="messages"><div class="section clearfix">
                <?php print $messages; ?>
            </div></div> <!-- /.section, /#messages -->
    <?php endif; ?>

    <?php if ($page['featured']): ?>
        <div id="featured"><div class="section clearfix">
                <?php print render($page['featured']); ?>
            </div></div> <!-- /.section, /#featured -->
    <?php endif; ?>
    
    <section class="l-home-content">
        <div class="container">
            <?php print render($page['content']); ?>
        </div>
    </section>
</main>

<?php include($theme_path . '/templates/inc/footer.php'); ?>
