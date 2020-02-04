//
// Created by Adam on 2/2/2020.
//

#include <stdio.h>

int power(int base, int n);
int cbv_power(int base, int n);

int main()
{
    int i;
    for (i = 0; i < 10; ++i) {
        printf("%d %d %d \n", i, power(2, i), power(-3, i));
        printf("%d %d %d \n", i, cbv_power(2, i), cbv_power(-3, i));
    }
    return 0;
}

int power (int base, int n)
{
    int i, p;
    p = 1;

    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

int cbv_power(int base, int n)
{
    int p;

    for(p = 1; n > 0; --n)
    {
        p = p * base;
    }
    return p;
}
