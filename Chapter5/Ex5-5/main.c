#include <stdio.h>
#include <string.h>
#include "my_string_fn.h"

int main(void)
{
    printf("Testing string functions\n");
    char s[MAXLINE] = "Hello, World";
    char t[MAXLINE] = "Hello, ";
    char u[MAXLINE] = "World";

    char *v;
    int i;
    printf("Testing strings:\n s: %s\n t: %s\n u: %s\n", s,t,u);
    printf("Testing my_strncat\n");
    printf("Test 1: my_strncat(t, u, 100) concats entire string\n");
    v = my_strncat(t, u, 100);
    printf("result: %s\n", v);
    printf("Test 2: my_strncat(t, u, 6) concats entire string\n");
    v = my_strncat(t, u, 5);
    printf("result: %s\n", v);
    printf("Test 3: my_strncat(t, u, 5) cuts off last character\n");
    v = my_strncat(t, u, 4);
    printf("result: %s\n", v);
    printf("Test 4: my_strncat(t, u, 0) doesn't copy anything\n");
    v = my_strncat(t, u, 0);
    printf("result: %s\n", v);

    printf("Testing my_strncpy\n");
    printf("Test 1: my_strncpy(v, u, 100) copies completely\n");
    v = my_strncpy(v, u, 100);
    printf("result: %s\n", v);
    printf("Test 2: my_strncpy(v, s, 13) copies completely\n");
    v = my_strncpy(v, s, 13);
    printf("result: %s\n", v);
    printf("Test 3: my_strncpy(v, u, 3) copies partially\n");
    v = my_strncpy(v, u, 3);
    printf("%s\n", v);

    printf("Testing my_strncmp\n");
    printf("Testing strings:\n s: %s\n t: %s\n u: %s\n", s,t,u);
    printf("Test 1: my_strncmp(t, u, 100) is positive\n");
    i = my_strncmp(t, u, 100);
    printf("result: %d\n", i);
    printf("Test 2: my_strncmp(u, u, 7) is 0\n");
    i = my_strncmp(u, u, 7);
    printf("result: %d\n", i);
    printf("Test 3: my_strncmp(u, u, 3) is 0\n");
    i = my_strncmp(u, u, 3);
    printf("result: %d\n", i);
    printf("Test 4: my_strncmp(t, u, 4) is 0\n");
    i = my_strncmp(t, u, 4);
    printf("result: %d\n", i);
    printf("Test 5: my_strncmp(u, t, 100) is negative\n");
    i = my_strncmp(u, t, 100);
    printf("result: %d\n", i);

    return 0;
}