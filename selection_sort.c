//Author: Clovis Wanderley Bertholini Sobrinho
//Date: May, 20, 2020.
//Harvard X --> cs50 --> Week 3 --> Algorithm --> Selection Sort
//selection_sort.c --> takes the given array and sort it

#include <stdio.h>
#include <stdlib.h>

const int QTD = 5;

//functions declarations
void selection_sort(int v[]);

int main(void)
{
	int numbers[QTD];
       	//populate numbers array
	for (int i = 0; i < QTD; i++)
		numbers[i] = random(); 
	//print numbers unsorted
	for (int i = 0; i < QTD; i++)
	{
		printf("%i", numbers[i]);
		printf("\n");
	}
	printf("\n");
	//sort numbers array with selection sort algorithm
	selection_sort(numbers);
	return 0;
}

void selection_sort(int v[])
{
	int j = 1;
	int k = 0;
	while (j < QTD)
	{
		int selected;
		//TODO SELECT LOWER ITEM
		//insert selected item to first position on unsorted part
		while (k > j - 1)
		{
			v[k] = v[k - 1];
			k--;
		}
		v[j - 1] = selected;
		j++;
	}
	//print numbers sorted
	for (int i = 0; i < QTD; i++)
	{
		printf("%i", v[i]);
		printf("\n");
	}
}
