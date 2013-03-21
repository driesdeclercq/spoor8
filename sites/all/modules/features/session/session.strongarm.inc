<?php
/**
 * @file
 * session.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function session_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_508_compliant';
  $strongarm->value = 0;
  $export['addthis_508_compliant'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_addressbook_enabled';
  $strongarm->value = 0;
  $export['addthis_addressbook_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_clickback_tracking_enabled';
  $strongarm->value = 0;
  $export['addthis_clickback_tracking_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_click_to_open_compact_menu_enabled';
  $strongarm->value = 0;
  $export['addthis_click_to_open_compact_menu_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_co_brand';
  $strongarm->value = '';
  $export['addthis_co_brand'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_enabled_services';
  $strongarm->value = array(
    'facebook_like' => 'facebook_like',
    'google_plusone_share' => 'google_plusone_share',
    'pinterest' => 'pinterest',
    'twitthis' => 'twitthis',
    '100zakladok' => 0,
    '2tag' => 0,
    '2linkme' => 0,
    'a97abi' => 0,
    'addressbar' => 0,
    'adfty' => 0,
    'adifni' => 0,
    'advqr' => 0,
    'amazonwishlist' => 0,
    'amenme' => 0,
    'aim' => 0,
    'aolmail' => 0,
    'apsense' => 0,
    'armenix' => 0,
    'arto' => 0,
    'aviary' => 0,
    'azadegi' => 0,
    'baang' => 0,
    'baidu' => 0,
    'balltribe' => 0,
    'beat100' => 0,
    'bebo' => 0,
    'bentio' => 0,
    'biggerpockets' => 0,
    'bitly' => 0,
    'bizsugar' => 0,
    'bland' => 0,
    'blinklist' => 0,
    'blip' => 0,
    'blogger' => 0,
    'bloggy' => 0,
    'blogkeen' => 0,
    'blogmarks' => 0,
    'blogtrottr' => 0,
    'blurpalicious' => 0,
    'bolt' => 0,
    'bobrdobr' => 0,
    'bonzobox' => 0,
    'socialbookmarkingnet' => 0,
    'bookmarkycz' => 0,
    'bookmerkende' => 0,
    'box' => 0,
    'brainify' => 0,
    'bryderi' => 0,
    'buddymarks' => 0,
    'buffer' => 0,
    'buzzzy' => 0,
    'camyoo' => 0,
    'cardthis' => 0,
    'care2' => 0,
    'chimein' => 0,
    'chiq' => 0,
    'cirip' => 0,
    'citeulike' => 0,
    'classicalplace' => 0,
    'cleanprint' => 0,
    'cleansave' => 0,
    'clipdo' => 0,
    'cndig' => 0,
    'colivia' => 0,
    'technerd' => 0,
    'connotea' => 0,
    'cootopia' => 0,
    'cosmiq' => 0,
    'cssbased' => 0,
    'curateus' => 0,
    'delicious' => 0,
    'designbump' => 0,
    'digthiswebhost' => 0,
    'digaculturanet' => 0,
    'digg' => 0,
    'diggita' => 0,
    'digo' => 0,
    'digzign' => 0,
    'diigo' => 0,
    'dipdive' => 0,
    'domelhor' => 0,
    'dosti' => 0,
    'dotnetkicks' => 0,
    'dotnetshoutout' => 0,
    'douban' => 0,
    'draugiem' => 0,
    'drimio' => 0,
    'dropjack' => 0,
    'dudu' => 0,
    'dzone' => 0,
    'edelight' => 0,
    'efactor' => 0,
    'ekudos' => 0,
    'elefantapl' => 0,
    'email' => 0,
    'mailto' => 0,
    'embarkons' => 0,
    'eucliquei' => 0,
    'evernote' => 0,
    'extraplay' => 0,
    'ezyspot' => 0,
    'stylishhome' => 0,
    'fabulously40' => 0,
    'facebook' => 0,
    'informazione' => 0,
    'fark' => 0,
    'farkinda' => 0,
    'fashiolista' => 0,
    'favable' => 0,
    'faves' => 0,
    'favlogde' => 0,
    'favoritende' => 0,
    'favorites' => 0,
    'favoritus' => 0,
    'flaker' => 0,
    'flosspro' => 0,
    'folkd' => 0,
    'formspring' => 0,
    'thefreedictionary' => 0,
    'fresqui' => 0,
    'friendfeed' => 0,
    'funp' => 0,
    'fwisp' => 0,
    'gabbr' => 0,
    'gamekicker' => 0,
    'gg' => 0,
    'giftery' => 0,
    'gigbasket' => 0,
    'givealink' => 0,
    'globalgrind' => 0,
    'gmail' => 0,
    'govn' => 0,
    'goodnoows' => 0,
    'google' => 0,
    'google_plusone' => 0,
    'googletranslate' => 0,
    'greaterdebater' => 0,
    'grono' => 0,
    'habergentr' => 0,
    'hackernews' => 0,
    'hadashhot' => 0,
    'hatena' => 0,
    'gluvsnap' => 0,
    'hedgehogs' => 0,
    'hellotxt' => 0,
    'historious' => 0,
    'hotbookmark' => 0,
    'hotklix' => 0,
    'hotmail' => 0,
    'w3validator' => 0,
    'hyves' => 0,
    'identica' => 0,
    'idibbit' => 0,
    'igoogle' => 0,
    'ihavegot' => 0,
    'index4' => 0,
    'indexor' => 0,
    'instapaper' => 0,
    'investorlinks' => 0,
    'iorbix' => 0,
    'irepeater' => 0,
    'isociety' => 0,
    'iwiw' => 0,
    'jamespot' => 0,
    'jappy' => 0,
    'joliprint' => 0,
    'jolly' => 0,
    'jumptags' => 0,
    'kaboodle' => 0,
    'kaevur' => 0,
    'kaixin' => 0,
    'ketnooi' => 0,
    'kindleit' => 0,
    'kipup' => 0,
    'kledy' => 0,
    'kommenting' => 0,
    'latafaneracat' => 0,
    'librerio' => 0,
    'lidar' => 0,
    'linkninja' => 0,
    'linkedin' => 0,
    'linksgutter' => 0,
    'linkshares' => 0,
    'linkuj' => 0,
    'livejournal' => 0,
    'lockerblogger' => 0,
    'logger24' => 0,
    'mymailru' => 0,
    'markme' => 0,
    'mashant' => 0,
    'mashbord' => 0,
    'me2day' => 0,
    'meinvz' => 0,
    'mekusharim' => 0,
    'memonic' => 0,
    'memori' => 0,
    'mendeley' => 0,
    'meneame' => 0,
    'live' => 0,
    'mindbodygreen' => 0,
    'misterwong' => 0,
    'misterwong_de' => 0,
    'moemesto' => 0,
    'moikrug' => 0,
    'mototagz' => 0,
    'mrcnetworkit' => 0,
    'multiply' => 0,
    'myaol' => 0,
    'myhayastan' => 0,
    'mylinkvault' => 0,
    'myspace' => 0,
    'n4g' => 0,
    'naszaklasa' => 0,
    'netlog' => 0,
    'netvibes' => 0,
    'netvouz' => 0,
    'newsmeback' => 0,
    'newstrust' => 0,
    'newsvine' => 0,
    'nujij' => 0,
    'odnoklassniki_ru' => 0,
    'oknotizie' => 0,
    'oneview' => 0,
    'orkut' => 0,
    'dashboard' => 0,
    'oyyla' => 0,
    'packg' => 0,
    'pafnetde' => 0,
    'pdfonline' => 0,
    'pdfmyurl' => 0,
    'phonefavs' => 0,
    'pingfm' => 0,
    'planypus' => 0,
    'plaxo' => 0,
    'plurk' => 0,
    'pochvalcz' => 0,
    'pocket' => 0,
    'politicnote' => 0,
    'posteezy' => 0,
    'posterous' => 0,
    'pratiba' => 0,
    'print' => 0,
    'printfriendly' => 0,
    'pusha' => 0,
    'qrfin' => 0,
    'qrsrc' => 0,
    'quantcast' => 0,
    'qzone' => 0,
    'reddit' => 0,
    'rediff' => 0,
    'redkum' => 0,
    'researchgate' => 0,
    'ridefix' => 0,
    'safelinking' => 0,
    'scoopat' => 0,
    'scoopit' => 0,
    'sekoman' => 0,
    'select2gether' => 0,
    'sharer' => 0,
    'shaveh' => 0,
    'shetoldme' => 0,
    'sinaweibo' => 0,
    'skyrock' => 0,
    'smiru' => 0,
    'snipit' => 0,
    'sodahead' => 0,
    'sonico' => 0,
    'speedtile' => 0,
    'spinsnap' => 0,
    'spokentoyou' => 0,
    'yiid' => 0,
    'springpad' => 0,
    'squidoo' => 0,
    'startaid' => 0,
    'startlap' => 0,
    'storyfollower' => 0,
    'studivz' => 0,
    'stuffpit' => 0,
    'stumbleupon' => 0,
    'stumpedia' => 0,
    'sunlize' => 0,
    'supbro' => 0,
    'surfingbird' => 0,
    'svejo' => 0,
    'symbaloo' => 0,
    'taaza' => 0,
    'tagza' => 0,
    'taringa' => 0,
    'tarpipe' => 0,
    'textme' => 0,
    'thewebblend' => 0,
    'thinkfinity' => 0,
    'thisnext' => 0,
    'throwpile' => 0,
    'toly' => 0,
    'topsitelernet' => 0,
    'transferr' => 0,
    'tuenti' => 0,
    'tulinq' => 0,
    'tumblr' => 0,
    'tvinx' => 0,
    'twitter' => 0,
    'typepad' => 0,
    'upnews' => 0,
    'urlaubswerkde' => 0,
    'urlcapt' => 0,
    'viadeo' => 0,
    'virb' => 0,
    'visitezmonsite' => 0,
    'vk' => 0,
    'vkrugudruzei' => 0,
    'voxopolis' => 0,
    'vybralisme' => 0,
    'vyoom' => 0,
    'webnews' => 0,
    'webshare' => 0,
    'werkenntwen' => 0,
    'domaintoolswhois' => 0,
    'windows' => 0,
    'windycitizen' => 0,
    'wirefan' => 0,
    'wordpress' => 0,
    'worio' => 0,
    'wowbored' => 0,
    'raiseyourvoice' => 0,
    'wykop' => 0,
    'xanga' => 0,
    'xing' => 0,
    'yahoobkm' => 0,
    'yahoomail' => 0,
    'yammer' => 0,
    'yardbarker' => 0,
    'yemle' => 0,
    'yigg' => 0,
    'yookos' => 0,
    'yoolink' => 0,
    'yorumcuyum' => 0,
    'youblr' => 0,
    'youbookmarks' => 0,
    'youmob' => 0,
    'yuuby' => 0,
    'zakladoknet' => 0,
    'ziczac' => 0,
    'zingme' => 0,
  );
  $export['addthis_enabled_services'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_facebook_like_count_support_enabled';
  $strongarm->value = 1;
  $export['addthis_facebook_like_count_support_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_google_analytics_social_tracking_enabled';
  $strongarm->value = FALSE;
  $export['addthis_google_analytics_social_tracking_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_google_analytics_tracking_enabled';
  $strongarm->value = FALSE;
  $export['addthis_google_analytics_tracking_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_open_windows_enabled';
  $strongarm->value = 0;
  $export['addthis_open_windows_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_profile_id';
  $strongarm->value = '';
  $export['addthis_profile_id'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_standard_css_enabled';
  $strongarm->value = 1;
  $export['addthis_standard_css_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_twitter_template';
  $strongarm->value = '{{title}} {{url}} via @AddThis';
  $export['addthis_twitter_template'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_twitter_via';
  $strongarm->value = 'AddThis';
  $export['addthis_twitter_via'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_ui_delay';
  $strongarm->value = '0';
  $export['addthis_ui_delay'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_ui_header_background_color';
  $strongarm->value = '';
  $export['addthis_ui_header_background_color'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'addthis_ui_header_color';
  $strongarm->value = '';
  $export['addthis_ui_header_color'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__session';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'slideshow' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'language' => array(
          'weight' => '1',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '5',
        ),
        'metatags' => array(
          'weight' => '9',
        ),
      ),
      'display' => array(
        'language' => array(
          'teaser' => array(
            'weight' => '26',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '25',
            'visible' => FALSE,
          ),
          'slideshow' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
        ),
        'facebook_comments' => array(
          'default' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '28',
            'visible' => FALSE,
          ),
          'slideshow' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__session'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_session';
  $strongarm->value = '2';
  $export['language_content_type_session'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_session';
  $strongarm->value = array();
  $export['menu_options_session'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_session';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_session'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_session';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_session'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_session';
  $strongarm->value = '1';
  $export['node_preview_session'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_session';
  $strongarm->value = 0;
  $export['node_submitted_session'] = $strongarm;

  return $export;
}
