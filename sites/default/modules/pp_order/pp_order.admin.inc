<?php
/**
 * @file Administracni stranky - nastaveni cen komponent a marze.
 */

/**
 * Admin form pro nastaveni lamel se zavesem do otvoru a nad otvor
 * @param array $form
 * @param array $form_state
 * @return array
 */
function pp_order_admin_do_otvoru($form, $form_state) {
    $form['standard'] = array(
        '#type' => 'fieldset',
        '#title' => t('Lamely standardní'),
        '#collapsible' => TRUE,
    );

    $form['standard']['pp_order_v1_lamela_200'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena lamely 200/2'),
        '#default_value' => variable_get('pp_order_v1_lamela_200'),
        '#description' => t('Cena jednoho běžného metru lamely 200/2. [Kč/m]'),
    );

    $form['standard']['pp_order_v1_lamela_300'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena lamely 300/3'),
        '#default_value' => variable_get('pp_order_v1_lamela_300'),
        '#description' => t('Cena jednoho běžného metru lamely 300/3. [Kč/m]'),
    );

    $form['standard']['pp_order_v1_lamela_400'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena lamely 400/4'),
        '#default_value' => variable_get('pp_order_v1_lamela_400'),
        '#description' => t('Cena jednoho běžného metru lamely 400/4. [Kč/m]'),
    );

    $form['mrazirenske'] = array(
        '#type' => 'fieldset',
        '#title' => t('Lamely mrazírenské'),
        '#collapsible' => TRUE,
    );

    $form['mrazirenske']['pp_order_v1_lamela_200_mrazirenska'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena lamely 200/2'),
        '#default_value' => variable_get('pp_order_v1_lamela_200_mrazirenska'),
        '#description' => t('Cena jednoho běžného metru mrazírenské lamely 200/2. [Kč/m]'),
    );

    $form['mrazirenske']['pp_order_v1_lamela_300_mrazirenska'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena lamely 300/3'),
        '#default_value' => variable_get('pp_order_v1_lamela_300_mrazirenska'),
        '#description' => t('Cena jednoho běžného metru mrazírenské lamely 300/3. [Kč/m]'),
    );

    $form['mrazirenske']['pp_order_v1_lamela_400_mrazirenska'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena lamely 400/4'),
        '#default_value' => variable_get('pp_order_v1_lamela_400_mrazirenska'),
        '#description' => t('Cena jednoho běžného metru mrazírenské lamely 400/4. [Kč/m]'),
    );

    return system_settings_form($form);
}

/**
 * Admin form pro nastaveni cen lamel pro predsunute, posuvne a shrnovaci lamely.
 * Take provadi nastaveni marze
 * @param array $form
 * @param array $form_state
 * @return array mixed
 */
function pp_order_admin_predsunute($form, $form_state) {
    $form['lamely'] = array(
        '#type' => 'fieldset',
        '#title' => t('Ceny lamel'),
        '#collapsible' => TRUE,
    );
    $form['lamely']['pp_order_v2_lamely_200_50'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena lamely 200/2'),
        '#default_value' => variable_get('pp_order_v2_lamely_200_50'),
        '#description' => t('Cena jednoho metru čtverečního lamely 200/2 při krytí 50%. [Kč/m<sup>2</sup>]'),
    );

    $form['lamely']['pp_order_v2_lamely_300_50'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena lamely 300/3'),
        '#default_value' => variable_get('pp_order_v2_lamely_300_50'),
        '#description' => t('Cena jednoho metru čtverečního lamely 300/3 při krytí 50%. [Kč/m<sup>2</sup>]'),
    );

    $form['lamely']['pp_order_v2_lamely_400_50'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena lamely 400/4'),
        '#default_value' => variable_get('pp_order_v2_lamely_400_50'),
        '#description' => t('Cena jednoho metru čtverečního lamely 400/4 při krytí 50%. [Kč/m<sup>2</sup>]'),
    );

    $form['mrazirenske'] = array(
        '#type' => 'fieldset',
        '#title' => t('Lamely mrazírenské'),
        '#collapsible' => TRUE,
    );

    $form['mrazirenske']['pp_order_v2_lamely_mrazirenske'] = array(
        '#type' => 'textfield',
        '#title' => t('Koeficient pro mrazírenské clony'),
        '#default_value' => variable_get('pp_order_v2_lamely_mrazirenske'),
        '#description' => t('Koeficient pro výpočet ceny mrazírenského provedení clony.'),
    );

    $form['marze'] = array(
        '#type' => 'fieldset',
        '#title' => t('Marže'),
        '#collapsible' => TRUE,
    );

    $form['marze']['pp_order_v2_marze_male'] = array(
        '#type' => 'textfield',
        '#title' => t('Marže do 10m<sup>2</sup>'),
        '#default_value' => variable_get('pp_order_v2_marze_male'),
        '#description' => t('Koeficient pro výpočet koncové ceny pro objednávky do 10m<sup>2</sup>.'),
    );

    $form['marze']['pp_order_v2_marze_velke'] = array(
        '#type' => 'textfield',
        '#title' => t('Marže nad 10m<sup>2</sup>'),
        '#default_value' => variable_get('pp_order_v2_marze_velke'),
        '#description' => t('Koeficient pro výpočet koncové ceny pro objednávky nad 10m<sup>2</sup> (včetně).'),
    );

    return system_settings_form($form);
}


