<?php
/**
 * @file
 * news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function news_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news_body|node|news_item|teaser';
  $field_group->group_name = 'group_news_body';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_item';
  $field_group->mode = 'teaser';
  $field_group->parent_name = 'group_news';
  $field_group->data = array(
    'label' => 'Group News Body',
    'weight' => '5',
    'children' => array(
      0 => 'body',
      1 => 'field_news_link',
      2 => 'dummy_share_session',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Group News Body',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_news_body|node|news_item|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news|node|news_item|teaser';
  $field_group->group_name = 'group_news';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_item';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group News',
    'weight' => '2',
    'children' => array(
      0 => 'field_news_image',
      1 => 'image_background',
      2 => 'group_news_body',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_news|node|news_item|teaser'] = $field_group;

  return $export;
}
