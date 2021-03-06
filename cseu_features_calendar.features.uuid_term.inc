<?php
/**
 * @file
 * cseu_features_calendar.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function cseu_features_calendar_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'COST Action Event',
    'description' => '<p>CA15212 own events, deriving from working groups activities.</p>',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '47577082-a851-4e79-be05-daeca36e124e',
    'vocabulary_machine_name' => 'cseu_event_types',
    'path' => array(
      'pathauto' => 0,
    ),
  );
  $terms[] = array(
    'name' => 'External Event',
    'description' => '<p>Events done by others on citizen science research and policy events.</p>',
    'format' => 'full_html',
    'weight' => 1,
    'uuid' => '803eafd5-3521-4f7f-8db6-b7d02e9dfdbe',
    'vocabulary_machine_name' => 'cseu_event_types',
    'path' => array(
      'pathauto' => 0,
    ),
  );
  $terms[] = array(
    'name' => 'Training Schools',
    'description' => '<p>Training Schools</p>',
    'format' => 'full_html',
    'weight' => 0,
    'uuid' => '92705ee2-cbb1-4e53-b3ae-569a561b96b2',
    'vocabulary_machine_name' => 'cseu_usage',
    'path' => array(
      'pathauto' => 0,
    ),
  );
  return $terms;
}
