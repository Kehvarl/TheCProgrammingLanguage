#include <stdio.h>

//
// Created by Adam on 2/6/2020.
//
void shellsort(int[], int);

int main()
{
    int array[10];
    int i;

    for (i=0; i < 10; i++)
        array[i] = 10-i;

    for (i=0; i < 10; i++)
        printf("%d", array[i]);

    printf("\n");

    shellsort(array, 10);

    for (i=0; i < 10; i++)
        printf("%d", array[i]);

    printf("\n");
    return 0;
}

void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
    {
        for (i=gap; i < n; i++)
        {
            for (j=i-gap; j >= 0 && v[j] > v[j+gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}