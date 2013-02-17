<div id="sticky-wrapper">
  <div id="header-wrapper" class="l-container-wide clearfix">
    <div id="header" class="l-container">
      <?php if ($logo): ?>
        <?php // Set h1 on logo when there is no page title. ?>
        <?php $sitename_wrapper_tag = empty($title) ? 'h1' : 'div'; ?>
        <<?php print $sitename_wrapper_tag; ?> id="logo" class="l-left">
          <a href="<?php print $front_page; ?>" title="<?php print t('Go to the homepage'); ?>" rel="home">
            <img src="<?php print $logo; ?>" alt="<?php print $site_name; ?> logo" />
          </a>
        </<?php print $sitename_wrapper_tag; ?>>
      <?php endif; ?>
      <div id="toolbar">
        <?php if ($page['language']): ?>
          <div id="language" class="clearfix">
            <?php print render($page['language']); ?>
          </div>
        <?php endif; ?>
        <?php if ($page['search']): ?>
          <div id="search" class="clearfix">
            <?php print render($page['search']); ?>
          </div>
        <?php endif; ?>
      </div>
      <div id="navigation">
        <?php
          if ($page['navigation']) {
            print render($page['navigation']);
          }
        ?>
      </div>
    </div>
  </div>
  <div class="l-container-wide hidden clearfix l-move-under">
    <?php if ($page['contact']): ?>
      <div id="contact" class="clearfix">
        <?php print render($page['contact']); ?>
      </div>
    <?php endif ?>
    <div id="mobile-toolbar" class="l-container-wide hidden clearfix"></div>

    <div id="content-wrapper" class="l-container-wide clearfix">
      <?php if ($page['precontent']): ?>
        <div id="pre-content" class="l-container-wide hidden clearfix">
          <?php print $page['precontent']; ?>
        </div>
      <?php endif; ?>
      <div id="content" class="l-container clearfix">
        <?php if ($messages): ?>
          <div id="messages" class="clearfix">
            <?php print $messages; ?>
          </div>
        <?php endif; ?>
        <?php
        if (isset($tabs)) {
          print render($tabs);
        }

        if ($show_title && $title) {
          print render($title_prefix);
          print '<h1>' . $title . '</h1>';
          print render($title_suffix);
        }

        print render($page['content']);
        ?>
      </div>
    </div>
  </div>
  <div class="push"></div>
</div>

<div id="footer-wrapper" class="l-container-wide clearfix">
  <div id="footer" class="l-container clearfix">
    <?php
      if ($page['footer']) {
        print render($page['footer']);
      }
    ?>
  </div>
</div>
