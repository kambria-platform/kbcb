#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "git.h"

#ifdef DEVELOPMENT
#define ENV "development"
#else
#define ENV "profuction"
#endif

#define BUFFER_LENGTH 8

char *getGitPath()
{
    char *path = malloc(BUFFER_LENGTH);

    FILE *fp;
    char reader[BUFFER_LENGTH];
    fp = popen("git rev-parse --show-toplevel", "r");
    if (fp == NULL)
    {
        exit(1);
    }
    while (fgets(reader, BUFFER_LENGTH, fp) != NULL)
    {
        strcat(path, reader);
        path = realloc(path, strlen(path) + BUFFER_LENGTH);
    }

    pclose(fp);
    path[strcspn(path, "\n")] = '\0'; // Remove newline
    return path;
}

char *getHookPath(char *filename)
{
    char *git_path = getGitPath();
    if (ENV == "development")
    {
        char dist[] = "/dist/";
        git_path = realloc(git_path, strlen(git_path) + strlen(dist));
        strcat(git_path, dist);
    }
    else
    {
        char hooks[] = "/.git/hooks/";
        git_path = realloc(git_path, strlen(git_path) + strlen(hooks));
        strcat(git_path, hooks);
    }

    git_path = realloc(git_path, strlen(git_path) + strlen(filename));
    strcat(git_path, filename);
    return git_path;
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
    {
        exit(1);
    }
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
    {
        exit(1);
    }
}
