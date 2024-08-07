#include <stdio.h> 
#include "strend.h"

int main(void)
{
    char s[MAXLINE];
    char t[MAXLINE];

    printf("Enter s: ");
    getLine(s, MAXLINE);
    printf("Enter t: ");
    getLine(t, MAXLINE);
    printf("s is suffixed with t: %s\n", strend(s, t) ? "YES" : "NO");
    
    return 0;

}
