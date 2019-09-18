#include <stdio.h>
#include <string.h>
#include "util.h"
#include "kambria.h"

int main(const int argc, const char *argv[])
{
    const char *ERROR = "Invalid parameters.";
    const char *HELP = "Show help.";

    if (argc >= 2)
    {
        if (strcmp(argv[1], "init") == 0)
        {
            char repo[100] = "empty";
            char key[100] = "empty";

            /**
             * Get params by options
             */
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
            }

            /**
             * Get params manually
             */
            if (strcmp(repo, "empty") == 0)
            {
                printf("Repository URL: ");
                gets(repo);
            }
            if (strcmp(key, "empty") == 0)
            {
                printf("Authentication key: ");
                gets(key);
            }

            /**
             * Execute params
             */
            // Repo related
            if (strcmp(repo, "empty") == 0 || strlen(repo) == 0)
            {
                char *error = "\tYou cannot setup Kambria Codebase without your repository url.\n"
                              "\tPlease create your repo on Kambria Codebase first.\n"
                              "\tFor more detail, access app.kambria.io";
                handleCommonError(error);
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
                handleCommonInfo(info);
                createEmptyRC();
            }
            else
            {
                createRC(key);
            }
        }
        else if (strcmp(argv[1], "fix") == 0)
        {
            printf("Fix\n");
        }
        else
        {
            handleCommonError(ERROR);
        }
    }
    else
    {
        printf(HELP);
    }

    return 0;
}