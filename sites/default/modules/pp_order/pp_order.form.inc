<?php


/**
 * Creates order form
 * @param array $form
 * @param array $form_state
 * @return array
 */
function pp_order_form($form, $form_state)
{
    // js behaviour
    $form['#attached']['js'][] = drupal_get_path('module', 'pp_order') . '/pp_order.js';

    // sekce formulare
    $form['contact'] = _pp_order_contact_fieldset();
    $form['sizes'] = _pp_order_basic_fieldset($form, $form_state);

    $form['more'] = array(
        '#type' => 'markup',
    );

    $form['finish'] = _pp_order_finish_fieldset($form, $form_state);

    // more sekce specificteji
    // vyuziva se pri ajax lazy-loadingu
    if (isset($form_state['values']['order_type'])) {
        if ($form_state['values']['order_type'] == 'lamely') {
            $form['more'] = _pp_order_lamels_fieldset($form, $form_state);
        } elseif ($form_state['values']['order_type'] == 'kyvna') {
            $form['more'] = _pp_order_doors_fieldset($form, $form_state);
        }
    }

    $form['more']['#prefix'] = '<div id="more_info_wrapper">';
    $form['more']['#suffix'] = '</div>';

    // anti spam kontrola
    // vyuziva i js behaviouru
    $form['js_check'] = array(
        '#type' => 'textfield',
        '#title' => t('Anti spam kontrola'),
        '#default_value' => '',
        '#description' => t("Toto pole by mělo být vyplněno automaticky, ovšem pokud jej vidíte nevyplněné vložte do něj text 'Anti-spam kontrola'."),
        '#element_validate' => array('pp_order_element_validate_antispam'),
    );

    $form['#prefix'] = '<section class="l-order-form">';
    $form['#suffix'] = '</section>';
    // vratim kompletni formular
    return $form;
}


/**
 * Defines contact fieldset of order form
 * @return array
 */
function _pp_order_contact_fieldset()
{
    $fieldset = array(
        '#type' => 'fieldset',
        '#title' => t('Kontaktní údaje'),
    );

    $fieldset['organization'] = array(
        '#type' => 'textfield',
        '#title' => t('Název společnosti'),
    );

    $fieldset['person'] = array(
        '#type' => 'textfield',
        '#title' => t('Kontaktní osoba'),
        '#required' => TRUE,
    );

    $fieldset['street'] = array(
        '#type' => 'textfield',
        '#title' => t('Ulice'),
        '#required' => TRUE,
    );

    $fieldset['street_number'] = array(
        '#type' => 'textfield',
        '#title' => t('Číslo popisné'),
        '#required' => TRUE,
    );

    $fieldset['city'] = array(
        '#type' => 'textfield',
        '#title' => t('Město'),
        '#required' => TRUE,
    );

    $fieldset['zip'] = array(
        '#type' => 'textfield',
        '#title' => t('PSČ'),
        '#required' => TRUE,
        '#element_validate' => array('pp_order_element_validate_zip'),
    );

    $fieldset['email'] = array(
        '#type' => 'textfield',
        '#title' => t('E-mail'),
        '#required' => TRUE,
        '#element_validate' => array('pp_order_element_validate_email'),
    );

    $fieldset['phone'] = array(
        '#type' => 'textfield',
        '#title' => t('Telefon'),
        '#required' => TRUE,
        //'#element_validate' => array('pp_order_element_validate_zip'),
    );

    return $fieldset;
}


/**
 *
 * @return array
 */
