<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
?>

<?php
function spoor_acht_preprocess_page(&$vars) {
  $vars['show_title'] = TRUE;

  // Display suite handles title display for: pages.
  if (isset($vars['node']) && $vars['node']->type == 'page') {
    $vars['show_title'] = FALSE;
  }
}
