#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float celsiusToFahrenheit(float celsius);

int main() {

    for (int i = LOWER; i <= UPPER; i += STEP)
        printf("%d: %6.1f\n", i, celsiusToFahrenheit(i));
    return 0;
}

float celsiusToFahrenheit(float celsius) {
    return (9.0/5.0)*celsius + 32; 
}
