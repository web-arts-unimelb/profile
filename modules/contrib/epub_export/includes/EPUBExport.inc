<?php
/**
 * @file
 * Main integration class for working with FunnyMonkey\EPUB\EPUBPackage class.
 */


use FunnyMonkey\EPUB\EPUBPackage as FMEPub;

define('EPUB_EXPORT_NOLOAD', 1);
define('EPUB_EXPORT_NORENDER', 2);

class EPUBExport {
  /**
   * @var array of assets that are related to the primary piece of content
   */
  protected $assets = array();

  /**
   * @var string stores the entity type
   */
  protected $entity_type = '';

  /**
   * @var int entity id
   */
  protected $id = 0;

  /**
   * @var string htmlid concated entity_type and entity id
   */
  protected $htmlid = '-0';

  /**
   * @var DOMDocument stores the DOMDocument representation of the rendered
   * content for adjusting markup and content as necessary
   */
  protected $dom = NULL;

  /**
   * @var string representing the current asset path alias
   */
  protected $alias = '';

  /**
   * @var string representing the amount of redirection required to reference
   * other items.
   */
  protected $pathRedirection = '';

  /**
   * @var mixed stdClass this will generally be a loaded entity object from
   * the appropriate entity_load() function.
   */
  public $entity = NULL;

  /**
   * @var string holds the rendered entity object
   */
  public $rendered = '';

  /**
   * Constructor.
   *
   * @param string $entity_type
   *   String indicating the entity type
   * @param int $id
   *   Entity id to load for the given type
   */
  public function __construct($entity_type, $id = 0) {
    $this->entity_type = $entity_type;
    $this->id = $id;
    $this->htmlid = $this->entity_type . '-' . $id;
    try {
      $this->load();
    }
    catch (Exception $e) {
      return FALSE;
    }

    return TRUE;
  }

  /**
   * Returns a context useful for calls to drupal_alter, etc.
   */
  public function context() {
    return array(
      'entity_type' => $this->entity_type,
      'id' => $this->id,
    );
  }

  /**
   * Attempts to load the requested entity into the object.
   *
   * After calling the load method the DOM will be loaded and rendered via the
   * appropriate drupal calls. This will also do any basic setup to remove
   * extraneous markup via css classes.
   *
   * @throws 'Unable to load type[...]' exception if the entity cannot be loaded
   * @throws 'Unable to render entity[...] if an appropriate rendering function
   * cannot be found.
   * @throws DOM_NO_MODIFICATION_ALLOWED_ERR via DOMNode::removeChild
   * @throws DOM_NOT_FOUND via DOMNode::removeChild
   * @see http://us2.php.net/manual/en/domnode.removechild.php
   * @todo  Better generalize the render chain, and path redirection.
   */
  public function load() {
    // @todo can we make this more generic (eg. explode('_', $entity_type))?
    // then pass to drupal_alter()
    switch ($this->entity_type) {
      case 'node':
        $this->alias = drupal_get_path_alias('node/' . $this->id);
        $parts = explode('/', $this->alias);
        $this->pathRedirection = str_repeat('../', count($parts));
        break;
      case 'taxonomy_term':
        $this->alias = drupal_get_path_alias('taxonomy/term/' . $this->id);
        $parts = explode('/', $this->alias);
        $this->pathRedirection = str_repeat('../', count($parts));
        break;
      default:
        // Do nothing for now.
    }

    // Load the requested entity.
    $centity = reset(entity_load($this->entity_type, array($this->id), array(), TRUE));
    $entity = clone($centity);
    $this->entity = $entity;
    if (empty($this->entity)) {
      throw new Exception('Unable to load type: ' . $this->typeinfo(), EPUB_EXPORT_NOLOAD);
    }

    $uri = entity_uri($this->entity_type, $this->entity);
    if (!empty($uri['path'])) {
      // Add the originating entity to the asset list.
      $this->assets[$uri['path']] = array();
    }

    // Attempt to render the entity using the appropriate render function.
    $data = entity_view($this->entity_type, array($this->entity), 'epub_export');
    $this->rendered = drupal_render($data);

    $head = $this->getHead();
    $scripts = $this->getScripts();

    $variables = array(
      'head' => $head,
      'head_title' => check_plain(entity_label($this->entity_type, $this->entity)),
      'styles' => '',
      'scripts' => $scripts,
      'attributes' => '',
      'content' => $this->rendered,
      'page_bottom' => '',
    );
    $variables['language'] = $GLOBALS['language'];
    $variables['language']->dir = $GLOBALS['language']->direction ? 'rtl' : 'ltr';

    $this->rendered = theme('epub_export', $variables);

    $this->dom = new DOMDocument('1.0', 'utf-8');
    $this->dom->preserveWhiteSpace = FALSE;
    $this->dom->validateOnParse = TRUE;
    $this->dom->strictErrorChecking = FALSE;

    // We use adjust libxml error reporting to work around limitations with
    // DOMDocument's limitations in handling HTML5
    libxml_use_internal_errors(TRUE);
    $this->dom->loadHTML($this->rendered);
    libxml_clear_errors();

    $xpath = new DOMXpath($this->dom);

    // Remove any DOM elements and children based on class.
    foreach ($this->stripClasses() as $class) {
      // Remove DOM elements containing the list of classes.
      $query = "//*[contains(@class, '" . $class . "')]";
      $entries = $xpath->query($query);
      if (!empty($entries)) {
        foreach ($entries as $entry) {
          try {
            $entry->parentNode->removeChild($entry);
          }
          catch (Exception $e) {
            throw $e;
          }
        }
      }
    }

    $this->rendered = $this->dom->saveHTML();
  }

