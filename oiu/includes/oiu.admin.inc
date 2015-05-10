<?php
// $Id$

/**
 * @file
 * Admin page callback for the oiu module.
 */

/**
 * Builds and returns the indieweb settings form.
 */
function oiu_cron_settings_form($form, &$form_state) {
  
  $form['oiu_cron_frequency'] = array(
    '#type' => 'textarea',
    '#title' => t('Cron Frequency'),
    '#description' => t('Number of Crons to skip before running.'),
    '#default_value' => variable_get('oiu_cron_frequency', '23'),
    '#rows' => 1,
  );

  return system_settings_form($form);
}

