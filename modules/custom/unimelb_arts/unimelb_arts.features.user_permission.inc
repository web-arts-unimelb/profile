<?php
/**
 * @file
 * unimelb_arts.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function unimelb_arts_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration menu.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'admin',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'admin',
      1 => 'editor',
      2 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: administer content types.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      0 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: administer nodequeue.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      0 => 'site admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create event content.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create news content.
  $permissions['create news content'] = array(
    'name' => 'create news content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create page content.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any event content.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any news content.
  $permissions['delete any news content'] = array(
    'name' => 'delete any news content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any page content.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own event content.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own news content.
  $permissions['delete own news content'] = array(
    'name' => 'delete own news content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own page content.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any event content.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any news content.
  $permissions['edit any news content'] = array(
    'name' => 'edit any news content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any page content.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own event content.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      0 => 'admin',
      1 => 'editor',
      2 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own news content.
  $permissions['edit own news content'] = array(
    'name' => 'edit own news content',
    'roles' => array(
      0 => 'admin',
      1 => 'editor',
      2 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own page content.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      0 => 'admin',
      1 => 'editor',
      2 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: manipulate all queues.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: manipulate queues.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: show format selection for node.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      0 => 'site admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for taxonomy_term.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      0 => 'site admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for user.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      0 => 'site admin',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format tips.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: show more format tips link.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'admin',
      1 => 'editor',
      2 => 'site admin',
    ),
    'module' => 'node',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      0 => 'admin',
      1 => 'site admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
