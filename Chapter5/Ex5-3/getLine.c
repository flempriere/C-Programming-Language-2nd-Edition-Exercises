#include <stdio.h>
#include "strcat.h"

int getLine(char s[], int lim)
{
    int i, c='\0';
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n');
    s[i] = '\0';
    return i;
}