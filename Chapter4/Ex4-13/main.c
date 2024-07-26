#include <stdlib.h>
#include <stdio.h>
#include "reverse.h"

int main(void)
{
    char source[MAXLINE];
    printf("Enter the source string: ");
    getLine(source, MAXLINE);
    reverse(source);
    printf("Reversed string: %s\n", source);

    return 0;
}