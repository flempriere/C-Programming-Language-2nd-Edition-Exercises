# Chapter 3: Control Flow

## Examples

### [Binary Search](./Examples/BinarySearch/binary_search.c)

Finds the index of a given value in a sorted array.

### [Count Digits](./Examples/CountDigits/count_digits_v2.c)

Reimplements the [Count Digits](../Chapter1/Chapter1.md#count-digits) example from [Chapter 1](../Chapter1/Chapter1.md) with a `switch` statement instead of an `if-else` construct.

## Exercises

### [Ex 3-1](./Exercises/Ex3_1/ex3-1.c)

In this case we update the while loop condition to

```C
while((low <= high) && (a[mid] != v))
```

This requires us to compute `mid` before we enter the loop (and make sure we always update it.). We compare the results by timing the average search time to perform a search for every element in a array of 10 million elements, and an element that is not in the list. Our results are

| Technique                   | Average search time in array of $`10^{7}`$ elements |
|-----------------------------|-----------------------------------------------------|
| Original K&R                | $`1.1599\times 10^{-7}`$                            |
| Exercise 3.1 Implementation | $`9.4278\times 10^{-8}`$                            |

So the old method is slower, but not significantly so. (and both methods are very fast).

**Note:** We've had to technically use some undiscussed machinery, namely the `time.h` header to make this comparison. However, given the small differences the extra accuracy is worth it.

### [Ex 3-2](./Exercises/Ex3_2/ex3-2.c)

*Write a function `escape(s, t)` that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a `switch`. Write a function `unescape(s,t)` for the other direction as well, converting escape sequences into the real characters.*

### Summary of Exercises

- Exercise 3-3: function expand(s1, s2) that replaces notations like a-z, with the equivalent list abcd...xyz.
- Exercise 3-4: Explain why the provided itoa fails for a maximally negative number is a two's complement representation, fix the function to work independent of representation.

## 3.1 Statements and Blocks

- *expression* followed by `;` is a *statement*
  - `;` - statement terminator
- Braces `{}` group *declarations* and *statements*
  - called a *block* or *compound statement*
- Blocks syntactically equivalent to one statement
  - No need for a semicolon after a block.

### 3.2 If-Else

- Expresses decisions
- Format:

```C
if (expression)
    statement1
else
    statement2
```

- `else` is optional
- Logic: test if expression is non-zero, and calls *statement1* if so (else) calls *statement 2*.

- Optional `else` can lead to ambiguity in nested case,
use parentheses and indentation to make clear
  - e.g. Write:

```C
if (n > 0)
    if (a > b)
        z = a;
    else
        z = b;
```

or

```C
if (n > 0) {
    if (a > b)
        z = a;
}
else
    z = b;
```

depending on which case you want.

**Non Example:**

```C
if (n >= 0)
    for (i = 0; i < n; i++)
        if (s[i] > 0) {
            printf("...");
            return i;
        }
else
    printf("error -- n is negative\n");
```

Here the indentation indicates the `else` is associated with the outer `if` but syntactically it is associated with the inner `if`.

## 3.3 Else-if

A common construction is

```C
if (expr1)
    statement
else if (expr2)
    statement
.
.
.
else
    statement
```

- Expressions are evaluated in order
- **First** *expr* to evaluate **true** triggers its statement
  - Chain then terminated
- Last `else` triggered if none trigger
  - Like a normal `if` it maybe excluded.

### Example: [Binary Search](#binary-search)

- Determines if $x$ is in a sorted array $v$ (increasing order)
  - Returns the position of the element $0$ to $n-1$ else $-1$ if it doesn't exist.
  - We check the middle element, check if it matches $x$ or if it is $> x$ or $< x$ and then repeat the process on the associated remaining half.

```C
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]) high = mid - 1;
        else if (x > v[mid]) low = mid + 1;
        else return mid; /* found match */
    }
    return -1; /* no match */
}
```

The middle logic block is an if-else if - else statement.

### Relevant Exercises

See [Ex 3.1](#ex-3-1).

## 3.4 Switch

`switch` - multiway decision for testing against a number of *constant* integer values

Format:

```C
switch(expression)
{
    case const-expr: statements
    case const-expr: statements
    default: statements
}
```

- Each `case` labelled by (at least) one integer valued constant or constant expression.
- If `expression` matches `const-expr` execution starts at that case.
  - All case expressions must be different
- `default` is optional, executed if no case matches
- Cases and default may occur in any order

### Example: [count digits, white space etc](#count-digits) using `switch`

```C
#include <stdio.h>

int main() 
{
    int c, i, nwhite, nother, ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++) ndigit[i] = 0;
    while ((c = getchar()) != EOF) 
    {
        switch(c)
        {
            case '0': case '1': case '2': case '3' :  case '4' : case '5': case '6': case '7' : case '8' : case '9' :
                ndigit[c - '0']++;
                break;
            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;
            default:
                nother++;
                break;
        }
    }
    printf("digits =");
    for (i = 0; i < 10; i++) printf(" %d", ndigits[i]);
    printf(", white space = %d, other = %d\n",
        nwhite, nother);
    return 0;
}
```

- `break` causes an immediate exit from the `switch` statement.
- Cases are just labels.
  - Execution falls through to the next label unless
    explicitly escaped.
  - Use `break` or `return`
  - `break` can also be used in loops.
- *Falling through* needs to be considered carefully.
  - Allows multiple labels to attach to one action.
  - Need `breaks` to prevent falling through to the next though...
  - Not robust, modifications may break it.
  - Avoid unless its one computation.
  - Use a `break` defensively after the last case.

### Relevant Exercises

See [Ex 3.2](#ex-3-2).

### 3.5 Loops - While and For

- While syntax:

```C
while (expression)
    statement
```

- expression evaluated, statement executed if expr is non-zero.
  - expr then revaluated (and statement executed) until evaluates to zero.
  - control resumes after statement

- For syntax:

```C
for (expr1 ; expr2 ; expr3)
    statement
```

is equivalent to

```C
#include <ctype.h>

/* atoi: convert s to integer; version 2 */
int atoi(char s[])
{
    int i, n, sign;
    for (i = 0; isspace(s[i]); i++); //skips whitespace
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') i++;//skip sign
    for (n = 0; isdigit(s[i]); i++) {
        n = 10 * n + (s[i] - '0');
    }
    return sign * n;
}
```

- Standard library contains `strtol` for converting `string` to `long integers`.
- Central loop control good for complicated nested loops, e.g. shellsort

```C
/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; g /= 2) {
        for (i = gap; i < n; i++) {
            for (j = i - gap; j >= 0 && v[j]>v[j+gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}
```

- Three nested loops
  - outermost contols gap between compared elements
    - shrinks from $n/2$ by a factor of $2$ per pass until $0$
  - middle loop steps along the elements
  - innermost compares each pair seperated by gap and reverses those out of order.
    - gap reduces to one, so all are eventually sorted

#### Comma Operator

- the comma operator `,` is mostly used for `for` loops
  - pair of expressions seperated by `,` are evaluated left to right.
    - type and value of result is that of the right operand
    - useful in `for` loops for multi-indexing
- e.g. this implementation of `reverse(s)` which reverses inplace

```C
#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
```

- Comma operator used to initialise i and j
- Comma operator used to index i and j
- *Note* comma operator is not the same thing as syntactic comma for seperating func args, vars, etc.
  - left -> right eval is thus not guaranteed
- Use sparingly
  - save for tightly coupled constructs
    - e.g. for loop, multistep single line macros
  - could potentially use in `reverse` if we view reversing as a single operation:
    `c = s[i], s[i] = s[j], s[j] = c;`

### 3.6 Loops - Do-While

- While and for test termination condition at the top
- `do-while` tests at the bottom *after*
  - ensures at least one pass
- Syntax:

```C
do
    statement
while (expression);
```

- *Statement* executed, then *expression* evaluated
  - if *true* repeat again, else terminate
- **Example**: `itoa` converts a number to a character string (i.e. reverses `atoi`.)
  - Naive implementation hard - digits generated backwards.
    - Implementation below follows this then reverses

```C
/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n; /* make positive */
    i = 0;
    do {
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it, terminate if 0 */
    if (sign < 0) 
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
```

- Observe that the brackets go around the `do` component
  - -> this is the block statement.
  - the `while` sits outside.
- `do` here useful since need to populate at least one character even if integer is `0`.

### 3.7 Break and Continue

- Sometimes convenient to exit a loop midway
  - `break` allows for early exit from `while, for, do`
    - immediate exit from innermost loop.

**Example**: `trim`, remove trailing blanks, tabs, newlines. A break is used to exit from the loop when we find the rightmost blankspace.

```C
/* trim: remove trailing blanks, tabs and newlines */
int trim(char s[])
{
    int n;

    for (n = strlen(s) - 1; n >= 0; n--)
    {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
        {
            break;
        }
    }
    s[n+1] = '\0';
    return n;
}
```

- `strlen` returns string len, so start from last element (`strlen - 1`)
  - scan backwards until a non-blank is found, then break
  - else finish when n negative (i.e. all string scanned)

- `continue` goes to the next iteration of the loop immediately.
  - for loops will still have their *increment* step take control.
  - Test still takes place.(`for, while, do` regardless)
  - `continue` does not apply to `switch`
    - `continue` applied to `switch` in a loop will apply to the loop

**Example**: the below code fragment processes non-negative array elements in the array `a`. Negative values are skipped.

```C
for (i = 0; i < n; i++)
{
    if (a[i] < 0) continue;
    /* ... do things to positive elements ... */
}
```

- `continue` best used when following loop logic is complicated.
  - otherwise reverse the test and indent.

### 3.8 Goto and labels

- `goto` is easy to abuse!!!
  - avoid using!

- Use cases:
  - abandonly deeply nested process
    - can break out of multiple loops

- e.g.

```C
for (...) {
    for (...) {
        ...
        if (disaster) goto error;
    }
}
error:
    /* clean up */
```

- handy if error handling is non-trivial, and error can occur in several places.
- label has the form of a variable, followed by colon.
  - may attach to any statement in same function as relevant `goto`
    - label scope is the entire function
- **Example**: determining if two arrays `a` and `b` share a common element.

```C
for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
        if (a[i] == b[j])
            goto found;
    }
}
/* didn't find any common elements */

found:
    /* got one: a[i] == b[j] */
```

- The non-goto equivalent would be

```C
found = 0;
for (i = 0; i < n && !found; i++) {
    for (j = 0; j < m && !found; j++)
    {
        if (a[i] == b[j]) found = 1;
    }
}
if (found) {
    /* got one: a[i - 1] == b[j - 1]
}
else 
{
    /* didn't find one */
}
```

- arguably has extra tests / variables and is less 'elegant' though a break, might help.
- `goto` generally hard to maintain
  - hard to understand
  - avoid using unless nessecary
