//
// Created by Adam on 2/10/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_OP 100
#define NUMBER '0'
#define MAX_VAL 100
#define BUFF_SIZE 100

char buf[BUFF_SIZE];
int bufp = 0;
int getch(void);
void ungetch(int);
int get_op(char[]);

int sp = 0;
double val[MAX_VAL];
void push(double);
double pop(void);

int main()
{
    int type;
    double op1;
    double op2;
    double mod;
    char s[MAX_OP];

    while ((type = get_op(s)) != EOF)
    {
        switch (type)
        {
            case NUMBER:
                push(atof(s)); // NOLINT(cert-err34-c)
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 > 0.0)
                    push(pop()/op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                op1 = pop();


                if (op2 < 0.0)
                    op2 = -op2;

                if (op2 == 0.0)
                    printf("error: zero divisor\n");

                if (op1 < 0.0)
                    mod = -op1;
                else
                    mod = op1;

                while (mod >= op2)
                    mod = mod - op2;

                if (op1 < 0)
                    push(-mod);
                else
                    push(mod);

                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
        }
    }
    return 0;
}

void push(double f)
{
    if (sp < MAX_VAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int get_op(char s[])
{
    int i, c;

    while ((s[0] = (char)(c = getch())) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while(isdigit(s[++i] = (char)(c = getch())))
            ;
    if (c == '.')
        while(isdigit(s[++i] = (char)(c = getch())))
            ;

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
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