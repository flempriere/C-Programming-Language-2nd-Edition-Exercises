# Chapter 1: A Tutorial Introduction

## Examples

### [Hello World](./Examples/HelloWorld/hello_world.c)

Everybody's first C program.

### Fahrenheit To Celsius

#### [Fahrenheit To Celsius v1](./Examples/FahrenheitToCelsius/v1/fahrenheit_to_celsius.c)

#### [Fahrenheit To Celsius v2](./Examples/FahrenheitToCelsius/v2/fahrenheit_to_celsius_v2.c)

#### [Fahrenheit To Celsius v3](./Examples/FahrenheitToCelsius/v3/fahrenheit_to_celsius_v3.c)

#### [Fahrenheit To Celsius v4](./Examples/FahrenheitToCelsius/v4/fahrenheit_to_celsius_v4.c)

Prints a conversion table from Fahrenheit to Celsius.

### Copy Input

#### [Copy Input v1](./Examples/CopyInput/v1/copy_input.c)

#### [Copy Input v2](./Examples/CopyInput/v2/copy_input_v2.c)

Prints the unmodified program input.

### Count Characters

#### [Count Characters v1](./Examples/CountCharacters/v1/count_characters.c)

#### [Count Characters v2](./Examples/CountCharacters/v2/count_characters_v2.c)

Counts the number of characters in an input stream.

### [Count Lines](./Examples/CountLines/count_lines.c)

Counts the number of lines in an input stream.

### [Count Words](./Examples/CountWords/count_words.c)

Counts the number of lines, words and characters in an input stream.

### Exponentiation

#### [Exponentiation v1](./Examples/Power/v1/power.c)

#### [Exponentiation v2](./Examples/Power/v2/power_v2.c)

Computes the exponentiation $`m^n`$, for integer `m` and `n`.

### Longest Line

#### [Longest Line v1](./Examples/LongestLine/v1/longest_line.c)

#### [Longest Line v2](./Examples/LongestLine/v2/longest_line_v2.c)

Reads lines from input and prints the longest as output.

## Exercises

### [Ex 1-3](./Exercises/Ex1_3/ex1-3.c)

