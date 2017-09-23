#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 10000

int N, area, max_area;
int data[SIZE];

void readCase()
{
	int i;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
		scanf("%d ", &data[i]);
}

int getMinHeightIndex(int s, int e)
{
	int i, min = 10000000, index;
	for (i = s; i <= e; i++)
	{
		if (min > data[i])
		{
			min = data[i];
			index = i;
		}
	}
	return index;
}

int getWidth(int s, int e)
{
	int i, w = 0;
	for (i = s; i <= e; i++)
		w++;
	return w;
}

void solveCase(int start, int end)
{
	int minHeightIndex, height, width;

	/************************************************************************
	*	1. Divide and conquer. Divide left and right from lowest height.	*
	*	2. Calculate max area based on lowest height from sub-division.		*
	************************************************************************/

	// If start index > end index, finish checking
	if (start > end)
		return;

	minHeightIndex = getMinHeightIndex(start, end);

	// Height is the minimum value. Width is the maximum area in that sub-division
	height = data[minHeightIndex];
	width = getWidth(start, end);

	// Calculate area based on lowest height
	area = height * width;
	if (area > max_area)
		max_area = area;

	// Calculate max from left part & right part
	solveCase(start, minHeightIndex - 1);
	solveCase(minHeightIndex + 1, end);
}

int main()
{
	int test, T;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (test = 1; test <= T; test++)
	{
		max_area = 0;
		readCase();
		solveCase(0, N - 1);

		printf("#%d %d\n", test, max_area);
	}
	return 0;
}
