#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int wordLengths[255];
    int c, state, length;

    state = OUT;
    length = 0;
    for (int i = 0; i < 255; i++) wordLengths[i] = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            if (length < 255) {wordLengths[length]++; length = 0;};
        }
        else if (state == OUT) {
            state = IN;
            length = 1;
        }
        else ++length;
    }

    for (int i = 0; i < 255; i++) {
        printf("%d: ", i);
        for (int j = 0; j < wordLengths[i]; ++j) putchar('*');
        putchar('\n');
    }
    return 0;
}