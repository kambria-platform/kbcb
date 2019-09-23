/**
 * Add hook file to git
 * Exit if error
 */
void addHook();

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