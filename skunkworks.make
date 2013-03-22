; FoA Skunkworks install profile makefile.
api = 2
core = 7.x

;
; Contrib modules used only by the Skunkworks install profile.
;
projects[epub_export][version] = "1.x-dev"
projects[epub_export][subdir] = contrib

; Skunkworks wants a dev version of this module.
projects[jquery_update][version] = "2.x-dev"
projects[jquery_update][subdir] = contrib

projects[twitter_bootstrap_ui][version] = "2.x-dev"
projects[twitter_bootstrap_ui][subdir] = contrib

;
; Themes used by the Skunkworks install profile.
;
projects[bootstrap][version] = "2.x-dev"
projects[bootstrap][subdir] = contrib

;
; Libraries used by the Skunkworks install profile.
;
; @see http://drupal.org/project/bootstrap
libraries[bootstrap][download][type] = "get"
libraries[bootstrap][download][url] = "http://twitter.github.com/bootstrap/assets/bootstrap.zip"
libraries[bootstrap][directory_name] = "bootstrap"
libraries[bootstrap][destination] = "themes/custom/bootstrap"

libraries[epub][download][type] = "git"
libraries[epub][download][url] = "https://github.com/FunnyMonkey/FunnyMonkey-EPUB-Package.git"
libraries[epub][download][branch] = "master"
libraries[epub][directory_name] = "FunnyMonkey-EPUB-Package"
libraries[epub][destination] = "libraries"
