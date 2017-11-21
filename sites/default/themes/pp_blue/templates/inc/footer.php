<?php
/**
 * Created by PhpStorm.
 * User: jiri.bazant
 * Date: 10.06.16
 * Time: 7:39
 */
?>
<footer class="l_footer">
    <div class="container">
        <div class="row">
            <div class="col--footer">
                <div class="h-card">
                    <h3 class="l-footer__heading">Kontakt:</h3>
                    <div class="p-name">Jaroslav Bažant</div>
                    <div>Telefon: <a class="p-tel" href="tel:+420731566609">+420 731 566 609</a></div>
                    <p>Email: <span class="u-email"><?= spamspan('info@plasticport.cz') ?></span></p>
                </div>
            </div>
            <div class="col--footer">
                <h3 class="l-footer__heading">Fakturační údaje:</h3>
                <address>Jaroslav Bažant, <br>Tyršova 1157/52, <br>419 01 Duchcov</address>
            </div>
            <div class="col--footer">
                <h3 class="l-footer__heading">Prodejna:</h3>
                <address>Spojenecká ul. 764, <br>415 01 Teplice, <br>(u OC Albert, vjezd pod Okna Sulko)</address>
            </div>
            <div class="col--footer">
                <p><?= l('mapa stránek', 'sitemap.xml') ?></p>

                <p>Copyright &#169; Jaroslav Bažant</p>
            </div>
        </div>
    </div>
</footer>
