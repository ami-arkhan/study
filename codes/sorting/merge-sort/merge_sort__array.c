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

void merge(int low, int mid, int high)
{
	int l, r, index;

	/************************************************************
	*	Merge Sort:												*
	*	1. Store two parts in two separate temporary arrays.	*
	*	2. Merge back both temporary arrays as sorted.			*
	************************************************************/

	int left[SIZE / 2], right[SIZE / 2];
	int lenLeft = mid - low + 1;
	int lenRight = high - mid;

	// Store left part into 'left' array
	for (l = 0; l < lenLeft; l++)
		left[l] = data[low + l];

	// Store right part into 'right' array
	for (r = 0; r < lenRight; r++)
		right[r] = data[mid + 1 + r];

	// Merge back two parts as sorted
	l = r = 0;
	index = low;
	while (l < lenLeft && r < lenRight)
	{
		if (left[l] < right[r])
			data[ index++ ] = left[ l++ ];
		else if (left[l] > right[r])
			data[ index++ ] = right[ r++ ];
	}

	// If data still exists in 'left' array
	while (l < lenLeft)
		data[ index++ ] = left[ l++ ];

	// If data still exists in 'right' array
	while(r < lenRight)
		data[ index++ ] = right[ r++ ];
}

void mergeSort(int low, int high)
{
	int mid;
	if (low < high)
	{
		/****************************************************************
		*	Merge Sort:													*
		*	1. Find middle point to divide elements into two halves.	*
		*	2. Recursively call for merge sort for two halves.			*
		*	3. Merge the two sorted halves.								*
		*	4. Middle is calculated differently. This is to avoid		*
		*		overflow, when 'high + low' becomes very large.			*
		****************************************************************/
		mid = low + (high-low) / 2;

		// Divide elements into 2 halves
		mergeSort(low, mid);
		mergeSort(mid + 1, high);

		// Merge 2 halves
		merge(low, mid, high);
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
		mergeSort(0, N-1);

		printf("#%d ", test);
		printCase();
	}
}
