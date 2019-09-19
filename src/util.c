#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util.h>

#ifdef DEVELOPMENT
#define ENV "development"
#else
#define ENV "profuction"
#endif

char *getRootPath(char *filename)
{
    char *hook_path;
    if (ENV == "development")
        hook_path = "./dist/";
    else
        hook_path = "./.git/hooks/";

    char *re = malloc(strlen(hook_path) + strlen(filename) + 1);
    strcpy(re, hook_path);
    strcat(re, filename);
    return re;
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
                 "\tinit: \tInitiate your project on Kambria Codebse.\n"
                 "\tfix: \t(This function is rarely used) In case of merging conflict on Kambria Codebase and you cannot fix it by manually merging. Fix command will force to resync your repository.\n"
                 "\nOptions:\n"
                 "\t-r --repo: \tAdd your repository url to remote.\n"
                 "\t-k --key: \tAdd authentication key to .kambriarc.\n"
                 "\t--force: \tForce to init new connection without caring about remote existence.\n"
                 "\t-h --help: \tShow help information.";
    handleInfo(help);
    exit(0);
}