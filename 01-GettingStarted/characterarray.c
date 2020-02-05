//
// Created by Adam on 2/3/2020.
//

#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

int get_line(void);
int copy(void);

int main()
{
    /*
     * while there is a lone
     *  if it's longer tha previous lines
     *      save line
     *      save length
     * print longest line
     */

    int len;

    max = 0;

    while((len = get_line()) > 0)
        if (len > max)
        {
            max = len;
            copy();
        }

    if (max > 0)
        printf("%d\t%s", max, longest);

    return 0;
}


int get_line(void)
{
    int i, c;

    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c!= '\n'; ++i)
    {
        line[i] = (char) c;
    }
    if (c == '\n')
    {
        line[i] = (char) c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

int copy(void)
{
    int i;

    i = 0;

    while ((longest[i] = line[i]) != '\0')
        ++i;

    return i;
}