function _pp_order_basic_fieldset()
{
    $order_type_options = array(
        'kyvna' => t('Kyvná vrata'),
        'lamely' => t('Lamelová clona'),
        'jine' => t('Jiné'),
    );

    $fieldset = array(
        '#type' => 'fieldset',
        '#title' => t('Základní specifikace'),
    );

    // typ prujezdu
    $fieldset['order_type'] = array(
        '#type' => 'radios',
        '#options' => $order_type_options,
        '#title' => t('Typ přehrazení'),
        '#suffix' => '<div class="clearfix"></div>',
        '#required' => TRUE,
        '#ajax' => array(
            'callback' => 'pp_order_form_more_ajax_callback',
            'wrapper' => 'more_info_wrapper',
            'method' => 'replace',
        ),
    );

    // Rozmery otvoru
    $fieldset['height'] = array(
        '#type' => 'textfield',
        '#title' => t('Výška otvoru [cm]'),
        '#required' => TRUE,
        '#element_validate' => array('pp_order_element_validate_size'),
    );

    $fieldset['width'] = array(
        '#type' => 'textfield',
        '#title' => t('Šířka otvoru [cm]'),
        '#required' => TRUE,
        '#element_validate' => array('pp_order_element_validate_size'),
    );

    return $fieldset;
}


/**
 *
 * @return array
 */
function _pp_order_doors_fieldset()
{
    $fieldset = array(
        '#type' => 'fieldset',
        '#title' => t('Kyvná vrata - detail'),
    );

    $fieldset['door_type'] = array(
        '#type' => 'radios',
        '#options' => array(
            'single' => t('Jednokřídlová'),
            'double' => t('Dvoukřídlová'),
        ),
        '#title' => t('Typ dveří'),
        '#required' => TRUE
    );

    $fieldset['frame'] = array(
        '#type' => 'radios',
        '#options' => array(
            'stainless' => t('Nerez'),
            'galvanized' => t('Pozink'),
            'komaxit' => t('Komaxit'),
        ),
        '#title' => t('Rám'),
        '#required' => TRUE
    );

    $fieldset['fill'] = array(
        '#type' => 'radios',
        '#options' => array(
            '5mm' => t('Síla 5mm'),
            '7mm' => t('Síla 7mm'),
        ),
        '#title' => t('Výplň'),
        '#required' => TRUE
    );

    return $fieldset;
}


/**
 *
 * @return array
 */
function _pp_order_lamels_fieldset()
{
    $fieldset = array(
        '#type' => 'fieldset',
        '#title' => t('Lamelové clony - detail'),
        '#collapsible' => FALSE,
        '#collapsed' => FALSE,
    );

    $fieldset['position'] = array(
        '#type' => 'radios',
        '#options' => array(
            'exterier' => t('Exteriér / Interiér'),
            'interier' => t('Interiér / Interiér'),
        ),
        '#title' => t('Umístění otvoru'),
        '#required' => TRUE
    );

    $fieldset['draft'] = array(
        '#type' => 'radios',
        '#options' => array(
            'none' => t('Není'),
            'low' => t('Mírný'),
            'high' => t('Velký'),
        ),
        '#title' => t('Průvan'),
        '#required' => TRUE
    );

    $fieldset['traffic'] = array(
        '#type' => 'checkboxes',
        '#options' => array(
            'ppl' => t('Osoby'),
            'pallet' => t('Paletový vozík'),
            'forklifts' => t('Vysokozdvižný vozík'),
            'auto' => t('Osobní automobil'),
            'truck' => t('Nákladní automobil'),
        ),
        '#title' => t('Průjezd'),
        '#required' => TRUE
    );

    $fieldset['heating'] = array(
        '#type' => 'radios',
        '#options' => array(
            'yes' => t('Ano'),
            'no' => t('Ne'),
            'freez' => t('Mrazírna'),
        ),
        '#title' => t('Vytápění'),
        '#required' => TRUE
    );

    $fieldset['attachment'] = array(
        '#type' => 'radios',
        '#options' => array(
            'under'   => t('Do otvoru'),
            'over'    => t('Nad otvor'),
            'forward' => t('Předsunuté'),
        ),
        '#title' => t('Uchycení'),
        '#required' => TRUE
    );

    $fieldset['ledge'] = array (
        '#type' => 'radios',
        '#options' => array(
            'basic'       => t('Pevná'),
            'travers'     => t('Pojezdová'),
            'collapsible' => t('Shrnovací'),
        ),
        '#title' => t('Lišta'),
        '#required' => TRUE,
    );

    // obrazky s nahledy zaveseni
    $images_path = drupal_get_path('module', 'pp_order') . '/images/';

    $fieldset['att-over'] = array(
        '#markup' => theme('image', array(
            'path' => $images_path,
            'attributes' => array(
                'id' => 'img-attachment-preview-over',
                'class' => 'img-attachment-preview',
            ),
            'title' => t('Schéma: Uchycení nad otvor'),
            'alt' => '',
        )),
    );

    $fieldset['att-under'] = array(
        '#markup' => theme('image', array(
            'path' => $images_path,
            'attributes' => array(
                'id' => 'img-attachment-preview-under',
                'class' => 'img-attachment-preview',
            ),
            'title' => t('Schéma: Uchycení do otvoru'),
            'alt' => '',
        )),
    );

    $fieldset['att-forward'] = array(
        '#markup' => theme('image', array(
            'path' => $images_path,
            'attributes' => array(
                'id' => 'img-attachment-preview-forward',
                'class' => 'img-attachment-preview',
            ),
            'title' => t('Schéma: Uchycení předsunuté'),
            'alt' => '',
        )),
    );

    return $fieldset;
}


