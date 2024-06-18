/*
Exercise 3-1

Write an implementation of binary search that uses
one test in the loop and one that uses two,

compare the speed.

The time different is minimal, but the two test is cleaner,
the one test is minimally faster
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_SIZE 10

void initIntArray(int a[], int size, int fill);
void initialiseIntArray(int a[], int size);
void initialiseFloatArray(double a[], int size);
int binsearch2test(int x, int v[], int n);
int binsearch1test(int x, int v[], int n);
void printResults(double times[], int r1[], int r2[], int size);

int main()
{
    int values[MAX_SIZE], results1[MAX_SIZE], results2[MAX_SIZE];
    double times[MAX_SIZE];
    
    initIntArray(results1, MAX_SIZE, 0);
    initIntArray(results2, MAX_SIZE, 0);
    initialiseIntArray(values, MAX_SIZE);
    initialiseFloatArray(times, MAX_SIZE);

    printf("Arrays initialised\n");

    int i;
    clock_t start, end;
    for (i = 0; i < MAX_SIZE; i++) {
        printf("Running first search on %d\n", i);
        start = clock();
        results2[i] = binsearch2test(i, values, MAX_SIZE);
        end = clock();
        times[i] = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Running second search on %d\n", i);
        start = clock();
        results1[i] = binsearch1test(i, values, MAX_SIZE);
        end = clock();
        times[i] -= ((double) (end - start)) / CLOCKS_PER_SEC;
    }

    printResults(times, results1, results2, MAX_SIZE);

    return 0;
}

void initIntArray(int a[], int size, int fill)
{
    for (; size > 0; size--) a[size - 1] = fill; 
}

void initialiseIntArray(int a[], int size)
{
    for (; size > 0; size--) a[size - 1] = size;
}

void initialiseFloatArray(double a[], int size)
{
    for (; size > 0; size--) a[size - 1] = 0.0;
}

int binsearch2test(int x, int v[], int n)
{
    int lo, hi, mid;
    lo = 0;
    hi = n - 1;

    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (x < v[mid]) hi = mid - 1;
        else if (x > v[mid]) lo = mid + 1;
        else return mid;
    }
    return -1;
}

int binsearch1test(int x, int v[], int n)
{
    int lo, hi, mid;
    lo = 0;
    hi = n - 1;
    mid = (lo + hi) / 2;
    while ((lo <= hi) && (v[mid] != x)) {
        if (x < v[mid]) hi = mid - 1;
        else lo = mid + 1;
        mid = (lo + hi) / 2;
    }
    return (v[mid] == x) ? mid : (-1);
}

void printResults(double times[], int r1[], int r2[], int size)
{
    int i;
    printf("Target \tResult (1 test) \tResult (2 test)\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d \t\t %d \t\t %d\n", i, r1[i], r2[i]);
    }
    printf("Target \tTime (2 test - 1 test)\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d \t\t %f \n", i, times[i]);
    }
}
