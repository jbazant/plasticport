<?php
/**
 * Created by PhpStorm.
 * User: jiri.bazant
 * Date: 10.12.17
 * Time: 23:07
 *
 * @var array $fields
 */
?>
<div class="l-list__col">
    <div class="product-card__img"><?php print $fields['field_image']->content; ?></div>
    <a href="<?php print $fields['path']->content; ?>" class="product-card__content">
        <h3 class="heading--primary product-card__heading"><?php print $fields['field_short_title']->content; ?></h3>
        <p><?php print $fields['field_short']->content; ?></p>
    </a>
</div>
