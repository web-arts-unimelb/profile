<?php
/**
 * @file foa_web_test_case.php
 *
 * Creates a Faculty of Arts Drupal for running tests on.
 *
 * As opposed to the standard DrupalWebTestCase, this class also executes
 * the profile's installation tasks before running tests.
 */

class FoaWebTestCase extends DrupalWebTestCase {
  /**
   * The profile to install as a basis for testing.
   *
   * @var string
   */
  protected $profile = 'foa';

  /**
   * Sets up a Drupal site for running functional and integration tests.
   *
   * Generates a random database prefix and installs Drupal with the specified
   * installation profile in DrupalWebTestCase::$profile into the
   * prefixed database. Afterwards, installs any additional modules specified by
   * the test.
   *
   * After installation all caches are flushed and several configuration values
   * are reset to the values of the parent site executing the test, since the
   * default values may be incompatible with the environment in which tests are
   * being executed.
   *
   * @param ...
   *   List of modules to enable for the duration of the test. This can be
   *   either a single array or a variable number of string arguments.
   *
   * @see DrupalWebTestCase::prepareDatabasePrefix()
   * @see DrupalWebTestCase::changeDatabasePrefix()
   * @see DrupalWebTestCase::prepareEnvironment()
   */
  protected function setUp() {
    global $user, $language, $conf;

    // Create the database prefix for this test.
    $this->prepareDatabasePrefix();

    // Prepare the environment for running tests.
    $this->prepareEnvironment();
    if (!$this->setupEnvironment) {
      return FALSE;
    }

    // Reset all statics and variables to perform tests in a clean environment.
    $conf = array();
    drupal_static_reset();

    // Change the database prefix.
    // All static variables need to be reset before the database prefix is
    // changed, since DrupalCacheArray implementations attempt to
    // write back to persistent caches when they are destructed.
    $this->changeDatabasePrefix();
    if (!$this->setupDatabasePrefix) {
      return FALSE;
    }

    // Preset the 'install_profile' system variable, so the first call into
    // system_rebuild_module_data() (in drupal_install_system()) will register
    // the test's profile as a module. Without this, the installation profile of
    // the parent site (executing the test) is registered, and the test
    // profile's hook_install() and other hook implementations are never invoked.
    $conf['install_profile'] = $this->profile;

    // Perform the actual Drupal installation.
    include_once DRUPAL_ROOT . '/includes/install.inc';
    drupal_install_system();

    $this->preloadRegistry();

    // Set path variables.
    variable_set('file_public_path', $this->public_files_directory);
    variable_set('file_private_path', $this->private_files_directory);
    variable_set('file_temporary_path', $this->temp_files_directory);

    // Set the 'simpletest_parent_profile' variable to add the parent profile's
    // search path to the child site's search paths.
    // @see drupal_system_listing()
    // @todo This may need to be primed like 'install_profile' above.
    variable_set('simpletest_parent_profile', $this->originalProfile);

    // Include the testing profile.
    variable_set('install_profile', $this->profile);
    $profile_details = install_profile_info($this->profile, 'en');

    // Install the modules specified by the testing profile.
    module_enable($profile_details['dependencies'], FALSE);

    // Install modules needed for this test. This could have been passed in as
    // either a single array argument or a variable number of string arguments.
    // @todo Remove this compatibility layer in Drupal 8, and only accept
    // $modules as a single array argument.
    $modules = func_get_args();
    if (isset($modules[0]) && is_array($modules[0])) {
      $modules = $modules[0];
    }
    if ($modules) {
      $success = module_enable($modules, TRUE);
      $this->assertTrue($success, t('Enabled modules: %modules', array('%modules' => implode(', ', $modules))));
    }

    // Run the profile tasks.
    $install_profile_module_exists = db_query("SELECT 1 FROM {system} WHERE type = 'module' AND name = :name", array(
      ':name' => $this->profile,
    ))->fetchField();
    if ($install_profile_module_exists) {
      $success = module_enable(array($this->profile), FALSE);
      $this->assertTrue($success, t('Enabled profile: %profile', array('%profile' => $this->profile)));
    }

    // Reset/rebuild all data structures after enabling the modules.
    $this->resetAll();

    // The profile tasks above only run the install and enable hooks, not any batch
    // tasks that may be defined in the .profile. Since we want to check the results
    // of those batch tasks, they need to be executed!
    //
    // Grab the installation tasks defined by the profile.
    $func = "{$this->profile}_profile_tasks";
    $batch = $func('profile', '');

    // Batch tasks will be listed in the `operations' key of the Batch API
    // array of stuff we just got. If set, simply iterate over those and
    // call each in turn.
    //
    // This will probably fail horribly when the profile tasks take longer
    // than max_execution_time to complete. However, I don't think that batch
    // tasks can be called in a nested fashion, so if you have takss that
    // take forever, they should maybe go in the profiles hook_enable().
    if (isset($batch['operations'])) {
      foreach ($batch['operations'] as $task) {
        // Batch API wants an extra by-reference $context variable to show
        // installation progress status. We really don't care about that
        // here, so suppress any warnings about that missing variable.
        $success = @call_user_func_array($task[0], $task[1]);

        // Optionally proudly tell our user what we did.
        // $this->assertTrue(($success !== FALSE), t('Executed task: %task', array('%task' => $task[0])));
      }
    }

    // Run cron once in that environment, as install.php does at the end of
    // the installation process.
    drupal_cron_run();

    // Ensure that the session is not written to the new environment and replace
    // the global $user session with uid 1 from the new test site.
    drupal_save_session(FALSE);
    // Login as uid 1.
    $user = user_load(1);

    // Restore necessary variables.
    variable_set('install_task', 'done');
    variable_set('clean_url', $this->originalCleanUrl);
    variable_set('site_mail', 'simpletest@example.com');
    variable_set('date_default_timezone', date_default_timezone_get());

    // Set up English language.
    unset($conf['language_default']);
    $language = language_default();

    // Use the test mail class instead of the default mail handler class.
    variable_set('mail_system', array('default-system' => 'TestingMailSystem'));

    drupal_set_time_limit($this->timeLimit);
    $this->setup = TRUE;
  }
}
