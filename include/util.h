/**
 * Get env
 */
std::string getEnv();

/**
 * Get version
 */
std::string getVer();

/**
 * Get shared data path
 */
std::string getDataPath();

/**
 * Get root path of repo concating filename
 * @param - filename
 */
std::string getRootPath(std::string filename);

/**
 * Handle error
 * Show error to cerr and exit program
 * @param - error message
 */
void handleError(std::string messgae);

/**
 * Handle info
 * Show info to clog
 * @param - info message
 */
void handleInfo(std::string message);

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
void removeLineFromFile(std::string line, std::string fpath, std::string ftemp);

/**
 * Set file as executable
 * @param fpath - file path
 */
void setExecutable(std::string fpath);

/**
 * Check if file is executable (contents executable code)
 * @param fpath - file path
 */
bool checkEmptyExectuableFile(std::string fpath);
