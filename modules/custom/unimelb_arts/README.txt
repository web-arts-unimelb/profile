Updated the feature?

To ensure the summary field on nodes works as intended, you need to
make sure that the `unimelb_arts.module.inc' file is included by
the unimelb_arts.module file.

Add in the following line at the bottom of the file:

  include_once 'unimelb_arts.module.inc';
