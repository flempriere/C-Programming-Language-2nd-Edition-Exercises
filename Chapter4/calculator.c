/*
A simple command line calculator using reverse polish
notation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/* main function defines */
#define MAXOP 100
#define NUMBER '0'
/* exercise 4-4 function keys*/
#define TOP '?'
#define DUPLICATE '~'
#define SWAP '@'
#define CLEAR '#'
#define VARIABLE_ASSIGNMENT '='
/* exercise 4-5 defines*/
#define MATH_FUNC '$'
#define PI 3.1415


/* stack defines */
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

/* char buffer defines */
 #define BUFSIZE 100
/* Exercise 4-9 */
/* buffer goes from char -> int, to handle case that char is unsigned, EOF=-1*/
int buf = 0; //buf now one character of input
int bufp = 0; //marks if buffer is full or not (since number could be legit)
#define EMPTY 0
#define FULL 1

int getch(void); //modified by exercise 4-8 and 4-9
void ungetch(int c);
void ungets(char s[]); //exercise 4-7 (functionality not used)

int getop(char s[]);
void push(double f);
double pop(void); 
double top(void);
/* Exercise 4-4 functions start*/
void duplicate(void);
void swapTop(void);
void clear(void);
/* end Exercise 4-4 functions*/

/* Exercise 4-5 functions */
void mathfn(char s[], int lim);
void printRangeError(char s[], double x, double lower, double upper);

/* Exercise 4-6 variable support */
#define N_VARIABLES 27 //alphabetic variable support + last accessed
#define LAST_PRINTED_VAR 'p'
void initialiseArray(double a[], int len);



int main()
{
    int type, var;
    var = 0;
    double op2;
    char s[MAXOP];
    double variables[N_VARIABLES];
    initialiseArray(variables, N_VARIABLES);


    printf("Welcome to the command line calculator.\n");
    printf("This program uses polish notation e.g x + y -> x y +\n");
    printf(">>: ");
    while((type = getop(s)) != EOF) {
        switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case MATH_FUNC:
            mathfn(s, MAXOP);
            break;
        case TOP:
            variables[N_VARIABLES - 1] = top();
            printf("\t%.8g\n", variables[N_VARIABLES - 1]);
            break;
        case DUPLICATE:
            duplicate();
            break;
        case SWAP:
            swapTop();
            break;
        case CLEAR:
            clear();
            break;
        case VARIABLE_ASSIGNMENT:
            pop(); //remove previous variable assignment
            if (isupper(var)) variables[var - 'A'] = pop();
            else printf("error: invalid variable name\n");
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0) push(pop()/op2);
            else printf("error: zero divisor!\n");
            break;
        case '%':
            /*Ex 4-3: We handle float values by using fmod*/
            op2 = pop();
            if (op2 != 0.0) push(fmod(pop(), op2));
            break;
        case '\n':
            variables[N_VARIABLES - 1] = pop();
            printf("\t%.8g\n", variables[N_VARIABLES - 1]);
            printf(">>: ");
            break;
        default:
            if (isupper(type)) push(variables[type - 'A']);
            else if (type == LAST_PRINTED_VAR) push(variables[N_VARIABLES - 1]);
            else {
                printf("error: unknown command %s\n", s);
            }
            break;
        }
        var = type;
    }
    return 0;
}

int getch(void)
{
    if (bufp == FULL) {
        bufp = EMPTY;
        return buf;
    }
    else return getchar();
}

void ungetch(int c)
{
    if (bufp == FULL)
    {
        printf("ungetch: too many characters\n");
    }
    else {buf = c; bufp = FULL;}
}

void ungets(char s[])
/*
Pushes an entire string onto the buffer. Does not need to know about buf, or
buf_p other than that they operate as a stack (LIFO), so we need to put the
string in backwards. 

if we len ungets() know about buf and the bufp then we can do stricter error
checking for buffer overflow that isn't handled but ungetch etc...
*/
{
    int len;
    for (len = strlen(s); len > 0;) ungetch(s[--len]);
}

