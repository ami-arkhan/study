#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 20

int N, sum, element, max_element, sum_count, used;
int Data[SIZE];

// For debugging how many test case is generated to find the solution
//int case_generated;

void init()
{
	max_element = 0;
	sum_count = 0;

	// For debugging how many test case is generated to find the solution
	//case_generated = 0;
}

void readCase()
{
	int i;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
		scanf("%d ", &Data[i]);
}

void solveCase()
{
	int i, j;
	/****************************************************************************
	*	1. Subset generated and empty subset is ignored, hence i starts from 1.	*
	*	2. Power of 2. For 4 elements, 2^4 = 16 subset is generated.			*
	****************************************************************************/
	for (i = 1; i < (1 << N); i++)
	{
		// For debugging how many test case is generated to find the solution
		//case_generated++;

		sum = element = 0;
		/********************************************
		*	1. Checking which element is taken.		*
		*	2. For 4 elements, 4 bits are checked	*
		********************************************/
		for (j = 0; j < N; j++)
		{
			// If elements taken, add to sum
			if (i&(1 << j))
			{
				sum += Data[j];
				element++;
			}
		}
		if (sum == 0)
		{
			sum_count++;
			if (element > max_element)
				max_element = element;
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
		init();
		readCase();
		solveCase();

		printf("#%d %d %d\n", test, sum_count, max_element);

		// For debugging how many test case is generated to find the solution
		//printf("Case generated: %d\n", case_generated);
	}
	return 0;
}
