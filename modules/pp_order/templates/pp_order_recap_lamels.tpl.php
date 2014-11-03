<?php
/**
 * Template s rekapitulaci poptavky lamelove clony.
 *
 * Pouziva se pro vykresleni emailu i node s poptavkou.
 *
 * @var int $vyska_otvor
 * @var int $sirka_otvor
 * @var int $vyska_lamela
 * @var int $sirka_lamela
 * @var string $otvor_umisteni
 * @var string $pruvan
 * @var string $vytapeni
 * @var string $uchyceni
 * @var string $prujezd
 * @var string $kontaktni_osoba
 * @var string $spolecnost
 * @var string $ulice
 * @var string $cp
 * @var string $psc
 * @var string $mesto
 * @var string $email
 * @var string $telefon
 * @var string $poznamka
 * @var string $celkova_cena
 * @var string $lamela_typ
 * @var string $lamela_prekryv
 * @var string $email_obchod
 * @var string $tel_obchod
 * @var array $price counted values array, only for internal use
 *
 */
?>
<h2>
    <?php if ('new_order' == $type): ?>
        Poptávka lamelové clony
    <?php elseif ('recap' == $type): ?>
        Nacenění Vaší poptávky
    <?php else: ?>
        Rekapitulace poptávky lamelové clony
    <?php endif; ?>
</h2>

<?php if ('recap' == $type): ?>
    <p>
        Níže je uvedena rekapitulace Vaší poptávky i s námi navrhovanou cenou.
        V případě zájmu nebo dotazů nás prosím kontaktujte na našem emailu
        (<a href="mailto:<?php print $email_obchod ?>"><?php print $email_obchod ?></a>
        nebo telefonu <?php print $tel_obchod ?>.
    </p>
    <p>Všechny uvedené ceny jsou bez DPH.</p>
<?php endif; ?>

<table class="recap-table">
    <tr>
        <th class="section" colspan="4">Zadané rozměry otvoru</th>
    </tr>
    <tr>
        <th class="col1">Výška:</th>
        <td class="col2"><?php print $vyska_otvor; ?></td>
        <th class="col3">Šířka:</th>
        <td class="col4"><?php print $sirka_otvor; ?></td>
    </tr>

    <tr>
        <th class="section" colspan="4">Detaily</th>
    </tr>
    <tr>
        <th>Umístění otvoru:</th>
        <td><?php print $otvor_umisteni; ?></td>
        <th>Průvan:</th>
        <td><?php print $pruvan; ?></td>
    </tr>
    <tr>
        <th>Vytápění:</th>
        <td><?php print $vytapeni; ?></td>
        <th>Průjezd:</th>
        <td><?php print $prujezd; ?></td>
    </tr>

    <tr>
        <th>Uchycení:</th>
        <td><?php print $uchyceni; ?></td>
        <th>Lišta:</th>
        <td><?php print $lista; ?></td>
    </tr>

    <tr>
        <th class="section" colspan="4">Kontaktní údaje</th>
    </tr>
    <tr>
        <th rowspan="2">Adresa:</th>
        <td rowspan="2">
            <?php print $spolecnost; ?><br />
            <?php print $kontaktni_osoba; ?><br />
            <?php print $ulice; ?> <?php print $cp; ?><br />
            <?php print $psc; ?> <?php print $mesto; ?>
        </td>
        <th>Email:</th>
        <td><?php print $email; ?></td>
    </tr>
    <tr>
        <th>Telefon:</th>
        <td><?php print $telefon; ?></td>
    </tr>
    <tr>
        <th>Poznámka:</th>
        <td colspan="3"><?php print $poznamka; ?></td>
    </tr>

    <tr>
        <th class="section" colspan="4">Vypočtené parametry lamely</th>
    </tr>
    <tr>
        <th>Výška:</th>
        <td><?php print $vyska_lamela; ?></td>
        <th>Šířka:</th>
        <td><?php print $sirka_lamela; ?></td>
    </tr>
    <tr>
        <th>Typ lamely:</th>
        <td><?php print $lamela_typ; ?></td>
        <th>Překryv lamel:</th>
        <td colspan="3"><?php print $lamela_prekryv; ?></td>
    </tr>
    <?php if ('recap' == $type && isset($pocet_lamel)): ?>
        <tr>
            <th>Potřebný počet lamel:</th>
            <td colspan="3"><?php print $pocet_lamel; ?></td>
        </tr>
    <?php endif; ?>

    <tr>
        <th class="section" colspan="4">Vypočtená cena:</th>
    </tr>
    <tr>
        <th>Cena materiálu:</th>
        <td><?php print $cena_materialu; ?></td>
        <th>Cena montáže:</th>
        <td><?php print $cena_montaze; ?></td>
    </tr>
    <tr>
        <th>Cena dopravy:</th>
        <td><?php print $cena_dopravy; ?></td>
        <td colspan="2"></td>
    </tr>
    <tr class="result">
        <th colspan="2">Celková cena:</th>
        <td colspan="2"><?php print $celkova_cena; ?></td>
    </tr>
    <tr>
        <td colspan="4">
            <?php if ('recap' == $type): ?>
                Cena je generována automatickým systémem.
            <?php elseif ('new_order' == $type): ?>
                <?php if ($inform_customer): ?>
                    Zákazníkovi mohla být (ale nebyla) odeslána automaticky vypočtená cenová nabídka.
                <?php else: ?>
                    Zákazníkovi <strong>NEbyla</strong> odeslána cenová nabídka.
                <?php endif; ?>
            <?php endif; ?>
        </td>
    </tr>
</table>
