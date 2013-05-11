<?php
/**
 * @file
 * session.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function session_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|session|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'session';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'session_pictures' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|session|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|session|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'session';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'session_pictures' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_video' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-session-video',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'video-wrapper',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'img',
          'fi-cl' => 'loading-image',
          'fi-at' => 'src="/sites/all/themes/spoor_acht/images/ajax-loader-big.gif"',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_band_twitter' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'band-twitter',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_band_facebook' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'band-facebook',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_band_soundcloud' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'band-soundcloud',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_band_website' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'band-website',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_addthis' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Share this session',
          'lb-el' => 'h2',
          'lb-cl' => 'block-title',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'addthis-share',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|session|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|session|slideshow';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'session';
  $ds_fieldsetting->view_mode = 'slideshow';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|session|slideshow'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|session|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'session';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'node_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'View session',
        'wrapper' => '',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'field_session_cover_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field-session-cover-image',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'session-image-wrapper',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|session|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|webform|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'webform';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|webform|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function session_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'dummy_share_session';
  $ds_field->label = 'Dummy share session';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'block|7',
    'block_render' => '2',
  );
  $export['dummy_share_session'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'facebook_comments_title';
  $ds_field->label = 'Facebook comments title';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => 'Comments',
      'format' => 'plain_text',
    ),
    'use_token' => 0,
  );
  $export['facebook_comments_title'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'session_pictures';
  $ds_field->label = 'Session pictures';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|slideshow-block',
    'block_render' => '2',
  );
  $export['session_pictures'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function session_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|session|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'session';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'field_video',
        2 => 'field_intro_text',
        3 => 'field_session_text',
      ),
      'left' => array(
        4 => 'session_pictures',
      ),
      'right' => array(
        5 => 'field_addthis',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_video' => 'header',
      'field_intro_text' => 'header',
      'field_session_text' => 'header',
      'session_pictures' => 'left',
      'field_addthis' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|session|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|session|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'session';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'title',
        1 => 'field_video',
        2 => 'field_intro_text',
        3 => 'field_session_text',
        4 => 'group_band_links',
        7 => 'field_band_twitter',
        8 => 'field_band_soundcloud',
        9 => 'field_band_facebook',
        10 => 'field_band_website',
      ),
      'left' => array(
        5 => 'session_pictures',
      ),
      'right' => array(
        6 => 'field_addthis',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_video' => 'header',
      'field_intro_text' => 'header',
      'field_session_text' => 'header',
      'group_band_links' => 'header',
      'session_pictures' => 'left',
      'field_addthis' => 'right',
      'field_band_twitter' => 'header',
      'field_band_soundcloud' => 'header',
      'field_band_facebook' => 'header',
      'field_band_website' => 'header',
    ),
    'classes' => array(),
    'wrappers' => array(
      'header' => 'div',
      'left' => 'div',
      'right' => 'div',
      'footer' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|session|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|session|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'session';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_session_cover_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'field_intro_text',
        3 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_session_cover_image' => 'left',
      'title' => 'right',
      'field_intro_text' => 'right',
      'node_link' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['node|session|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function session_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'slideshow';
  $ds_view_mode->label = 'Slideshow';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['slideshow'] = $ds_view_mode;

  return $export;
}
