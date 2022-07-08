#include <stdio.h>

#define TABINC 8

int main() {
    int index, n_spaces, incr, c;
    index = 1;
    n_spaces = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') { //calc number of tab spaces
            n_spaces += TABINC - ((index + n_spaces - 1) % TABINC);
        }
        else if (c == ' ') {
            ++n_spaces;
        }
        else {
            while ((incr = TABINC - ((index -1) % TABINC)) <= n_spaces) {
                putchar('\t'); //use as many tabs as possible
                n_spaces -= incr;
                index += incr;
            }
            for (int i = n_spaces; i > 0; i--) {
                ++index; //fill the rest with blanks
                putchar(' ');
            }
            ++index;
            putchar(c);
            if (c == '\n') {index = 1;}
            n_spaces = 0;
        }
    }
    return 0;
}