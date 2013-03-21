<?php

/**
 * Formatter theming fucntion: construct share icons.
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
    . spoor_acht_share_pinterest($title, $url, $entity)
    . spoor_acht_share_facebook($title, $url, $entity);// $entity->field_body);

}

/**
 * Construct the Twitter share link.
 */
function spoor_acht_share_twitter($title, $url) {
  // Compile the Twitter share link.
  $twitter_url = 'https://twitter.com/intent/tweet';
  $via = 'SPOOR_8';

  $twitter_url .= '?url=' . $url;
  $twitter_url .= '&amp;text=' . $title;
  $twitter_url .= '&amp;via=' . $via;

  return l(t('Share on Twitter'), $twitter_url);
}

/**
 * Construct the Google+ share link.
 */
function spoor_acht_share_googleplus($url) {
  // Compile the Twitter share link.
  $googleplus_url = 'https://plus.google.com/share';

  $googleplus_url .= '?url=' . urlencode($url);

  return l(t('Share on Google+'), $googleplus_url);
}

/**
 * Construct the Facebook share link.
 */
function spoor_acht_share_facebook($title, $url, $entity) {
  $facebook_url = 'http://www.facebook.com/sharer.php?u=' . $url;

  return l(t('Share on Facebook'), $facebook_url);
}

/**
 * Construct the Pinterest share link.
 * http://pinterest.com/pin/create/button/
 * ?media=
 * &url=http%3A%2F%2Fvimeo.com%2F46192539
 * &is_video=true
 * &title=
 * &description=
 */
function spoor_acht_share_pinterest($title, $url, $entity) {
  $pinterest_url = 'http://pinterest.com/pin/create/button/'
    . '?media=' . urlencode(file_create_url($entity->field_session_cover_image[LANGUAGE_NONE][0]['uri']))
    . '&url=' . urlencode($url);
  return l(t('Share on Pinterest'), $pinterest_url);
}

/**
 *
 */
function spoor_acht_share_set_og_tags($entity) {
  // Page tags.
  $values = array(
    'title' => $entity->title,
//    'description' => $entity->body[LANGUAGE_NONE][0]['summary'],
    'site_name' => variable_get('site_name', "Spoor 8"),
    'url' => 'http://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'],
    'image_path' => file_create_url($entity->field_session_cover_image[LANGUAGE_NONE][0]['uri']),
  );
  $elements = _spoor_acht_share_get_og_tags($values);

  foreach($elements as $type => $element) {
    drupal_add_html_head($element, $type);
  }

  /* Video tags.
  if ($entity->type == 'session') {
    $values['video'] = array(
      'id' => $entity->field_video_vimeo_id[LANGUAGE_NONE][0]['value'],
      'width' => '640',
      'height' => '360',
    );
  }
   *
   */
}

/**
 <meta property="og:title" content="Circular scrubbing video player" />
  <meta property="og:description" content="A video player interface experiment, which features circular scrubbing and a very minimal design." />
  <meta property="og:type" content="video" />
  <meta property="og:url" content="http://ahrengot.com/playground/circular-scrubbing"/>
  <meta property="og:image" content="http://ahrengot.com/playground/circular-scrubbing/thumb.jpg"/>
  <meta property="og:site_name" content="Ahrengot's Playground"/>
TODO  <meta property="fb:admins" content="100000936142315"/>

  <!-- Video player specific OG tags -->
  <meta property="og:video" content="http://ahrengot.com/playground/circular-scrubbing/video-player.swf?url=http://ahrengot.com/playground/circular-scrubbing/assets/video/example.mp4" />
  <meta property="og:video:width" content="374" />
  <meta property="og:video:height" content="202" />
  <meta property="og:video:type" content="application/x-shockwave-flash" />
 */
function _spoor_acht_share_get_og_tags($values) {
  $elements = array();
  $weight = 10;

  // Add page tags.
  $elements['og_title'] = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:title',
      'content' => $values['title'],
    ),
    '#weight' => ++$weight,
  );
  $elements['og_description'] = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:description',
   //   'content' => $values['description'],
    ),
    '#weight' => ++$weight,
  );
  $elements['og_type'] = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:type',
      'content' => 'video',
    ),
    '#weight' => ++$weight,
  );
  $elements['og_site_name'] = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:site_name',
      'content' => $values['site_name'],
    ),
    '#weight' => ++$weight,
  );
  $elements['og_url'] = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:url',
      'content' => $values['url'],
    ),
    '#weight' => ++$weight,
  );
  $elements['og_image'] = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'property' => 'og:image',
      'content' => $values['image_path'],
    ),
    '#weight' => ++$weight,
  );

  // Add video tags.
  if (isset($values['video'])) {
    $elements['og_video'] = array(
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => 'og:video',
        'content' => 'http://vimeo.com/moogaloop.swf?clip_id=' . $values['video']['id'],
      ),
      '#weight' => ++$weight,
    );
    $elements['og_video_secure_url'] = array(
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => 'og:video:secure_url',
        'content' => 'https://vimeo.com/moogaloop.swf?clip_id=' . $values['video']['id'],
      ),
      '#weight' => ++$weight,
    );
    $elements['og_video_width'] = array(
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => $values['video']['width'],
        'content' => '640',
      ),
      '#weight' => ++$weight,
    );
    $elements['og_video_height'] = array(
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => 'og:video:height',
        'content' => $values['video']['height'],
      ),
      '#weight' => ++$weight,
    );
    $elements['og_video_type'] = array(
      '#tag' => 'meta',
      '#attributes' => array(
        'property' => 'og:video:type',
        'content' => 'application/x-shockwave-flash',
      ),
      '#weight' => ++$weight,
    );
  }

  return($elements);
}