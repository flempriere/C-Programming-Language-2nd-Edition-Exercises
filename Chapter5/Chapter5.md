# The C Programming Language
## Chapter 5: Pointers and Arrays


### Summary of Exercises
- Ex 5-1: Corrects `getint` to handle the case of a `+` or `-` not followed by a digit.
- Ex 5-2: Implementation of `getfloat`, analogous to `getint` but for floating point arithmetic.

### Introduction
- A pointer is a variable that contains the address of another variable
- Pointers are closely related to arrays

### Pointers and Addresses
- Memory consists of individual cells
    - they may be manipulated individually
    - or, as a contiguous group

- Pointer is a block of memory containing the address of another block of memory

- The `&` operator gives the address of an object, so `p = &c` assigns the address of `c` to `p`.
    - `&` only applies to memory objects
    - Cannot be used on expressions, constants or `register` variables

- The `*` operator is called the *indirection* or *dereferencing* operator
    - Applied to a pointer it accesses the object at the address pointed to by the pointer.

**Example: Use of a pointer**
```
int x = 1, y = 2, z[10];
int *ip; /* ip is a pointer to an int */

ip = &x /* ip points to x */
y = *ip; /* y is now 1  --- equiv to y = x*/ 
*ip = 0; /* x is now 0 */
ip &z[0]; /* ip now points to z[0] */
```

- The declaration of the pointer `int *ip;` is a mnemonic, it states
that `*ip` is an int. 
    - The logic also applies to function declarations, e.g. `double *dp, atof(char *);`
        - states `*dp` and `atof` have values of `double`, and the argument of `atof` is a pointer to `char`.
- pointer is constrained to  point to a given kind of object.
    - **exception** a pointer to `void` may hold any pointer, but cannot be *dereferenced*.

- if `ip` points to the integer `x`, then `x` can be substituted by `*ip` in any context.

```
*ip = *ip + 10; /* equiv to: */
x = x + 10;
```
- Unary operators `*` and `&` bind more tightly than arithmetic operators.
```
y = *ip + 1
```
Takes `ip`, dereferences it, adds `1`, assigns to `y`.
```
*ip += 1
```
Increments what `ip` points to, as do
- `++*ip`
- `(*ip)++`
    - Needs parentheses (else `ip` itself is incremented)
        - Because `*` and `++` associate right to left. (i.e. `*` associates to `(ip++)`)
- Pointers can be used without derefencing
    - They are still variables
    - e.g. if `ip` and `iq` are pointer to `int`, `ip = iq` copies the value (i.e. address in) of `iq` to `ip`.
        - Hence `ip` now points to the same object as `iq`.

### Pointers and Function Arguments
- *Recall:* C passes function arguments by *value*
    - function cannot directly modify value of the original argument,  it modifies a copy.
- We can use pointers to the *values* we want to change instead.

**Example: swap**

```
/*Broken Swap
**This version doesn't work since it operates on copies
*/
void swap(int x, int y) {
    int tmp = x;
    x = y;
    y = tmp;
}

/*fixed Swap
**This version uses pointers to swap values
void swap(int *px, int *py) {
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

int a, b;
/* assign values ... to a, b */
swap(&a, &b);
```
- The first version doesn't work because the arguments are copies
- In the second the function operates on the pointers, we pass the addresses of the variables to swap with `&`.

- Pointer args allow a function  to access and change objects in the function that calls them.
    - e.g. consider a function `getint` that converts an input character stream into integers.
        - Has to return the found integer **and** signal when the input has finished, i.e. `EOF`.
            - Since `EOF` may correspond to a valid integer these have to be via different paths.

**Example : getint**
```
int n, array[SIZE], getint(int *);

for (n = 0; n < SIZE && getint(&array[n]) != EOF;  n++);

#include <ctype.h>

int getch(void);
void ungetch(void);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while(isspace(c = getch())); /*skip whitespace */

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') c = getch();
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c = '0');
    }
    *pn *= sign;
    if (c != EOF) ungetch(c);
    return c;
}
```
- This calls `getint()` for every index in the array
- `*pn` is used in `getint` as a ordinary `int`
- `getch()` and `ungetch()` are the same as for the calculator

### Pointers and Arrays
- Pointers and arrays are closely related in C
- `int a[10]` defines an integer array of size 10
    - a consecutive block named `a[0], a[1], ... , a[9]`.
-  A pointer `pa` declared as `int *pa;` may be assigned to the first element via `&a[0]`.
    - `x = *pa` copies `a[0]` into `x`.
    - by definition `pa + 1` points to the next element of the array
        - `pa + i` therefore points to the `i`-th element.
            - `*(pa + i)` thus accesses the `i`-th element, equiv to `a[i]`.
        - **THIS IS TRUE REGARDLESS OF THE ARRAY TYPE OR SIZE**
