#include <stdio.h>
#include "kambriarc.h"

#define KAMBRIARC_PATH "./.kambriarc"

int createEmptyRC()
{
    FILE *kambriarc;
    kambriarc = fopen(KAMBRIARC_PATH, "w");
    fclose(kambriarc);
    return 0;
}

int createRC(char *key)
{
    FILE *kambriarc;
    kambriarc = fopen(KAMBRIARC_PATH, "w");
    fputs(key, kambriarc);
    fclose(kambriarc);
    return 0;
}