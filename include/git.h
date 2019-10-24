/**
 * Get git path
 */
std::string getGitPath();

/**
 * Get hook path by filename
 * @param - hook name
 */
std::string getHookPath(const std::string filename);

/**
 * Check hook existence
 * @param - hook name
 * @return - 1 if existed
 *         - 0 otherwise
 */
bool checkHookExistence(const std::string filename);

/**
 * Add git remote
 * @param - remote name
 * @param - repo url
 */
void addRemote(const std::string remote, const std::string url);

/**
 * Remove git remote
 * @param - remote name
 */
void removeRemote(const std::string remote);
