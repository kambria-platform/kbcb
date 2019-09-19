/**
 * Add hook file to git
 * Exit if error
 */
void addHook();

/**
 * Add kambria remote url
 * @param - repo url
 */
void addKambriaRemote(char *repo_url);

/**
 * Delete kambria remote
 */
void deleteKambriaRemote();

/**
 * Create empty .kambriarc
 */
void createEmptyRC();

/**
 * Create .kambriarc with key
 */
void createRC(char *key);