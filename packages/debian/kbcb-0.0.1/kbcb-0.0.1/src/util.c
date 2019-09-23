#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "git.h"

#define STRINGIFY(string) #string
#define PARSE(string) STRINGIFY(string)
#define DATA_PATH PARSE(SHARED)

#ifdef DEVELOPMENT
#define ENV "development"
#else
#define ENV "production"
#endif

char *getEnv()
{
  return ENV;
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
               "\tinit: \tInitiate your project on Kambria Codebase.\n"
               "\tfix: \t(This function is rarely used) In case of merging conflicts on Kambria Codebase and you cannot fix it by manually merging. 'fix' command will force to resync your repository.\n"
               "\tget-dir: \tGet directory of installed file.\n"
               "\nOptions:\n"
               "\t-r --repo: \tAdd your repository url to remote.\n"
               "\t-k --key: \tAdd authentication key to .kambriarc.\n"
               "\t--force: \tForce to init new connection without caring about remote existence.\n"
               "\t--pre-push: \tpre-push file."
               "\t-h --help: \tShow help information.";
  handleInfo(help);
  exit(0);
}