/**
 *
 * @return array
 */
function _pp_order_finish_fieldset()
{
    $fieldset = array(
        '#type' => 'fieldset',
        '#title' => t('Dokončení poptávky'),
    );

    $fieldset['notes'] = array(
        '#type' => 'textarea',
        '#title' => t('Poznámky'),
    );

    $fieldset['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Odeslat'),
        '#prefix' => '<div class="form-actions">',
        '#suffix' => '</div>',
    );

    return $fieldset;
}


/**
 * Ajax callback pro zobrazeni fieldsetu s upresnenim parametru
 * @param array $form
 * @param array $form_state
 */
function pp_order_form_more_ajax_callback($form, $form_state)
{
    return $form['more'];
}


/**
 * Implements form_validate
 * @param array $form
 * @param array $form_state
 */
function pp_order_form_validate($form, &$form_state) {
    // validace
    // jedine, co snad jeste musim validovat je kombinace zaveseni / lista
    // vse ostatni by jiz melo byt validovano kontrolami primo u elementu
    if (
           'lamely' == $form_state['values']['order_type']
        && 'over' == $form_state['values']['attachment']
        && 'collapsible' == $form_state['values']['ledge']
    ) {
        form_set_error(
            'ledge',
            t('Při zavěšení nad otvor nelze použít shrnovací lištu.')
        );
    }
}


/**
 * Implements form_submit
 * @param array $form
 * @param array $form_state
 */
