#include <ctype.h>
#include <stdio.h>
#include "getint.h"

#define CHECK_EOF(c) do {if (c != EOF) ungetch(c);} while(0)
/* getint: get next integer from input into *pn 
    returns 0 on invalid input, -1 on EOF, else the last read character
*/
int getint(int *pn)
{
    int c, sign;

    while(isspace(c = getch())); /*skip whitespace*/

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        printf("character was: %d\n", c);
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int d = c;
        if (!isdigit(c = getch())) {
            CHECK_EOF(c);
            ungetch(d);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch()) *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    CHECK_EOF(c);
    return c;
}