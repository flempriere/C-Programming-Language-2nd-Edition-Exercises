#include "detab.h"
#include <stdio.h>

#define START_COL 1
/*
detab, replaces strings of tabs with blanks. Takes a list of tabstops,
if len <= 0, then uses default tabstop behaviour. If the list is exhausted
before end of line is reached, falls back on default tabstop behaviour
*/
void detab(int len, int a[])
{
    int col = START_COL, rem = len, *p = a;
    int c;
    int nxt_tab = nextTab(rem, p, START_COL); 

    while((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            while(nxt_tab <= col) //find next tabstop
            {
                rem--; 
                nxt_tab = nextTab(rem, (rem > 0) ? ++p : p, col);
            }
            for(; col <= nxt_tab; col++) putchar(' '); 
            rem--;
            nxt_tab = nextTab(rem, (rem > 0) ? ++p : p, col);
        }
        else if (c == '\n')
        {
            putchar(c);
            col = START_COL; 
            rem = len;
            p = a; 
            nxt_tab = nextTab(rem, p, col);
        }
        else
        {
            putchar(c);
            col++;
        }
    }
}