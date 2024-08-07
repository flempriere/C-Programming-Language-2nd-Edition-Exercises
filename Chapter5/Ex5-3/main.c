#include <stdio.h>
#include "strcat.h"





int main(void) {
    char s[2*MAXLINE];
    char t[MAXLINE];

    printf("Enter s: ");
    getLine(s, MAXLINE);
    printf("Enter t: ");
    getLine(t, MAXLINE);
    printf("s: %s\n t: %s\n", s, t);
    my_strcat(s, t);
    printf("s after strcat: %s\n", s);
}