function pp_order_form_submit($form, &$form_state) {
    // pokud je to lamela
    if ('lamely' == $form_state['values']['order_type']) {
        // pokud je to do otvoru nebo nad otvor
        if (
            'basic' == $form_state['values']['ledge']
            && in_array($form_state['values']['attachment'], array('over', 'under'))
        ) {
            try {
                $counted_data = _pp_order_count_lamels_data_v1(
                    $form_state['values']['height'],
                    $form_state['values']['width'],
                    $form_state['values']['attachment'],
                    $form_state['values']['heating']
                );

                $is_valid = $counted_data['is_valid'];
            }
            catch (Exception $e) {
                watchdog('pp_order', 'Zachycena vyjimka: %m',
                    array('%m' => $e->getMessage()),
                    WATCHDOG_WARNING
                );
                $is_valid = FALSE;
            }
        }
        elseif (
               'travers' == $form_state['values']['ledge'] && 400 < $form_state['values']['height']
            || 'collapsible' == $form_state['values']['ledge'] && 350 < $form_state['values']['height']
        ) {
            // moc vysoke, nepocitam cenu
            $is_valid = FALSE;
        }
        else {
            try {
                $counted_data = _pp_order_count_lamels_data_v2(
                    $form_state['values']['height'],
                    $form_state['values']['width'],
                    $form_state['values']['attachment'],
                    $form_state['values']['ledge'],
                    $form_state['values']['heating']
                );
                $is_valid = $counted_data['is_valid'];
            }
            catch (Exception $e) {
                watchdog('pp_order', 'Zachycena vyjimka: %m',
                    array('%m' => $e->getMessage()),
                    WATCHDOG_WARNING
                );
                $is_valid = FALSE;
            }
        }

        // pokud jsem se nedopocital k validni cene, tak vsechen vypocet zahazuji
        if (!$is_valid) {
            watchdog('pp_order', 'Nepovedlo se určit cenu pro data: %data',
                array('%data' => json_encode($form_state['values'])),
                WATCHDOG_WARNING
            );

            $counted_data = array(
                'is_valid' => FALSE,
            );
        }

        $counted_data['construction_price'] = _pp_order_count_construction_price(
            $counted_data['counted_height'],
            $counted_data['counted_width']
        );

        $counted_data['transfer_price'] = variable_get('pp_order_doprava', 10);

        if (empty($counted_data['construction_price'])) {
            $counted_data['is_valid'] = FALSE;
        }
        
        $template_data = array(
            'form' => $form_state['values'],
            'price' => $counted_data,
        );
        watchdog ('pp_order', 'Data:' . json_encode($template_data));

        _pp_order_lamel_order_process($template_data, $counted_data['is_valid']);

        watchdog('pp_order', 'Lamela typu %typ. Data: %data', array(
            '%data' => json_encode($template_data),
            '%typ'  => $form_state['values']['attachment'],
        ));
    }

    // zpracovani kyvnych vrat
    elseif ('kyvna' == $form_state['values']['order_type']) {
        _pp_order_doors_order_process(array('form' => $form_state['values']));
    }

    // zpracovani ostatnich poptavek
    elseif ('jine' == $form_state['values']['order_type']) {
        _pp_order_other_order_process(array('form' => $form_state['values']));
    }

    else {
        watchdog('pp_order', 'Neznamy typ poptavky: %typ', array(
            '%typ' => $form_state['values']['order_type'],
        ));
        $form_state['redirect'] = 'poptavka/chyba';

        return;
    }

    $form_state['redirect'] = 'poptavka/podekovani';
}


/**
 * sestavi string z vybranych voleb prujezdu
 *
 * @param $form
 * @param $form_state
 *
 * @return string human readable polozky oddelene carkou
 */
function pp_order_traffic_string($form, $form_state)
{
    $out = array();

    foreach ($form_state['values']['traffic'] as $key => $value) {
        if ('0' != $value) {
            $out[] = $form['more']['traffic']['#options'][$value];
        }
    }

    return implode(', ', $out);
}



/**
 * Vypocet ceny pro lamely do otvoru a nad otvor
 * @param int $height
 * @param int $width
 * @param string $type
 * @param string $heating
 * @return array
 */
function _pp_order_count_lamels_data_v1($height, $width, $type, $heating)
{
    // pokud je to nad otvor musim pripocist nadsazeni listy
    $real_height = _pp_order_get_real_height($height, $type);

    // pokusim se najit lamelu podle vysky
    list($lamel_type, $lamel_cover) = _pp_order_get_lamel_type_by_height($real_height);

    // zjistim pocet lamel
    list($lamel_count, $real_width) = _pp_order_get_lamels_count($lamel_type, $lamel_cover, $width, $type);

    // spocitam potrebnou delku lamely
    $lamel_lenght_total = $real_height * $lamel_count;

    // zjistim cenu lamely a vypocitam koncovou cenu
    $const_name = 'pp_order_v1_lamela_' . $lamel_type;
    if ('freez' == $heating) {
        $const_name .= '_mrazirenska';
    }

    $lamel_price = $lamel_lenght_total * variable_get($const_name, 0) / 100;
    $ledge_price = variable_get('pp_order_lista_zaklad') * $real_width / 100;

    $final_price = $lamel_price + $ledge_price;

    return array(
        'counted_height' => $real_height,
        'counted_width' => $real_width,
        'lamel_type' => $lamel_type,
        'lamel_cover' => $lamel_cover,
        'lamel_price' => $lamel_price,
        'ledge_price' => $ledge_price,
        'final_price' => ceil($final_price / 10) * 10,
        'is_valid' => $lamel_price > 0 && $ledge_price > 0,
        'lamel_count' => $lamel_count,
    );
}


