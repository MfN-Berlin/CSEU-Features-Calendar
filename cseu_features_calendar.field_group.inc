<?php
/**
 * @file
 * cseu_features_calendar.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cseu_features_calendar_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categorisation|node|cseu_event|form';
  $field_group->group_name = 'group_categorisation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cseu_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categorisation',
    'weight' => '1',
    'children' => array(
      0 => 'field_cseu_event_type',
      1 => 'field_working_group',
      2 => 'field_cseu_usage',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-categorisation field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_categorisation|node|cseu_event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|cseu_event|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cseu_event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event',
    'weight' => '0',
    'children' => array(
      0 => 'field_cseu_event_date',
      1 => 'field_cseu_event_venue',
      2 => 'body',
      3 => 'field_cseu_cover_image',
      4 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_content|node|cseu_event|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Categorisation');
  t('Event');

  return $field_groups;
}