  /**
   * Get the scripts to load into the header region.
   * @todo move to template_preprocess?
   */
  protected function getScripts() {
    $bootstrap = libraries_load('bootstrap');
    $scripts = '';
    if ($bootstrap['installed']) {
      $css = array(
        '/' . $bootstrap['library path'] . '/css/bootstrap-responsive.min.css',
        '/' . $bootstrap['library path'] . '/css/bootstrap.min.css',
      );
      $element = array(
        '#tag' => 'link',
        '#attributes' => array(
          'rel' => 'stylesheet',
          'type' => 'text/css',
        ),
      );

      foreach ($css as $file) {
        $element['#attributes']['href'] = $file;
        $scripts .= theme('html_tag', array('element' => $element));
      }
    }
    return $scripts;
  }

  /**
   * Get any additional tags for the header.
   * @todo move to template_preprocess?
   */
  protected function getHead() {
    $head = '<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />';
    $head .= '<meta name="viewport" content="width=device-width, initial-scale=1.0">';
    return $head;
  }

  /**
   * Provide a rendered text string.
   */
  protected function typeinfo() {
    return 'type: ' . $this->entity_type . ' id: ' . $this->id;
  }

  /**
   * Dig through the rendered content and pull out any referenced assets.
   *
   * This strictly discovers what assets are referenced. This doesn't do any
   * additional steps around determining what to do with the assets.
   */
  public function findAssets() {
    if (empty($this->assets)) {
      // Add the primary doc to the list of resources first.
      $uri = entity_uri($this->entity_type, $this->entity);
      if (!empty($uri['path'])) {
        // Add this to the asset list.
        if ($alias = drupal_get_path_alias($uri['path'])) {
          $this->assets[$alias] = array();
        }
        else {
          $this->assets[$uri['path']] = array();
        }
      }
    }

    foreach ($this->tagMap() as $tag => $attribute) {
      $elements = $this->dom->getElementsByTagName($tag);
      foreach ($elements as $element) {
        if ($dom_node = $element->attributes->getNamedItem($attribute)) {
          $asset = $dom_node->nodeValue;
          if (!$this->include_uri($asset)) {
            continue;
          }
          $this->assets[$asset] = array();
        }
      }
    }
  }

  /**
   * Return the discovered asset list.
   *
   * @return array
   *   Associative array of assets.
   */
  public function getAssets() {
    return $this->assets;
  }

