#include <stdio.h>
#include <stdlib.h>
#include "git.h"
#include "kambria.h"
#include "util.h"

void copyKambriaPrePush()
{
  FILE *input;
  input = fopen(getDataPath(), "r");
  if (input == NULL)
  {
    char *error = "kbcb package met a critical damage, please reinstall the package and retry!";
    handleError(error);
  }
  FILE *output;
  char *hook_path = getHookPath("kambria-pre-push");
  output = fopen(hook_path, "w");
  char c;
  while ((c = fgetc(input)) != EOF)
  {
    fputc(c, output);
  }

  setExecutable(hook_path);
  free(hook_path);
  fclose(input);
}

void addExecutableCode()
{
  char *hook_path = getHookPath("pre-push");
  if (checkHookExistence("pre-push") == 1)
  {
    char *temp_path = getHookPath("temp-pre-push");
    removeLineFromFile("sh ./kambria-pre-push\n", hook_path, temp_path);
    removeLineFromFile("exit 0\n", hook_path, temp_path);

    char *executableCode = "\n"
                           "sh ./kambria-pre-push\n"
                           "\n"
                           "exit 0\n";
    FILE *output;
    output = fopen(hook_path, "a");
    fputs(executableCode, output);

    free(temp_path);
    fclose(output);
  }
  else
  {
    char *executableCode = "#!/bin/sh\n"
                           "\n"
                           "sh ./kambria-pre-push\n"
                           "\n"
                           "exit 0\n";
    FILE *output;
    char *hook_path = getHookPath("pre-push");
    output = fopen(hook_path, "w");
    fputs(executableCode, output);

    fclose(output);
  }

  setExecutable(hook_path);
  free(hook_path);
}

void addHook()
{
  // Copy kambria-pre-hooks to user's git
  copyKambriaPrePush();
  // Add executable code to pre-push
  addExecutableCode();
}

void addKambriaRemote(const char *repo_url)
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

void createRC(const char *key)
{
  FILE *kambriarc;
  char *kambriarc_path = getRootPath(".kambriarc");
  kambriarc = fopen(kambriarc_path, "w");
  fputs(key, kambriarc);

  free(kambriarc_path);
  fclose(kambriarc);
}
