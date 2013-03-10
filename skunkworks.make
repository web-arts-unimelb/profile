; FoA Skunkworks install profile makefile.
api = 2
core = 7.x

;
; Contrib modules used by the Skunkworks install profile.
;
projects[admin_menu][version] = "3.0-rc3"
projects[admin_menu][subdir] = contrib

projects[auto_nodetitle][version] = "1.0"
projects[auto_nodetitle][subdir] = contrib

projects[better_formats][version] = "1.0-beta1"
projects[better_formats][subdir] = contrib

projects[colorbox][version] = "1.4"
projects[colorbox][subdir] = contrib

projects[css_splitter][version] = "1.x-dev"
projects[css_splitter][subdir] = contrib

projects[ctools][version] = "1.2"
projects[ctools][subdir] = contrib

projects[custom_formatters][version] = "2.2"
projects[custom_formatters][subdir] = contrib

projects[date][version] = "2.6"
projects[date][subdir] = contrib

projects[diff][version] = "3.2"
projects[diff][subdir] = contrib

projects[ds][version] = "2.0"
projects[ds][subdir] = contrib

projects[email][version] = "1.2"
projects[email][subdir] = contrib

projects[entity][version] = "1.0-rc3"
projects[entity][subdir] = contrib

projects[entityreference][version] = "1.0-rc5"
projects[entityreference][subdir] = contrib

projects[epub_export][version] = "1.x-dev"
projects[epub_export][subdir] = contrib

projects[features][version] = "1.0"
projects[features][subdir] = contrib

projects[field_group][version] = "1.1"
projects[field_group][subdir] = contrib

projects[filefield_sources][version] = "1.7"
projects[filefield_sources][subdir] = contrib

projects[insert][version] = "1.2"
projects[insert][subdir] = contrib

projects[jquerymenu][version] = "3.x-dev"
projects[jquerymenu][subdir] = contrib

projects[jquery_ui][version] = "1.x-dev"
projects[jquery_ui][subdir] = contrib

projects[jquery_update][version] = "2.x-dev"
projects[jquery_update][subdir] = contrib

projects[ldap][version] = "1.0-beta12"
projects[ldap][subdir] = contrib
; @see http://drupal.org/node/1775658
projects[ldap][patch][] = http://drupal.org/files/ldap_server_init-1775658-1.patch

projects[libraries][version] = "2.0"
projects[libraries][subdir] = contrib

projects[link][version] = "1.1"
projects[link][subdir] = contrib

projects[linkimagefield][version] = "1.x-dev"
projects[linkimagefield][subdir] = contrib

projects[menu_admin_per_menu][version] = "1.0"
projects[menu_admin_per_menu][subdir] = contrib

projects[mollom][version] = "2.3"
projects[mollom][subdir] = contrib

projects[nodequeue][version] = "2.0-beta1"
projects[nodequeue][subdir] = contrib

projects[pathauto][version] = "1.2"
projects[pathauto][subdir] = contrib

projects[prepro][version] = "0.10"
projects[prepro][subdir] = contrib

projects[redirect][version] = "1.0-rc1"
projects[redirect][subdir] = contrib
; @see http://drupal.org/node/1796596
projects[redirect][patch][] = http://drupal.org/files/redirect-detect_prevent_circular_redirects_patch_and_test-1796596-48.patch

projects[sassy][version] = "2.13"
projects[sassy][subdir] = contrib

projects[strongarm][version] = "2.0"
projects[strongarm][subdir] = contrib

projects[token][version] = "1.4"
projects[token][subdir] = contrib

projects[twitter_bootstrap_ui][version] = "2.x-dev"
projects[twitter_bootstrap_ui][subdir] = contrib

projects[views][version] = "3.5"
projects[views][subdir] = contrib

projects[views_bulk_operations][version] = "3.1"
projects[views_bulk_operations][subdir] = contrib

projects[views_slideshow][version] = "3.0"
projects[views_slideshow][subdir] = contrib

projects[wysiwyg][version] = "2.2"
projects[wysiwyg][subdir] = contrib

;
; Custom modules used by the Skunkworks install profile.
;
projects[askunimelb_widgets][type] = "module"
projects[askunimelb_widgets][download][type] = "git"
projects[askunimelb_widgets][download][url] = "https://github.com/web-arts-unimelb/askunimelb_widgets.git"
projects[askunimelb_widgets][download][branch] = "master"
projects[askunimelb_widgets][subdir] = custom

;
; Themes used by the Skunkworks install profile.
;
projects[bootstrap][version] = "2.0"
projects[bootstrap][subdir] = contrib

projects[rubik][version] = "4.0-beta8"
projects[rubik][subdir] = contrib

projects[tao][version] = "3.0-beta4"
projects[tao][subdir] = contrib

;
; Libraries used by the Skunkworks install profile.
;
; @see http://drupal.org/project/bootstrap
libraries[bootstrap][download][type] = "get"
libraries[bootstrap][download][url] = "http://twitter.github.com/bootstrap/assets/bootstrap.zip"
libraries[bootstrap][directory_name] = "bootstrap"
libraries[bootstrap][destination] = "themes/custom/bootstrap"

libraries[colorbox][download][type] = "get"
libraries[colorbox][download][url] = "https://github.com/jackmoore/colorbox/archive/1.x.zip"
libraries[colorbox][directory_name] = "colorbox"
libraries[colorbox][destination] = "libraries"

libraries[cycle][download][type] = "git"
libraries[cycle][download][url] = "https://github.com/FunnyMonkey/FunnyMonkey-EPUB-Package.git"
libraries[cycle][download][branch] = "master"
libraries[cycle][directory_name] = "FunnyMonkey-EPUB-Package"
libraries[cycle][destination] = "libraries"

libraries[tinymce][download][type] = "get"
libraries[tinymce][download][url] = "http://github.com/downloads/tinymce/tinymce/tinymce_3.5.8.zip"
libraries[tinymce][directory_name] = "tinymce"
libraries[tinymce][destination] = "libraries"

libraries[timepicker][download][type] = "git"
libraries[timepicker][download][url] = "https://github.com/wvega/timepicker.git"
libraries[timepicker][download][branch] = "master"
libraries[timepicker][directory_name] = "wvega-timepicker"
libraries[timepicker][destination] = "libraries"
