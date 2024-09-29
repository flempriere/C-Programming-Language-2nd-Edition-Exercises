#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[])
{
    int i, c;

    while (isblank((s[0] = c = getch())));
    if (c == EOF) return c;
    s[1] = '\0';

    i = 0;
    if (!isdigit(c)) { /* check if digit */
        if (c == '-')
        {
            if (isdigit(c = getch()) || c == '.')
            {
                s[++i] = c; 
            }
            else 
                if (c != EOF) {ungetch(c); return '-';}
        }
        else if (c == '.')
        {
            s[++i] = c = getch();
        }
        else if (c == '\n') return '\n';
        else {
            while(isalnum(s[++i] = c = getch()));
            if (c != EOF) {
                ungetch(c);
                if (i == 1) return s[0];
                else {
                    s[i] = '\0';
                    return MATH_FUNC;
                }
            }
        }
    }
    if (isdigit(c))
    {
        while(isdigit(s[++i] = c = getch()));
    }
    if (c == '.')
    {
        while(isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF) ungetch(c);
    return NUMBER;
}