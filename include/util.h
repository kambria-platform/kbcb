/**
 * Get root path of repo
 * Concate filename
 */
char *getRootPath(char *filename);

/**
 * Handle error
 * Show error and exit program
 * @param - message
 */
void handleError(const char *messgae);

/**
 * Handle info
 * @param - message
 */
void handleInfo(const char *message);

/**
 * Show help info and exit program
 */
void showHelp();
