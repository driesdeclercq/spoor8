<?php
/**
 * @file
 * feature_newsletter.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function feature_newsletter_user_default_permissions() {
  $permissions = array();

  // Exported permission: access newsletter statistics.
  $permissions['access newsletter statistics'] = array(
    'name' => 'access newsletter statistics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'newsletter',
  );

  // Exported permission: access site-wide contact form.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'contact',
  );

  // Exported permission: administer newsletters.
  $permissions['administer newsletters'] = array(
    'name' => 'administer newsletters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'newsletter',
  );

  // Exported permission: subscribe newsletters.
  $permissions['subscribe newsletters'] = array(
    'name' => 'subscribe newsletters',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'newsletter',
  );

  return $permissions;
}
