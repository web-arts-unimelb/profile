; Make file for epub export
api = 2
core = 7.x
projects[] = drupal

; Contrib
projects[entity][version] = 1.0-rc3
projects[libraries] = 2.0
projects[epub_export] = 1.x-dev


; Libraries
projects[FunnyMonkey-EPUB-Package][type] = library
projects[FunnyMonkey-EPUB-Package][download][type] = git
projects[FunnyMonkey-EPUB-Package][download][tag] = 0.3
projects[FunnyMonkey-EPUB-Package][download][url] = git@github.com:FunnyMonkey/FunnyMonkey-EPUB-Package.git

; projects[bootstrap][type] = library
; projects[bootstrap][url] = http://twitter.github.com/bootstrap/assets/bootstrap.zip
