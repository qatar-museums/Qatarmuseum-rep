<?php
/**
 * @file QMA Views definitions.
 */

/*
* QMA uses the i18n_menu_node module to allow simplicity in maintaining a multilingual menu
* We query the menu structure with views (via menu_node_views module) to produce listings of child pages
* These two modules do not work well together as menu_node_views queries the menu_node table
* Lookup of menu trail on current node will fail for translations as they have no entry in menu_node table
* To avoid this we re-implement the contextual filter provided by menu_node_views to find the source node and lookup from there to retrieve the true menu trail
* This retrieves the source node for each translation and so we then perform the hook qma_menus_views_post_execute to alter the results set and convert to the current language
*
* To avoid the post execute hook we could do this in a single query by adding
* LEFT JOIN node n2 ON (n2.tnid = node.nid OR (node.tnid=0 AND n2.nid=node.nid))
* WHERE n2.language=the current language OR undefined
* and then return n2.nid as nid
*/

/**
 * Implement hook_views_data().
 * Here we register the new contextual filter described above
 */
function qma_menus_views_data() {
  $data = array();
  $data['menu_links']['i18n_nid'] = array(
    'title' => t('i18n Node id', array(), array('context' => 'QMA')),
    'help' => t('IMPORTANT, READ COMMENTS IN qma_menus.views.inc', array(), array('context' => 'QMA')),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'qma_menus_argument_nid',
    ),
    
  );
  
  
  return $data;
}