/**
 * Vypocet ceny pro lamely pojezdove a predsunute
 *
 * @param int $height
 * @param int $width
 * @param string $type
 * @param string $ledge
 * @param string $heating
 * @return array
 * @throws Exception
 */
function _pp_order_count_lamels_data_v2($height, $width, $type, $ledge, $heating) {
    // pokud je to nad otvor musim pripocist nadsazeni listy
    $real_height = _pp_order_get_real_height($height, $type);

    // pokusim se najit lamelu podle vysky
    list($lamel_type, $lamel_cover) = _pp_order_get_lamel_type_by_height($real_height, TRUE);

    $real_width = _pp_order_get_real_width($width, $type, $lamel_type);

    // spocitam obsah otvoru (lamely) v m2
    $m2 = $real_height * $real_width / 10000;

    // zjistim cenu lamely a vypocitam koncovou cenu
    $price_per_m2 = variable_get(sprintf('pp_order_v2_lamely_%s_%s', $lamel_type, $lamel_cover));
    if ('freez' == $heating) {
        $price_per_m2 *= variable_get('pp_order_v2_lamely_mrazirenske');
    }

    if ($m2 < 10) {
        $marze = variable_get('pp_order_v2_marze_male');
    }
    else {
        $marze = variable_get('pp_order_v2_marze_velke');
    }
    $lamel_price = $price_per_m2 * $m2 * $marze;

    // zjistim cenu listy
    $ledge_width = ('under' == $type) ? $width / 100.0 : $width / 100.0 + 0.2;

    switch($ledge) {
        case 'basic':
            // sem bych se mel dostat pouze pro predsunutou pevnou listu
            // vsechny ostatni pripady pevne listy resi v1 varianta
            $ledge_price = 0;
            break;

        case 'travers':
            $ledge_price = variable_get('pp_order_lista_posuvna') * $ledge_width;

            break;

        case 'collapsible':
            $ledge_price = variable_get('pp_order_lista_shrnovaci') * $ledge_width;
            break;

        default:
            throw new Exception('Unknown lamel type: ' . $type);
    }

    // pokud se jedna o predsunutou listu, musim jeste pripocist predsazeni
    // a cenu stojny
    if ('forward' == $type) {
        if ('travers' == $ledge) {
            // pokud je posuvna, tak mam 3 nohy
            $stojna_price = variable_get('pp_order_predsunuta_stojna') * ($real_height / 100) * 3;
        } else {
            // 2 krat vyska lamely v metrech (tzn / 50)
            $stojna_price = variable_get('pp_order_predsunuta_stojna') *  $real_height / 50;
        }
    }
    else {
        $stojna_price = 0;
    }

    $final_price = $lamel_price + $ledge_price + $stojna_price;

    // vratim vypocteny vysledek
    return array(
        'counted_height' => $real_height,
        'counted_width' => $real_width,
        'lamel_type' => $lamel_type,
        'lamel_cover' => $lamel_cover,
        'lamel_price' => $lamel_price,
        'ledge_price' => $ledge_price,
        'stojna_price' => $stojna_price,
        'final_price' => ceil($final_price / 10) * 10,
        'is_valid' => ($lamel_price > 0 && $ledge_price > 0)
            || ('basic' == $ledge && 0 < $lamel_price && 0 == $ledge_price),
    );
}


