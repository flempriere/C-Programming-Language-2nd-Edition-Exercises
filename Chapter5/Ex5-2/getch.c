#include <stdio.h>
#include "getfloat.h"

static int buf[BUFSIZE];
static int bufp;


int getch(void)
{
    if (bufp) {
        int c = buf[--bufp];
        return c;
    }
    else return getchar();
}

void ungetch(int c)
{
    if (bufp == BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else {buf[bufp++] = c;}
}