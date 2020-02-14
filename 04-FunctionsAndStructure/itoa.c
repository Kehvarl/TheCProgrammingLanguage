//
// Created by Adam on 2/13/2020.
//

#include <stdio.h>

#define BUFF_SIZE 100

char buffer [BUFF_SIZE];
int buff_ptr = 0;

void itoa(int n)
{
    if (n < 0)
    {
        buffer[buff_ptr] = '-';
        ++buff_ptr;
        n = -n;
    }

    if (n/10)
        itoa(n / 10);

    buffer[buff_ptr] = (char)(n % 10 + '0');
    ++buff_ptr;
}

int main()
{
    itoa(1234);
    printf("%s", buffer);
}