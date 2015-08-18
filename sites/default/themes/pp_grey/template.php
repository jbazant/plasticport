<?php

function pp_grey_preprocess_page(&$vars) {
}

function pp_grey_theme() {
	return array(
		'pp_slideshow' => array(
			'template' => 'templates/pp_slideshow',
			'variables' => array(
				'items' => array(),
				'slideshow_class' => '',
			)
		)
	);
}