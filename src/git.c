#include <stdio.h>
#include "git.h"

#ifdef ROOT
#define STRINGIFY(path) #path
#define GET_ROOT(path) STRINGIFY(path)
#define ROOT_PATH GET_ROOT(ROOT)
#else
#define ROOT_PATH "."
#endif

#ifdef DEVELOPMENT
#define ENV "development"
#define SHARED_PATH ROOT_PATH "/src/hooks/pre-push"
#define OUTPUT_PATH ROOT_PATH "/pre-push"
#else
#define ENV "production"
#define SHARED_PATH "/usr/share/kbcb/pre-push"
#define OUTPUT_PATH "./.git/hooks/pre-push"
#endif

int addHook()
{
    printf("*** Environment: %s\n", ENV);
    printf("*** Source path: %s\n", ROOT_PATH);

    /**
     * Copy pre-hooks to user's git
     */
    FILE *input;
    FILE *output;
    input = fopen(SHARED_PATH, "r");
    output = fopen(OUTPUT_PATH, "w");
    if (input == NULL)
    {
        printf("kbcb package met a critical damage, please reinstall the package and retry!\n");
        return 1;
    }
    char c;
    while ((c = fgetc(input)) != EOF)
    {
        fputc(c, output);
    }
    fclose(input);

    return 0;
}

int addKambriaRemote(char *repo)
{

    return 0;
}
