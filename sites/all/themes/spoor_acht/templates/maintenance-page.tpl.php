<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
  "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>">
<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <meta name="MobileOptimized" content="width">
  <meta name="HandheldFriendly" content="true">
  <meta name="viewport" content="width=device-width">
  <meta http-equiv="X-UA-Compatible" content="IE=Edge,chrome=IE8">
  <meta http-equiv="cleartype" content="on">
  <meta http-equiv="ImageToolbar" content="false">
  <meta name="MSSmartTagsPreventParsing" content="true">
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes; ?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>

  <div id="header" class="l-container clearfix">
    <div class="l-left">
      <?php if ($logo): ?>
        <?php $sitename_wrapper_tag = empty($title) ? 'h1' : 'div'; ?>
        <<?php print $sitename_wrapper_tag; ?> class="site-name l-left">
          <a href="<?php print $front_page; ?>" title="<?php print t('Go to the homepage'); ?>" rel="home">
            <img src="<?php print $logo; ?>" alt="<?php print $site_name; ?> logo" />
          </a>
        </<?php print $sitename_wrapper_tag; ?>>
      <?php endif; ?>
      <?php if ($site_slogan): ?>
        <div class="site-slogan l-left"><?php print $site_slogan; ?></div>
      <?php endif; ?>
      <?php if ($search): ?>
        <div class="search l-left"><?php print $search; ?></div>
      <?php endif; ?>
    </div>
  </div>


  <div id="content-container" class="l-container clearfix">
    <?php if ($sidebar_first): ?>
      <div id="sidebar-first" class="sidebar">
        <?php print $sidebar_first; ?>
      </div>
    <?php endif; ?>

    <div id="content">
      <?php if ($messages): ?>
        <div id="messages" class="clearfix">
          <?php print $messages; ?>
        </div>
      <?php endif; ?>
      <?php
        if ($title) {
          print render($title_prefix);
          print '<h1>' . $title . '</h1>';
          print render($title_suffix);
        }

        print $content;
      ?>
    </div>
  </div>

  <?php print $page_bottom; ?>
</body>
</html>
