<?php $theme_path = drupal_get_path('theme', 'pp_blue'); ?>
<!DOCTYPE html>
<html lang="cs">
<head>
    <meta http-equiv="X-UA-Compatible" content="IE=Edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <?php print $styles; ?>
    <script>document.createElement("picture");</script>
</head>
<body>
<?php include($theme_path . '/templates/inc/header.php'); ?>
<main id="content">
    <div class="info-strip">
        <div class="info-strip__top">
            <div class="container">
                <h1 class="info-strip__heading">
                    <?php print $title; ?>
                </h1>
            </div>
        </div>
        <?php if ($breadcrumb): ?>
            <div class="info-strip__bottom">
                <div class="container"><?php print $breadcrumb; ?></div>
            </div>
        <?php endif; ?>
    </div>

    <?php if ($messages): ?>
        <div id="messages">
            <div class="section clearfix">
                <?php print $messages; ?>
            </div>
        </div>
    <?php endif; ?>

    <section class="l-maintenance"><?php print $content ?></section>
</main>
<?php include($theme_path . '/templates/inc/footer.php'); ?>
<?php print $scripts; ?>
</body>
</html>
