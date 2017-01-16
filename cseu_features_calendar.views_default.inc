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
  $handler->display->display_options['title'] = 'Upcoming Events';
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
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_cseu_event_type']['id'] = 'field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type']['table'] = 'field_data_field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type']['field'] = 'field_cseu_event_type';
  $handler->display->display_options['fields']['field_cseu_event_type']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Venue - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['id'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['table'] = 'field_data_field_cseu_event_venue';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['field'] = 'field_cseu_event_venue_locality';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['label'] = '';
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cseu_event_venue_locality']['element_default_classes'] = FALSE;
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
    0 => 'title',
    1 => 'field_cseu_event_venue_country',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'cseu-event-content';
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
  $export['cseu_events_calendar_view'] = $view;

  return $export;
}
