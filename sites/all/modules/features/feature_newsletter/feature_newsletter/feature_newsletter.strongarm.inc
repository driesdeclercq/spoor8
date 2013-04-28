<?php
/**
 * @file
 * feature_newsletter.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function feature_newsletter_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_always_show_subscribe_block';
  $strongarm->value = 0;
  $export['newsletter_always_show_subscribe_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_auto_subscribe_new_users';
  $strongarm->value = array();
  $export['newsletter_auto_subscribe_new_users'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_block_prefix';
  $strongarm->value = 'if you wish to receive updates on our activities, leave your email address here so we can stay in touch.';
  $export['newsletter_block_prefix'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_block_suffix';
  $strongarm->value = '';
  $export['newsletter_block_suffix'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_cron_number';
  $strongarm->value = '500';
  $export['newsletter_cron_number'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_format';
  $strongarm->value = 'html';
  $export['newsletter_format'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_from';
  $strongarm->value = 'dries@mail.com';
  $export['newsletter_from'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_node_limit';
  $strongarm->value = '50';
  $export['newsletter_node_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_personal_info_form';
  $strongarm->value = array(
    'firstname' => 'show',
    'lastname' => 'show',
    'gender' => 'hidden',
    'receive_format' => 'show',
  );
  $export['newsletter_personal_info_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_send_confirm';
  $strongarm->value = 1;
  $export['newsletter_send_confirm'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_send_unsubscribe';
  $strongarm->value = 1;
  $export['newsletter_send_unsubscribe'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_send_welcome';
  $strongarm->value = 1;
  $export['newsletter_send_welcome'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_show_email';
  $strongarm->value = 1;
  $export['newsletter_show_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_show_email_in_block';
  $strongarm->value = 1;
  $export['newsletter_show_email_in_block'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_test_to';
  $strongarm->value = 'dries@mail.com';
  $export['newsletter_test_to'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_track_open_rate';
  $strongarm->value = 0;
  $export['newsletter_track_open_rate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'newsletter_use_smtp';
  $strongarm->value = 0;
  $export['newsletter_use_smtp'] = $strongarm;

  return $export;
}