/**
 * Admin form pro nastaveni cen zaveseni a stojne
 * @param array $form
 * @param array $form_state
 * @return array mixed
 */
function pp_order_admin_listy($form, $form_state) {
    $form['pp_order_lista_zaklad'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena závěsné lišty'),
        '#default_value' => variable_get('pp_order_lista_zaklad'),
        '#description' => t('Cena jednoho běžného metru závěsné lišty. [Kč/m]'),
    );

    $form['pp_order_lista_posuvna'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena posuvné lišty'),
        '#default_value' => variable_get('pp_order_lista_posuvna'),
        '#description' => t('Cena jednoho běžného metru posuvné lišty. [Kč/m]'),
    );

    $form['pp_order_lista_shrnovaci'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena shrnovací lišty'),
        '#default_value' => variable_get('pp_order_lista_shrnovaci'),
        '#description' => t('Cena jednoho běžného metru shrnovací lišty. [Kč/m]'),
    );

    $form['pp_order_predsunuta_stojna'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena stojné'),
        '#default_value' => variable_get('pp_order_predsunuta_stojna'),
        '#description' => t('Cena jednoho běžného metru stojné. [Kč/m]'),
    );

    return system_settings_form($form);
}


function pp_order_admin_montaz($form, $form_state) {
    $form['pp_order_montaz_pod_5m'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena montáže do 5m<sup>2</sup>'),
        '#default_value' => variable_get('pp_order_montaz_pod_5m', 2490),
        '#description' => t('Cena montáže pro lamely menší než 5m<sup>2</sup> (včetně) v Kč.'),
    );

    $form['pp_order_montaz_nad_5m'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena montáže nad 5m<sup>2</sup>'),
        '#default_value' => variable_get('pp_order_montaz_nad_5m', 3490),
        '#description' => t('Cena montáže pro lamely větší než 5m<sup>2</sup> v Kč.'),
    );

    $form['pp_order_doprava'] = array(
        '#type' => 'textfield',
        '#title' => t('Cena dopravy'),
        '#default_value' => variable_get('pp_order_doprava', 10),
        '#description' => t('Cena dopravy v Kč za 1 km.'),
    );

    return system_settings_form($form);
}


function pp_order_admin_obecne($form, $form_state) {
    $form['pp_order_email_poptavky'] = array(
        '#type' => 'textfield',
        '#title' => t('Email pro poptávky'),
        '#default_value' => variable_get('pp_order_email_poptavky', 'info@plasticport.cz'),
        '#description' => t('Email, na který a z kterého jsou zasílány nové poptávky.'),
    );

    $form['pp_order_tel_poptavky'] = array(
        '#type' => 'textfield',
        '#title' => t('Telefon pro poptávky'),
        '#default_value' => variable_get('pp_order_tel_poptavky', '+420 731 566 609'),
        '#description' => t('Telefon, který je zasílán jako kontakt v rámci poptávky.'),
    );

    return system_settings_form($form);
}