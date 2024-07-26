#include <string.h>
#include "reverse.h"

void recursiveReverse(char s[], int i, int j);
void swap(char s[], int i, int j);

void reverse(char s[]) {
    int len = strlen(s);
    recursiveReverse(s, 0, --len);
}

void recursiveReverse(char s[], int i, int j)
{
    if (i < j) {
        swap(s, i, j);
        recursiveReverse(s, ++i, --j);
    }
}

void swap(char s[], int i, int j)
{
    char t = s[j];
    s[j] = s[i];
    s[i] = t; 
}
