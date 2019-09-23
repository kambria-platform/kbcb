/**
 * Get git path
 */
char *getGitPath();

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
