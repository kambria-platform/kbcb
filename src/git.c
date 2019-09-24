#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "git.h"
#include "util.h"

#define GIT_BUFFER_LENGTH 8

char *getGitPath()
{
  char *path = malloc(GIT_BUFFER_LENGTH);

  FILE *fp;
  char reader[GIT_BUFFER_LENGTH];
  fp = popen("git rev-parse --show-toplevel", "r");
  if (fp == NULL)
  {
    char *error_fp = "Cannot recognize your repository, please make sure you are in a valid repository!";
    handleError(error_fp);
  }

  while (fgets(reader, GIT_BUFFER_LENGTH, fp) != NULL)
  {
    strcat(path, reader);
    path = realloc(path, strlen(path) + GIT_BUFFER_LENGTH);
  }

  pclose(fp);

  if (strlen(path) == 0)
  {
    char *error_path = "Cannot recognize your repository, please make sure you are in a valid repository!";
    handleError(error_path);
  }

  path[strcspn(path, "\n")] = '\0'; // Remove newline
  return path;
}

int checkHookExistence(char *filename)
{
  char *path = getHookPath(filename);
  if (access(path, F_OK) != -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

char *getHookPath(const char *filename)
{
  char *git_path = getGitPath();
  if (strcmp(getEnv(), "development") == 0)
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

void addRemote(const char *remote, const char *url)
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

void removeRemote(const char *remote)
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
