#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 10000

int N, area, max_area;
int data[SIZE];

// For debugging how many iterations are called to find the solution
//int iteration_count;

void readCase()
{
	int i;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
		scanf("%d ", &data[i]);
}

int getMinHeight(int s, int e)
{
	int i, min = 10000000;
	for (i = s; i <= e; i++)
		if (min > data[i])
			min = data[i];

	return min;
}

int getWidth(int s, int e)
{
	int i, w = 0;
	for (i = s; i <= e; i++)
		w++;
	return w;
}

void solveCase()
{
	int i, j, minHeight, width;

	/************************************************************************
	*	1. Divide and conquer. Divide left and right from lowest height.	*
	*	2. Calculate max area based on lowest height from sub-division.		*
	************************************************************************/


	for (i = 0; i < N; i++)
	{
		for (j = i; j < N; j++)
		{

			// For debugging how many iterations are called to find the solution
			//iteration_count++;

			minHeight = getMinHeight(i, j);
			width = j - i + 1;

			// Calculate area based on lowest height
			area = minHeight * width;
			if (area > max_area)
				max_area = area;

		}
	}
}

int main()
{
	int test, T;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (test = 1; test <= T; test++)
	{
		// For debugging how many iterations are called to find the solution
		//iteration_count = 0;

		max_area = 0;
		readCase();
		solveCase(0, N - 1);

		printf("#%d %d\n", test, max_area);

		// For debugging how many iterations are called to find the solution
		//printf("Iteration count: %d\n", iteration_count);
	}
	return 0;
}
