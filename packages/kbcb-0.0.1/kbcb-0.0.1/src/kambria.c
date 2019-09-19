#include <stdio.h>
#include <git2.h>
#include "kambria.h"
#include "util.h"

#ifdef ROOT
#define STRINGIFY(path) #path
#define GET_ROOT(path) STRINGIFY(path)
#define BUILD_PATH GET_ROOT(ROOT)
#else
#define BUILD_PATH "."
#endif

#ifdef DEVELOPMENT
#define SHARED_PATH BUILD_PATH "/src/hooks/pre-push"
#else
#define SHARED_PATH "/usr/share/kbcb/pre-push"
#endif

#define KAMBRIARC_PATH "./.kambriarc"

void addHook()
{
    /**
     * Copy pre-hooks to user's git
     */
    FILE *input;
    input = fopen(SHARED_PATH, "r");
    if (input == NULL)
    {
        char *error = "kbcb package met a critical damage, please reinstall the package and retry!";
        handleCommonError(error);
    }

    FILE *output;
    char *hook_path = getHookPath("pre-push");
    output = fopen(hook_path, "w");
    char c;
    while ((c = fgetc(input)) != EOF)
    {
        fputc(c, output);
    }

    free(hook_path);
    fclose(input);
}

void addKambriaRemote(char *repo_url)
{
    git_libgit2_init();

    git_repository *repo = NULL;
    int error_repo = git_repository_open(&repo, "./");
    handleGitError(error_repo);
    git_remote *remote;
    int error_remote = git_remote_create(&remote, repo, "kambria", repo_url);
    handleGitError(error_remote);

    git_repository_free(repo);
    git_remote_free(remote);
    git_libgit2_shutdown();
}

void deleteKambriaRemote()
{
    git_libgit2_init();

    git_repository *repo = NULL;
    int error_repo = git_repository_open(&repo, "./");
    handleGitError(error_repo);
    int error_remote = git_remote_delete(repo, "kambria");
    handleGitError(error_remote);

    git_repository_free(repo);
    git_libgit2_shutdown();
}

void createEmptyRC()
{
    FILE *kambriarc;
    kambriarc = fopen(KAMBRIARC_PATH, "w");
    fclose(kambriarc);
}

void createRC(char *key)
{
    FILE *kambriarc;
    kambriarc = fopen(KAMBRIARC_PATH, "w");
    fputs(key, kambriarc);
    fclose(kambriarc);
}
