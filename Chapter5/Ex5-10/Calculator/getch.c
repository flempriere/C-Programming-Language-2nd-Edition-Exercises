#include <stdio.h>

#define BUFSIZE 100

int buf = 0;
static char **input = NULL;
static char *cur;
static int len;

void set_input(int l, char *s[])
{
    len = l;
    input = s;
    cur = *input;
}

int getch(void)
{
    int c;
    if (buf) {
        c = buf;
        buf = '\0';
        return c;
    }
    else if (input == NULL) {
        return getchar();
    }
    else
    {
        if (!len) c =  EOF;
        else if (*cur)
        {
            c = *cur++;
        }
        else
        {
            input++;
            cur = *input;
            len--;
            c = ' ';
        }
        return c;
    }
}

void ungetch(int c)
{
    if (buf)
    {
        printf("ungetch: too many characters\n");
    }
    else {buf = c;}
}