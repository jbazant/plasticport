<section class="home-card">
  <div class="container">
    <?php foreach($items as $item): ?>
      <a href="<?php print $item['path'] ?>" class="home-card__col">
        <div class="home-card__wrap">
          <div class="home-card__top">
            <img
              srcset="<?php print $item['img'] ?> 2x"
              src="<?php print $item['img'] ?>"
              alt="Produkty: <?php print $item['title'] ?>"
              height="350"
            />
            <div class="home-card__inner">
              <h3 class="home-card__heading"><?php print $item['title']; ?></h3>
              <div class="home-card__swing-up">
                <?php foreach($item['description'] as $para): ?>
                <p><?php print $para; ?></p>
                <?php endforeach; ?>
              </div>
            </div>
          </div>
        </div>
      </a>
    <?php endforeach; ?>
  </div>
</section>