/**
 * Vraci kolik lamel je potreba na danou sirku
 * @param string $type typ lamely
 * @param string $cover kryti lamely
 * @param integer $width sirka otvoru
 * @return integer
 */
function _pp_order_get_lamels_count($type, $cover, $width, $t) {
    switch ($type . '_' . $cover) {
        case '200_00':
            $base = 20;
            $per_piece = 20.0;
            break;

        case '200_50':
            $base = 20;
            $per_piece = 15.0;
            break;

        case '300_35':
            $base = 30;
            $per_piece = 25.0;
            break;

        case '300_65':
            $base = 30;
            $per_piece = 20.0;
            break;

        case '400_35':
            $base = 30;
            $per_piece = 35.0;
            break;

        case '400_50':
            $base = 30;
            $per_piece = 30.0;
            break;

        default:
            throw new Exception('Neznamy typ lamely a prekryvu ' . $type . '_' . $cover);
    }

    $lamel_count = (int)(ceil(($width - $base) / $per_piece) + 1);
    $real_width = 'under' == $type ? ($per_piece * ($lamel_count - 1) + $base) : $width;

    return array($lamel_count, $real_width);
}


/**
 * Vraci typ pouzite lamely na zaklade vysky
 * @param int $height
 * @param bool $always_50 pokud true, pak je kryti vzdy 50%
 * @return string
 */
function _pp_order_get_lamel_type_by_height($height, $always_50 = FALSE) {
    if ($height <= 260) {
        $type = '200';

        if ($always_50) {
            $cover = '50';
        }
        elseif ($height <= 100) {
            $cover = '00';
        }
        else {
            $cover = '50';
        }
    }

    elseif ($height <= 360) {
        $type = '300';

        if ($always_50) {
            $cover = '50';
        }
        elseif ($height <= 290) {
            $cover = '35';
        }
        else {
            $cover = '65';
        }
    }

    elseif ($height <= 540) {
        $type = '400';

        if ($always_50) {
            $cover = '50';
        }
        elseif ($height <= 390) {
            $cover = '35';
        }
        else {
            $cover = '50';
        }
    }
    else {
        $type = 'unknown';
        $cover = 'unknown';
    }

    return array($type, $cover);
}


/**
 * Vraci vypoctenou vysku lamely (v zavislosti na zaveseni
 * @param $height
 * @param $type
 * @return int
 * @throws Exception
 */
function _pp_order_get_real_height($height, $type) {
    $real_height = $height;
    if ('under' == $type) {
        //do nothing
    }
    else {
        if ($height <= 255) {
            $real_height += 5;
        }
        elseif ($height <= 350) {
            $real_height += 10;
        }
        elseif ($height <= 525) {
            $real_height += 15;
        }
        else {
            throw new Exception ('Prilis vysoka lamela');
        }
    }

    return $real_height;
}


/**
 * Vypocet sirky clony
 * @param int $width sirka clony v cm
 * @param string $type typ zaveseni
 * @param string $lamel_type typ lamely
 * @return int
 */
function _pp_order_get_real_width($width, $type, $lamel_type) {
    switch ($type) {
        case 'over':
            return $width + 20;

        case 'forward':
            return $width + _pp_order_get_forward_size($lamel_type) + 20;

        default:
            return $width;
    }
}


/**
 * Vraci velikost predsazeni v cm na zaklade typu pouzite lamely
 * @param string $lamel_type
 * @return int
 */
function _pp_order_get_forward_size($lamel_type) {
    return '400' == $lamel_type
        ?  80 // 2 x 40 cm
        :  60 // 2 x 30 cm
    ;
}


/**
 * Validate zip value
 * @param array $element
 * @param array $form_state
 */
