//
// Created by Adam on 2/15/2020.
//

#include <stdio.h>
#include <ctype.h>

#define BUFF_SIZE 100

char buf[BUFF_SIZE];
int bufp = 0;

int getch(void);
void ungetch(int);

int getint(int * pn)
{
    int c, sign;

    while(isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-')? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
    }

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn = *pn * sign;
    if (c != EOF)
        ungetch(c);

    return c;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFF_SIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = (char)c;
}