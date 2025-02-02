/**
 * Add pre-push hook file to git
 * Exit if error
 */
void addHook();

/**
 * Remove pre-push hook file to git
 */
void removeHook();

/**
 * Add kambria remote url
 * @param - repo url
 */
void addKambriaRemote(const char *repo_url);

/**
 * Delete kambria remote
 */
void removeKambriaRemote();

/**
 * Create empty .kambriarc
 */
void createEmptyRC();

/**
 * Create .kambriarc with key
 * @param - authentication key
 */
void createRC(const char *key);

/**
 * Remove .kambriarc
 */
void removeRC();