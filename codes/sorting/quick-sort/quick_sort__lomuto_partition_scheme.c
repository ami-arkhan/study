#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 101

int N;
int data[SIZE];

void readCase()
{
	int i;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
		scanf("%d ", &data[i]);
}

int lomutoPartition(int low, int high)
{
	/********************************************************************************
	*	1. In 'Lomuto Partition Scheme' last element is made as pivot.				*
	*	2. Move smaller and equal elements to left. When all small elements 		*
	*		are moved, next index position will be the pivot element position,		*
	*		because all other elements are larger than the pivot element.			*
	*	3. Terminate when partition consists of single element.						*
	********************************************************************************/

	int pivot = data[high];
	int index = low;
	int i, temp;

	// If partition element is single, return index
	if (low == high)
		return low;

	// Compare all elements with pivot, set and return pivot location to make partitions
	for (i = low; i < high; i++)
	{
		if (data[i] <= pivot)
		{
			temp = data[index];
			data[index++] = data[i];
			data[i] = temp;
		}
	}
	temp = data[index];
	data[index] = data[high];
	data[high] = temp;

	return index;
}

void quickSort(int low, int high)
{
	/************************************************************************
	*	Quick Sort:															*
	*	1. Search for partition index and make partition of left and right.	*
	*	2. When partition is created, move lower values on one side,		*
	*		and higher values on the other side.							*
	*	3. Sort each partition.												*
	************************************************************************/

	if (low < high)
	{
		int partitionIndex;

		// Get partition point location.
		partitionIndex = lomutoPartition(low, high);

		/****************************************************************
		*	1. Partition index element is sorted to correct position.	*
		*	2. So sorting on left and right partition is needed.		*
		****************************************************************/
		quickSort(low, partitionIndex - 1);
		quickSort(partitionIndex + 1, N - 1);
	}
}

void printCase()
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", data[i]);
	printf("\n");
}

int main()
{
	int test, T;
	freopen("input.txt", "r", stdin);
	scanf("%d\n", &T);

	for (test = 1; test <= T; test++)
	{
		readCase();
		quickSort(0, N - 1);

		printf("#%d ", test);
		printCase();
	}
}
