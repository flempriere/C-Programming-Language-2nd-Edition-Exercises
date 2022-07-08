#include <stdio.h>

int main() {
    int charCount[255];
    int c;
    for (int i = 0; i < 255; ++i) charCount[i] = 0;

    while((c = getchar()) != EOF) {
        ++charCount[c];
    }
    for (int i = 0; i <  255; ++i) {
        printf("%c: ", i);
        for (int j = 0; j < charCount[i]; ++j) {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}