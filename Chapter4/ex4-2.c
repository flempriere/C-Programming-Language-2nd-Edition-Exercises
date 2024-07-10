#include <ctype.h>
#include <stdio.h>


#define MAXLINE 1000

int getLine(char s[], int lim);
double atof(char s[]);

int main(void)
{
    char source[MAXLINE];
    double result;
    printf("Enter the source number: ");
    getLine(source, MAXLINE);
    result = atof(source);
    printf("Result: %f\n", result);

}

int getLine(char s[], int lim)
{
    int i, c='\0';
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') s[i++] = c;
    s[i] = '\0';
    return i;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign, exp;
    for (i = 0; isspace(s[i]); i++); /* skip whitespace */
    sign = ((s[i] == '-') ? -1 : 1);
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    val = sign*val / power;

    if (s[i] == 'e' || s[i] == 'E')
    {
        sign = (s[++i] == '-' ?  -1 : 1);
        if (s[i] == '+' || s[i] == '-') i++;
        for (exp = 0; isdigit(s[i]); i++)
        {
            exp = 10 * exp + (s[i] - '0');
        }
        if (sign == 1)
        {
            for (; exp > 0; exp--) val *= 10;
        }
        else
            for (; exp > 0; exp--) val /= 10;
    }
    return val;
}
