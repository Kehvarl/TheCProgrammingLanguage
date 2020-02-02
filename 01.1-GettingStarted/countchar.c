//
// Created by Adam on 2/1/2020.
//
#include <stdio.h>


/* count characters in input.  V1 */
int main ()
{
    long nc;

    nc = 0;
    while(getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
}