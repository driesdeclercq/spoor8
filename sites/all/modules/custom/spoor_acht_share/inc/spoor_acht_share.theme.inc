<?php

/**
 * Field formatter for displaying a file as a large icon.
 */
function theme_spoor_acht_share_icons($variables) {
  $entity = $variables['entity'];
  $title = $entity->title;

  spoor_acht_share_set_og_tags($entity);

  $options = array('absolute' => TRUE);
  $nid = $entity->nid;
  $url = url('node/' . $nid, $options);


  return spoor_acht_share_twitter($title, $url)
      . spoor_acht_share_googleplus($url)
      . spoor_acht_share_facebook($title, $url, $entity);// $entity->field_body);

}

function spoor_acht_share_twitter($title, $url) {
  // Compile the Twitter share link.
  $twitter_url = 'https://twitter.com/intent/tweet';
  $via = 'SPOOR_8';

  $twitter_url .= '?url=' . $url;
  $twitter_url .= '&amp;text=' . $title;
  $twitter_url .= '&amp;via=' . $via;

  return l(t('Share on Twitter'), $twitter_url);
}

function spoor_acht_share_googleplus($url) {
  // Compile the Twitter share link.
  $googleplus_url = 'https://plus.google.com/share';

  $googleplus_url .= '?url=' . urlencode($url);

  return l(t('Share on Google+'), $googleplus_url);
}

function spoor_acht_share_facebook($title, $url, $entity) {
//  $facebook_url = 'http://www.facebook.com/sharer.php?u=' . $url;

  $facebook_url = 'http://www.facebook.com/dialog/feed?app_id=19884028963&ref=share_popup&link=http%3A%2F%2Fvimeo.com%2F50539479&redirect_uri=http%3A%2F%2Fvimeo.com%2F50539479%3Fclose';

  return l(t('Share on Facebook'), $facebook_url);
}

function spoor_acht_share_set_og_tags($entity) {

  $vimeo_id = 58199485;// $entity->field_video_vimeo_id[LANGUAGE_NONE][0]['value'];
  // property="og:type" content="video"
  $element = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:type',
      'content' => 'video',
    ),
    '#weight' => 30,
  );
  drupal_add_html_head($element, 'og_type');

  // property="og:video" content="http://vimeo.com/moogaloop.swf?clip_id=46192539"
  $element = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:video',
      'content' => 'http://vimeo.com/moogaloop.swf?clip_id=' . $vimeo_id,
    ),
    '#weight' => 31,
  );
  drupal_add_html_head($element, 'og_video');

  // property="og:video:secure_url" content="https://vimeo.com/moogaloop.swf?clip_id=46192539"
  $element = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:video:secure_url',
      'content' => 'https://vimeo.com/moogaloop.swf?clip_id=' . $vimeo_id,
    ),
    '#weight' => 32,
  );
  drupal_add_html_head($element, 'og_video_secure_url');

  // property="og:video:type" content="application/x-shockwave-flash"
  $element = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:video_type',
      'content' => 'application/x-shockwave-flash',
    ),
    '#weight' => 33,
  );
  drupal_add_html_head($element, 'og_video_type');

  // property="og:video:width" content="640"
  $element = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:video:width',
      'content' => '640',
    ),
    '#weight' => 34,
  );
  drupal_add_html_head($element, 'og_video_width');

  // property="og:video:height" content="360"
  $element = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:video:height',
      'content' => '360',
    ),
    '#weight' => 35,
  );
  drupal_add_html_head($element, 'og_video_height');



/*
  $imgpath = image_style_url('session_detail', $entity->field_session_cover_image[LANGUAGE_NONE][0]['uri']);
  $element = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:image',
      'content' => $imgpath,
    ),
  );
  drupal_add_html_head($element, 'og_image');
*/
  $element = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:description',
      'content' => 'fadediefafa',
    ),
  );
  drupal_add_html_head($element, 'og_description');
}

/*

<meta property="og:type" content="video">
<meta property="og:video" content="http://vimeo.com/moogaloop.swf?clip_id=46192539">
<meta property="og:video:secure_url" content="https://vimeo.com/moogaloop.swf?clip_id=46192539">
<meta property="og:video:type" content="application/x-shockwave-flash">
<meta property="og:video:width" content="640">
<meta property="og:video:height" content="360">

 */