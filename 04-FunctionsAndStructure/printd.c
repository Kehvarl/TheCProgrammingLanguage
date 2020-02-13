//
// Created by Adam on 2/12/2020.
//

#include <stdio.h>

void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');

}

int main()
{
    printd(-1234567);
    return 0;
}