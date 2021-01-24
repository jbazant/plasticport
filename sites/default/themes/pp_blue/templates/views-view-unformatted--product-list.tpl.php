<?php
/**
 * Created by PhpStorm.
 * User: jiri.bazant
 * Date: 10.12.17
 * Time: 23:19
 */
?>
<section class="l-list">
    <div class="container">
        <?php if (!empty($title)): ?>
            <h2 class="heading--primary"><?php print $title; ?></h2>
        <?php endif; ?>
        <?php foreach ($rows as $id => $row): ?>
            <?php print $row; ?>
        <?php endforeach; ?>
    </div>
</section>

