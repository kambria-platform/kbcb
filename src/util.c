#include <stdio.h>

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