function pp_order_element_validate_zip($element, &$form_state)
{
    if ($element['#value'] !== '') {
        $filtered_value = str_replace(' ', '', $element['#value']);

        if (!preg_match('/^[0-9]{5}$/', $filtered_value)) {
            form_error($element, t('Pole %name není platné PSČ.', array('%name' => $element['#title'])));
        }
    }
}


/**
 * Validate email value
 * @param array $element
 * @param array $form_state
 */
function pp_order_element_validate_email($element, &$form_state)
{
    if ($element['#value'] !== '') {
        if (!valid_email_address($element['#value'])) {
            form_error($element, t('Pole %name není platný email.', array('%name' => $element['#title'])));
        }
    }
}

/**
 * Validate antispam field
 * @param array $element
 * @param array $form_state
 */
function pp_order_element_validate_antispam($element, &$form_state)
{
    if ('Anti-spam kontrola' != $element['#value']) {
        form_error($element, t('Pro odeslání formuláře musíte mít puštěný JavaScript, nebo vyplnit "Anti-spam kontrola" do pole "Anti spam kontrola".'));
    }
}


/**
 * Validace rozmeru otvoru
 * @param array $element
 * @param array $form_state
 */
function pp_order_element_validate_size($element, &$form_state) {
    if ($element['#value'] !== '') {
        if (!ctype_digit($element['#value'])) {
            form_error($element, t('Pole %name musí být rozměr v celých centimetrech.', array('%name' => $element['#title'])));
        }
        elseif ($element['#value'] < 10) {
            form_error(
                $element,
                t(
                    'Hodnota pole %name je příliš malá. Minimální velikost je 10cm.',
                    array('%name' => $element['#title'])
                ))
            ;
        }
        elseif ($element['#value'] > 100000) {
            form_error(
                $element,
                t(
                    'Hodnota pole %name je příliš velká.',
                    array('%name' => $element['#title'])
                ))
            ;
        }
    }
}

/**
 * Funkce pro odeslani a zalozeni poptavky lamely s vypocetenou i nevypoctenou cenou
 * @param array $template_data
 * @param bool $informCustomer
 */
function _pp_order_lamel_order_process($template_data, $informCustomer = FALSE) {
    $template_data['type'] = 'new_order';
    $template_data['inform_customer'] = $informCustomer;

    // hotfix
    if (!array_key_exists('final_price', $template_data['price'])) {
        $template_data['price']['final_price'] = NULL;
    }

    $intra_name = _pp_order_get_email_subject(
        'lamely',
        $template_data['form']['organization'],
        $template_data['form']['person'],
        $template_data['price']['final_price']
    );

    // ulozim poptavku jako novy node
    _pp_order_save_htmlmail_as_node(
        theme('order_recap_lamels', $template_data),
        $intra_name
    );

    // poslu poptavku emailem na obchod
    drupal_mail(
        'pp_order',
        'poptavka_lamela_nova',
        variable_get('pp_order_email_poptavky', 'info@plasticport.cz'),
        language_default(),
        array(
            'body_data' => $template_data,
            'email_subject' => $intra_name,
        )
    );

    // pouze pokud se jedna o nabidku, ktera byla spoctena
    // TODO zatim rucne vypnuto, pri pusteni zmenit text generovany v tpl s infem o "neodeslani" nabidky
    if (FALSE && $informCustomer) {
        // poslu poptavku emailem zakaznikovi
        // todo tohle by bylo idealni poslat az za pul hodiny
        $template_data['type'] = 'recap';
        drupal_mail(
            'pp_order',
            'poptavka_lamela_rekapitulace',
            $template_data['form']['email'],
            language_default(),
            array(
                'body_data' => $template_data,
                'email_subject' => 'Plasticport.cz - cenová nabídka',
            )
        );
    }
}


/**
 * Funkce pro odeslani poptavky kyvnych vrat na obchod a zalozeni node
 * @param array $template_data
 */
