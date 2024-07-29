#include "getfloat.h"
#include <stdio.h>

int main(void) {

    int n, state;
    double array[SIZE];
    printf("Enter floating point numbers seperated by whitespace\n");
    for (n = 0; n < SIZE && (state = getfloat(&array[n])) != EOF 
            && state != 0; n++);

    int j;
    for (j = 0; j < n; j++) printf("[%g]", array[j]);
    printf("\n");
    return 0;
}