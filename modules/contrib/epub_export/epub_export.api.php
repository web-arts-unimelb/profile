<?php
/**
 * @file
 * EPUB Export API developer documentation.
 */

/**
 * Alter the individual discovered assets.
 *
 * @param array $asset
 *   An array detailing asset data. Setting the asset array to
 *   anything that evaluates as false when passed as a paremeter to empty()
 *   will result in the asset being omitted from the entity export.
 *
 * @param array $context
 *   An array keyed by entity_type and entity_id providing entity
 *   context for the given asset.
 *
 * @see EPUBExport::parseAssets()
 */
function hook_epub_export_asset_alter(&$asset, $context) {

}

/**
 * Alter the complete set of discovered assets.
 *
 * @param array $assets
 *   An array detailing asset data. Keyed by asset URI containing
 *   the complete asset collection. Unsetting an asset element will omit that
 *   asset from the EPUB export.
 *
 * @param array $context
 *   An array keyed by entity_type and entity_id providing entity
 *   context for the given assets.
 *
 * @see EPUBExport::parseAssets()
 * @see hook_epub_export_asset_alter()
 */
function hook_epub_export_assets_alter(&$assets, $context) {

}

/**
 * Alter the tag map which defines how assets are discovered via content.
 *
 * @param array $map
 *   An associative array keyed by html tag with the html attribute
 *   corresponding to linked or referenced content.
 *
 * @param array $context
 *   An array keyed by entity_type and entity_id providing entity context for
 *   the given calling context.
 *
 * @see EPUBExport::tagMap()
 * @see EPUBExport::findAssets()
 * @see EPUBExport::rewriteResourceLinks()
 */
function hook_epub_export_tag_map_alter(&$map, $context) {

}

/**
 * Alter the css classes corresponding to content to omit from the export.
 *
 * Any content within tags of the listed classes will be removed from the
 * exported content. This is useful to ensure things like edit links, and
 * other information that is highly contextual is omitted from a static
 * export of the content.
 *
 * @param array $classes
 *   An array of css classes to filter content by
 * @param array $context
 *   An array keyed by entity_type and entity_id providing entity context for
 *   the given asset.
 *
 * @see EPUBExport::strip_classes()
 * @see EPUBExport::stripClasses()
 */
function hook_epub_export_strip_classes_alter(&$classes, $context) {
}

/**
 * Alter the paths that will be omitted from the export.
 *
 * This is used when discovering what content should be included as part of
 * the EPUB export. This is useful for preventing the exporter from traversing
 * to unwanted portions of your site or locations that may be contextually
 * irrelevent.
 *
 *  @param array $paths
 *   An array of paths to skip when considering what is an exported asset or
 *   not.
 * @param array $context
 *   An array keyed by entity_type and entity_id providing entity
 *   context for the given asset.
 *
 * @see hook_epub_export_asset_alter()
 * @see hook_epub_export_assets_alter()
 * @see EPUBExport::prune_paths()
 * @see EPUBExport::getPrunePaths()
 * @see EPUBExport::parseAssets()
 */
function hook_epub_export_prune_paths_alter(&$paths, $context) {
}

/**
 * Alter the supported types.
 *
 * This is used to determine what entity types will be included in the export.
 * By default this list consists of node and taxonomy.
 *
 * @param array $types
 *   An array of supported entity types to package with the EPUB.
 */
function hook_epub_export_supported_types_alter(&$types) {

}

/**
 * Alter the entity types that will be used a navigational elements.
 *
 * The entity types managed via this altering function will be used to create
 * the navigation document and the legacy NCX document.
 *
 * @param array $types
 *   An array of supported entity types to package with the EPUB.
 */
function hook_epub_export_navigation_types_alter(&$types) {
}
