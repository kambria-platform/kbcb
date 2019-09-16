#include <stdio.h>

int main()
{
    printf("Hi! I am a Kambria codebase worker!\n");

    FILE *file;
    FILE *copied_file;
    char c;

    file = fopen("/usr/share/kbcb/pre-push", "r");
    copied_file = fopen("./tmp/new-pre-push", "w");

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
