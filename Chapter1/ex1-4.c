#include <stdio.h>

/*print the Celsius-Fahrenheit table*/

int main() {
    float celsius, fahr;
    int lower = 0;
    int upper = 300;
    int step = 20;

    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0/5.0)*(celsius + 32);
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}