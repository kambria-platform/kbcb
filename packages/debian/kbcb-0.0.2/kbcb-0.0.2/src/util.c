#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "git.h"

#define STRINGIFY(string) #string
#define PARSE(string) STRINGIFY(string)
#define DATA_PATH PARSE(SHARED)
#define VERSION PARSE(VER)

#ifdef DEVELOPMENT
#define ENV "development"
#else
#define ENV "production"
#endif

#define UTIL_BUFFER_LENGTH 255

char *getEnv()
{
  return ENV;
}

char *getVer()
{
  return VERSION;
}

char *getDataPath()
{
  return DATA_PATH;
}

char *getRootPath(const char *filename)
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
    char root[] = "/";
    git_path = realloc(git_path, strlen(git_path) + strlen(root));
    strcat(git_path, root);
  }

  git_path = realloc(git_path, strlen(git_path) + strlen(filename));
  strcat(git_path, filename);
  return git_path;
}

void handleError(const char *message)
{
  printf("Error: %s\n", message);
  exit(0);
}

void handleInfo(const char *message)
{
  printf("%s\n", message);
}

void showHelp()
{
  char *help = "Usage:\n"
               "\tkbcb command --option <argument>\n"
               "\nCommands:\n"
               "\tinit: \t\tInitiate your project on Kambria Codebase.\n"
               "\tdisconnect: \tDisconnect to Kambria Codebase (if undeclared --strict, .kambriarc will be kept).\n"
               "\tfix: \t\t(This function is rarely used) Resync your repository in case of critical conflicts.\n"
               "\tget-dir: \tGet directory of installed file.\n"
               "\tversion: \tShow package version (the same as --help, -h).\n"
               "\thelp: \t\tShow help information (the same as --version, -v).\n"
               "\nOptions:\n"
               "\t-r --repo: \tAdd your repository url to remote.\n"
               "\t-k --key: \tAdd authentication key to .kambriarc.\n"
               "\t--force: \tForce to init new connection without caring about remote existence.\n"
               "\t-s --strict: \tPermanently delete .kambriarc.\n"
               "\t--pre-push: \tkambria-pre-push file.\n"
               "\t-v --version: \tShow package version.\n"
               "\t-h --help: \tShow help information.";
  handleInfo(help);
  exit(0);
}

void removeLineFromFile(char *line, char *fpath, char *ftemp)
{
  FILE *file, *temp;
  char str[UTIL_BUFFER_LENGTH];
  file = fopen(fpath, "r");
  temp = fopen(ftemp, "w");

  while (!feof(file))
  {
    fgets(str, UTIL_BUFFER_LENGTH, file);
    if (strcmp(line, str) != 0)
    {
      fputs(str, temp);
    }
  }
  fclose(file);
  fclose(temp);
  remove(fpath);
  rename(ftemp, fpath);
}

void setExecutable(char *fpath)
{
  char chmod[] = "chmod +x";
  char *cmd = malloc(strlen(chmod) + 1 + strlen(fpath) + 1);
  strcpy(cmd, chmod);
  strcat(cmd, " ");
  strcat(cmd, fpath);

  int error;
  error = system(cmd);
  free(cmd);
  if (error != 0)
  {
    exit(1);
  }
}

int checkEmptyExectuableFile(char *fpath)
{
  FILE *file;
  char str[UTIL_BUFFER_LENGTH];
  file = fopen(fpath, "r");

  char prefix[] = "#!/bin/sh\n";
  char breakline[] = "\n";

  int isEmpty = 1;
  while (!feof(file))
  {
    fgets(str, UTIL_BUFFER_LENGTH, file);
    if (strcmp(prefix, str) != 0 && strcmp(breakline, str) != 0)
    {
      isEmpty = 0;
    }
  }

  fclose(file);
  return isEmpty;
}
