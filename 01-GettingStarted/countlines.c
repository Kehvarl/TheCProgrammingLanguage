//
// Created by Adam on 2/1/2020.
//

#include <stdio.h>

int main()
{
    int c, nl, nc;

    nl = 0;
    nc = 0;

    while((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
    }
    printf("%d\t%d\n", nc, nl);

    return -1;
}