function _pp_order_doors_order_process($template_data) {
    $intra_name = _pp_order_get_email_subject(
        'kyvná vrata',
        $template_data['form']['organization'],
        $template_data['form']['person']
    );

    // ulozim poptavku jako novy node
    _pp_order_save_htmlmail_as_node(
        theme('order_recap_doors', $template_data),
        $intra_name
    );

    // poslu poptavku emailem na obchod
    drupal_mail(
        'pp_order',
        'poptavka_kyvna_nova',
        variable_get('pp_order_email_poptavky', 'info@plasticport.cz'),
        language_default(),
        array(
            'body_data' => $template_data,
            'email_subject' => $intra_name,
        )
    );
}


/**
 * Funkce pro odeslani poptavky "jine" na obchod a zalozeni node
 * @param array $template_data
 */
function _pp_order_other_order_process($template_data) {
    $intra_name = _pp_order_get_email_subject(
        '"jiné"',
        $template_data['form']['organization'],
        $template_data['form']['person']
    );

    // ulozim poptavku jako novy node
    _pp_order_save_htmlmail_as_node(
        theme('order_recap_other', $template_data),
        $intra_name
    );

    // poslu poptavku emailem na obchod
    drupal_mail(
        'pp_order',
        'poptavka_jine_nova',
        variable_get('pp_order_email_poptavky', 'info@plasticport.cz'),
        language_default(),
        array(
            'body_data' => $template_data,
            'email_subject' => $intra_name,
        )
    );
}


/**
 * Vraci vysledky testu vypoctu cen lamel
 */
function pp_order_test_form() {
    $ret = array();
    $width = 300;
    $height = 200;

    $vyhrivani = array('no', 'freez');

    foreach ($vyhrivani as $v) {
        $zaveseni = array('over', 'under');
        foreach ($zaveseni as $typ) {
            $ret[] = array(
                '#prefix' => '<p>',
                '#suffix' => '</p>',
                '#markup' => sprintf(
                    'Metoda 1 Výška: %d Šířka: %d Zavěšení: %s Lišta: pevná, Vyhřívání: %s',
                    $height,
                    $width,
                    $typ,
                    $v
                ),
            );
            $ret[] = array(
                '#prefix' => '<pre>',
                '#suffix' => '</pre>',
                '#markup' => print_r(_pp_order_count_lamels_data_v1(200, $width, $typ, $v), TRUE),
            );
        }

        $zaveseni = array('over', 'under', 'forward');
        foreach ($zaveseni as $typ) {
            _pp_order_test_v2_helper($typ, 'travers', $ret, $v);
        }

        $zaveseni = array('over', 'forward');
        foreach ($zaveseni as $typ) {
            _pp_order_test_v2_helper($typ, 'collapsible', $ret, $v);
        }

        _pp_order_test_v2_helper('forward', 'basic', $ret, $v);
    }

    return $ret;
}


function _pp_order_test_v2_helper($zaveseni, $lista, &$ret, $heating) {
    $width = 300;
    $height = 200;

    $ret[] = array(
        '#prefix' => '<p>',
        '#suffix' => '</p>',
        '#markup' => sprintf(
            'Metoda 2 Výška: %d Šířka: %d Zavěšení: %s Lišta: %s',
            $height,
            $width,
            $zaveseni,
            $lista
        ),
    );
    $ret[] = array(
        '#prefix' => '<pre>',
        '#suffix' => '</pre>',
        '#markup' => print_r(_pp_order_count_lamels_data_v2($height, $width, $zaveseni, $lista, $heating), TRUE),
    );
}


function _pp_order_count_construction_price($height, $width) {
    $ret = NULL;
    if(isset($width) && isset($height)) {
        $lamel_size = $width * $height;

        if ($lamel_size <= 50000) { // < 5m2
            $ret = variable_get('pp_order_montaz_pod_5m', 2490);
        }
        elseif ($lamel_size <= 180000) { // < 18m2
            $ret = variable_get('pp_order_montaz_nad_5m', 3490);
        }
    }

    return $ret;
}