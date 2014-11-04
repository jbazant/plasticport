<?php
/**
 * @file Implementace theme order_recap_valid
 *
 * Process funkce pro sestaveni template na vykresleni emailu i node s rekapitulaci poptavky
 *
 */


/**
 * @param array $variables
 */
function template_process_order_recap_lamels(&$variables) {
    $variables['vyska_lamela'] = isset($variables['price']['counted_height'])
        ? _getAsCm($variables['price']['counted_height'])
        : 'nevypočtena'
    ;
    $variables['sirka_lamela'] = isset($variables['price']['counted_width'])
        ? _getAsCm($variables['price']['counted_width'])
        : 'nevypočtena'
    ;

    // umisteni otvoru
    switch ($variables['form']['position']) {
        case 'exterier':
            $sTmp = t('Exteriér / Interiér');
            break;

        case 'interier':
            $sTmp = t('Interiér / Interiér');
            break;

        default:
            $sTmp = t('Neuvedeno');

    }
    $variables['otvor_umisteni'] = $sTmp;

    // pruvan
    switch ($variables['form']['draft']) {
        case 'none':
            $sTmp = t('Není');
            break;
        case 'low':
            $sTmp = t('Mírný');
            break;
        case 'high':
            $sTmp = t('Velký');
            break;
        default:
            $sTmp = t('Neuvedeno');

    }
    $variables['pruvan'] = $sTmp;

    // prujezd
    $aTmp = array();
    foreach($variables['form']['traffic'] as $traffic) {
        if (!isset($aTmp[$traffic])) {
            switch ($traffic) {
                case 'ppl':
                    $aTmp['ppl'] = t('Osoby');
                    break;

                case 'pallet':
                    $aTmp['pallet'] = t('Paletový vozík');
                    break;

                case 'forklifts':
                    $aTmp['forklifts'] = t('Vysokozdvižný vozík');
                    break;

                case 'auto':
                    $aTmp['auto'] = t('Osobní automobil');
                    break;

                case 'truck':
                    $aTmp['truck'] = t('Nákladní automobil');
                    break;

                default:
                    watchdog('pp_order', 'Nenzamy typ prujezdu: %typ',
                        array('%typ' => $traffic),
                        WATCHDOG_WARNING
                    );
            }
        }
    }

    if (empty($aTmp)) {
        $aTmp[] = t('Neuvedeno');
    }

    $variables['prujezd'] = implode(',', $aTmp);

    // vytapeni
    switch ($variables['form']['heating']) {
        case 'yes':
            $sTmp = t('Ano');
            break;
        case 'no':
            $sTmp = t('Ne');
            break;
        case 'freez':
            $sTmp = t('Mrazírna');
            break;
        default:
            $sTmp = t('Neuvedeno');
    }

    $variables['vytapeni'] = $sTmp;

    // uchyceni
    switch ($variables['form']['attachment']) {
        case 'over':
            $sTmp = t('Nad otvor');
            break;
        case 'under':
            $sTmp = t('Do otvoru');
            break;
        case 'forward':
            $sTmp = t('Předsunuté');
            break;
        default:
            $sTmp = t('Neuvedeno');
    }

    $variables['uchyceni'] = $sTmp;

    // lista
    switch ($variables['form']['ledge']) {
        case 'basic':
            $sTmp = t('Pevná');
            break;
        case 'travers':
            $sTmp = t('Pojezdové');
            break;
        case 'forward':
            $sTmp = t('Předsunuté');
            break;
        case 'collapsible':
            $sTmp = t('Shrnovací');

        default:
            $sTmp = t('Neuvedena');
    }

    $variables['lista'] = $sTmp;

    if (isset($variables['price']['final_price'])) {
        $variables['cena_materialu'] = number_format($variables['price']['final_price'], 2, ',', ' ') . ' Kč';
    }
    if (isset($variables['price']['construction_price'])) {
        $variables['cena_montaze'] = number_format($variables['price']['construction_price'], 2, ',', ' ') . ' Kč';
    }
    if (isset($variables['price']['transfer_price'])) {
        $variables['cena_dopravy'] = number_format($variables['price']['transfer_price'], 2, ',', ' ') . ' Kč za km';
    }

    if (isset($variables['price']['final_price']) && isset($variables['price']['construction_price'])) {
        $variables['celkova_cena'] = number_format(
                $variables['price']['construction_price'] + $variables['price']['final_price'], 2, ',', ' '
            ) . ' Kč'
        ;
    }

    $variables['lamela_typ'] = isset($variables['price']['lamel_type'])
        ? _getLamelType($variables['price']['lamel_type'])
        : 'neurčen'
    ;

    $variables['lamela_prekryv'] = isset($variables['price']['lamel_cover'])
        ? _getLamelCover($variables['price']['lamel_cover'])
        : 'neurčen'
    ;

    if (isset($variables['price']['lamel_count'])) {
        $variables['pocet_lamel'] = number_format($variables['price']['lamel_count'], 0, ',', ' ');
    }

    _pp_order_prepare_base($variables);
}


