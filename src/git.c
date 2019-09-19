#include <stdio.h>
#include <stdlib.h>
#include "git.h"

char *getRootPath()
{
    system("mkdir test");
}

void addRemote(char *remote, char*url)
{
    printf("addRemote\n");
}

void removeRemote(char *remote)
{
    printf("removeRemote\n");
}
