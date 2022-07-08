#include <stdio.h>

int main() {
    long nb = 0;
    long nt = 0;
    long nl = 0;
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == '\n') ++nl;
        if (c == '\t') ++nt;
        if (c == ' ') ++nb;
    }
    printf("n. Tabs: %ld, n. Blanks: %ld, n. newlines: %ld\n", nt, nb, nl);
    return 0;
}