#include <stdio.h>

#define BUFSIZE 100

int buf = 0;

int getch(void)
{
    if (buf) {
        int c = buf;
        buf = '\0';
        return c;
    }
    else return getchar();
}

void ungetch(int c)
{
    if (buf)
    {
        printf("ungetch: too many characters\n");
    }
    else {buf = c;}
}