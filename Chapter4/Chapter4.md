# The C Programming Language
## Chapter 4: Functions and Program Structure

### Summary of Exercises
- Ex 4-1: implementation of `strindex(s, t)` which returns the starting index of the rightmost occurence of `t` in `s`, or `-1` if there is no match.
- Ex 4-2: Implementation of `atof(s)` that converts a string `s` to a `float` with the ability to handle scientific notation.
---
The following exercises extend on the Calculator program introduced, all are tagged in `calculator.c` rather than as independent implementations.
- Ex 4-3: Implements the modulus function and negative numbers


### Basics of Functions
- Good for seperation of concerns
- Allow details to be abstracted into small code blocks

**Example**: Consider a pattern matching algorithm that returns the lines containing a given pattern. The code outline looks like
```
while (there is a line)
    if (the line has the pattern)
        print it
```
this naturally falls into three functions.

- Can write a function `strindex(s, t)` that returns the first index in `s` where the string `t` begins, else `-1`.
    - since array indices are $>=0$.

**Example continued:**
```
#include<stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int index);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /*pattern to match */
main()
{
    char line[MAXLINE];
    int found = 0;

    while (getline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n') s[i++] = c;
    s[i] = '\0';
    return i;
}

/*strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i,j,k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++);
        if (k > 0 && t[k] == '\0') return i;
    }
    return -1;
}
```
- Observe the first for loop acts as the starting index, we then scan forward to see if we have the full pattern.

#### Function Declarations

- Function declarations have the form
```
return-type function-name(argument declarations)
{
    declarations and statements
}
```
- parts may be omitted, the minimal function is
```
dummy() {}
```
- this returns nothing, takes no arguments and does nothing.
    - omitted return type is assumed `int` *not sure if still true for modern $c$ standards*
#### Programs
- a *program* is a series of definitions of variables and functions
    - functions communicate by arguments and return values
    - (plus external variables)
    - functions may occur in any order in the source file
        - source program may be across multiple files
        - individual functions must reside in one file

#### Return Expression
Syntax is `return expression;`
- any expression may follow return
- expression converted to the return-type (if needed)
- Calling function may ignore return value
- Control returns to caller after calling return
    - even if `return` has no expression
    - control returns to caller if program 'falls off' the last right bracket
- Not *illegal* but **not good** if a function returns a value from one point, and does not at another.
    - failure to return a value results in the "return value" being garbage

- *main* like other functions  can return a value, this can be used by the environment executing the program.


### Functions returning non-integers

- many functions e.g. numerical ($sin, cos$ *etc.*) return non-integer types

**Example: atof**
- converts a string to a floating point value with an optional decimal point and sign

```
#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /* skip whitespace */
    
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - [0]);
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign*val / power
}
```
- calling routine must know `atof` returns a non-int value.
    - Can be done by declaring `atof` explicitly in calling routine.
    - e.g. see the  basic calculator below

```
#include<stdio.h>

#define MAXLINE 1000

/* rudimentary calculator */
int main()
{
    double sum, atof(char []);
    char line[MAXLINE];
    int getline(char line[], int max);

    sum = 0;
    while (getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}
```
- the line `double atof(char []);` says that `atof` is a function that takes one `char[]` argument and returns a `double`.
    - `atof` must be declared and defined consistently
        - these mismatches can occur most often in multifile compilation
    - without a *prototype*, a function is defined *implicitly* by its first declaration.
        - if not declared, it is assumed to return an `int` and no argument assumptions are made
        - additionally declarations like `double atof()` with empty args also make no assumptions on the args
            - **DO NOT USE THIS BEHAVIOUR, IT IS FOR BACKWARDS COMPATABILITY**
                - declare args for those that use them, else use `void`.

We can write an `atoi` using `atof`
```
/* atoi: convert string s to int using atof */
int atoi(char s[])
{
    double atof(char s[])

    return (int) atof(s);
}
```
- we have to cast `atof`'s result to get an  `int`.
    - The return converts automatically
        - This operation may discard info so might have compiler warnings
        - cast makes this *explicit* and warning should be supressed

### External Variables

- C program made of sets of external objects (variables or functions) and *internal* objects (args and variables declared in a function)
- External variables are declared outside of any function
    - available to many functions
- Functions are always external
    - can't define a function in a function
- For *external* functions and variables, all references to them by the same name are references to the same thing
    - this includes when compiled seperately
    - referred to as *external linkage*
- External variables let functions communicate outside of args and return values
    - avoids long argument lists, but not great
    - good when functions share the same data, but neither calls the other.

**Example: Polish Notation Calculator**
- provide the operators `+, -, *, /` using (reverse) polish notation.
    - e.g. $(1 - 2) * (4 + 5) -> $ `1 2 - 4 5 + *`

- Implementation: operand pushed onto stack, when operator arrives we pop the appropriate number of args from the stack, then apply the result and push it back onto the stack
- *pseudocode: *
```
while (next token not EOF)
    if (number)
        push it
    elif (operator)
        pop operands
        do operation
        push result
    elif (newline)
        pop and print top of stack
    else
        error
```
- main doesn't need to know about the stack
    - so store stack + info in external variables

**Example Implementation**
```
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER 0; /* signal that number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch(type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n")
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
```
Because `+` and `*` are commutative the order of popping is irrelevant, but this is not the case for `-` and `/`.
    - `push(pop() - pop())` does not guarantee which `pop` executes first, hence we need to use a temporary variable.

The push and pop can be implemented as follows
```
#define MAXDEPTH 100 /* max stack depth */

int sp = 0; /* next free stack position */
double val[MAXDEPTH]; /* value stack */

/* push f onto value stack */
void push(double f)
{
    if (sp < MAXDEPTH) val[sp++] = f;
    else {
        printf("error: stack full, can't push %g\n", f);
    }
}
/* pop and return top value from the stack */
double pop(void)
{
    if (sp > 0) return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}
```

- Variable is external if it is declared outside of any function.
    - e.g. `stack` and `stack index` are shared by push and pop so are declared external
    - `main` itself does not refer to either variable

- *last function to implement is `getop`*
    - skip whitespace
    - if next character is not a *digit* or *hexadecimal point* return it
        - else collect digits (with optional decimal)
            - signal `NUMBER` that we collected a number

```
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t');

    s[1] = '\0';
    if (!isdigit(c) && c != '.') return c; 
    /*not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
    {
        while(isdigit(s[++i] = c = getch()))
    }
    if (c == '.') /* collect fraction part */
    {
        while(isdigit(s[++i] = c = getch()))
    }
    s[i] = '\0';
    if (c != EOF) ungetch(c);
    return NUMBER;
}
```
- What are `getch()` and `ungetch()`?
    - often need to read input until we read too much to know we've read enough.
        - e.g. building number -> have to see **not** a digit to know we've finished
            - need to *undo* the last read
        - make pair of cooperating functions `getch()` and `ungetch()`.
            - implementation simple: `getch()` and `ungetch()` share a buffer
                - here its a `char` array
                - `getch()` reads from the buffer, then from IO
                - `ungetch()` queues the buffer
            - this works like the stack, so here use external variable implementation
```
#define BUFSIZE 100

char buf[BUZSIZE]; /*buffer for ungetch()*/
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}
```

- **Note**: the standard library provides an `ungetch()` function that provides one character of pushback.









