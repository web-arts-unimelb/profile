; FoA install profile makefile.
api = 2
core = 7.x

;
; Contrib modules used by the FoA install profile.
;
projects[block_titlelink][version] = "1.3"
projects[block_titlelink][subdir] = contrib

projects[jquerymenu][version] = "4.0-alpha3"
projects[jquerymenu][subdir] = contrib
projects[jquerymenu][patch][] = "https://raw.github.com/web-arts-unimelb/profile/foa-drush-make/patches/jquerymenu-schema.patch"

projects[jquery_update][version] = "2.3"
projects[jquery_update][subdir] = contrib

projects[linkimagefield][version] = "1.x-dev"
projects[linkimagefield][subdir] = contrib

projects[rdfx][version] = "2.0-alpha4"
projects[rdfx][subdir] = contrib

projects[search_config][version] = "1.0"
projects[search_config][subdir] = contrib

projects[sparql][version] = "2.0-alpha4"
projects[sparql][subdir] = contrib

projects[views_accordion][version] = "1.0-rc2"
projects[views_accordion][subdir] = contrib


;
; Custom modules (and features) used by FoA.
;
projects[arts_video_gallery][type] = "module"
projects[arts_video_gallery][subdir] = custom
projects[arts_video_gallery][download][type] = "git"
projects[arts_video_gallery][download][url] = "https://github.com/web-arts-unimelb/arts-video-gallery.git"
projects[arts_video_gallery][download][branch] = "master"
projects[arts_video_gallery][directory_name] = "arts_video_gallery"
projects[arts_video_gallery][download][working-copy] = TRUE

projects[faeprofile][type] = "module"
projects[faeprofile][subdir] = custom
projects[faeprofile][download][type] = "git"
projects[faeprofile][download][url] = "https://github.com/web-arts-unimelb/faeprofile.git"
projects[faeprofile][download][branch] = "master"
projects[faeprofile][download][working-copy] = TRUE

; uom_events includes a makefile that fetches the API library it needs.
projects[uom_events][type] = "module"
projects[uom_events][subdir] = custom
projects[uom_events][download][type] = "git"
projects[uom_events][download][url] = "https://github.com/web-arts-unimelb/uom_events.git"
projects[uom_events][download][branch] = "master"
projects[uom_events][download][working-copy] = TRUE

projects[uom_fae_api][type] = "module"
projects[uom_fae_api][subdir] = custom
projects[uom_fae_api][download][type] = "git"
projects[uom_fae_api][download][url] = "https://github.com/web-arts-unimelb/uom_fae_api.git"
projects[uom_fae_api][download][branch] = "master"
projects[uom_fae_api][download][working-copy] = TRUE

;
; Custom themes used by the FoA install profile.
;
projects[unimelb][type] = "theme"
projects[unimelb][subdir] = custom
projects[unimelb][download][type] = "git"
projects[unimelb][download][url] = "https://github.com/web-arts-unimelb/unimelb.git"
projects[unimelb][download][branch] = "master"
projects[unimelb][download][working-copy] = TRUE

;
; Libraries used by the FoA install profile.
;
libraries[ARC2][download][type] = "get"
libraries[ARC2][download][url] = "http://github.com/semsol/arc2/tarball/master"
libraries[ARC2][directory_name] = "ARC2/arc"
libraries[ARC2][destination] = "libraries"

libraries[jquery.cycle][download][type] = "git"
libraries[jquery.cycle][download][url] = "https://github.com/malsup/cycle.git"
libraries[jquery.cycle][download][branch] = "master"
libraries[jquery.cycle][directory_name] = "jquery.cycle"
libraries[jquery.cycle][destination] = "libraries"

libraries[tcpdf][download][type] = "git"
libraries[tcpdf][download][url] = "http://git.code.sf.net/p/tcpdf/code"
libraries[tcpdf][download][branch] = "master"
libraries[tcpdf][directory_name] = "tcpdf"
libraries[tcpdf][destination] = "libraries"
