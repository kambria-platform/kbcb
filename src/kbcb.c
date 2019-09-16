#include <stdio.h>

#define ENV "development"


int main()
{
    printf("Environment: %s\n", ENV);

    FILE *file;
    FILE *copied_file;
    char c;

    file = fopen("/usr/share/kbcb/pre-push", "r");
    copied_file = fopen("./.git/hooks/pre-push", "w");

    if (file == NULL)
    {
        printf("Cannot open the file!\n");
        return 0;
    }

    while ((c = fgetc(file)) != EOF)
    {
        fputc(c, copied_file);
    }

    fclose(file);
    printf("Done!\n");

    return 0;
}
