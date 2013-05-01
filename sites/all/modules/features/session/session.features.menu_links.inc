<?php
/**
 * @file
 * session.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function session_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:sessions
  $menu_links['main-menu:sessions'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'sessions',
    'router_path' => 'sessions',
    'link_title' => 'Sessions',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Sessions');


  return $menu_links;
}
