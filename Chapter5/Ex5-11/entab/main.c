#include "entab.h"
#include <stdio.h>

#define MAXTAB 100

int main(int argc, char *argv[])
{
    int tabs[MAXTAB];
    int len;

    if (--argc > MAXTAB)
    {
        printf("Error: Exceeded max tabstops: %d\n", MAXTAB);
        return 1;
    }
    if (argc)
    {
        len = setTab(MAXTAB, tabs, argc, ++argv);
        if (len < 0)
        {
            printf("Encountered negative or -increasing tabstop\n");
            return 1;
        }
    }
    else {
        len = 0;
    }
    entab(len, tabs);
}