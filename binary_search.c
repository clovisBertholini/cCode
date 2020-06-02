//Author: Clovis Wanderley Bertholini Sobrinho
//Date: June, 1º, 2020.
//Harvard X --> cs50 --> Week 3 --> Algorithms --> Binary Search
//binary_search.c --> search a specific number at an array

#include <stdio.h>
#include <stdlib.h>

const int MAX = 15;

//functions declarations
void merge_sort(int v[], int a, int b);
void merge(int v[], int a, int mid, int b);
int binary_search(int v[], int n, int a, int b);

int main(void)
{
    int x = 288; //rand();
    int numbers[MAX];
    for (int i = 0; i < MAX; i++)
    {
        numbers[i] = rand();
    }
    //print numbers unsorted
	for (int i = 0; i < MAX; i++)
	{
		printf("%i", numbers[i]);
		printf("\n");
	}
	printf("\n");
    //sort numbers
    merge_sort(numbers, 0, MAX);
    //print numbers sorted
	for (int i = 0; i < MAX; i++)
	{
		printf("%i", numbers[i]);
		printf("\n");
	}
    //find number x
    int result = binary_search(numbers, x, 0, MAX - 1);
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

void merge_sort(int v[], int a, int b)
{
	//divide array in subarrays
	int mid = (a + b) / 2;
	if (a < b)
	{
		merge_sort(v, a, mid);
		merge_sort(v, mid + 1, b);
		merge(v, a, mid, b);
	}
}

void merge(int v[], int a, int mid, int b)
{
	int x[MAX];
	int i = a;
	int j = mid + 1;
	int k = a;
	while (i <= mid && j <= b)
	{
		if (v[i] < v[j])
		{
			x[k] = v[i];
			i++;
		}
		else
		{
			x[k] = v[j];
			j++;
		}
		k++;
	}
	if (j > b)
	{
		while (i <= mid)
		{
			x[k] = v[i];
			i++;
			k++;
		}
	}
	else
	{
		while (j <= b)
		{
			x[k] = v[j];
			j++;
			k++;
		}
	}
	for (k = a; k <= b; k++)
	{
		v[k] = x[k];
	}
}


int binary_search(int v[], int n, int a, int b)
{
    if (n == v[(b - a) / 2])
    {
        return 1;
    }
    else if (n < v[(b - a) / 2] && a != b)
    {
        b = (b - a) / 2;
        binary_search(v, n, a, b);
    }
    else if (n > v[(b - a) / 2] && a != b)
    {
        a = (b - a) / 2;
        binary_search(v, n, a, b);
    }
    else
    {
        return 0;
    }
}