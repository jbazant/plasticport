<?php

$module_path = drupal_get_path('module', 'pp_order');

?>
<section class="l-detail">
    <div class="container">
        <aside class="l-detail__aside"><img src="<?= url($module_path . '/img/p-red_2x.png') ?>" alt="Obrázek - poptávka"></aside>
        <div class="l-detail__content">
            <h2 class="heading--primary l-detail__heading">Chyba při odeslání poptávky</h2>
            <p>
                Omlouváme se, ale při zpracování Vaší poptávky došlo k chybě.
                Vaše poptávka <strong>nebyla odeslána</strong>.
            </p>

            <p>
                Zkuste prosím poptávku vyplnit a odeslat <?= l('znovu', '/poptavka') ?>.
            </p>

            <p>V případě, že potíže přetrvávají, nás neváhejte kontaktovat. Kontaktní údaje naleznete v patičce
                stránek.</p>
        </div>
    </div>
</section>