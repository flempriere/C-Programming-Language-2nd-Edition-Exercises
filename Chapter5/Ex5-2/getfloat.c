#include<ctype.h>
#include<stdio.h>
#include "getfloat.h"

#define CHECK_EOF(c) do {if (c != EOF) ungetch(c);} while(0)
#define INCR_DIGIT(c, d) do {c = 10.0 * c + (d - '0');} while(0)

int getfloat(double *pn)
{
    double power;
    int d, sign, exp, c;
    while(isspace(c = getch())); /* skip whitespace */

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = ((c == '-') ? -1 : 1);
    if (c == '+' || c == '-') {
        d = c;
        if (!(isdigit(c=getch()) || c == '.')) { /*+[-].xyz is valid*/
            ungetch(c); /*loop relies on left->right eval of ||*/
            ungetch(d);
            return 0;
        }
    }
    for (*pn = 0.0; isdigit(c); c = getch()) INCR_DIGIT(*pn, c);
    if (c == '.') c = getch();
    for (power = 1.0; isdigit(c); c = getch())
    {
        INCR_DIGIT(*pn, c);
        power *= 10;
    }
    *pn = sign * *pn / power;

    if (c == 'e' || c == 'E')
    {
        sign = ((c = getch()) == '-' ?  -1 : 1);
        if (c == '+' || c == '-') {
            d = c;
            if (!isdigit(c = getch())) {
                ungetch(c);
                ungetch(d);
                return 0;
            }
        }
        for (exp = 0; isdigit(c); c = getch()) INCR_DIGIT(exp, c);
        if (sign == 1)
        {
            for (; exp > 0; exp--) *pn *= 10;
        }
        else
            for (; exp > 0; exp--) *pn /= 10;
    }
    CHECK_EOF(c);
    return c;
}