  /**
   * Iterate over found assets and determine how and if they should be included.
   *
   * @todo abstract out the path detection routine into a standalone function
   */
  public function parseAssets() {


    if (!empty($this->assets)) {
      foreach ($this->assets as $asseturi => $asset) {
        $asset = array();

        $path = $this->cleanURI($asseturi);

        // Save the cleaned link.
        $asset['cleaned'] = $path;

        // @todo review if this process with 'dest' makes sense for external
        // assets.
        $options = drupal_parse_url($asseturi);

        $asset['dest'] = $options['path'];

        // Remove the leading / if present.
        if (strpos($asset['dest'], '/') === 0) {
          $asset['dest'] = substr_replace($asset['dest'], '', 0, 1);
        }

        // file path may be handwritten and already escaped.
        $path = urldecode($path);

        // Assume it's a regular file and then if not fallback to drupal object
        // loading.
        $filespath = drupal_realpath(file_default_scheme() . '://' . $path);

        if (file_exists($filespath)) {
          // File is in the filesdir.
          $asset['file'] = $filespath;
          $asset['dest'] = $path;
          $asset['mime'] = $this->getMimeType($filespath);
          $asset['title'] = basename($asset['file']);

          // Disover if this is a managed file and if so add to ref_entity_type
          // ref_entity_id
          $query = db_select('file_managed', 'fm')
            ->fields('fm')
            ->condition('uri', file_default_scheme() . '://' . $path);

          foreach ($query->execute() as $row) {
            $asset['ref_entity_type'] = 'file';
            $asset['ref_entity_id'] = $row->fid;
          }
        }
        elseif (file_exists(DRUPAL_ROOT . '/' . $path)) {
          // File is an absolute link to some file on this install.
          $asset['file'] = DRUPAL_ROOT . '/' . $path;
          $asset['mime'] = $this->getMimeType(DRUPAL_ROOT . '/' . $path);
          $asset['title'] = basename($asset['file']);
        }
        else {
          if ($item = menu_get_item($path)) {
            $asset['title'] = $item['title'];
            // @todo determine more robust method for determining the entity
            if (!empty($item['page_arguments'][0])) {
              $entity = $item['page_arguments'][0];
              if (!in_array($item['path'], $this->getPrunedPaths()) && !empty($entity)) {
                if (!empty($entity->entity_type) && in_array($entity->entity_type, epub_export_supported_types())) {
                  list($id, $vid, $bundle) = entity_extract_ids($entity->entity_type, $entity);
                  if (!empty($id)) {
                    $asset['entity_type'] = $entity->entity_type;
                    $asset['dest'] .= '/index.html';
                    $asset['mime'] = 'application/xhtml+xml';
                    $asset['ref_entity_type'] = $entity->entity_type;
                    $asset['ref_entity_id'] = $id;
                    $asset[$entity->entity_type][$id] = $entity;
                  }
                }
              }
            }
          }
        }
        $parts = explode('/', $asset['dest']);

        // Give other modules a chance to modify our exported assets.
        $context = $this->context();
        drupal_alter('epub_export_asset', $asset, $context);

        // Store the asset in our assets list, if we have a mimetype. Otherwise
        // set a message in watchdog as potential bad markup. We should have
        // been able to treat this as an external link or a bundled internal
        // link.
        if (!empty($asset['mime'])) {
          $this->assets[$asseturi] = $asset;
        }
        else {
          $label = entity_label($this->entity_type, $this->entity);
          $uri = entity_uri($this->entity_type, $this->entity);
          $link = l($label, $uri['path']);
          watchdog('epub_export', 'Skipping uri %uri; no proper data handling path. Perhaps bad markup or missing target for !entity.', array('%uri' => $asseturi, '!entity' => $link));
          unset($this->assets[$asseturi]);
        }
      }
    }

    // Give other modules an opportunity to alter all of our assets.
    $context = $this->context();
    drupal_alter('epub_export_assets', $this->assets, $context);
  }

  /**
   *
   */
  public function cleanURI($uri) {
    global $base_url;
    // @todo documentation for drupal_parse_url() indicates to not use it on
    // non-system generated urls, but this seems okay in this aspect.
    $options = drupal_parse_url($uri);
    if (!empty($options['path'])) {
      $path = $options['path'];
    }
    else {
      $path = $uri;
    }

    $path = trim($path);

    // Replace base url if it is present.
    if (strpos($path, $base_url) === 0) {
      $path = substr_replace($path, '', 0, strlen($base_url));
    }

    // Strip a leading / if available.
    if (strpos($path, '/') === 0) {
      $path = substr_replace($path, '', 0, 1);
    }
    $path = drupal_get_normal_path($path);

    // Strip files dir if applicable.
    if (strpos($path, variable_get('file_public_path', 'sites/default/files')) === 0) {
      $path = substr_replace($path, '', 0, strlen(variable_get('file_public_path', 'sites/default/files')));

      // Remove the leading / if present.
      if (strpos($path, '/') === 0) {
        $path = substr_replace($path, '', 0, 1);
      }
    }

    return $path;
  }

  /**
   * Returns a map of tags to respective attributes can link external content.
   *
   * @todo make this hookable and configurable
   * @return array
   *   Associative array keyed by tagname with the attribute key that may
   *   reference assets external to the current document or markup.
   */
  public function tagMap() {
    $map = array(
      'a' => 'href',
      //'area' => 'href',
      //'audio' => 'src',
      //'embed' => 'src',
      //'iframe' => 'src',
      'img' => 'src',
      'link' => 'href',
      //'object' => 'data',
      //'script' => 'src',
      //'source' => 'src'
      //'track' => 'src',
      //'video' => 'src',
    );

    // Give other modules an opportunity to alter the tag map.
    $context = $this->context();
    drupal_alter('epub_export_tag_map', $map, $context);
    return $map;
  }

