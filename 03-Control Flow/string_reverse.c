//
// Created by Adam on 2/7/2020.
//


#include <string.h>
#include <stdio.h>

void reverse(char []);

int main()
{
    char test[]= "The quick brown fox jumps over the lazy dog.";
    printf("%s\n", test);
    reverse(test);
    printf("%s\n", test);
    return 0;
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j=strlen(s)-1; i<j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = (char) c;
    }
}