- *By definition* the value of an array type variable is the address of the first element. 
    - Thus the following are equivalent:
        - `pa = &a[0]`
        - `pa = a`
- When evaluating an index like `a[i]` this is converted to the pointer arithmetic `*(a + i)`.
    - Thus `&a[i]` is equiv to `a + i`.
    - We may reverse this, if `pa` is a pointer then
        - `pa[i]` is equiv to `*(pa + i)`. 
- **Summary:** array indexing and pointer + offset are equivlent.
- **Warning:** arrays are not pointers!
    - An pointer is a variable (`pa = a`, `pa++` etc. are defined)
    - An array is a *name*, the equivalent `a=pa` and `a++` are illegal.
- Arrays passed to functions are local variables
    - They thus decay to pointers
**Example: strlen**
```
/* return length of a string */
int strlen(char *s)
{
    int n;

    for (n = 0; *s != '\0'; s++) n++;
    return n;
}
```
- `s` is a pointer - can increment
    - equiv for arrays: `for(n = 0; s[n] != '\0'; n++)`.
    - `s++` does not affect the calling functions copy of `s`, the *pointer* is a local copy
    - Hence the following all work:
        - `strlen("hello, world!"); /*const str */`
        - `strlen(array); /* char array */`
        - `strlen(ptr); /* char ptr */`
- `char s[]` and `char *s` are thus equivalent as function arguments
    - prefer the latter notation for making pointer explicit.
- When passed an array name the function can choose to use array or pointer logic at its convenience

**Examples**
- `f(&a[2])` and `f(a + 2)` both pass a pointer to the subarray of `a` starting from `a[2]`.;
    - `f` may be defined as either
        - `f(int arr[]) {...}` or,
        - `f(int *arr) {...}`.
- Syntactically one may refer to objects before the array head like `a[-1]`.
    - One must be sure they exist and are part of the same object
    - **Note:** it is illegal to access and refer to objects outside of the array bounds.

### Address Arithmetic
- If $p$ points to an array element, 
    - `p++` points to the next element.
    - `p += i` points to the `i`-th next element.