*Modify [Fahrenheit To Celsius](#fahrenheit-to-celsius) to print a heading above the table.*

### [Ex 1-4](./Exercises/Ex1_4/ex1-4.c)

*Write a program to print the corresponding Celsius to Fahrenheit table.*

### [Ex 1-5](./Exercises/Ex1_5/ex1-5.c)

*Modify the temperature conversion program to print the table in reverse order, that is from $`300`$ degrees to $`0`$.*

### [Ex 1-6](./Exercises/Ex1_6/ex1-6.c)

*Verify that the expression `getchar() != EOF` is $`0`$ or $`1`$.*

### [Ex 1-7](./Exercises/Ex1_7/ex1-7.c)

*Write a program to print the value of `EOF`.*

### [Ex 1-8](./Exercises/Ex1_8/ex1-8.c)

*Write a program to count blanks, tabs and newlines.*

**Note:** This program states **newlines** (the character) as opposed to **lines** (the concept), so if
the final line is not terminated by a newline, than the newline count will be one less than the number of lines.

### [Ex 1-9](./Exercises/Ex1_9/ex1-9.c)

*Write a program to copy its input to its output, replacing each
string of one or more blanks by a single blank.*

### [Ex 1-10](./Exercises/Ex1_10/ex1-10.c)

*Write a program to copy its input to its output, replacing each
tab by `\t`, each backspace by `\b` and each backslash by `\\`. This makes tabs and backspaces visible in an unambiguous way.*

### [Ex 1-11](./Exercises/Ex1_11)

*How would you test the word count program? What kinds of input are most likely to uncover bugs?*

To test the word count program, we should provide input, where can easily determine the expected output.

The most likely cases to uncover bugs are edge cases. In the case of word count, some edge cases to consider are

1. An empty input
2. Input consisting of one large word (without a newline)
3. Input consisting of only blanks
4. Input containing only newlines
5. Input containing single letter words
6. Input containing mixed blanks

These test cases are in the linked directory, where `.in` is the input, `test_no.out` is the expected output and `results.out` is the generated output.

Thanks to test case 2, we find that the program has a bug - If the final non-empty line is not terminated by a newline, the line count is off by one.

To fix this `count_words.c` is modified to track the previously read character, (using `EOF` to denote no previous character), if the last character exists and is not a newline we account for this final line.

**Note:** The original [**Count Lines**](#count-lines) program has the same bug, but we've left it as written by the authors.

### [Ex 1-12](./Exercises/Ex1_12/ex1-12.c)

*Write a program that prints its input one word per line.*

We adopt the behaviour of [Ex1.9](#ex-1-9) replacing all blank substrings with a single blank (or in this case newline.)

#### [Ex 1-13](./Exercises/Ex1_13/ex1_13.c)

*Write a program to print a histogram of the lengths of words
in its input. It is easy to print the histogram with the bars horizontal; a vertical orientation is more challenging.*

**Note:** We take on the challenge of printing the histogram vertically.

#### [Ex 1-14](./Exercises/Ex1_14/ex1-14.c)

*Write a program to print a histogram of the frequencies of different characters in its input.*

**Note:** To avoid tediously manually filtering out printable characters, for now we restrict ourselves to assuming an ascii representation, where the printable characters are then indexed by the numbers $`33`$ through to $`126`$, and all other characters are placed in a bin marked *Other*.

**Remark:** We again print the histogram vertically.

### [Ex 1-15](./Exercises/Ex1_15/ex1_15.c)

*Rewrite the temperature conversion table example to utilise a function to perform the conversion.*

### [Ex 1-16](./Exercises/Ex1_16/ex1-16.c)

*Revise the main routine of the longest line program so it will correctly print the length of arbitrarily long lines, and as much as possible of the text.* (See [longestLine](#longest-line-v1).)

### [Ex 1-17](./Exercises/Ex1_17/ex1-17.c)

*Write a program to print all input lines that are longer than 80 characters.*

We make the decision to exclude the newline character from this count. i.e. A line of exactly $`80`$ characters then a newline would not be printed.

### [Ex 1-18](./Exercises/Ex1_18/ex1-18.c)

*Write a program to remove trailing blanks and tabs from each line of input and to delete entirely blank lines.*

### [Ex 1-19](./Exercises/Ex1_19/ex1-19.c)

*Write a function `reverse(s)` that reverses the character string `s`. Use it to write a program that reverses its input a line at a time.*

### [Ex 1-20](./Exercises/Ex1_20/ex1-20.c)

*Write a program **detab** that replaces all tabs in the input with the proper number of blanks to space to the next tab stop. Assume
a fixed set of tab stops, say every $`n`$ columns. Should $`n`$ be a variable or a symbolic parameter?*

Ideally $`n`$ would be a variable supplied by the user. Since we haven't yet seen how to do this, we leave it as a symbolic constant since it should not change during the runtime of the program.

**Note:** The folder for this file contains some simple test cases, where we have used [Ex 1.10](#ex-1-10) to catch any undetabed tabs.

### [Ex 1-21](./Exercises/Ex1_21/ex1-21.c)

*Write a program **entab** that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for **detab** (see [Ex 1.20](#ex-1-20)). When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?*

We should prefer a single blank over a tabstop as that is what most people would expect a single space to be represented by.

### [Ex 1-22](./Exercises/Ex1_22/ex1-22.c)

*Write a program to **fold** long input lines into two or more shorter lines after the last non-blank character that occurs before the $`n`$-th column of input. Make sure your program does
something intelligent with very long, lines, and if there are
no blanks or tabs before the specified column.*

**Note:** Our implementation uses the following logic,

1. We break on the last complete word before a column.
2. We preserve whitespace (shifting it onto the next line).
3. A line is folded multiple times until it fits.
4. If there is no complete word, then we break at the last
column index.

### [Ex 1-23](./Exercises/Ex1_23/ex1-23.c)

*Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly.
**C comments do not nest**.*

**Note**: We extend this to support `C99` style singleline comments.

### [Ex 1-24](./Exercises/Ex1_24/ex1-24.c)

*Write a program to check a C program for rudimentary syntax errrors like unbalanced parantheses, brackets, and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard to do in full generality).*

**Note:** Our implementation does not account for the presence of comments, we assume that these will be stripped out by the use of a program like [Ex 1-23](#ex-1-23) first.

## 1.1 Getting Started

### Example: [Hello World](#hello-world)

- A C program consists of *functions* and *variables*.
- A function contains *statements* that specify operations.
- Variables store *values*.
- C Programs need a function `main`.
  - Program execution starts at `main`.
    - Every program thus needs a `main`.
  - Other functions can be given other names.
- Includes like `#include <stdio.h>` tells the compiler to include another file `stdio.h`.
  - Here `stdio.h` is part of the *Standard Library*.
  - Specifically the part handling *input/output*.

### Functions

- Functions can take in a list of *arguments* - values to be
provided to the function.
  - The list is provided in the format `name(args)` where `name` is the name of the function and `args` is a comma-seperated list.
    - For a function that takes no arguments we use the syntax `name(void)`, where `void` specifies that no args are to be provided.
- Functions are calling by naming them and then using the function call operator `()`.
  - e.g. `printf("hello, world\n")` here the function `printf` is called with the argument `"hello, world\n"`.

## 1.2 Variables and Arithmetic Expressions

### Example: [Farenheit To Celsius](#fahrenheit-to-celsius-v1)

### Comments

- The line

```text
 /**
  * @brief Prints a Fahrenheit-Celsius Table for
  * fahr = 0, 20, ... 300.
  * 
  */
  ```

  denotes a *comment*.

- Comments are ignored by the compiler. The *multi-line comment style* `/* comment */` makes everything between `/*` and `*/` a comment.

- **Note**: The additional syntax `/**` and `@brief` with `*` on every line forms whats called a `doxygen` comment. doxygen is a tool used to develop code documentation from code comments.
  - These are added by me, and will not be detailed in this code base.
- An alternative comment style is the so-called `C++` style or
*single-line* comment `//` in which everything after the `//` until the end of the line is treated as a comment.

### Variable Declarations

- Variables must be *declared* before they are used.
  - Modern standards recommend a variable be declared as close to its initial point of use as possible.
  - In older conventions, all variables were declared at the start of a function.
- A *declaration* consists a *type* then a list of *names* e.g. `int fahr, celsius`.
  - This declares two variables of type `int` with names `fahr` and `celsius` respectively.
  - Generally declaring multiple variables on the same line is avoided since it can lead to some confusing results we shall see later.

### Types

- `int` values hold whole numbers, while `float` values can hold values with fractional parts.
- **Warning**: The range of types in **C** are machine-dependent.
  - e.g `int` is commonly either $`16`$ bit or $`32`$ bit.
  - The former may represent $`-32768`$ to $`32767`$, the other a lot more.
  - `float` is typically $`32`$ bit and can represent values from about $`10^{-38}`$ to $`10^{38}`$.

- The table below describes some common types.

| Type   | Description                     |
|--------|---------------------------------|
| char   | character - a single byte       |
| short  | short integer                   |
| long   | long integer                    |
| double | double precision floating point |

### Assignment

- *assignment statements* like `lower = 0` assign a value to a variable.
  - Typically where possible a variable should be declared and assigned in the same statement.
- Individual statements are terminated by a semicolon `;`.

### Loops

- A `while` loop can be used to repeat a block of code. It has the syntax `while(condition) statement`
  - If the *condition* is *true* then the *statement* is executed, and the condition is tested again.
  - This repeats until the *condition* evaluates to *false*.
  - Multiple statements can be enclosed in braces to be controlled by the same while loop.
  - By default, try to use braces, they make code more readable.

### Operators

- operators are actions that can be performed on variables e.g. like `+`.
- **Warning**: Integer division e.g. `4/3` truncates.
  - In this case `1` would be the result.
  - This is why we multiply first in the calculation `celsius = 5 * (fahr - 32) / 9`.

### `printf()` and formatted output

- Defined by the ANSI Standard, but not directly part of the language, it is a *standard* function provided by the *standard library*.
- Takes in a variable number of arguments, the first of which is a *format string*, which is a character string where `%` is used to denote that a value should be substituted.
  - Substitutions are taken from the remaining arguments.
- Each `%` is followed by symbols that describe how and what value should be substituted.
  - `%d` denotes an integer
    - `3%d` prints integers in a right-aligned
        field at least three digits wide
  - `%f` denotes a float
    - `6.1%f` denotes a float at least 6 wide, with
        one digit after the decimal place
- `scanf` is a function that acts as the opposite of `printf`.
  - It reads input into variables using a *format string*.

The below table demonstrates some format specifiers.

| Format Specifier | Output                                                      |
|------------------|-------------------------------------------------------------|
| `%d`               | decimal representation of an integer.                        |
| `%6d`              | decimal int, at least 6 characters wide.                     |
| `%f`               | floating point.                                              |
| `%6f`              | floating point, at least 6 characters wide.                  |
| `%.2f`             | floating point, 2 characters after decimal point (d.p).      |
| `%6.2f`            | floating point, at least 6 wide with 2 characters after d.p. |

### Example: [Fahrenheit To Celsius V2](#fahrenheit-to-celsius-v2)

#### Floating Point

- Operations involving a floating point convert all arguments to floating point.
- Explicit floating point literals can be declared with `.0`, e.g. `9` is an `int` `9.0` is a `float`.

#### Related Exercises

See [Ex1.3](#ex-1-3) and [Ex1.4](#ex-1-4).

### Example [Fahrenheit To Celsius V3](#fahrenheit-to-celsius-v3)

## 1.3 The `for` Statement

- Syntax: `for(initialisation ; stop condition ; increment)`
- A `for` loop generalises a `while` loop. It contains three sections, seperated by semicolons.
  - An *initialisation* e.g. `int fahr = 0` which is performed once at the start of the loop.
    - This *may* include a variable declaration.
  - A *condition* e.g. `fahr <= 300`, evaluated *before* each loop iteration.
    - The loop ends once the condition is *false*.
  - An *increment* e.g. `fahr = fahr + 20` which a statement carried out after the body of each loop iteration completes.

### Related Exercises

See [Ex1.5](#ex-1-5).

## 1.4 Symbolic Constants

### Example: [Fahrenheit to Celsius V4](#fahrenheit-to-celsius-v4)

- It's bad practice to bury **magic constants**
  - e.g. `300` and `20` don't convey semantic meaning.
- A *symbolic name* can be provided with a `#define` which has the syntax

```C
#define name replacement-text
```

- Any occurence of `name` (not in quotes or as a substring) will be replaced by `replacement-text` at compile time.

- By convention symbolic constant names are written in upper case.
- Since this is just straight up textual replacement we do not use a semicolon.
  - The expression `int lower = LOWER;` would cause a syntax error if we did.

**Note** An alternative mechanism is provided by `constexpr` in the C23 standard. A variable declaration of the form,

```C++
constexpr type name = value;
```

makes name a compile time constant.

## 1.5 Character Input and Output

- Text input/output is dealt with as a character stream
- A *text stream* is a sequence of characters divided into lines of zero or more characters then a newline (`\n`).
- A library must conform to this model.
- `getchar()` and `putchar()` are the simplest standard library I/O functions.
  - `c = getchar()` reads then returns the next input and assigns it to `c`.
  - `putchar(c)` prints the contents of the integer `c` as a character to a stream.

### File Copying

#### Example [Copy Input](#copy-input-v1)

- The relational operator `!=` indicates not equal.
- `EOF` a unique implementation-defined indicator for the end-of-file.
  - Since `char` is only guaranteed to hold any *character* and `EOF` must not be a regular character we need the larger `int` type to guarantee we can hold `EOF`.
- Use `int` as the type for the output of `getchar`.

### Precedence and assignment

#### Example [Copy Input V2](#copy-input-v2)

- assignments can be made as part of a broader expression
  - e.g. the expression `(c = getchar()) != EOF)`
    assigns the return of `getchar()` to `c`compares that to `EOF` and returns `True` if not equal and `False` if they are equal.
- One needs to be careful of precedence, e.g. `!=` has a higher precedence than `=`.
  - `c = getchar() != EOF`is equiv to `c = (getchar() != EOF)`. So `c` is set to `0` or `1`.

#### Related Exercises

See [Ex1.6](#ex-1-6) and [Ex1.7](#ex-1-7)

### Example [Count Characters](#count-characters-v1)

### Prefix increment vs Postfix and Equality test

- `++nc` increments `nc` by one
- similar exist for `--`
- Can either use pre- or postfix, which have slightly different behaviour.

### `long`

- An `int` is only guaranteed to be at least `16` bit, while a `long` is guaranteed to be at least `32` bit.
- We use a `long` in the counting program to guarantee this extended range.
- The `printf` specifier for a `long` is `%ld`.

### Example [Count Characters V2](#count-characters-v2)

### Double

- A double precision floating point number.
- The `printf` specifier for a `double` is `%f` like for `float`.
  - (`floats` are promoted to `double`.)
- **Note:** We can use `%.0f` to suppress the fractional part of a float in output.

In our example we have an empty `for` loop. The book suggests leaving a blank line as a *null line* to indicate no loop body.

- An alternative is to use a simple `;` to denote an empty statement. e.g. `for (do;some;stuff); //<- empty statement`

### Example [line counting](#count-lines)

### Equality

- `==` tests for equality.

### Characters

- A character between single quotes, e.g. `'A'` represents an integer with the numerical value corresponding to the character.
  - Characters are stored as numbers in some encoding.
  - e.g. in ASCII `'A' = 65`.
- Prefer `'c'` where possible to describe a character `c`, it has semantic meaning.

### Related Exercises

See [Ex1.8](#ex-1-8), [Ex1.9](#ex-1-9) and [Ex1.10](#ex-1-10).

### Example: [Word Counting](#count-words)

### Initialising multiple variables

- The line `nl = nw = nc = 0` sets all three variables to zero. Assignments associate right to left.
  - `nc` first assigned `0`
  - `nw` then assigned same value as `nc`
  - `nl` then assigned same value as `nw`
- Generally, we avoid doing this, it's not very clear.

### Logic Operators

- `||` means OR
- `&&` means AND
- `&&` has higher precedence than `||`
- Expressions containing `||` and `&&` are evaluated left to right
  - will stop once truth or falsehood known

### The `else` keyword

- Specifies an alternative action if the condition of a corresponding `if` statement is false.
- The general form is

```C
if (expression) {
    statement
}
else {
    statement
}
```

- **Note:** Only one *branch* in the conditional is taken, either the `if`, if the expression is *true* or the `else` if the expression is *false*.

### Related Exercises

See [Ex1.11](#ex-1-11) and [Ex1.12](#ex-1-12).

## 1.6 Arrays

### Example: Count Digits and White Space

### Arrays

The declaration `int ndigit[10];` declares an array of $`10`$ integers.

- Subscripts start at `0` and go up to `size-1`.
  - Subscripts may be integer variables or constants.
- Declared by `datatype variable[size]`.
- C arrays are statically sized

The character representation of the digits has them laid out sequentially so we can convert the character digits `0` to `9` to the number by subtracting off the value of `0`.
    - We can also perform other similar range checks like the conditional in the example.

### `else if`

- Used to do multiway conditions a general `if` statement structure follows,

```C
if (condition_1) {
    statement_1
}
else if (condition_2) {
    statement_2
}
else {
    statement_3
}
```

### Related Exercises

See [Ex1.13](#ex-1-13) and [Ex1.14](#ex-1-14).

## 1.7 Functions

- Encapsulates a unit of work
  - Allows us to focus on the *what* is done instead of the *how*.

### Example [`power(m, n)`](#exponentiation-v1)

- Consider the problem of exponentiating an integer `m` by the positive power `n`.
- C has no inbuilt exponentiation operator.
- Function declaration has the form

```C
return-type function-name(parameters or void) {
    statements;
}
```

- Functions can appear in any order and may be split across files.
- Functions are called by writing their name followed by parentheses enclosing any arguments. `e.g. power(2, i) or power(-10, i)` (The second argument is modified from the books `power(-3, i)` to make the output more obviously correct.)
- Function parameters and variables are local to the function
- functions can return a value that agrees with their `return-type` with the `return` keyword.
  - A function that doesn't return anything is a `void` function.
  - Similarly the parameter list for a function that takes no parameters is declared `void`.

- `main` also returns a vaue. Conventionally `zero` indicates success, and anythiing else represents failure.
  - A more portable solution is given by the `EXIT_SUCCESS` and `EXIT_FAILURE` macros respectively.

- A function needs to be *declared* before it can be used. This is either through giving a full *definition* or providing a function *prototype*. E.g.

```C
int power(int m, int n)
```

Which declares a function called power that returns an int and takes in two ints as arguments.

- The parameter names in a declaration are not important, a definition could override them. e.g. `int power(int, int)` would also be valid.
- Names give important semantic meaning though.

**Note** The book contains a brief discussion on old-style function declarations. As of C23 they are no longer supported.

### Related Exercises

See [Ex1.15](#ex-1-15).

## 1.8 Arguments - Call by Value

- All arguments in C are passed *by value*.
  - i.e. parameters are given as temporary variables rather than the originals.
  - Modifying the parameter does not modify the original.
- Lets us write more compact programs with fewer variables since we can use the parameters!

- There are variables called *pointers* we shall see later that let us modify the original copies of parameters we pass in.
- **Warning**: Array parameters are not copied by value
  - Array names encode the memory address of the array, not values.

### Example [power_v2](#exponentiation-v2)

## 1.9 Character Arrays

- A string of characters is represented as an array of characters terminated by a *null-character* denoted by `'\0'`.
  - The value of the null character is zero.
  - The null-terminator exists even for string-literals.
- strings can be printed with the `%s` format specifier which relies on the null-termination.
- Design problems for strings
  - What to do if we encounter a string bigger than its limits?
  - How to ensure buffers are big enough when we perform copies.

### Related Exercises

See [Ex1.16](#ex-1-16), [Ex1.17](#ex-1-17), [Ex1.18](#ex-1-18) and [Ex1.19](#ex-1-19).

## 1.10 External Variables and Scope

### Example [Longest Line v2](#longest-line-v2)

- variables are *private* or *local* to where they are declared
  - e.g. in `main`
- By default variables exist only so long as the function that
instances them is running.
  - these variables are sometimes referred to as
    *automatic*.
  - They must be set each time, else they contain garbage
- *external* variables are globally accessible.
  - alternative mechanism to argument lists for inter-function communication.
  - Remain in existence permanently
    - Retain values after function calls.
- External variables have the following properties,
  - they must be *defined* once
    - To allocate storage.
  - then declared in each accessing function
    - you can use `extern`
  - extern is not needed if the declaration preceeds the function in the source code
    - By convention place all `extern` variables at the top of
        a source file (and omit `extern`)
    - `extern` is needed to connect variables across
        source files
      - typically in a `.h` file to `#include`.
- **Note** Overreliance on external variables makes data connections non-obvious.
  - Program is harder to modify.
  - couples functions to the rest of the codebase.
