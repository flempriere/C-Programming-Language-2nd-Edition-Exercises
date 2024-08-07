#include "my_string_fn.h"
#include <stdio.h>

char *my_strncpy(char *s, char *ct, unsigned n)
{
    char *ret = s;
    for(; n && (*s = *ct); s++, ct++, n--);
    if (n) {
        for(; n; --n) {*s++ = '\0';}
    }
    return ret;
}

char *my_strncat(char *s, char *ct, unsigned n)
{
    char *ret = s;
    while(*s++);
    s--;
    for(; n && (*s = *ct); s++, ct++, n--);
    if (n) *s = '\0';
    return ret;
}

int my_strncmp(char *s, char *ct, unsigned n)
{
    for (; n && *s == *ct; s++, ct++, n--) {
        if (!(*s)) return 0;
    }
    if (n) return (*s - *ct);
    return 0;
}
