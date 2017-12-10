<?php
/**
 * Created by PhpStorm.
 * User: jiri.bazant
 * Date: 09.12.17
 * Time: 17:26
 */
$theme_path = drupal_get_path('theme', 'pp_blue');
?>
<section class="l-detail">
    <div class="container">
        <aside class="l-detail__aside">
            <img src="<?php print url($theme_path . '/img/png/p-red_2x.png') ?>" alt="login decoration image"/>
        </aside>
        <div class="l-detail__content">
            <h2 class="heading--primary l-detail__heading">Přihlášení</h2>
            <?php
                print drupal_render($form['name']);
                print drupal_render($form['pass']);
                print drupal_render($form['form_build_id']);
                print drupal_render($form['form_id']);
                print drupal_render($form['actions']);
            ?>
        </div>
    </div>
</section>
