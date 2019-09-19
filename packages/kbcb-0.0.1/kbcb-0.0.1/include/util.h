/**
 * Handle error
 * Show error and exit program
 * @param - message
 */
void handleCommonError(const char *messgae);

/**
 * Handle info
 * @param - message
 */
void handleCommonInfo(const char *message);

/**
 * Handle error
 * This function is specicalized for git only
 * Exit program if errors
 * @param - error
 */
void handleGitError(int error);

/**
 * Get path of hook file
 * Notice: free the returned value after use
 * @param - filename
 */
char *getHookPath(char *filename);

/**
 * Show help info and exit program
 */
void showHelp();