  /**
   * Returns the mimetype for a given file.
   */
  public function getMimeType($file) {
    if (file_exists($file)) {
      $mime = mime_content_type($file);

      if ($mime == 'text/plain') {
        $info = pathinfo($file);
        switch ($info['extension']) {
          case 'css':
            $mime = 'text/css';
            break;

          case 'js':
            $mime = 'text/javascript';
            break;

        }
      }
      return $mime;
    }
    return FALSE;
  }

  /**
   * Return a css classes corresponding to markup that should be removed.
   *
   * This is useful for targetting details that are no longer pertinent when the
   * content will/may be used outside of a context of a live site where content
   * can be edited etc. Things like edit links and login/logout links are a good
   * representation of things that should be stripped.
   *
   * @todo determine if replacing with custom theme functions could do away with
   * this.
   * @return array
   *   css classes representing markup that should not be present in the final
   *   exported content.
   */
  public function strip_classes() {
    $classes = array(
      'contextual-links-wrapper',
      'meta submitted',
      'field-type-epub-export-epub',
      'submitted',
      // "Log in or register to post comments"
      'comment_forbidden',
      'comment-wrapper'
    );

    // Allow other modules to alter the css classes that are removed.
    $context = $this->context();
    drupal_alter('epub_export_strip_classes', $classes, $context);
    return $classes;
  }

  /**
   * Default paths to skip when considering assets.
   *
   * @return array
   *   Paths as returned from menu_get_item() to skip.
   */
  public function prune_paths() {
    $paths = array(
      'node/%/delete',
      'node/%/edit',
      'user/%',
      'user/login',
      'filter/tips',
    );

    // Give other modules an opportunity to alter the paths we consider assets.
    $context = $this->context();
    drupal_alter('epub_export_prune_paths', $paths, $context);
    return $paths;
  }


  /**
   * Determines if a URI should be included in epub export and rewriting.
   *
   * @param string $uri
   *   The uri to consider for inclusion. May be a partial or complete URL.
   *
   * @return bool
   *   TRUE if the uri should be included and/or rewritten FALSE otherwise.
   */
  public function include_uri($uri) {
    global $base_url;

    if (strpos($uri, 'http://') === 0 && strpos($uri, $base_url) === FALSE) {
      // This is an external link
      return FALSE;
    }

    if (strpos($uri, '#') === 0) {
      // This is a page internal anchor link
      return FALSE;
    }
    return TRUE;
  }

  /**
   * Rewrite referenced entities.
   *
   * After calling this function internal links within content will be rewritten
   * to the corresponding rewrite destination. Since the assets were discovered
   * via the content we should cover all of the available linksregardless of the
   * path used.
   */
  public function rewriteResourceLinks() {
    if (!empty($this->assets)) {
      $xpath = new DOMXpath($this->dom);
      foreach ($this->assets as $uri => $asset) {
        foreach ($this->tagMap() as $tag => $attribute) {
          $query = "//" . $tag . "[@" . $attribute . "='" . $uri . "']";
          $entries = $xpath->query($query);
          if (!empty($entries)) {
            foreach ($entries as $entry) {
              if (!empty($asset['dest'])) {
                // Only rewrite links we have bundled in our epub.
                $entry->setAttribute($attribute, $this->pathRedirection . $asset['dest']);
              }
            }
          }
        }
      }
      $this->rendered = $this->dom->saveXML();
    }
  }

  /**
   * Provide default fallback document.
   *
   * This document will be used as the EPUB default fallback document if one is
   * required.
   */
  protected function getDefaultFallbackDocument() {
    $head = $this->getHead();
    $scripts = $this->getScripts();

    $content = t('This referenced resource type is not supported by your device.');

    $variables = array(
      'head' => $head,
      'head_title' => check_plain(entity_label($this->entity_type, $this->entity)),
      'styles' => '',
      'scripts' => $scripts,
      'attributes' => '',
      'content' => $content,
      'page_bottom' => '',
    );
    $variables['language'] = $GLOBALS['language'];
    $variables['language']->dir = $GLOBALS['language']->direction ? 'rtl' : 'ltr';

    $this->rendered = theme('epub_export', $variables);
    return $this->rendered;
  }

  /**
   * Provides a list of assets to skip when deciding what assets to include.
   *
   * @see EPUBExport::prune_paths()
   */
  protected function getPrunedPaths() {
    return variable_get('epub_export_prune_paths', $this->prune_paths());
  }

