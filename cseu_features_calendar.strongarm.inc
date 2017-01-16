<?php
/**
 * @file
 * cseu_features_calendar.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cseu_features_calendar_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_cseu_date_type_event_long';
  $strongarm->value = 'l, F jS, Y';
  $export['date_format_cseu_date_type_event_long'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_cseu_date_type_iso_8601';
  $strongarm->value = 'Y-m-d';
  $export['date_format_cseu_date_type_iso_8601'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_cseu_date_type_month';
  $strongarm->value = 'F Y';
  $export['date_format_cseu_date_type_month'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__cseu_event';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'email_plain' => array(
        'custom_settings' => FALSE,
      ),
      'email_html' => array(
        'custom_settings' => FALSE,
      ),
      'email_textalt' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'cseu_ds_view_mode_tasks' => array(
        'custom_settings' => FALSE,
      ),
      'cseu_ds_view_mode_wgs' => array(
        'custom_settings' => FALSE,
      ),
      'cseu_ds_view_mode_institution' => array(
        'custom_settings' => FALSE,
      ),
      'cseu_ds_view_mode_task_labelonly' => array(
        'custom_settings' => FALSE,
      ),
      'cseu_ds_view_mode_tasks_full' => array(
        'custom_settings' => FALSE,
      ),
      'cseu_ds_view_mode_tasks_wg_label' => array(
        'custom_settings' => FALSE,
      ),
      'cseu_ds_view_mode_wg_label_only' => array(
        'custom_settings' => FALSE,
      ),
      'cseu_ds_view_mode_wgs_full' => array(
        'custom_settings' => FALSE,
      ),
      'cseu_ds_view_mode_wgs_label' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__cseu_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_cseu_event';
  $strongarm->value = array();
  $export['menu_options_cseu_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_cseu_event';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_cseu_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_cseu_event';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_cseu_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_cseu_event';
  $strongarm->value = '1';
  $export['node_preview_cseu_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_cseu_event';
  $strongarm->value = 0;
  $export['node_submitted_cseu_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_cseu_event_pattern';
  $strongarm->value = '[node:field-cseu-event-type:url:path]/[node:title]';
  $export['pathauto_node_cseu_event_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_cseu_event_types_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_cseu_event_types_pattern'] = $strongarm;

  return $export;
}
