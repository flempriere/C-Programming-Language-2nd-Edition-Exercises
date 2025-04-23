#include "detab.h"
#include <stdio.h>

void detab(int s_col, int incr)
{
    int col = START_COL;
    int c;
    int nxt_tab = nextTab(s_col, incr, START_COL); 

    while((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            while(nxt_tab <= col) //find next tabstop
            {
                nxt_tab = nextTab(s_col, incr, nxt_tab);
            }
            for(; col <= nxt_tab; col++) putchar(' ');
            nxt_tab = nextTab(s_col, incr, col);
        }
        else if (c == '\n')
        {
            putchar(c);
            col = START_COL;
            nxt_tab = nextTab(s_col, incr, col);
        }
        else
        {
            putchar(c);
            col++;
        }
    }
}