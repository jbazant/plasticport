<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h2><?php print $title; ?></h2>
<?php endif; ?>
<section class="home-card">
  <div class="container">
    <?php foreach ($rows as $id => $row) print $row; ?>
  </div>
</section>
