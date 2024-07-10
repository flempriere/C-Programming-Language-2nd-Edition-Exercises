#include <stdio.h>

#define BUFSIZE 100
#define EMPTY 0
#define FULL 1

int buf;
int bufp = EMPTY;

int getch(void)
{
    if (bufp == FULL) {bufp = EMPTY; return buf;}
    else return getchar();
}

void ungetch(int c)
{
    if (bufp == FULL)
    {
        printf("ungetch: too many characters\n");
    }
    else {buf = c; bufp = FULL;}
}