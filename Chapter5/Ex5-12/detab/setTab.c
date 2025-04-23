#include "detab.h"
#include <stdlib.h>
#include <stdio.h>

#define DETAB_SET_ARG(x,y) do { \
    argFlags |= (y);            \
    (x) = atoi(*argv + 1);      \
} while(0)                      \

int setTab(int *s_col, int *incr, int argc, char *argv[])
{
    unsigned int argFlags = 0x0u;
    unsigned int colFlag = 0x1u;
    unsigned int incrFlag = 0x2u;

    int error_code = 0;

    for (; argc && !error_code; argc--, *argv++)
    {
        if (*argv[0] == '-')
        {
            if (argFlags & colFlag)
            {
                error_code = 1; //colFlag already set.
            }
            else DETAB_SET_ARG(*s_col, colFlag);
        }
        else if (*argv[0] == '+')
        {
            if (argFlags & incrFlag)
            {
                error_code = 1; //Increment Flag already set.
            }
            else DETAB_SET_ARG(*s_col, colFlag);
        }
        else error_code = 1;
    }
    if (!(argFlags & incrFlag)) *incr = TABSTOP;
    if (!(argFlags & colFlag)) *s_col = START_COL;

    return error_code;
}

int nextTab(int s_col, int incr, int idx)
{
    int nxt, x;
    if (idx < s_col) nxt = s_col;
    else {
        x = (idx - s_col) / incr;
        nxt = s_col + (x+1)*incr;
    }
    return nxt;
}
