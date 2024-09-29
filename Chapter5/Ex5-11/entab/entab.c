#include "entab.h"
#include <stdio.h>

#define START_COL 1
/*
entab, replaces strings of blanks with tabs. Takes a list of tabstops,
if len <= 0, then uses default tabstop behaviour. If the list is exhausted
before end of line is reached, falls back on default tabstop behaviour
*/
void entab(int len, int a[])
{
    int col = START_COL, rem = len, *p = a;
    int n_spaces = 0, n_tabs = 0;
    int c;
    int nxt_tab = nextTab(rem, p, START_COL); 

    for (; (c = getchar()) != EOF; col++)
    {
        if (c == ' ')
        {
            if (col == nxt_tab)
            {
                n_spaces = 0;
                n_tabs++;
                rem--;
                nxt_tab = nextTab(rem, (rem > 0) ? ++p : p, col);
            }
            else
            {
                n_spaces++;
            }
        }
        else if (c == '\t')
        {
            n_spaces = 0;
            n_tabs++;
            col = nxt_tab;
            rem--;
            nxt_tab = nextTab(rem, (rem > 0) ? ++p : p, col);
        }
        else
        {
            for(; n_tabs > 0; n_tabs--) {putchar('\\'); putchar('t');}
            for(; n_spaces > 0; n_spaces--) putchar(' ');
            putchar(c);
            if (c == '\n') {
                col = START_COL - 1; 
                rem = len;
                p = a; 
                nxt_tab = nextTab(rem, p, START_COL);
            }
        }
    }
}