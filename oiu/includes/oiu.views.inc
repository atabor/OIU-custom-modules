<?php

function oiu_views_data() {

  $data = array();
  
  $data['related_stories_weight']['table']['group'] = t('Related Stories');
  
  $data['related_stories_weight']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'nid_story',
  );
  // would like to rename 'field' back to nid_story once this gets working
  // --> did it but is it a good idea; seems to be opposite of convention
  
/*  $data['related_stories_weight']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'nid_connected_story',
  );*/

  
  
  // fields ****************************************************
  
  // nid_story
  // >> not sure what really has to be defined here
  $data['related_stories_weight']['nid_story'] = array(
  'title' => t('Nid Story'),
  'help' => t('The node ID of the anchor story.'), 
  'field' => array(
    'handler' => 'views_handler_field_node',
    'click sortable' => TRUE,
  ),
  'argument' => array(
    'handler' => 'views_handler_argument_node_nid',
    'name field' => 'title', // the field to display in the summary.
    'numeric' => TRUE,
  ),
  'filter' => array(
    'handler' => 'views_handler_filter_numeric',
  ),
  'sort' => array(
    'handler' => 'views_handler_sort',
  ),
  'relationship' => array(
    'label' => t('Node'),
    'base' => 'node', 
    'base field' => 'nid',
   ),
);
  
// nid_connected_story  
$data['related_stories_weight']['nid_connected_story'] = array(
  'title' => t('Nid Connected Story'),
  'help' => t('The node ID of connected story nodes.'), 
  'field' => array(
    'handler' => 'views_handler_field_node',
    'click sortable' => TRUE,
  ),
  'argument' => array(
    'handler' => 'views_handler_argument_node_nid',
    'name field' => 'title',
    'numeric' => TRUE,
    'validate type' => 'nid',
  ),
  'filter' => array(
    'handler' => 'views_handler_filter_numeric',
  ),
  'sort' => array(
    'handler' => 'views_handler_sort',
  ),
  'relationship' => array(
    'label' => t('Node'),
    'base' => 'node', 
    'base field' => 'nid',
   )
);

// weight
$data['related_stories_weight']['weight'] = array(
  'title' => t('Weight'),
  'help' => t('The strength of the connection.'),
  'field' => array(
    'handler' => 'views_handler_field_numeric',
    'click sortable' => TRUE,
  ),
  'argument' => array(
    'handler' => 'views_handler_argument_numeric',
  ),
  'filter' => array(
    'handler' => 'views_handler_filter_numeric',
  ),
  'sort' => array(
    'handler' => 'views_handler_sort',
  ),
);

// strongest_connection - currently not filled in
/* $data['related_stories_weight']['strongest_connection'] = array(
  'title' => t('Strongest Connection'),
  'help' => t('The type of connection that contributes most to Weight.'),
  'field' => array(
    'handler' => 'views_handler_field_string',
    'click sortable' => TRUE,
  ),
  'argument' => array(
    'handler' => 'views_handler_argument_string',
  ),
  'filter' => array(
    'handler' => 'views_handler_filter_string',
  ),
  // Information for sorting on a nid.
  'sort' => array(
    'handler' => 'views_handler_sort',
  ),
);
 */
  
return $data;
}

  