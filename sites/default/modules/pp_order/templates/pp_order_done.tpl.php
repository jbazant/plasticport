<?php
/**
 * Created by PhpStorm.
 * User: jiri.bazant
 * Date: 12.06.16
 * Time: 0:10
 */

$module_path = drupal_get_path('module', 'pp_order');

?>
<section class="l-detail">
    <div class="container">
        <aside class="l-detail__aside"><img src="<?= url($module_path . '/img/p-blue_2x.png') ?>" alt="Obrázek - poptávka"></aside>
        <div class="l-detail__content">
            <h2 class="heading--primary l-detail__heading">Poptávka byla odeslána</h2>
            <p>Děkujeme za zaslání poptávky. Brzy Vás budeme kontaktovat.</p>
            <?php if (time() < strtotime('2017-02-20')): ?>
                <p><strong>Z důvodu dovolené budou poptávky z období 14.2. - 29.2. odbaveny až následující týden!</strong></p>
            <?php endif; ?>

            <h3 class="heading--secondary">Můžete pokračovat na</h3>
            <ul class="l-detail__list">
                <li><?= l('Úvodní stránku', '/') ?></li>
                <li><?= l('Poptávkový formulář', '/poptavka') ?></li>
                <li><?= l('Naše produkty', '/produkty') ?></li>
                <li><?= l('Zakázkovou výrobu', '/zakazkova-vyroba') ?></li>
            </ul>
        </div>
    </div>
</section>
