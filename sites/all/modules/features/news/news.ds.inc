<?php
/**
 * @file
 * news.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function news_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news_item|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news_item';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'dummy_share_session' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'facebook_comments_title' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '3',
      'label' => 'inline',
      'format' => 'ds_post_date_short',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Posted on ',
          'lb-el' => 'span',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'field-post-date',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|news_item|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news_item|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news_item';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'dummy_share_session' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'inline',
      'format' => 'ds_post_date_short',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Posted on ',
          'lb-el' => 'span',
          'lb-cl' => 'label-post-date',
          'lb-def-at' => TRUE,
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'field-post-date',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['node|news_item|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function news_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news_item|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news_item';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'header' => array(
        0 => 'language',
        1 => 'body',
        2 => 'field_news_image',
        3 => 'field_news_link',
      ),
    ),
    'fields' => array(
      'language' => 'header',
      'body' => 'header',
      'field_news_image' => 'header',
      'field_news_link' => 'header',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => FALSE,
  );
  $export['node|news_item|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news_item|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news_item';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_news_image',
        1 => 'body',
        2 => 'field_news_link',
        3 => 'post_date',
        4 => 'facebook_comments_title',
        5 => 'facebook_comments',
      ),
      'right' => array(
        6 => 'dummy_share_session',
      ),
    ),
    'fields' => array(
      'field_news_image' => 'left',
      'body' => 'left',
      'field_news_link' => 'left',
      'post_date' => 'left',
      'facebook_comments_title' => 'left',
      'facebook_comments' => 'left',
      'dummy_share_session' => 'right',
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
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|news_item|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news_item|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news_item';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'title',
        1 => 'post_date',
        2 => 'field_news_image',
        3 => 'body',
        4 => 'field_news_link',
        5 => 'dummy_share_session',
      ),
    ),
    'fields' => array(
      'title' => 'left',
      'post_date' => 'left',
      'field_news_image' => 'left',
      'body' => 'left',
      'field_news_link' => 'left',
      'dummy_share_session' => 'left',
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
  $export['node|news_item|teaser'] = $ds_layout;

  return $export;
}
