<?php
/**
 * @file
 * qma_site_config.default_elysia_cron_rules.inc
 */

/**
 * Implements hook_default_elysia_cron_rules().
 */
function qma_site_config_default_elysia_cron_rules() {
  $cron_rules = array();

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = ':default';
  $cron_rule->disable = FALSE;
  $cron_rule->rule = NULL;
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules[':default'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'acquia_agent_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 * * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['acquia_agent_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'backup_migrate_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 */6 * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['backup_migrate_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'ctools_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 */6 * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['ctools_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'dblog_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '*/30 * * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['dblog_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'drupagram_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '*/30 * * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['drupagram_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'field_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 */6 * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['field_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'googleanalytics_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '4 0 * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['googleanalytics_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'honeypot_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 * * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['honeypot_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'l10n_update_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = NULL;
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['l10n_update_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'linkchecker_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 * * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['linkchecker_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'logintoboggan_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 * * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['logintoboggan_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'node_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '*/30 * * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['node_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'oauth_common_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 * * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['oauth_common_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'qma_membership_code_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 */6 * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['qma_membership_code_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'registration_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '0 * * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['registration_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'search_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '*/15 * * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['search_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'system_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '*/15 * * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['system_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'twitter_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '*/15 * * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['twitter_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'update_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '4 0 * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['update_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'views_data_export_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '4 0 * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['views_data_export_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'votingapi_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '*/30 * * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['votingapi_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'xmlsitemap_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '4 0 * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['xmlsitemap_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'xmlsitemap_engines_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '4 0 * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['xmlsitemap_engines_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'xmlsitemap_menu_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '4 0 * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['xmlsitemap_menu_cron'] = $cron_rule;

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'xmlsitemap_node_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = '4 0 * * *';
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['xmlsitemap_node_cron'] = $cron_rule;

  return $cron_rules;

}
