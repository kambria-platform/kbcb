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
    removeLineFromFile("KAMBRIA_SRC_DIR=`git rev-parse --show-toplevel`\n", hook_path, temp_path);
    removeLineFromFile("sh $KAMBRIA_SRC_DIR/.git/hooks/kambria-pre-push $1 $2\n", hook_path, temp_path);
    removeLineFromFile("exit 0\n", hook_path, temp_path);

    char *executableCode = "KAMBRIA_SRC_DIR=`git rev-parse --show-toplevel`\n"
                           "sh $KAMBRIA_SRC_DIR/.git/hooks/kambria-pre-push $1 $2\n"
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
                           "KAMBRIA_SRC_DIR=`git rev-parse --show-toplevel`\n"
                           "sh $KAMBRIA_SRC_DIR/.git/hooks/kambria-pre-push $1 $2\n"
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

void removeHook()
{
  // Remove kambria-pre-push
  char *kambria_hook_path = getHookPath("kambria-pre-push");
  printf("*** Removing kambria-pre-push: %s - ", kambria_hook_path);
  if (checkHookExistence("kambria-pre-push") == 1)
  {
    int ok = remove(kambria_hook_path);
    if (ok == 0)
    {
      printf("Done!\n");
    }
    else
    {
      printf("Error: Unnable to remove the file!\n");
    }
  }
  else
  {
    printf("Done!\n");
  }
  free(kambria_hook_path);
  // Remove pre-push
  char *hook_path = getHookPath("pre-push");
  printf("*** Removing pre-push: %s - ", hook_path);
  if (checkHookExistence("pre-push") == 1)
  {
    char *temp_path = getHookPath("temp-pre-push");
    removeLineFromFile("KAMBRIA_SRC_DIR=`git rev-parse --show-toplevel`\n", hook_path, temp_path);
    removeLineFromFile("sh $KAMBRIA_SRC_DIR/.git/hooks/kambria-pre-push $1 $2\n", hook_path, temp_path);
    removeLineFromFile("exit 0\n", hook_path, temp_path);

    int isEmpty = checkEmptyExectuableFile(hook_path);
    if (isEmpty == 1)
    {
      int ok = remove(hook_path);
      if (ok == 0)
      {
        printf("Done!\n");
      }
      else
      {
        printf("Error: Unnable to remove the file!\n");
      }
    }
    free(temp_path);
  }
  else
  {
    printf("Done!\n");
  }
  free(hook_path);
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

void removeRC()
{
  char *kambriarc_path = getRootPath(".kambriarc");
  printf("*** Removing .kambriarc: %s - ", kambriarc_path);
  int ok = remove(kambriarc_path);
  if (ok == 0)
  {
    printf("Done!\n");
  }
  else
  {
    printf("Error: Unnable to remove the file!\n");
  }

  free(kambriarc_path);
}
