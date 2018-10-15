<?php
/**
 * @file
 * cseu_features_calendar.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cseu_features_calendar_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cseu_events_calendar_view';
  $view->description = '';
  $view->tag = 'Calendar';
  $view->base_table = 'node';
  $view->human_name = 'Events Calendar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'all events';
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cseu_event_date']['id'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['field'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_cseu_event_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['delta_offset'] = '0';
  /* Sort criterion: Content: Date -  start date (field_cseu_event_date) */
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['id'] = 'field_cseu_event_date_value';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['field'] = 'field_cseu_event_date_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: All Events */
  $handler = $view->new_display('page', 'All Events', 'all');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_cseu_event_date_1',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'cseu-events-calendar-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_cseu_event_date' => 'field_cseu_event_date',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No upcoming events.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Style from category  */
  $handler->display->display_options['fields']['field_cseu_event_type_1']['id'] = 'field_cseu_event_type_1';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['table'] = 'field_data_field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['field'] = 'field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['ui_name'] = 'Style from category ';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_type_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_type_1']['alter']['text'] = 'cseu-event-category-[field_cseu_event_type_1-tid]';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type_1']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Event Date - Month */
  $handler->display->display_options['fields']['field_cseu_event_date_1']['id'] = 'field_cseu_event_date_1';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['field'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['ui_name'] = 'Event Date - Month';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date_1']['settings'] = array(
    'format_type' => 'cseu_date_type_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Venue - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['id'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['field'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_default_classes'] = FALSE;
  /* Field: Event Category */
  $handler->display->display_options['fields']['field_cseu_event_type']['id'] = 'field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type']['table'] = 'field_data_field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type']['field'] = 'field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type']['ui_name'] = 'Event Category';
  $handler->display->display_options['fields']['field_cseu_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_type']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cseu_event_type']['element_class'] = 'cseu-event-category [field_cseu_event_type_1]';
  $handler->display->display_options['fields']['field_cseu_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cseu_event_date']['id'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['field'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_date']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cseu_event_date']['element_class'] = 'cseu-event-date';
  $handler->display->display_options['fields']['field_cseu_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['settings'] = array(
    'format_type' => 'cseu_date_type_iso_8601',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_cseu_event_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['delta_offset'] = '0';
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'field_cseu_event_type_2',
    1 => 'title',
    2 => 'field_cseu_event_venue_country',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'cseu-event-content';
  /* Field: Event Category - Mobile */
  $handler->display->display_options['fields']['field_cseu_event_type_2']['id'] = 'field_cseu_event_type_2';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['table'] = 'field_data_field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['field'] = 'field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['ui_name'] = 'Event Category - Mobile';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['element_class'] = 'cseu-event-category-mobile [field_cseu_event_type_1]';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type_2']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'cseu-event-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Venue - Country */
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['id'] = 'field_cseu_event_venue_country';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['field'] = 'field_cseu_event_venue_country';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['alter']['text'] = '[field_cseu_event_venue_locality], [field_cseu_event_venue_country]';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_class'] = 'cseu-event-venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['display_name'] = 1;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_cseu_event_date.field_cseu_event_date_value' => 'field_data_field_cseu_event_date.field_cseu_event_date_value',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cseu_event' => 'cseu_event',
  );
  /* Filter criterion: Content: Category (field_cseu_event_type) */
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['id'] = 'field_cseu_event_type_tid';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['table'] = 'field_data_field_cseu_event_type';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['field'] = 'field_cseu_event_type_tid';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['expose']['operator_id'] = 'field_cseu_event_type_tid_op';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['expose']['operator'] = 'field_cseu_event_type_tid_op';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['vocabulary'] = 'cseu_event_types';
  $handler->display->display_options['path'] = 'events';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'All Events';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Month */
  $handler = $view->new_display('page', 'Month', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'month';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['row_options']['colors']['legend'] = 'type';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_cseu_event_date.field_cseu_event_date_value' => 'field_data_field_cseu_event_date.field_cseu_event_date_value',
  );
  $handler->display->display_options['path'] = 'events/month';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Month';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['title'] = 'Calendar';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Week */
  $handler = $view->new_display('page', 'Week', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'week';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'week';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'week';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_cseu_event_date.field_cseu_event_date_value' => 'field_data_field_cseu_event_date.field_cseu_event_date_value',
  );
  $handler->display->display_options['path'] = 'events/week';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Week';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Day */
  $handler = $view->new_display('page', 'Day', 'page_3');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'day';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'day';
  $handler->display->display_options['style_options']['name_size'] = '3';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'day';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_cseu_event_date.field_cseu_event_date_value' => 'field_data_field_cseu_event_date.field_cseu_event_date_value',
  );
  $handler->display->display_options['path'] = 'events/day';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Day';
  $handler->display->display_options['menu']['weight'] = '4';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Year */
  $handler = $view->new_display('page', 'Year', 'page');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'year';
  $handler->display->display_options['pager']['options']['link_format'] = 'clean';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['calendar_type'] = 'year';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '0';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cseu_event_date']['id'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['field'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_cseu_event_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['granularity'] = 'year';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_cseu_event_date.field_cseu_event_date_value' => 'field_data_field_cseu_event_date.field_cseu_event_date_value',
  );
  $handler->display->display_options['path'] = 'events/year';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Year';
  $handler->display->display_options['menu']['weight'] = '5';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_m');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['pager']['options']['date_id'] = 'mini';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'calendar_style';
  $handler->display->display_options['style_options']['name_size'] = '1';
  $handler->display->display_options['style_options']['mini'] = '1';
  $handler->display->display_options['style_options']['with_weekno'] = '0';
  $handler->display->display_options['style_options']['multiday_theme'] = '1';
  $handler->display->display_options['style_options']['theme_style'] = '1';
  $handler->display->display_options['style_options']['max_items'] = '0';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'calendar_entity';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Date: Date (node) */
  $handler->display->display_options['arguments']['date_argument']['id'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['table'] = 'node';
  $handler->display->display_options['arguments']['date_argument']['field'] = 'date_argument';
  $handler->display->display_options['arguments']['date_argument']['default_action'] = 'default';
  $handler->display->display_options['arguments']['date_argument']['default_argument_type'] = 'date';
  $handler->display->display_options['arguments']['date_argument']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['date_argument']['add_delta'] = 'yes';
  $handler->display->display_options['arguments']['date_argument']['date_fields'] = array(
    'field_data_field_cseu_event_date.field_cseu_event_date_value' => 'field_data_field_cseu_event_date.field_cseu_event_date_value',
  );

  /* Display: iCal */
  $handler = $view->new_display('feed', 'iCal', 'events_feed');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'date_ical';
  $handler->display->display_options['row_plugin'] = 'date_ical';
  $handler->display->display_options['row_options']['date_field'] = 'field_data_field_cseu_event_date.field_cseu_event_date_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_cseu_event_date.field_cseu_event_date_value' => 'field_data_field_cseu_event_date.field_cseu_event_date_value',
  );
  $handler->display->display_options['path'] = 'events/ical/%/calendar.ics';
  $handler->display->display_options['displays'] = array(
    'all' => 'all',
    'page_1' => 'page_1',
    'page_2' => 'page_2',
    'page_3' => 'page_3',
    'page' => 'page',
    'upcal' => 'upcal',
    'default' => 0,
    'block_m' => 0,
    'up' => 0,
  );

  /* Display: Upcoming */
  $handler = $view->new_display('block', 'Upcoming', 'up');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'events_all';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No upcoming events.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cseu_event_date']['id'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['field'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['settings'] = array(
    'format_type' => 'cseu_date_type_iso_8601',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_cseu_event_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['delta_offset'] = '0';
  /* Field: Content: Venue - Country */
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['id'] = 'field_cseu_event_venue_country';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['field'] = 'field_cseu_event_venue_country';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['display_name'] = 1;
  /* Field: Content: Venue - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['id'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['field'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="cseu-event-date">[field_cseu_event_date]</span>|<span class="cseu-event-venue">[field_cseu_event_venue_locality], [field_cseu_event_venue_country]</span>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'cseu-event-heading';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'cseu-event-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_cseu_event_date.field_cseu_event_date_value' => 'field_data_field_cseu_event_date.field_cseu_event_date_value',
  );

  /* Display: Upcoming iCal */
  $handler = $view->new_display('block', 'Upcoming iCal', 'upcal');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['display_description'] = 'Upcoming events block';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'events_all';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No upcoming events.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cseu_event_date']['id'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['field'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['settings'] = array(
    'format_type' => 'cseu_date_type_iso_8601',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_cseu_event_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['delta_offset'] = '0';
  /* Field: Content: Venue - Country */
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['id'] = 'field_cseu_event_venue_country';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['field'] = 'field_cseu_event_venue_country';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['display_name'] = 1;
  /* Field: Content: Venue - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['id'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['field'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="cseu-event-date">[field_cseu_event_date]</span>|<span class="cseu-event-venue">[field_cseu_event_venue_locality], [field_cseu_event_venue_country]</span>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'cseu-event-heading';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'cseu-event-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['add_delta'] = 'yes';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_cseu_event_date.field_cseu_event_date_value' => 'field_data_field_cseu_event_date.field_cseu_event_date_value',
  );

  /* Display: Past Events */
  $handler = $view->new_display('page', 'Past Events', 'past');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Past Events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_cseu_event_date_1',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'cseu-events-calendar-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_cseu_event_date' => 'field_cseu_event_date',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No upcoming events.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Style from category  */
  $handler->display->display_options['fields']['field_cseu_event_type_1']['id'] = 'field_cseu_event_type_1';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['table'] = 'field_data_field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['field'] = 'field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['ui_name'] = 'Style from category ';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_type_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_type_1']['alter']['text'] = 'cseu-event-category-[field_cseu_event_type_1-tid]';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type_1']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Event Date - Month */
  $handler->display->display_options['fields']['field_cseu_event_date_1']['id'] = 'field_cseu_event_date_1';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['field'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['ui_name'] = 'Event Date - Month';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date_1']['settings'] = array(
    'format_type' => 'cseu_date_type_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Venue - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['id'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['field'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_default_classes'] = FALSE;
  /* Field: Event Category */
  $handler->display->display_options['fields']['field_cseu_event_type']['id'] = 'field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type']['table'] = 'field_data_field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type']['field'] = 'field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type']['ui_name'] = 'Event Category';
  $handler->display->display_options['fields']['field_cseu_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_type']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cseu_event_type']['element_class'] = 'cseu-event-category [field_cseu_event_type_1]';
  $handler->display->display_options['fields']['field_cseu_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cseu_event_date']['id'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['field'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_date']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cseu_event_date']['element_class'] = 'cseu-event-date';
  $handler->display->display_options['fields']['field_cseu_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['settings'] = array(
    'format_type' => 'cseu_date_type_iso_8601',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['fields']['field_cseu_event_date']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['delta_offset'] = '0';
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'field_cseu_event_type_2',
    1 => 'title',
    2 => 'field_cseu_event_venue_country',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'cseu-event-content';
  /* Field: Event Category - Mobile */
  $handler->display->display_options['fields']['field_cseu_event_type_2']['id'] = 'field_cseu_event_type_2';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['table'] = 'field_data_field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['field'] = 'field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['ui_name'] = 'Event Category - Mobile';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['element_class'] = 'cseu-event-category-mobile [field_cseu_event_type_1]';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type_2']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'cseu-event-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = FALSE;
  /* Field: Content: Venue - Country */
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['id'] = 'field_cseu_event_venue_country';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['field'] = 'field_cseu_event_venue_country';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['alter']['text'] = '[field_cseu_event_venue_locality], [field_cseu_event_venue_country]';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_class'] = 'cseu-event-venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['display_name'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_cseu_event_date) */
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['id'] = 'field_cseu_event_date_value';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['field'] = 'field_cseu_event_date_value';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '<';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_cseu_event_date.field_cseu_event_date_value' => 'field_data_field_cseu_event_date.field_cseu_event_date_value',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cseu_event' => 'cseu_event',
  );
  /* Filter criterion: Content: Category (field_cseu_event_type) */
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['id'] = 'field_cseu_event_type_tid';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['table'] = 'field_data_field_cseu_event_type';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['field'] = 'field_cseu_event_type_tid';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['expose']['operator_id'] = 'field_cseu_event_type_tid_op';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['expose']['operator'] = 'field_cseu_event_type_tid_op';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_cseu_event_type_tid']['vocabulary'] = 'cseu_event_types';
  $handler->display->display_options['path'] = 'events/past';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Past Events';
  $handler->display->display_options['menu']['weight'] = '6';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'All Events';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';
  $export['cseu_events_calendar_view'] = $view;

  $view = new view();
  $view->name = 'cseu_view_list_events_by_usage';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'List of events by usage';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'cseu-article-teaser-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cseu_event_date']['id'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['field'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['settings'] = array(
    'format_type' => 'medium',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Venue - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['id'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['field'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_default_classes'] = FALSE;
  /* Field: Content: Venue - Country */
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['id'] = 'field_cseu_event_venue_country';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['field'] = 'field_cseu_event_venue_country';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['alter']['text'] = '[field_cseu_event_venue_locality], [field_cseu_event_venue_country]';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['display_name'] = 1;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
  /* Field: Wrapper */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Wrapper';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<article class="cseu-article-teaser-horizontal-layout">
	<header class="cseu-article-teaser-header-container">
		<h2 class="cseu-article-teaser-title-smaller">
			[title]
		</h2>	
		<p class="cseu-article-teaser-date-bold">
			[field_cseu_event_date]
                        <br />
			[field_cseu_event_venue_country]
		</p>
	</header>
	<div class="cseu-article-teaser-wrapper">
		<div class="cseu-article-teaser-content-container without-teaser-image">
			<div class="cseu-article-teaser-synopsis">
				[body]
			</div>
			<p class="cseu-article-teaser-target-link">
				[view_node]
			</p>
		</div>
	</div>
</article>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_cseu_event_date) */
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['id'] = 'field_cseu_event_date_value';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['field'] = 'field_cseu_event_date_value';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['order'] = 'DESC';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'cseu_usage' => 'cseu_usage',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cseu_event' => 'cseu_event',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = '%';
  $export['cseu_view_list_events_by_usage'] = $view;

  $view = new view();
  $view->name = 'cseu_view_list_training_schools';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Training Schools';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'cseu-article-teaser-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No upcoming training schools.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cseu_event_date']['id'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['field'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['settings'] = array(
    'format_type' => 'medium',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Venue - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['id'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['field'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_default_classes'] = FALSE;
  /* Field: Content: Venue - Country */
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['id'] = 'field_cseu_event_venue_country';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['field'] = 'field_cseu_event_venue_country';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['alter']['text'] = '[field_cseu_event_venue_locality], [field_cseu_event_venue_country]';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['display_name'] = 1;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
  /* Field: Wrapper */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Wrapper';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<article class="cseu-article-teaser-horizontal-layout">
	<header class="cseu-article-teaser-header-container">
		<h2 class="cseu-article-teaser-title-smaller">
			[title]
		</h2>	
		<p class="cseu-article-teaser-date-bold">
			[field_cseu_event_date]
                        <br />
			[field_cseu_event_venue_country]
		</p>
	</header>
	<div class="cseu-article-teaser-wrapper">
		<div class="cseu-article-teaser-content-container without-teaser-image">
			<div class="cseu-article-teaser-synopsis">
				[body]
			</div>
			<p class="cseu-article-teaser-target-link">
				[view_node]
			</p>
		</div>
	</div>
</article>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_cseu_event_date) */
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['id'] = 'field_cseu_event_date_value';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['field'] = 'field_cseu_event_date_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cseu_event' => 'cseu_event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '97',
  );
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'cseu_usage';
  /* Filter criterion: Content: Date -  start date (field_cseu_event_date) */
  $handler->display->display_options['filters']['field_cseu_event_date_value']['id'] = 'field_cseu_event_date_value';
  $handler->display->display_options['filters']['field_cseu_event_date_value']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['filters']['field_cseu_event_date_value']['field'] = 'field_cseu_event_date_value';
  $handler->display->display_options['filters']['field_cseu_event_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_cseu_event_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_cseu_event_date_value']['default_date'] = 'today';

  /* Display: Upcoming */
  $handler = $view->new_display('page', 'Upcoming', 'upcoming');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Training Schools';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_cseu_event_date) */
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['id'] = 'field_cseu_event_date_value';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['field'] = 'field_cseu_event_date_value';
  $handler->display->display_options['path'] = 'training-schools/upcoming';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Upcoming';
  $handler->display->display_options['menu']['description'] = 'Upcoming Training Schools';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Training Schools';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: Past */
  $handler = $view->new_display('page', 'Past', 'past');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Past Training Schools';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No past training schools.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_cseu_event_date) */
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['id'] = 'field_cseu_event_date_value';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['field'] = 'field_cseu_event_date_value';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cseu_event' => 'cseu_event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '97',
  );
  $handler->display->display_options['filters']['tid']['group'] = 1;
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'cseu_usage';
  /* Filter criterion: Content: Date -  start date (field_cseu_event_date) */
  $handler->display->display_options['filters']['field_cseu_event_date_value']['id'] = 'field_cseu_event_date_value';
  $handler->display->display_options['filters']['field_cseu_event_date_value']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['filters']['field_cseu_event_date_value']['field'] = 'field_cseu_event_date_value';
  $handler->display->display_options['filters']['field_cseu_event_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_cseu_event_date_value']['group'] = 1;
  $handler->display->display_options['filters']['field_cseu_event_date_value']['default_date'] = 'now';
  $handler->display->display_options['path'] = 'training-schools/past';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Past';
  $handler->display->display_options['menu']['description'] = 'Past Training Schools';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['cseu_view_list_training_schools'] = $view;

  $view = new view();
  $view->name = 'cseu_wg_events_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Working Group Events List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_accordion';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_ressource_type',
      'rendered' => 0,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'cseu-chairs-by-group-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['use-grouping-header'] = 1;
  $handler->display->display_options['style_options']['collapsible'] = 1;
  $handler->display->display_options['style_options']['row-start-open'] = 'none';
  $handler->display->display_options['style_options']['autoheight'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'cseu_working_group' => 'cseu_working_group',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cseu_working_group' => 'cseu_working_group',
  );

  /* Display: WG Events */
  $handler = $view->new_display('page', 'WG Events', 'events_page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'cseu-wg-events-list-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Content: Long label  */
  $handler->display->display_options['fields']['field_cseu_long_label']['id'] = 'field_cseu_long_label';
  $handler->display->display_options['fields']['field_cseu_long_label']['table'] = 'field_data_field_cseu_long_label';
  $handler->display->display_options['fields']['field_cseu_long_label']['field'] = 'field_cseu_long_label';
  $handler->display->display_options['fields']['field_cseu_long_label']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_long_label']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_long_label']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_long_label']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_long_label']['type'] = 'text_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_cseu_long_label] - [title]';
  $handler->display->display_options['fields']['title']['alter']['path'] = '/wgs/wg[nid]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'cseu-wgs-list-view-title-hidden';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['nid']['title'] = '%1';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'cseu_working_group' => 'cseu_working_group',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cseu_working_group' => 'cseu_working_group',
  );
  $handler->display->display_options['path'] = 'wgs/%/events';
  $handler->display->display_options['menu']['title'] = 'Working Groups';
  $handler->display->display_options['menu']['description'] = 'Working Groups';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Attach WG Events */
  $handler = $view->new_display('attachment', 'Attach WG Events', 'attach_events');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'attachment-accordion-wg-events';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_accordion';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_cseu_event_date_1',
      'rendered' => 1,
      'rendered_strip' => 1,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'cseu-events-calendar-row';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['use-grouping-header'] = 1;
  $handler->display->display_options['style_options']['collapsible'] = 1;
  $handler->display->display_options['style_options']['row-start-open'] = 'none';
  $handler->display->display_options['style_options']['autoheight'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No upcoming events.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Article referencing from field_working_group */
  $handler->display->display_options['relationships']['reverse_field_working_group_node']['id'] = 'reverse_field_working_group_node';
  $handler->display->display_options['relationships']['reverse_field_working_group_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_working_group_node']['field'] = 'reverse_field_working_group_node';
  $handler->display->display_options['relationships']['reverse_field_working_group_node']['ui_name'] = 'Article referencing from field_working_group';
  $handler->display->display_options['relationships']['reverse_field_working_group_node']['label'] = 'Article referencing from field_working_group';
  $handler->display->display_options['relationships']['reverse_field_working_group_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  /* Field: Style from category */
  $handler->display->display_options['fields']['field_cseu_event_type_1']['id'] = 'field_cseu_event_type_1';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['table'] = 'field_data_field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['field'] = 'field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['relationship'] = 'reverse_field_working_group_node';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['ui_name'] = 'Style from category';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_type_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_type_1']['alter']['text'] = 'cseu-event-category-[field_cseu_event_type_1-tid]';
  $handler->display->display_options['fields']['field_cseu_event_type_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type_1']['type'] = 'taxonomy_term_reference_plain';
  /* Field:  Event Date - Month */
  $handler->display->display_options['fields']['field_cseu_event_date_1']['id'] = 'field_cseu_event_date_1';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['field'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['relationship'] = 'reverse_field_working_group_node';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['ui_name'] = ' Event Date - Month';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_date_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_date_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date_1']['settings'] = array(
    'format_type' => 'date_format_cseu_date_type_month',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Article Ressource Type */
  $handler->display->display_options['fields']['field_ressource_type']['id'] = 'field_ressource_type';
  $handler->display->display_options['fields']['field_ressource_type']['table'] = 'field_data_field_ressource_type';
  $handler->display->display_options['fields']['field_ressource_type']['field'] = 'field_ressource_type';
  $handler->display->display_options['fields']['field_ressource_type']['relationship'] = 'reverse_field_working_group_node';
  $handler->display->display_options['fields']['field_ressource_type']['ui_name'] = 'Article Ressource Type';
  $handler->display->display_options['fields']['field_ressource_type']['label'] = '';
  $handler->display->display_options['fields']['field_ressource_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ressource_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ressource_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_ressource_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'reverse_field_working_group_node';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['element_default_classes'] = FALSE;
  /* Field: Content: Venue - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['id'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['field'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['relationship'] = 'reverse_field_working_group_node';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_default_classes'] = FALSE;
  /* Field: Event Category */
  $handler->display->display_options['fields']['field_cseu_event_type']['id'] = 'field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type']['table'] = 'field_data_field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type']['field'] = 'field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type']['relationship'] = 'reverse_field_working_group_node';
  $handler->display->display_options['fields']['field_cseu_event_type']['ui_name'] = 'Event Category';
  $handler->display->display_options['fields']['field_cseu_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_type']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cseu_event_type']['element_class'] = 'cseu-event-category [field_cseu_event_type_1]';
  $handler->display->display_options['fields']['field_cseu_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_cseu_event_date']['id'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['field'] = 'field_cseu_event_date';
  $handler->display->display_options['fields']['field_cseu_event_date']['relationship'] = 'reverse_field_working_group_node';
  $handler->display->display_options['fields']['field_cseu_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_date']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cseu_event_date']['element_class'] = 'cseu-event-date';
  $handler->display->display_options['fields']['field_cseu_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_date']['settings'] = array(
    'format_type' => 'date_format_cseu_date_type_iso_8601',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'field_cseu_event_type_2',
    1 => 'title',
    2 => 'field_cseu_event_venue_country',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'cseu-event-content';
  /* Field: Event Category - Mobile */
  $handler->display->display_options['fields']['field_cseu_event_type_2']['id'] = 'field_cseu_event_type_2';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['table'] = 'field_data_field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['field'] = 'field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['relationship'] = 'reverse_field_working_group_node';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['ui_name'] = 'Event Category - Mobile';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['element_class'] = 'cseu-event-category-mobile [field_cseu_event_type_1]';
  $handler->display->display_options['fields']['field_cseu_event_type_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type_2']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_working_group_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'cseu-event-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Venue - Country */
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['id'] = 'field_cseu_event_venue_country';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['field'] = 'field_cseu_event_venue_country';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['relationship'] = 'reverse_field_working_group_node';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['alter']['text'] = '[field_cseu_event_venue_locality], [field_cseu_event_venue_country]';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_class'] = 'cseu-event-venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_country']['display_name'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date -  start date (field_cseu_event_date) */
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['id'] = 'field_cseu_event_date_value';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['table'] = 'field_data_field_cseu_event_date';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['field'] = 'field_cseu_event_date_value';
  $handler->display->display_options['sorts']['field_cseu_event_date_value']['relationship'] = 'reverse_field_working_group_node';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cseu_working_group' => 'cseu_working_group',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_working_group_node';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'cseu_event' => 'cseu_event',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['relationship'] = 'reverse_field_working_group_node';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_cseu_event_date.field_cseu_event_date_value' => 'field_data_field_cseu_event_date.field_cseu_event_date_value',
  );
  $handler->display->display_options['displays'] = array(
    'events_page' => 'events_page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $export['cseu_wg_events_list'] = $view;

  return $export;
}
