#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "git.h"

#ifdef DEVELOPMENT
#define ENV "development"
#else
#define ENV "profuction"
#endif

char *getHookPath(char *filename)
{
    char *hook_path;
    if (ENV == "development")
        hook_path = "./dist/";
    else
        hook_path = "./.git/hooks/";

    char *re = malloc(strlen(hook_path) + strlen(filename) + 1);
    strcpy(re, hook_path);
    strcat(re, filename);
    return re;
}

void addRemote(char *remote, char *url)
{
    char git_add[] = "git remote add";
    char *cmd = malloc(strlen(git_add) + 1 + strlen(remote) + 1 + strlen(url) + 1);
    strcpy(cmd, git_add);
    strcat(cmd, " ");
    strcat(cmd, remote);
    strcat(cmd, " ");
    strcat(cmd, url);

    int error;
    error = system(cmd);
    free(cmd);
    if (error != 0)
        exit(1);
}

void removeRemote(char *remote)
{
    char git_add[] = "git remote remove";
    char *cmd = malloc(strlen(git_add) + 1 + strlen(remote) + 1);
    strcpy(cmd, git_add);
    strcat(cmd, " ");
    strcat(cmd, remote);

    int error;
    error = system(cmd);
    free(cmd);
    if (error != 0)
        exit(1);
}
