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

int hoarePartition(int low, int high)
{
	/********************************************************************************
	*	1. In 'Hoare Partition Scheme' first or last element is made as pivot.		*
	*	2. There are two checking, smaller and equal elements to left and			*
	*		larger elements to right. When all elements are checked,				*
	*		swap with pivot element and return pivot point location.				*
	*	3. Terminate when partition consists of single element.						*
	********************************************************************************/

	int pivot, pIndex, temp;

	// If partition element is single, return index
	if (low == high)
		return low;

	/********************************************************************************
	*	1. Set high element as pivot.												*
	*	2. Compare all elements with pivot, set and return final pivot location.	*
	********************************************************************************/
	pIndex = high;
	pivot = data[pIndex];
	high--;
	while (1)
	{
		// find location where data is larger than pivot
		while (data[low] < pivot)
			low++;

		// find location where data is smaller than pivot
		while (data[high] > pivot)
			high--;

		/****************************************************************
		*	1. If two points intercede, it means partition complete.	*
		*	2. Insert pivot element between two partition.				*
		*	3. As 'low' increases and 'high' decreases,					*
		*		both will intercede at some point.						*
		****************************************************************/
		if (low >= high)
		{
			temp = data[pIndex];
			data[pIndex] = data[low];
			data[low] = temp;

			// Pivot element location is: 'low'
			return low;
		}

		// Swap two elements to continue partitioning of elements
		temp = data[low];
		data[low] = data[high];
		data[high] = temp;
	}
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
		partitionIndex = hoarePartition(low, high);

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
