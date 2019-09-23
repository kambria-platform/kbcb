#include <stdio.h>
#include <string.h>
#include "util.h"
#include "kambria.h"

#define KBCB_BUFFER_LENGTH 255

int main(const int argc, const char *argv[])
{
  if (argc >= 2)
  {
    /**
     * Handle INIT option
     */
    if (strcmp(argv[1], "init") == 0)
    {
      char repo[KBCB_BUFFER_LENGTH] = "empty";
      char key[KBCB_BUFFER_LENGTH] = "empty";

      // Get params by options
      for (int i = 2; i < argc; i++)
      {
        if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--repo") == 0)
        {
          strcpy(repo, argv[i + 1]);
        }
        if (strcmp(argv[i], "-k") == 0 || strcmp(argv[i], "--key") == 0)
        {
          strcpy(key, argv[i + 1]);
        }
        if (strcmp(argv[i], "--force") == 0)
        {
          removeKambriaRemote();
        }
      }

      // Get params manually
      if (strcmp(repo, "empty") == 0)
      {
        printf("Repository URL: ");
        fgets(repo, KBCB_BUFFER_LENGTH, stdin);
        repo[strcspn(repo, "\n")] = '\0'; // Remove newline
      }
      if (strcmp(key, "empty") == 0)
      {
        printf("Authentication key: ");
        fgets(key, KBCB_BUFFER_LENGTH, stdin);
        key[strcspn(key, "\n")] = '\0'; // Remove newline
      }

      // Execute params
      // Repo related
      if (strcmp(repo, "empty") == 0 || strlen(repo) == 0)
      {
        char *error_repo = "\tYou cannot setup Kambria Codebase without your repository url.\n"
                           "\tPlease create your repo on Kambria Codebase first.\n"
                           "\tFor more detail, access app.kambria.io";
        handleError(error_repo);
      }
      else
      {
        addHook();
        addKambriaRemote(repo);
      }
      // Key related
      if (strcmp(key, "empty") == 0 || strlen(key) == 0)
      {
        char *info = "You have skipped to input your key!\n"
                     "We will create a empty .kambriarc then you can edit it later.\n";
        handleInfo(info);
        createEmptyRC();
      }
      else
      {
        createRC(key);
      }
    }

    /**
     * Handle FIX option
     */
    else if (strcmp(argv[1], "fix") == 0)
    {
      handleError("The fix function is not implemented yet!");
    }

    /**
     * Handle GET option
     */
    else if (strcmp(argv[1], "get-dir") == 0)
    {
      // Get params by options
      for (int i = 2; i < argc; i++)
      {
        if (strcmp(argv[i], "--pre-push") == 0)
        {
          handleInfo(getDataPath());
        }
      }
    }

    /**
     * Hanlde HELP option
     */
    else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
      showHelp();
    }

    /**
     * Handle undefined option
     */
    else
    {
      char *invalid_params = "Invalid parameters.";
      handleError(invalid_params);
    }
  }
  else
  {
    showHelp();
  }

  return 0;
}
