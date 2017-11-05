<?php
/**
 * Created by PhpStorm.
 * User: jiri.bazant
 * Date: 10.06.16
 * Time: 7:31
 */
?>
<header class="l-header">
    <div class="container">
        <a href="<?= url('/') ?>" class="logo"><span>Plastic Port</span></a>

        <?php if ($main_menu): ?>
        <nav class="nav">
            <div class="nav__helper">
                    <?php print theme('links__system_main_menu', array(
                        'links' => $main_menu,
                        'attributes' => array(
                            'id' => 'main-menu-links',
                            'class' => array('nav__list'),
                        ),
                        'heading' => array(
                            'text' => t('Main menu'),
                            'level' => 'h4',
                            'class' => array('element-invisible'),
                        ),
                    )); ?>
            </div>
            <div class="menu">
                <svg width="35" height="28" viewbox="0 0 23 17.5" class="icon">
                    <path fill="#00478d"
                          d="M0.8,2.5h21.3c0.5,0,0.8-0.6,0.8-1.2C23,0.6,22.6,0,22.2,0H0.8C0.4,0,0,0.6,0,1.3C0,1.9,0.4,2.5,0.8,2.5z"
                          class="menu__line menu__line--top"></path>
                    <path fill="#00478d"
                          d="M22.2,7.5H0.8C0.4,7.5,0,8.1,0,8.8C0,9.4,0.4,10,0.8,10h21.3c0.5,0,0.8-0.6,0.8-1.2C23,8.1,22.6,7.5,22.2,7.5z"
                          class="menu__line menu__line--middle"></path>
                    <path fill="#00478d"
                          d="M22.2,15H0.8C0.4,15,0,15.6,0,16.3c0,0.7,0.4,1.2,0.8,1.2h21.3c0.5,0,0.8-0.6,0.8-1.2C23,15.6,22.6,15,22.2,15z"
                          class="menu__line menu__line--bottom"></path>
                </svg>
            </div>
        </nav>
        <?php endif; ?>
    </div>
</header>
