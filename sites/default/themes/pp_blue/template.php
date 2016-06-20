<?php
/**
 * Created by PhpStorm.
 * User: jiri.bazant
 * Date: 09.06.16
 * Time: 8:47
 */

/**
 * Breadcrumbs as unordered list
 */
function pp_blue_breadcrumb($variables) {
    $breadcrumb = $variables['breadcrumb'];

    $crumbs = '';

    if (!empty($breadcrumb)) {
        $crumbs = '<ul class="breadcrumbs">';

        foreach($breadcrumb as $value) {
            $crumbs .= '<li>'.$value.'</li>';
        }
        $crumbs .= '</ul>';
    }
    return $crumbs;
}

/**
 * Adds class to main menu links li tags
 * @param $variables
 */
function pp_blue_preprocess_links(&$variables)
{
    $newitems = array();
    if ($variables['theme_hook_original'] == 'links__system_main_menu') {
        foreach ($variables['links'] as $key => $item) {
            $newitems['nav__item ' . $key] = $item;
        }
        $variables['links'] = $newitems;
    }
}
