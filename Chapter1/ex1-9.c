#include <stdio.h>
/*copies input to output, removing excess spaces*/
int main() {
    int c;
    int space_flag = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') space_flag = 1;
        else {
            if (space_flag == 1) putchar(' ');
            putchar(c);
            space_flag = 0;
        }
    }
    return 0;
}