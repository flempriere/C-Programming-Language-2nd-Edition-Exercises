#include <stdio.h>
#include "ex5-6.h"


int main(void)
{
    char s[MAXLINE] = "test_string_1";
    char t[MAXLINE] = "str_str_str";

    char a[MAXLINE] = "12345";
    char v[MAXLINE];
    char b[MAXLINE] = "-12345";
    char f[MAXLINE] = "12.345";
    char g[MAXLINE] = "-12.345";
    char h[MAXLINE] = "-123.45e-1";
    char i[MAXLINE] = ".12345e+1";
    int j;

    printf("Testing reverse: \ns: %s\n", s);
    reverse(s);
    printf("Reversed: %s\n", s);

    printf("Testing strindex and strrindex: \nt: %s\npattern: str\n", t);
    printf("strindex(s): %d\n strrindex(s): %d\n", 
        strindex(t, "str"), strrindex(t, "str"));
    
    printf("Testing atoi and itoa\n");
    j = atoi(a);
    itoa(j, v);
    printf("Original string: %s\natoi(): %d\nconverted back: %s\n", a, j, v);

    printf("Testing atoi and itoa\n");
    j = atoi(b);
    itoa(j, v);
    printf("Original string: %s\natoi(): %d\nconverted back: %s\n", b, j, v);

    printf("Testing itoa with optional base (hex) and padding, int as before\n");
    itob(j, v, 16);
    printf("Hexadecimal conversion: %s\n", v);
    itoa2(j, v, 10);
    printf("Padded conversion with min width = 10: %s, int as before\n", v);

    printf("Testing atof: \nstrings are %s\n%s\n%s\n%s\n%s\n",
        a,f,g,h,i);
    printf("Floats are: \n%g\n%g\n%g\n%g\n%g\n", atof(a), atof(f),
        atof(g), atof(h), atof(i));

    printf("Test getline: \n");
    j = getLine(v, MAXLINE);
    printf("Read in line was: %s, read %d characters\n", v, j);

    return 0;
}