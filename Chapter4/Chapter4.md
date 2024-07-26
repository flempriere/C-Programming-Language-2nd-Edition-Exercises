# The C Programming Language
## Chapter 4: Functions and Program Structure

### Summary of Exercises
- Ex 4-1: implementation of `strindex(s, t)` which returns the starting index of the rightmost occurence of `t` in `s`, or `-1` if there is no match.
- Ex 4-2: Implementation of `atof(s)` that converts a string `s` to a `float` with the ability to handle scientific notation.
---
The following exercises extend on the Calculator program introduced, all are tagged in `calculator.c` rather than as independent implementations.
- Ex 4-3: Implements the modulus function and negative numbers
- Ex 4-4: Adds additional stack commands (view top without popping, clear, swap top two elements, duplicate top elements)
- Ex 4-5: Adds access to `math.h` functions
- Ex 4-6: Adds 26 variables provided by uppercase letters $A-Z$, and last printed variable provided by $p$
- Ex 4-7: Implements routine `ungets(s)` which pushes an entire string onto the buffer, *unused by implementation*, our implementation uses `ungetch` and is unaware of the underlying implementation.
- Ex 4-8: Adapts `getch()` and `ungetch()` to handle only one element of pushback at any time
- Ex 4-9: Switches type used in `getch()` and `ungetch()` to `int` to handle case of `unsigned` char rep mishandling `EOF = -1`.

The final exercise is included in `CalculatorGetLine.c`.
- Ex 4-10: Handles the above exercises, but replaces `getch()` and `ungetch()` with approach operating on one line at a time using `getLine()`. 

---
- Ex 4-11: Modification of `getop` to avoid using `ungetch()`.
    - Implemented in `calculator.h`
- Ex 4-12: Implemention of `atoi(char s[], int v, int lim)` that converts an integer `v` into its string representation in `s`.
    - Our implementation will truncate after the `lim`-most significant digits
    - Also returns the length of the copied string `s`.
- Ex 4-13: recursive implementation of `reverse(char s[])`, that reverses the string `s` inplace.
- Ex 4-14: macro `swap(t, x, y)` that takes in a type `t` and variables `x` and `y` of type `t` and performs a swap.


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

### Scope Rules

- functions and external variables comprising a C program need not be compiled at the same time
    - source code can be split across files
    - can load precompiled routines

*Questions*
- How are declarations written s.t. variables are properly declared during compilation?
- How are declarations arranged s.t. all the pieces are properly connected?
- How are declarations organised so there is only one copy?
- How are external variables initialised?

The *scope* of a name is the part of a program within which a name can be used.
 - automatic variable declared at the start of a function
    - the *scope* is then  the function the variable is declared within.
    - local variables of the same name in different functions are unrelated
        - same for function parameters
            - they are effectively local variables
- external variables or function
    - from the point it is declared to the end of the file being compiled
    - e.g. if `main`, `sp`, `val`, `push` and `pop` are defined in one file, in the order shown above, (see below)
    - variables `sp` and `val` are visible in `push` and `pop` but not in `main`.
        - (note `push` and `pop` are also not available in `main`)
    - to reference an external variable before it is defined (or if defined in a different file) use the `extern` keyword

```
main() {...}
int sp = 0;
double val[MAXVAL];
void push(double f) {...}
double pop(void) {...}
```

- **Note** a *declaration* is different to a *definition*
    - *declaration* announces property of variables (namely *type*)
    - *definition* also sets aside storage
    - e.g. consider the lines below, outside a function
    ```
    int sp;
    double val[MAXVAL];
    ```
    - this *defines* the external variables `sp` and `val`, they are also *declarations* for the rest of the current **source file**.
    - conversely, consider
    ```
    extern int sp;
    extern double val[];
    ```
    - this *declares* for the rest of the source file, that `sp` is an `int` (and `val` is a `double` array), the variables are not created, and storage is not reserved.
    - There must be **only one** *definition* of an external variable among all of the component files of a source program.
        - other files use `extern` to access the *definition*
        - array sizes must be specified in the *definition*
            - optional in an `extern` *declaration*
    - initialisation  of an external variable only goes w/ definition

**Example**:
- can define `push` and `pop` in one file, and connect to the variables `sp` and `val` in another.
```
in file1:
    extern int sp;
    extern double val[];

    void push(double f) { ... }
    double pop(void) { ... }

in file2:
    int sp = 0;
    double val[MAXVAL];
```

### Header Files
- The calculator program could be split into multiple files
    - `main` occupies one file
    - `push`, `pop` and their variables in another
    - `getop` into a third
    - `getch` and `ungetch` into a fourth
    - each file handles one *aspect* of the program
- Need to share definitions and declarations across files
    - Ideally centralise this
    - common material -> *header file* (denoted .h)
        - here called `calc.h` 
        - this can be utilised via `#include`
    - **Note** for larger programs, seperating  out into multiple header files may be better.

### Static Variables
- variables `sp` and `val` in `stack.c` and `buf` and `bufp` in `getch.c` are for private use of their functions
    - not supposed to be used outside their own source file
