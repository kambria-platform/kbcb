/**
 * Get env
 */
char *getEnv();

/**
 * Get shared data path
 */
char *getDataPath();

/**
 * Get root path of repo concating filename
 * @param - filename
 */
char *getRootPath(const char *filename);

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

/**
 * Remove a specific line from a input filename
 * @param line - specific string
 * @param fpath - file path
 * @param ftemp - temp file path
 */
void removeLineFromFile(char *line, char *fpath, char *ftemp);
