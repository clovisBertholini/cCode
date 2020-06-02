//Author: Clovis Wanderley Bertholini Sobrinho
//Date: June, 1º, 2020.
//Harvard X --> cs50 --> Week 3 --> Algorithms --> Binary Search
//binary_search.c --> search a specific number at an array

#include <stdio.h>
#include <stdlib.h>

const int MAX = 15;

int binary_search(int v[], int n);

int main(void)
{
    int x = rand();
    int numbers[MAX];
    for (int i = 0; i < MAX; i++)
    {
        numbers[i] = rand();
    }
    int result = binary_search(numbers, x);
    if (result == 1)
    {
        printf("The number %i exists in array", x);
    }
    else
    {
        printf("The number %i not exists in array", x);
    }
    return 0;
}