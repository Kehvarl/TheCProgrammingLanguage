//
// Created by Adam on 2/8/2020.
//

#include <stdio.h>
#include <string.h>

void expand(char[], char[]);

int main()
{
    char s1[1000] = "This is a test a-z, a-b-c, 0-9, -9, 0-, -a-z";
    char s2[1000];

    expand(s1, s2);

    printf("%s\n%s\n", s1, s2);

    return 0;
}

void expand(char s1[], char s2[])
{
    int i, i2, start, end;

    i2 = 0;
    for(i = 0; i < strlen(s1); i++)
    {
        if (s1[i] == '-')
        {
            if(i == 0) {
                s2[i2] = s1[i];
                ++i2;
            }
            else if(s1[i -1] == ' ')
            {
                s2[i2] = s1[i];
                ++i2;
            }
            else if ( ((s1[i - 1] >= 'a' && s1[i - 1] <= 'z') ||
                    (s1[i - 1] >= '0' && s1[i - 1] <= '9')) &&
                      ((s1[i + 1] >= 'a' && s1[i + 1] <= 'z') ||
                       (s1[i + 1] >= '0' && s1[i + 1] <= '9')) )
            {
                start = s1[i - 1];
                end = s1[i + 1];
                while (start < end)
                {
                    ++start;
                    s2[i2] = (char)start;
                    ++i2;
                }
                ++i;
            }
            else
            {
                s2[i2] = s1[i];
                ++i2;
            }

        }
        else
        {
            s2[i2] = s1[i];
            ++i2;
        }
        s2[i2] = '\0';
    }
}