int getop(char s[])
{
    int i, c;

    while (isblank((s[0] = c = getch())));
    s[1] = '\0';

    i = 0;
    if (!isdigit(c)) { /* check if digit */
        if (c == '-')
        {
            if (isdigit(c = getch()) || c == '.')
            {
                s[++i] = c; 
            }
            else 
                if (c != EOF) {ungetch(c); return '-';}
        }
        else if (c == '.')
        {
            s[++i] = c = getch();
        }
        else if (c == '\n') return '\n';
        else {
            while(isalnum(s[++i] = c = getch()));
            if (c != EOF) {
                ungetch(c);
                if (i == 1) return s[0];
                else {
                    s[i] = '\0';
                    return MATH_FUNC;
                }
            }
        }
    }
    if (isdigit(c))
    {
        while(isdigit(s[++i] = c = getch()));
    }
    if (c == '.')
    {
        while(isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF) ungetch(c);
    return NUMBER;
}

void push(double f)
{
    if (sp < MAXVAL) val[sp++] = f;
    else printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0) return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
/*
Exercise 4-4 functions
top: returns the top element without popping
duplicate: duplicates the top element
swapTop: swaps the top two elements

Note: These functions could be implemented in an
implementation-free way using push() and pop()
but we take advantage of the array implementation
to do less operations.
*/
double top(void)
{
    if (sp > 0) return val[sp - 1];
    printf("error: stack empty\n");
    return 0.0;
}

void duplicate(void)
{
    if ((sp > 0) && (sp < MAXVAL)) push(top());
    else {
        printf("error: stack empty\n");
    }
}

void swapTop(void)
{
    if (sp < 2) {
        printf("error: not enough elements to swap\n");
    }
    else {
        double tmp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = tmp;
    }
}

void clear(void)
{
    sp = 0;
}
void printRangeError(char s[], double x, double lower, double upper)
{
    printf("error: value of x %g is invalid for %s.\n", x, s);
    printf("Valid range is [%g, %g]\n", lower, upper);
}

void initialiseArray(double a[], int len)
{
    for (; len > 0; len--) a[len - 1] = 0.0;
}

void mathfn(char s[], int lim)
/*
We use strncmp, since strcmp(s, t) = 0 if equal we have
to use note operator ! to invert truthfulness
*/
{
    double x, y;
    if (!strncmp(s, "sin", lim)) push(sin(pop()));
    else if (!strncmp(s, "cos", lim)) push(cos(pop()));
    else if (!strncmp(s, "tan", lim)) push(tan(pop()));
    else if (!strncmp(s, "asin", lim)) {
        x = pop();
        if (!((x < 1) && (x > - 1)))
        {
            printRangeError("asin", x, -1, 1);
        }
        else push(asin(x));
    }
    else if (!strncmp(s, "acos", lim)) {
        x = pop();
        if (!((x < 1) && (x > -1)))
        {
            printRangeError("acos", x, -1, 1);
        }
        else push(acos(x));
    }
    else if (!strncmp(s, "atan", lim)) push(atan(pop()));
    else if (!strncmp(s, "atan2", lim)) {
        x = pop();
        if (x != 0.0) push(atan2(pop(), x));
        else printf("Error: zero divisor in function atan2");
    }
    else if (!strncmp(s, "sinh", lim)) push(sinh(pop()));
    else if (!strncmp(s, "cosh", lim)) push(cosh(pop()));
    else if (!strncmp(s, "tanh", lim)) push(tanh(pop()));
    else if (!strncmp(s, "exp", lim)) push(exp(pop()));
    else if (!strncmp(s, "log", lim)) push(log(pop()));
    else if (!strncmp(s, "log10", lim)) push(log10(pop()));
    else if (!strncmp(s, "pow", lim)) {
        y = pop();
        push(pow(pop(), y));
    }
    else if (!strncmp(s, "sqrt", lim)) {
        x = pop();
        if (x < 0) printf("error: argument of sqrt must be non-negative\n");
        else push(sqrt(x));
    }
    else if (!strncmp(s, "ceil", lim)) push(ceil(pop()));
    else if (!strncmp(s, "floor", lim)) push(floor(pop()));
    else {
        printf("error: unrecognised function\n");
    }
}