- $C$ implements consistent pointer arithmetic.
    - Consider a basic storage allocator consisting of two routines.
        - `alloc(n)` returns a pointer to `n` consecutive `char` memory blocks.
        - `afree(p)` releases the storage of `p` to be reused.
        - Note: storage managed by `alloc` and `afree` acts as a stack, we can't call them in arbitrary orders.
            - Calls to `afree(p)` must be in reverse of the `alloc(n)` calls.
        - `alloc` hands out pieces of a larger `char` array (`allocbuf`)
            - underlying array kept private. Can be declared `static`
                - Since pointers mean we don't need to use array indices
                - practically one could use an anonymous array via `malloc
        - Also need to track how much of `allocbuf` has been used
            - utilise a pointer `allocp` - points to next free element.
            - `alloc` must chec for sufficient space, and if so returns `allocp`'s current address. (which is then incremented by `n`.)
                - returns `0` if insufficient space.
            - `afree(p)` sets `allocp` back to `p` if `p` is inside `allocbuf`.

**Example: Simple Allocator**
```
#define ALLOCSIZE 10000 /* size of memory buffer */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allop = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        /* it fits */
        allocp += n;
        return allocp - n; /* previous allocp value */
    }
    else return 0; /* not enough space */
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) allocp = p;
}
```
- Pointer may be initialised like any other variable
    - Meaningful values are `0` or the address of previously defined data.
- `static char *allocp = allocbuf` defines `allocp` to be a character pointer initialised to the address of `allocbuf`.
    - Equivalent syntax: `static char *allocp = &allocbuf[0]`.

- The test `if (allocbuf + ALLOCSIZE - allocp >= n) {...}` checks if there is enough room to provide `n` characters.
- `C` guarantees that `0` is never a valid address, thus we are safe to return it as a fail condition.
    - pointers are not integers, `0` is special. Typically `NULL` is used to denote a `0` pointer.

- Note the previous test and `if (p >= allocbuf && p < allocbuf + ALLOCSIZE)` shows several pointer arithmetic features:
    - Can compare pointers (*with the caveat that *p* and *q* point to the same array)
        - If so then, `==, !=, <, >=, etc.` work.
        - `e.g. p < q`, is true if `p` points earlier in the array than `q`.
        - Pointer may be meaningfully compared with `0`, but undefined for arithmetic or comparisons if `p` and `q` do not point to the same underlying array.
            - *With the execption of one element past the end of an array*
    - A pointer `p` and an integer `n` may be added or subtracted. 
        - Means to in(de)crement the element pointed to by `p` by `n`.
        - True regardless of `p`'s type. It is scaled accordingly.
            - e.g. for a $4$ byte `int`, each increment is scaled to the $4$ byte `int`.

**Example: strlen with pointer arithmetic**
```
/* strlen: return length of string s */
int strlen(char *s)
{
    char *p = s;

    while (*p != '\0') p++;
    return p - s;
}
```
- `p` is initialised to the start of the of the string `s`.
    - Scan `p` until we find the null terminator `\0`.
        - `p++` advances one `char` at a time.
        `p - s` gives the number of characters advanced over.
    - **Note:** This number may be too big to store in an `int`.
        - header `<stddef.h>` defines the type `ptrdiff_t` large enough to hold the signed difference of any two pointers.
            - Could instead for caution use `size_t` (as in the standard library.)
                - `size_t` is the unsigned integer type returned by the `sizeof` operator.
- Pointer arithmetic is consistent.
    - If we wanted to allocate `float` types instead we could use the same code but switch `char` for `float` in our `alloc` and `afree`.
        - `p++` advances to the next `float`

- **Valid pointer operations are:**
    - Assignment of pointers of the same type
    - Adding or subtracting a pointer and an integer
    - Subtracting or comparing two pointers to members of the same array.
    - Assignment or comparison to `0`.
- All other arithmetic illegal **notably, we cannot:**
    - Add two pointers
    - Multiply, divide, shift or mask pointers.
    - Add `float` or `double` to them.
    - Assign a pointer of one type to another without a cast, (excepting `void *` type.)

### Character Pointers and Functions.
- String constant (*literal*) written `"I am a string"` is a character array.
    - Internal representation is *null-terminated*.
        - storage length is `character length + 1`.
    - Common as function arguments
        - e.g. `printf("Hello World!\n")`.
            - In this form string literal accessed via *pointer*.
    - The declaration `pmessage = "now is the time"` assigns a pointer to the first element of the string literal to `pmessage`.
        - **THIS IS NOT A STRING COPY OPERATION**
        - `C` does not provide multicharacter processing as a unit.
    - **Note:** The following declarations are inequivalent
```
char amessage[] = "now is the time" /* an array */
char *pmessage = "now is the time" /* a pointer */
```
- In the former the string can be modified as an array
    - But we cannot change what memory block `amessage` refers to.
- In the second modification of the string is *undefined* behaviour
    - But we can change what memory block `pmessage` refers to.

**Example: strcpy(s, t)** copies `t` into `s`.
```
/* array implementation */
void strcpy(char *s, char *t)
{
    int i = 0;
    while ((s[i] = t[i]) != '\0') i++;
}
/* pointer implementation */
void strcpy(char *s, char *t)
{
    int i = 0;
    while ((*s = *t) != '\0') s++, t++;
}
/* Improved pointer version */
void strcpy(char *s, char *t)
{
    while(*s++ = *t++);
}
```
- **Note** We cannot simply do `s = t` since that equates the pointers, *i.e. they now point to the same memory block rather than a distinct copy*. 
- `s` and `t` are value copies so they can be manipulated freely.
    - The improved pointer version uses the following features:
        - The value of the while loop is that of `*s++`
        - The value of `*s++` is the value of `*s` **BEFORE** `s` is incremented.
            - This is the value assigned to `*s` by `*t++` which by the same logic is the value of `*t` **BEFORE** `*t` is incremented.
            - Thus we read the value of `*t` into `*s` then move them for the read.
        - The `while` loop ends when the loop condition evaluates to `0`. 
            - i.e. when `*s == \0`.
- `strcpy` in the standard library returns the target string.

**Example: strcmp(s, t)**, lexigraphically orders strings.
```
/*strcmp: return < 0 is s < t, 0 iff s == t, > 0 if s > t */

/* array version */
int strcmp(char *s, char *t)
{
    int i;
    for (i = 0; s[i] == t[i]; i++)
    {
        if (s[i] == '\0') return 0; 
    }
    return s[i] - t[i];
}

/* pointer implementation */
int strcmp(char *s, char *t)
{
    for (:, *s == *t; s++, t++)
    {
        if (*s == '\0') return 0;
    }
    return *s - *t;
}
```
- Other combinations of `++`, `--` and `*` produce different outcomes, useful in different cases.
    - e.g. `*--p` decrements `p`, then fetches the value `p` points to.
    - *Stack idiom:* `*p++ = val; /*push*/ val = *--p /* pop */`
- `string.h` provides the example functions and other useful functions.















