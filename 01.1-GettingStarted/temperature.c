//
// Created by Adam on 1/31/2020.
//

#include <stdio.h>

/* Print Fahrenheit-Celsius table.  Floating-point version*/
int main()
{
    float fahrenheit, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit of temperature table */
    step = 20;      /* increment between entries in table */

    fahrenheit = lower;
    while (fahrenheit <= upper) {
        celsius = (5.0f/9.0f) * (fahrenheit - 32.0f);
        printf("%3.0f %6.1f\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + step;
    }
}
