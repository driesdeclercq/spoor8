<?php
/**
 * @file
 * session.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function session_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_band_links|node|session|form';
  $field_group->group_name = 'group_band_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'session';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Band social links',
    'weight' => '7',
    'children' => array(
      0 => 'field_band_twitter',
      1 => 'field_band_facebook',
      2 => 'field_band_soundcloud',
      3 => 'field_band_website',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Band social links',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_band_links|node|session|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_band_links|node|session|full';
  $field_group->group_name = 'group_band_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'session';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Band social links',
    'weight' => '4',
    'children' => array(
      0 => 'field_band_twitter',
      1 => 'field_band_facebook',
      2 => 'field_band_soundcloud',
      3 => 'field_band_website',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Band social links',
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
  $export['group_band_links|node|session|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_session_band_pictures|node|session|form';
  $field_group->group_name = 'group_session_band_pictures';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'session';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Band pictures',
    'weight' => '6',
    'children' => array(
      0 => 'field_session_image',
      1 => 'field_session_cover_image',
      2 => 'field_session_slideshow_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Band pictures',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_session_band_pictures|node|session|form'] = $field_group;

  return $export;
}
