<?php
/**
 * @file
 * news.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function news_user_default_permissions() {
  $permissions = array();

  // Exported permission: create news_item content.
  $permissions['create news_item content'] = array(
    'name' => 'create news_item content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any news_item content.
  $permissions['delete any news_item content'] = array(
    'name' => 'delete any news_item content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own news_item content.
  $permissions['delete own news_item content'] = array(
    'name' => 'delete own news_item content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any news_item content.
  $permissions['edit any news_item content'] = array(
    'name' => 'edit any news_item content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own news_item content.
  $permissions['edit own news_item content'] = array(
    'name' => 'edit own news_item content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  return $permissions;
}
