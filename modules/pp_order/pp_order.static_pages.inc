<?php


/**
 * Stranka po prijeti poptavky, ktera nebyla automaticky
 * @return array
 */
function pp_order_done() {
    return array(
        '#type' => 'markup',
        '#markup' => '<p>' . t('Děkujeme za zaslání poptávky. Brzy Vás budeme kontaktovat.') . '</p>',
    );
}