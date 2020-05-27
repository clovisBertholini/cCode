//Author: Clovis Wanderley Bertholini Sobrinho
//Date: May, 25, 2020.
//Harvard X --> cs50 --> Week 3 --> Algorithm --> Merge Sort
//merge_sort.c --> takes the given array and sort it

#include <stdio.h>
#include <stdlib.h>

const int QTD = 15;

//functions declarations
void merge_sort(int v[], int a, int b);
void merge(int v[], int a, int mid, int mid1, int b);

int main(void)
{
	int numbers[QTD];
       	
	//populate numbers array
	for (int i = 0; i < QTD; i++)
		numbers[i] = rand(); 
	
	//print numbers unsorted
	for (int i = 0; i < QTD; i++)
	{
		printf("%i", numbers[i]);
		printf("\n");
	}
	printf("\n");
	
	//sort numbers array with merge sort algorithm
	merge_sort(numbers, 0, QTD); 
	return 0;
}

void merge_sort(int v[], int a, int b)
{
	//TODO
	int mid = (a + b) / 2;
	if (v[a] == v[b])
	{
		break;
	}
	else (v[a] < v[b])
	{
		merge_sort(v, a, mid);
		merge_sort(v, mid + 1, b);
		merge(v, a, mid, mid + 1, b);
	}
}

void merge(int v[], int a, int mid, int mid1, int b)
{
	int x[b];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < mid && j < b)
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
	while (i < mid)
	{
		x[k] = v[i];
		i++;
		k++;
	}
	while (j < b)
	{
		x[k] = v[j];
		j++;
		k++;
	}

	//print numbers sorted
	for (int i = 0; i < QTD; i++)
	{
		printf("%i", x[i]);
		printf("\n");
	}
}
