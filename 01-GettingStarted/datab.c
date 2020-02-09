//
// Created by Adam on 2/04-FunctionsAndStructure/2020.
//

#include <stdio.h>

#define MAX_LINE  1000
#define TAB_STOP  8

int main()
{
    int c, i, s, spaces;
    char text[MAX_LINE];
    i = 0;
    while((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            spaces = TAB_STOP - ((i % TAB_STOP));
            printf("need %d spaces \n", spaces);
            for (s = 0; s < spaces; ++s) {
                text[i] = ' ';
                ++i;
            }
        }
        else
            text[i] = (char)c;
        ++i;
    }
    printf("%s", text);
}
