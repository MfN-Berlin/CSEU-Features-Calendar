<?php
/**
 * @file
 * cseu_features_calendar.taxonomy_display.inc
 */

/**
 * Implements hook_taxonomy_display_default_displays().
 */
function cseu_features_calendar_taxonomy_display_default_displays() {
  $export = array();

  $taxonomy_display = new stdClass();
  $taxonomy_display->api_version = 1;
  $taxonomy_display->machine_name = 'cseu_usage';
  $taxonomy_display->term_display_plugin = 'TaxonomyDisplayTermDisplayHandlerCore';
  $taxonomy_display->term_display_options = '';
  $taxonomy_display->associated_display_plugin = 'TaxonomyDisplayAssociatedDisplayHandlerViews';
  $taxonomy_display->associated_display_options = array(
    'view' => 'cseu_view_list_events_by_usage',
    'display' => 'page',
  );
  $taxonomy_display->add_feed = FALSE;
  $taxonomy_display->breadcrumb_display_plugin = 'TaxonomyDisplayBreadcrumbDisplayHandlerHidden';
  $taxonomy_display->breadcrumb_display_options = '';
  $export['cseu_usage'] = $taxonomy_display;

  return $export;
}