- `static` declaration (applied to external variable or function)
    - limits scope to rest of source file being compiled
    - External `static` allows to hide names of private external variables
**Example**
```
static char buf[BUFSIZE] /* buffer for ungetch() */
static int bufp = 0; /*next free position in buffer */

int getch(void) { ... }
void ungetch(int c) { ... }
```
- no routines aside from `getch` and `ungetch` may use `buf` and `bufp`. 
- Can also use `static` to functions too
    - makes function invisible outside of source file, as opposed to global by default behaviour of function
- Can apply to local / internal variables
    - still local to a function like automatics
    - remain in existence pre and post function call
        - provide private, permanent storage within a fn call.

### Register Variables

- `register` declaration indicates a variable is heavily used
    - suggests that it be stored in machine registers
    - Compiler may ignore the advice
**Example**
```
register int x;
register char c;
```
etc.
- register can only be used on automatic variables
    - including function formal params e.g.
```
f(register unsigned m, register long n)
{
    register int i;
    ...
}
```
- register variables restricted by underlying hardware
    - only a few at a time
    - only certain types
    - excess ignored by compiler
- cannot take address of register variable
    - even if not actually placed there

### Block Structure

- C is not block structured (like Pascal)
    - **cannot** define functions inside functions
    - **can** define variables within a block
        - declarations of variables may follow the left brace introducing any compound statement
        - variables introduced this way hide identically named variables in outer blocks
            - lifetime extends until the corresponding right brace

**Example**
```
if (n > 0)
{
    int i; /* declares new var i */
    for (i = 0; i < n; i++)
}
```
- scope of `i` is the `true` branch of the `if`.
    - `i` unrelated to any `i` variable outside the block
    - automatic variable initialised each time the block is entered
- automatic variables and function parameters hide external variables and functions of the same name

**Example**
```
int x;
int y;

f(double x)
{
    double y;
}
```
- within `f`, `x` refers to the param, `y` refers to the automatic variable
    - outside they refer to the external vars `x,y`. 
- avoid shadowing outer scope names, they lead to confusion.

### Initialisation
- Absent explicit initialisation:
    - *static* and *external* are initialised to zero
    - *automatic* and *register* variables are undefined
- *scalar* variables initialised with syntax
    - `variable = value`

**Examples**
```
int x = 1
char squota = '\'';
long day = 1000L * 60L * 24L /* millseconds per day */
```

- Must be a constant expression for *static* and *external* variables
    - initialisation is **conceptually** done *once*  before program execution
- For *automatic* and *register* may be any expression with previously defined values, e.g.
    - constants
    - other variables
    - function calls

**Example: rewritten BinSearch**
```
int binsearch(int x, int v[], int n)
{
    int low = 0;
    int high = n - 1;
    int mid;
}
```
The initialisation of $low$ uses a constant, $high$ uses a previous variable, $mid$ is not initialised.

#### Array initialisation
- arrays can be initialised with a  comma-seperated list enclosed in braces, e.g.
```
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
```
- for arrays of undefined size, the size is computed from the length of the initialiser list
- if array size defined and $len(list) < len(array)$, remaining indices are set to zero.
    - if $len(list) > len(array)$ an error is generated.
    - repetition cannot be specified
    - cannot declare an element at index $i$ without declaring the value of the preceding indices
- `char` arrays may be initialised with string notation `"string"`

**Example**
```
char pattern = "ould"; /* is equivalent to: */
char pattern[] = {'o', 'u', 'l', 'd', '\0'};
/* note the NULL termination */
```

### Recursion

- C functions may be used recursively
    - i.e. call themselves (directly or not)

**Example: Printing a number as a string**
- digits generated wrong order, (low before high)
    - can be solved recursively
```
#include <stdio.h>

/* printd : print n in decimal */
void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10) printd(n / 10);
    putchar(n % 10 + '0');
}
```
- On a recursive call:
    - fresh set of automatic vars generated
    - These are independent to the higher calls
- e.g. in `printd(123)` the call structure is
    - `printd(123)`
    - `printd(12)`
    - `printd(1)`
    - and prints $123$.

**Example: Quicksort**
- Invented by Tony Hoare (1962)
- Given array, choose an element $x$
- Partition into two subsets  
$$A : a \in A \iff a < x, \\
B : b \in B \iff b \geq x$$
- Repeat recursively on $A$ and $B$
- Stop condition is set size $< 2$ since automatically sorted

```
/*qsort:  sort v[left]...v[right] in ascending order*/
void qsort(int v[], int left, int right)
{
    int i, last;

    if (left >= right) return; /* < 2 elems left*/
    swap(v, left, (left + right) / 2); 
    /* partition element moved to left */
    last = left;
    for (i = left + 1; i <= right; i++) {
        /* partition */
        if (v[i] < v[left]) swap(v, ++last, i);
    }
    swap(v, left, last); /*restore partition elem */
}

void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
```
- standard library contains *qsort* which can sort any comparable object.
- Recursion typically is cleaner to read, but,
    - requires allocation of stack memory
    - is not faster

