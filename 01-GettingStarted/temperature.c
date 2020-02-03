//
// Created by Adam on 1/31/2020.
//

#include <stdio.h>

int main_while();
int main_for();

int main()
{
    main_for();
    main_while();
}

/* Print Fahrenheit-Celsius table.  Floating-point version, for-loop*/
int main_for()
{
    int fahrenheit;

    for (fahrenheit = 0; fahrenheit <= 300; fahrenheit = fahrenheit + 20)
    {
        printf("%3d, %6.1f\n", fahrenheit, (5.0f/9.0f) * (fahrenheit - 32));
    }

    return -1;
}


/* Print Fahrenheit-Celsius table.  Floating-point version, while-loop*/
int main_while()
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

    return -1;
}
