#include <stdio.h>

int main() {
    /*copy input to output; verify assignment comparision is 0 or 1*/
    int c;

    while (c = (getchar() != EOF)) {
        printf("%d\n", c);
    }
    printf("%d\n", c);
    return 0;
}