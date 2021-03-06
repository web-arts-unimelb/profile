Faculty of Arts Drupal Install Profile
--------------------------------------

This install profile provides a Drupal 7 setup with a few common content
types and user roles to allow you to quickly deploy a new site. When you
install using this profile, various blocks will be configured so you can
create a responsive front page by adding items to a nodequeue.

IMPORTANT
---------

After checkout, you need to grab a copy of the unimelb theme from
its own git repository before you install the site:

 * git submodule init
 * git submodule update

TESTING
-------

To run the tests for this install profile, you need a Drupal site with the
simpletest module enabled. Then you can run the test script from the Drupal
document root:

  php ./scripts/run-tests.sh --url http://$SITENAME --class FoaTestCase
