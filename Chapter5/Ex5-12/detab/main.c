#include "detab.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int start_col, incr;
    int error;

    if (--argc > 2)
    {
        printf("Error: too many arguments. Call structure is detab -n +m\n");
        return 1;
    }
    
    error = setTab(&start_col, &incr, argc, ++argv);
    if (error)
    {
        printf("Error: invalid args. Call structure is detab -n +m\n");
        return 1;
    }
    printf("Set start column to: %d\n", start_col);
    printf("Set increment to %d\n", incr);
    detab(start_col, incr);
}