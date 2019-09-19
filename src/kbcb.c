#include <stdio.h>
#include <string.h>
#include "util.h"
#include "kambria.h"

#define MAX_LENGTH 255

int main(const int argc, const char *argv[])
{
    if (argc >= 2)
    {
        // Handle init option
        if (strcmp(argv[1], "init") == 0)
        {
            char repo[MAX_LENGTH] = "empty";
            char key[MAX_LENGTH] = "empty";

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
                fgets(repo, MAX_LENGTH, stdin);
                repo[strcspn(repo, "\n")] = '\0'; // Remove newline
            }
            if (strcmp(key, "empty") == 0)
            {
                printf("Authentication key: ");
                fgets(key, MAX_LENGTH, stdin);
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
        // Handle fix option
        else if (strcmp(argv[1], "fix") == 0)
        {
            handleError("The fix function is not implemented yet!");
        }
        // Hanlde help
        else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            showHelp();
        }
        // Handle undefined option
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