#include <stdio.h>
/* strcat: appends t to s. It is the caller's responsibility
to ensure that s is large enough to hold s + t*/
void my_strcat(char *s, char *t)
{
    while(*s++);/* find the end of s*/
    s--; //move the pointer back to the null terminator
    while((*s++ = *t++)); /* copy t*/
}