#include "strend.h"
#include <string.h>
#include <stdio.h>

int strend(char *s, char *t)
{
    unsigned n = strlen(t);
    while(*s++); 
    /*move to end of the string [0 ... n - 1]\0 X*/
    for (s -= n + 1; *s == *t && *s; s++, t++);
    /* loop until unequal or we reach the end*/
    if (*s) return 0; /* didn't reach end -> unequal*/
    return 1;
}
