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
        handleCommonError("kbcb package met a critical damage, please reinstall the package and retry!\n");
    }

    FILE *output;
    char *hook_path = getHookPath("pre-push");
    printf("Test: %s\n", hook_path);
    output = fopen(hook_path, "w");
    char c;
    while ((c = fgetc(input)) != EOF)
    {
        fputc(c, output);
    }

    free(hook_path);
    fclose(input);
    return 0;
}

int addKambriaRemote(char *repo)
{
    git_libgit2_init();
    git_buf root = {0};
    int error = git_repository_discover(&root, "./", 0, NULL);
    printf("Git: %s\n", root.ptr);
    git_buf_free(&root);
    git_libgit2_shutdown();
    return 0;
}

int createEmptyRC()
{
    FILE *kambriarc;
    kambriarc = fopen(KAMBRIARC_PATH, "w");
    fclose(kambriarc);
    return 0;
}

int createRC(char *key)
{
    FILE *kambriarc;
    kambriarc = fopen(KAMBRIARC_PATH, "w");
    fputs(key, kambriarc);
    fclose(kambriarc);
    return 0;
}