<?php
/**
 * @file
 * qma_in_conversation.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function qma_in_conversation_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'conversation_hub';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'interview_hub' => 'interview_hub',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-interviews-block_1' => array(
          'module' => 'views',
          'delta' => 'interviews-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-interviews-block' => array(
          'module' => 'views',
          'delta' => 'interviews-block',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;
  $export['conversation_hub'] = $context;

  return $export;
}
