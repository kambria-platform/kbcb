/**
 * Get git path
 */
char *getGitPath();

/**
 * Check hook existence
 * @param - hook name
 * @return - 1 if existed
 *         - 0 otherwise
 */
int checkHookExistence(char*filename);

/**
 * Get hook path by filename
 * @param - hook name
 */
char *getHookPath(const char *filename);

/**
 * Add git remote
 * @param - remote name
 * @param - repo url
 */
void addRemote(const char *remote, const char *url);

/**
 * Remove git remote
 * @param - remote name
 */
void removeRemote(const char *remote);
