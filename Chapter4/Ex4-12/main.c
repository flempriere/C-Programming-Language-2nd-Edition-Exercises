#include <stdlib.h>
#include <stdio.h>
#include "itoa.h"

int main(void)
{
    char source[MAXLINE];
    int result;
    printf("Enter the source number: ");
    getLine(source, MAXLINE);
    result = atoi(source);
    printf("Number as integer: %d\n", result);
    itoa(source, result, MAXLINE);
    printf("Converting to string: %s\n", source);

    return 0;
}