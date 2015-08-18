<div class="slideshow <?php print $slideshow_class; ?>">
	<div class="slideshow_images">
		<?php 
			foreach($items as $key => $item) {
				$text = sprintf(
					'<span class="slideshow_heading">%s</span><br /><span class="slideshow_text">%s</span>',
					$item['heading'],
					$item['description']
				);
				
				print '<div class="slide-' . $key . '">' 
					. l($text, $item['target'], array('html' => TRUE,)) 
					. '</div>'
				;
			}
		?>
	</div>
	<div class="slideshow_links">
		<?php 
			foreach($items as $key => $item) {
				print '<a href="#">' . ($key + 1) . '</a>';
			}
		?>
	</div>
</div>