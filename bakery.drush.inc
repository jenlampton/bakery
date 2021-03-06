<?php

/**
 * @file
 * Drush integration for Bakery.
 */

/**
 * Implements hook_drush_help().
 */
function bakery_drush_help($section) {
  switch ($section) {
    case 'drush:bakery-add-slave':
      return dt('Update the Bakery configuration to add a slave site.');
  }
}

/**
 * Implements hook_drush_command().
 */
function bakery_drush_command() {
  $items['bakery-add-slave'] = array(
    'description' => 'Add a Bakery slave site.',
    'arguments' => array(
      'slave' => 'Slave site URL, starts with http and ending with /.',
    ),
  );
  return $items;
}

/**
 * Drush command for adding new slave.
 */
function drush_bakery_add_slave($slave) {
  $config = config('bakery.settings');
  $slaves = $config->get('slaves');
  $slaves[] = $slave;
  $config->set('slaves', $slaves);
}
