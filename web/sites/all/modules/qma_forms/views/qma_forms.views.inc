<?php

/**
 * @file
 * qma_forms.views.inc
 */


/**
 * Implements hook_views_data().
 */
function qma_forms_views_data() {
  $data = array();

  $data['qma_forms_question'] = array(
    'table' => array(
      'base' => array(
        'field' => 'qid',
        'title' => 'Qma Forms Question',
        'help' => 'A table to contain interview questions',
      ),
      'group' => 'Qma Forms Question',
    ),
    'qid' => array(
      'title' => 'Qid',
      'help' => 'The primary key',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
    ),
    'language' => array(
      'title' => 'Language',
      'help' => 'The languages.language of this question.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'created' => array(
      'title' => 'Created',
      'help' => 'The Unix timestamp when the question was created.',
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_date',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_date',
      ),
    ),
    'question' => array(
      'title' => 'Question',
      'help' => 'The question text.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
    ),
    'name' => array(
      'title' => 'Name',
      'help' => 'The questioner’s name.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'interviewee' => array(
      'title' => 'Interviewee',
      'help' => 'The interviewee’s name.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_qma_forms_interviewee',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'location' => array(
      'title' => 'Location',
      'help' => 'The question’s location.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'email' => array(
      'title' => 'Email',
      'help' => 'The question’s email address.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
  );
  
  
  
  $data['qma_forms_press_question'] = array(
    'table' => array(
      'base' => array(
        'field' => 'qid',
        'title' => 'Qma Forms Press Question',
        'help' => 'A table to contain press questions',
      ),
      'group' => 'Qma Forms Press Question',
    ),
    'qid' => array(
      'title' => 'Qid',
      'help' => 'The primary key',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
    ),
    'language' => array(
      'title' => 'Language',
      'help' => 'The languages.language of this question.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'created' => array(
      'title' => 'Created',
      'help' => 'The Unix timestamp when the question was created.',
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_date',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_date',
      ),
    ),
    'question' => array(
      'title' => 'Question',
      'help' => 'The question text.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
    ),
    'name' => array(
      'title' => 'Name',
      'help' => 'The questioner’s name.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'organisation' => array(
      'title' => 'Company',
      'help' => 'The enquirer’s organisation.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'request_type' => array(
      'title' => 'Request',
      'help' => 'The request type(s).',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'email' => array(
      'title' => 'Email',
      'help' => 'The enquirer’s email address.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
  );
  
  
  
  $data['qma_forms_resource_question'] = array(
    'table' => array(
      'base' => array(
        'field' => 'qid',
        'title' => 'Qma Forms Creative Resource Question',
        'help' => 'A table to contain Creative Resource questions',
      ),
      'group' => 'Qma Forms Creative Resource Question',
    ),
    'qid' => array(
      'title' => 'Qid',
      'help' => 'The primary key',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
    ),
    'language' => array(
      'title' => 'Language',
      'help' => 'The languages.language of this suggestion.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'created' => array(
      'title' => 'Created',
      'help' => 'The Unix timestamp when the question was created.',
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_date',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_date',
      ),
    ),
    'question' => array(
      'title' => 'Suggestion',
      'help' => 'The suggestion text.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
    ),
    'name' => array(
      'title' => 'Name',
      'help' => 'The respondent’s name.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'email' => array(
      'title' => 'Email',
      'help' => 'The respondent’s email address.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
  );

  $data['qma_forms_education_question'] = array(
    'table' => array(
      'base' => array(
        'field' => 'qid',
        'title' => 'Qma Forms Education Question',
        'help' => 'A table to contain Education questions',
      ),
      'group' => 'Qma Forms Education Question',
    ),
    'qid' => array(
      'title' => 'Qid',
      'help' => 'The primary key',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
    ),
    'language' => array(
      'title' => 'Language',
      'help' => 'The languages.language of this suggestion.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'created' => array(
      'title' => 'Created',
      'help' => 'The Unix timestamp when the question was created.',
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_date',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_date',
      ),
    ),
    'suggestion' => array(
      'title' => 'Suggestion',
      'help' => 'The suggestion text.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
    ),
    'name' => array(
      'title' => 'Name',
      'help' => 'The respondent’s name.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'company' => array(
      'title' => 'Name',
      'help' => 'The respondent’s company.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'email' => array(
      'title' => 'Email',
      'help' => 'The respondent’s email address.',
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
  );

  return $data;
}
