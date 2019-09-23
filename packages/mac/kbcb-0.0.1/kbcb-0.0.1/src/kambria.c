#include <stdio.h>
#include <stdlib.h>
#include "git.h"
#include "kambria.h"
#include "util.h"

#define STRINGIFY(string) #string
#define PARSE(string) STRINGIFY(string)
#define DATA_PATH PARSE(SHARED)

void addHook()
{
  /**
   * Copy pre-hooks to user's git
   */
  FILE *input;
  input = fopen(DATA_PATH, "r");
  if (input == NULL)
  {
    char *error = "kbcb package met a critical damage, please reinstall the package and retry!";
    handleError(error);
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
  addRemote("kambria", repo_url);
}

void removeKambriaRemote()
{
  removeRemote("kambria");
}

void createEmptyRC()
{
  FILE *kambriarc;
  char *kambriarc_path = getRootPath(".kambriarc");
  kambriarc = fopen(kambriarc_path, "w");

  free(kambriarc_path);
  fclose(kambriarc);
}

void createRC(char *key)
{
  FILE *kambriarc;
  char *kambriarc_path = getRootPath(".kambriarc");
  kambriarc = fopen(kambriarc_path, "w");
  fputs(key, kambriarc);

  free(kambriarc_path);
  fclose(kambriarc);
}
