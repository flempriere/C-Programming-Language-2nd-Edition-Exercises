#include "detab.h"
#include <stdlib.h>
#include <stdio.h>

int setTab(int lim, int a[], int argc, char *argv[])
{
    int i, prev = -1;
    int *p = a;
    for (; argc && lim; argc--, lim--)
    {
        i = atoi(*argv++);
        if (i <= prev || i < 0) 
        {
            return -1;    
        }
        *p++ = i;
    }
    return p - a;
}

int nextTab(int lim, int a[], int col)
{
    int nxt;
    if (lim > 0) nxt = *a;
    else {
        nxt = col + (((col % TABSTOP) == 0) ? (TABSTOP) : (TABSTOP - col % TABSTOP));
    }
    return nxt;
}