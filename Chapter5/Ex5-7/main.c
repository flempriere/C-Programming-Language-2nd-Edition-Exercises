#include "ex5-7.h"
#include <stdio.h>

int main(void)
{
    int nlines;
    char *lineptr[MAXLINES];
    char arena[MAXLINES * MAXLEN];
    printf("=====Sort Lines====\n");
    if((nlines = readlines(lineptr, arena, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}