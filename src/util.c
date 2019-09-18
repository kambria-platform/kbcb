#include <stdio.h>
#include <string.h>
#include <git2.h>

#ifdef DEVELOPMENT
#define ENV "development"
#else
#define ENV "production"
#endif

void handleCommonError(const char *message)
{
    printf("Error: %s\n", message);
    exit(0);
}

void handleCommonInfo(const char *message)
{
    printf("%s\n", message);
}

void handleGitError(int error)
{
    if (error < 0)
    {
        const git_error *e = giterr_last();
        printf("Error %d/%d: %s\n", error, e->klass, e->message);
        exit(error);
    }
}

char *getHookPath(const char *filename)
{
    char *hook_path;
    if (ENV == "development")
    {
        hook_path = "./";
    }
    else
    {
        git_libgit2_init();
        git_buf git_dir = {0};
        int error = git_repository_discover(&git_dir, "./", 0, NULL);
        handleGitError(error);
        char _git_dir[strlen(git_dir.ptr)];
        strcpy(_git_dir, git_dir.ptr);
        hook_path = strcat(_git_dir, "hooks/");

        git_buf_free(&git_dir);
        git_libgit2_shutdown();
    }

    char *re = malloc(strlen(hook_path) + strlen(filename) + 1);
    strcpy(re, hook_path);
    strcat(re, filename);
    return re;
}