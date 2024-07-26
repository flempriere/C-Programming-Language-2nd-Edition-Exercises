#include "getint.h"
#include <stdio.h>

int main(void) {

    int n, array[SIZE], state;
    printf("Enter integers seperated by whitespace\n");
    for (n = 0; n < SIZE && (state = getint(&array[n])) != EOF 
            && state != 0; n++);

    int j;
    for (j = 0; j < n; j++) printf("[%d]", array[j]);
    printf("\n");
    return 0;
}