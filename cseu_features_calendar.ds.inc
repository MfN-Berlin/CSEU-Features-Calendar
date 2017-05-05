<?php
/**
 * @file
 * cseu_features_calendar.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function cseu_features_calendar_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|cseu_event|cseu_ds_view_mode_event';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'cseu_event';
  $ds_layout->view_mode = 'cseu_ds_view_mode_event';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_cseu_event_date',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_cseu_event_date' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|cseu_event|cseu_ds_view_mode_event'] = $ds_layout;

  return $export;
}