### The C Preprocessor
- A conceptual first step in compilation
- most common uses
    - `#include` to include file contents
    - `#define` for textual substitution of a token
- Alternative use cases include
    - conditional compilation
    - functionlike macros / macros with arguments

#### File Inclusion
- source line of the form:
    - `#define "filename"`
- or
    - `#define <filename>`
- are replaced by contents of the file *filename*.
    - quoted searches from source file's location, else and if:
    - <> search method is *implementation-defined*
- Common to use to include:
    - common `#defines`
    - common `extern` variables
    - function prototypes

**Note:** Strictly speaking, headers need not be files, since access is implementation defined for < > includes.

- `#include` is the prefered way to tie declarations together for a large program
    - ensures all files have same definitions and variable declarations

#### Macro Substitution
- Macro definition has the form
    - `#define name replacement-text`
    - token `name` is replaced by `replacement-text`.
    - *replacement-text* may be arbitrary
    - Can continue a definition  across multiple lines using `\` at a line end
    - macro name scope is from the `#define` to the end of the compiled source file.
    - definition may use previous definitions
- substitution only for tokens, do not occur within strings
    - e.g. if we `#define YES`
        - `printf("YES");` and `YESMAN` are unchanged
        - `YES MAN` would be substituted though

- Any name may be defined

**Example: Forever**
```
#define forever for (;;) /* infinite loop*/
```
 which creates an infinite loop.

 - Macros can be defined with arguments.

 **Example: max**
```
 #define max(A, B) ((A) > (B) ? (A) : (B))
```
- Macros expand into inline code
    - each occurence of a *formal parameter* (A or B here) is replaced by the corresponding argument.

**Example: max use case**
```
x = max(p+q, r+s)
/* this expands out to: */
x = ((p+q) > (r+s) ? (p+q) : (r+s))
```
- If arguments are treated consistently this is type generic.
- **Note** macros have some pitfalls
    - in the above each expr is evaluated twice (e.g. p+q)
        - **VERY BAD IF THERE ARE SIDE EFFECTS**
        - e.g. `max(i++, j++) /* WRONG */ `
            - the larger value is incremented twice
    - need parentheses to ensure order of operations preserved
        - e.g. `#define square(x) x * x`
        - Then `square(z +1)` expands to `z + 1 * z + 1`
        - From order of operations this becomes:
            - `z + z + 1` = `2z + 1`
- functionlike macros are thus useful but should be used sparingly.
    - e.g. `getchar()` and `putchar()` typically macros
        - avoids runtime cost of a function call per `char`.
        - `#<ctype.h>` also uses macros for its functions
- Can undefine names using `#undef`
    - helps ensure a routine is a function
```
#undef getchar

int getchar(void) {...}
```
- Formal parameters not replaced in quoted strings
    - if parameter name preceded by `#` in replacement text expand out to quoted string with parameter substituted

**Example: Debugging Macro**
```
#define dprint(expr) printf(#expr " = %g\n", expr)
```
- the above example uses string concatenation, and behaves as
```
dprint(x/y) /* expands to */
printf("x/y" " = %g\n", x/y) /* strings concatenate to */
printf("x/y = %g\n", x/y)
```
- Within the macro argument `'` and `"` are converted to `\'` and `\"` respectively.
    - input is thus a valid string literal
- preprocessor provides `##` for argument concatenation during macro expansion.
    - parameter in replacement text adjacent to `##`:
        - parameter replaced by actual argument
        - `##` and whitespace removed
        - result rescanned

**Example: Paste**
```
#define paste(front, back) front ## back

/* example usecase */
paste(name, 1) -> name1
```
- Nested `##` rules are complicated

#### Conditional Inclusion
- preprocess can be controlled with conditional statements
    - allows selective code inclusion
- `#if` evaluates a constant integer expression
    - no `sizeof`, casts or `enum` constants
    - if expression non-zero
        - execute subsequent lines until `#endif, #elif or #else`
        - expression `defined(name)` in an `#if` evaluates as
            - 1 if *name* is defined
            - 0 otherwise

**Example: header file inclusion**
- the following wrapper around the contents of `hdr.h` ensures `hdr.h` is included only once
```
#if !defined(HDR)
#define HDR

/* contents of hdr.h go here */

#endif
```
- first inclusion defines the name `HDR`
- future inclusions check for the existence of `HDR` skip the file contents.
- if used consistently
    - headers may include other headers
    - user need not worry about interdependencies

**Example: selecting the correct header**
- this example tests the name `SYSTEM` and selects the appropriate `HDR` file to include
```
#if SYSTEM == SYSV
    #define HDR "sysv.h"
#elif SYSTEM == BSD
    #define HDR "bsd.h"
#elif SYSTEM == MSDOS
    #define HDR "msdos.h"
#else
    #define HDR "default.h"
#endif
#include HDR
```

- we can use `#ifndef` and `#ifdef` as specialised forms to test for if a name is defined. The first example can be rewritten as
```
#ifndef HDR
#define HDR

/* contents of hdr.h */

#endif
```
















