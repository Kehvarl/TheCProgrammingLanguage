//
// Created by Adam on 2/3/2020.
//

#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int limit);
int copy(char to[], const char from[]);

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
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while((len = get_line(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }

    if (max > 0)
        printf("%d\t%s", max, longest);

    return 0;
}


int get_line(char line[], int limit)
{
    int i, c;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c!= '\n'; ++i)
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

int copy(char to[], const char from[])
{
    int i;

    i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;

    return i;
}