  /**
   * Provides a list of classes that should be stripped from the rendered node.
   *
   * @see EPUBExport::strip_classes()
   */
  protected function stripClasses() {
    return variable_get('epub_export_strip_classes', $this->strip_classes());
  }

  /**
   * Bundles a entity export into an epub package.
   *
   * This function should always be called without parameters.
   *
   * @param array $epub
   *   Internal recursion data (DO NOT USE)
   * @param int $level
   *   Internal recursion tracking (DO NOT USE)
   *
   * @return string
   *   Zipname if EPUB bundled properly or empty string.
   *
   * @todo adjust to use try/catch blocks where necessary
   */
  public function bundleEPUB(&$epub = NULL, $level = 0, &$gathered = array()) {
    // used to grab our navigational elements for legacy NCX document.
    $links = array();

    libraries_load('FunnyMonkey-EPUB-Package');
    if (empty($epub)) {
      $epub = new FMEPub();
    }

    foreach ($this->getAssets() as $uri => $asset) {
      if (empty($gathered[$asset['dest']])) {
        $gathered[$asset['dest']] = TRUE;

        // If this is not a core media type add a fallback.
        if (in_array($asset['mime'], $epub->coreMediaTypes())) {
          $fallback = NULL;
        }
        else {
          // Add a default fallback document
          if (empty($gathered['fallback.html'])) {
            $epub->manifestAddItem('def-fallback', 'fallback.html', 'application/xhtml+xml', 'inline', $this->getDefaultFallbackDocument());
            $gathered['fallback.html'] = TRUE;
          }
          $fallback = 'def-fallback';
        }

        if (isset($asset['file'])) {
          $id = str_replace(array('/', '.'), '-', $asset['title']);
          // This is a static file directly add it.
          $epub->manifestAddItem($id, $asset['dest'], $asset['mime'], 'file', $asset['file'], $fallback);
        }
        elseif (isset($asset['entity_type'])) {
          $id = str_replace(array('/', '.'), '-', $asset['cleaned']);
          // This is a drupal object rewrite ResourceLinks.
          foreach ($asset[$asset['entity_type']] as $eid => $entity) {
            $htmlid = $entity->entity_type . '-' . $eid;
            if ($level <= 1) {
              // Items get added to the table of contents.
              if (in_array($entity->entity_type, epub_export_navigation_types())) {
                $epub->spineAddItemRef($htmlid);

                // Used to track the links for backwards compatible NCX document.
                $links[] = '<li><a href="' . $asset['dest'] . '">' . $asset['title'] . '</a></li>';
              }
            }

            if ($htmlid != $this->htmlid) {
              $entityexport = new EPUBExport($asset['entity_type'], $eid);
              $entityexport->findAssets();
              $entityexport->parseAssets();
              $entityexport->rewriteResourceLinks();
              $entityexport->bundleEPUB($epub, $level + 1, $gathered);
              $epub->manifestAddItem($htmlid, $asset['dest'], $asset['mime'], 'inline', $entityexport->rendered, $fallback);
            }
            else {
              $epub->manifestAddItem($htmlid, $asset['dest'], $asset['mime'], 'inline', $this->rendered, $fallback);
            }
          }
        }
      }
    }

    // Bundle our EPUB.
    if ($level == 0) {
      $epub->validate();
      $epub->buildNCX();
      if (!$author = user_load($this->entity->uid)) {
        $author = drupal_anonymous_user();
      }

      // @todo dc:identifier should probably be UUID, URI, or field value
      $epub->metaSetDCMESElement('dc:identifier', variable_get('site_name', 'Drupal') . $this->id);
      $epub->metaSetDCMESElement('dc:title', check_plain(entity_label($this->entity_type, $this->entity)));
      $epub->metaAddDCMESElement('dc:creator', check_plain(format_username($author)));

      // Add our navigation 'nav' element.
      $toc = '<!DOCTYPE HTML>
<html xmlns="http://www.w3.org/1999/xhtml" xmlns:epub="http://www.idpf.org/2007/ops">
<head>
</head>
<body>
<nav epub:type="toc" id="toc">
<h1 class="title">Table of Contents</h1>
<ol>' . implode("\n", $links) . '
</ol>
</nav>
</body>
</html>';
      $epub->manifestAddItem('nav', 'fmnav.html', 'application/xhtml+xml', 'inline', $toc, NULL, array('nav'));

      $zipname = drupal_tempnam(file_directory_temp(), 'epub-build-') . '.epub';
      try {
        $epub->bundle($zipname);
        return $zipname;
      }
      catch (Exception $e) {
        throw($e);
      }
    }
    return '';
  }
}
