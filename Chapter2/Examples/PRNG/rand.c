/**
 * @file rand.c
 * @author Felix Lempriere
 * @brief Implementation of a random number generator function and a random
 * number seed function.
 *
 * @version 0.1
 * @date 2025-04-26
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Exclusive upper bound on generated random numbers.
 *
 */
#define MY_RAND_MAX 32768

/**
 * @brief Global variable tracking the state of the Pseudorandom number
 * generator.
 *
 */
unsigned long int next = 1;

/**
 * @brief Returns a pseudo random number from [0, MY_RAND_MAX)
 * 
 * @return int 
 */
int my_rand(void);

/**
 * @brief Sets the seed for my_rand
 * 
 * @param seed 
 */
void my_srand(unsigned int seed);

/**
 * @brief Number of test numbers to generate.
 * 
 */
#define N_TESTS 1000000

int main(void) {
    
    int s = 0;
    my_srand(s);
    if (my_rand() != s) {
        printf("Seed failed\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < N_TESTS; i++) {
        if (my_rand() < 0 || my_rand() >= MY_RAND_MAX) {
            printf("Error: Number generated outside of the range\n");
            return EXIT_FAILURE;
        }
    }
    printf("All tests passed successfully\n");
    return EXIT_SUCCESS;
}

int my_rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % MY_RAND_MAX;
}

void my_srand(unsigned int seed) { next = seed; }
