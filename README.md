# The C Programming Language - 2nd Edition

This repository contains code fragments, notes and exercises from [The C Programming Language - 2nd Edition, by Kernighan and Ritche](https://www.cs.princeton.edu/~bwk/cbook.html).

## Structure

This repository has been broken down by Chapter. Each Chapter contains a markdown file containing notes as well as an index for code fragments. Code fragments are subdivided into

1. Examples - Code fragments provided by the books
2. Exercises - Solutions to Exercises

## Content

1. [Chapter 1](./Chapter1/Chapter1.md) - A Tutorial Introduction.
2. [Chapter 2](./Chapter2/Chapter2.md) - Types, Operators and Expressions.
3. [Chapter 3](./Chapter3/Chapter3.md) - Control Flow.
4. [Chapter 4](./Chapter4/Chapter4.md) - Functions and Program Structure.

## Code Style

Generally each Chapter is treated by restricting oneself to the parts of the language as presented in the book up to that point.

Where we deviate from this we will generally make reference to doing so. Three deviations that we use consistently are:

1. Avoiding K&R style function declarations and implicitly typed variables. (These have been deprecated in Modern Standards.)
2. Declaring variables at point of use, rather than at the start of a block, and initialising on declaration wherever possible.
    1. This includes using the ability to declare a variable in the initialisation of a `for` loop.
3. Returning from main via the `EXIT_SUCCESS` or `EXIT_FAILURE` macros from `stdlib.h`.

### Examples and Exercises

Examples may be slightly edited from their original presentation to bring them inline with the updated code style listed above, otherwise they are left as they are.

For code examples that are standalone functions, we will typically provide a basic test driver implementation in main, so that the code can be run standalone.

Exercises are to be completed with the tools introduced by the language, at that point in time. Often tools introduced later may make an Exercise significantly easier or shorter, but part of the learning experience is learning how to use simple machinery to do complex things.

Other non-language specific programming techniques such as Queues and Stacks may be used in solutions though, since these techniques are independent of the language.

Generally we try to write our solutions to be to the point. That means we typically avoid non-obvious error handling, and solutions may not be the most optimal algorithms. This is to make the focus on the solution, not the extra code.