/**
 * Poptavka kyvnych vrat
 * @param $variables
 */
function template_process_order_recap_doors(&$variables) {
    switch ($variables['form']['door_type']) {
        case 'single':
            $sTmp = t('Jednokřídlová');
            break;

        case 'double':
            $sTmp = t('Dvoukřídlová');
            break;

        default:
            $sTmp = t('Neuvedeno');

    }
    $variables['typ_dveri'] = $sTmp;

    switch ($variables['form']['frame']) {
        case 'stainless':
            $sTmp = t('Nerez');
            break;

        case 'galvanized':
            $sTmp = t('Pozink');
            break;

        case 'komaxit':
            $sTmp = t('Komaxit');
            break;

        default:
            $sTmp = t('Neuvedeno');

    }
    $variables['ram'] = $sTmp;

    switch ($variables['form']['fill']) {
        case '5mm':
            $sTmp = t('Síla 5mm');
            break;

        case '7mm':
            $sTmp = t('Síla 7mm');
            break;

        default:
            $sTmp = t('Neuvedeno');

    }
    $variables['vypln'] = $sTmp;

    _pp_order_prepare_base($variables);
}


function template_process_order_recap_other(&$variables) {
    _pp_order_prepare_base($variables);
}

/**
 * Spolecna data pro vsechny typy poptavek
 * @param $variables
 */
function _pp_order_prepare_base(&$variables) {
    $variables['vyska_otvor'] = _getAsCm($variables['form']['height']);
    $variables['sirka_otvor'] = _getAsCm($variables['form']['width']);

    $variables['kontaktni_osoba'] = check_plain($variables['form']['person']);
    $variables['spolecnost'] = check_plain($variables['form']['organization']);
    $variables['ulice'] = check_plain($variables['form']['street']);
    $variables['cp'] = check_plain($variables['form']['street_number']);
    $variables['psc'] = check_plain($variables['form']['zip']);
    $variables['mesto'] = check_plain($variables['form']['city']);
    $variables['email'] = check_plain($variables['form']['email']);
    $variables['telefon'] = check_plain($variables['form']['phone']);
    $variables['poznamka'] = empty($variables['form']['notes']) ? '---' : check_plain($variables['form']['notes']);

    $variables['email_obchod'] = variable_get('pp_order_email_poptavky', 'info@plasticport.cz');
    $variables['tel_obchod'] = variable_get('pp_order_tel_poptavky', '+420 731 566 609');
}


/**
 * Pomocna funkce pro formatovani rozmeru
 * @param int $size
 * @return string
 */
function _getAsCm($size) {
    return number_format($size, 0, ',', ' ') . ' cm';
}


/**
 * Pomocna funkce pro zobrazeni typu lamely
 * @param string $type
 * @return string
 */
function _getLamelType($type) {
    switch($type) {
        case '200':
            $r = '200/2';
            break;

        case '300':
            $r = '300/3';
            break;

        case '400':
            $r = '400/4';
            break;

        default:
            $r = 'neuvedeno';
    }

    return $r;
}


/**
 * Pomocna funkce pro zobrazeni prekryvu lamely
 * @param string $cover
 * @return string
 */
function _getLamelCover($cover) {
    if (ctype_digit($cover) && $cover < 100) {
        return $cover . '%';
    }
    else {
        //todo smazat watchdog
        watchdog('pp_order', 'Cover neuvedeno debug: %cover', array('%cover' => $cover));
        return 'neuvedeno';
    }
}
