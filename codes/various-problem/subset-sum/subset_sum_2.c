#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 20

int N, sum, element, max_element, sum_count, used;
int Data[SIZE];

// For debugging how many test case is generated to find the solution
// int case_generated;

void init()
{
	max_element = 0;
	sum_count = 0;

	// For debugging how many test case is generated to find the solution
	// case_generated = 0;
}

void readCase()
{
	int i;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
		scanf("%d ", &Data[i]);
}

void solveCase(int index)
{
	int i;

	// Termination Condition, when all combination checked.
	if (index > N)
		return;

	// Atleast one element must be taken
	if (index == N && used != 0)
	{
		sum = 0;
		element = 0;
		for (i = 0; i < index; i++)
		{
			if (used&(1 << i))
			{
				sum += Data[i];
				element++;
			}
		}

		// For debugging how many test case is generated to find the solution
		// case_generated++;

		if (sum == 0)
		{
			sum_count++;
			if (element > max_element)
				max_element = element;
		}

		return;
	}

	/****************************************
	*	1. Set a bit:		A |= (1<<X)		*
	*	2. Clear a bit:		A &= ~(1<<X)	*
	*	3. Toggle a bit:	A ^= (1<<X)		*
	****************************************/

	// Set bit, when number is taken
	used |= (1 << index);
	solveCase(index + 1);

	// Clear bit, when number is not taken
	used &= ~(1 << index);
	solveCase(index + 1);
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
		solveCase(0);

		printf("#%d %d %d\n", test, sum_count, max_element);
	}
	return 0;
}
