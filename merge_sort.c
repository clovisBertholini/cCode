//Author: Clovis Wanderley Bertholini Sobrinho
//Date: May, 25, 2020.
//Harvard X --> cs50 --> Week 3 --> Algorithm --> Merge Sort
//merge_sort.c --> takes the given array and sort it

#include <stdio.h>
#include <stdlib.h>

const int QTD = 15;

//functions declarations
int merge_sort(int v[]);

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
	merge_sort(numbers);

	//print numbers sorted
	for (int i = 0; i < QTD; i++)
	{
		printf("%i", v[i]);
		printf("\n");
	}
	return 0;
}

int merge_sort(int v[])
{
	//TODO
	if (i = 1)
	{}
	else
	{
		merge_sort(	
}
