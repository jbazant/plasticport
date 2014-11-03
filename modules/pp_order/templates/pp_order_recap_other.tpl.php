<?php
/**
 * Template s rekapitulaci poptavky "jine".
 *
 * Pouziva se pro vykresleni emailu i node s poptavkou.
 *
 * @var int $vyska_otvor
 * @var int $sirka_otvor
 * @var string $kontaktni_osoba
 * @var string $spolecnost
 * @var string $ulice
 * @var string $cp
 * @var string $psc
 * @var string $mesto
 * @var string $email
 * @var string $telefon
 * @var string $poznamka
 * @var string $email_obchod
 * @var string $tel_obchod
 *
 */
?>
<h2>Poptávka - jiné</h2>

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
        <td colspan="4">Zákazníkovi <strong>NEbyla</strong> odeslána cenová nabídka.</td>
    </tr>
</table>
