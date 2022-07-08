#include <stdio.h>

#define TABINC 8

int main()  {
    int index, n_spaces, c;
    n_spaces = 0;
    index = 1;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            n_spaces = TABINC - ((index - 1) % TABINC);
            while (n_spaces > 0) {
                putchar(' ');
                ++index;
                --n_spaces;
            }
        }
        else if (c == '\n') {
            putchar(c);
            index = 1;
        }
        else {
            putchar(c);
            ++index;
        }
    }
    return 0;
}