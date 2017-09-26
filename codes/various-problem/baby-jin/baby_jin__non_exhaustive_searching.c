#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 6
#define DIGIT 10

int run, triplet;
int data[SIZE], digits[DIGIT];

// For debugging how many test case is generated to find the solution
//int case_generated;

void init()
{
	int i;

	run = triplet = 0;
	for (i = 0; i < DIGIT; i++)
		digits[i] = 0;

	// For debugging how many test case is generated to find the solution
	//case_generated = 0;
}

void readCase()
{
	int i;
	for (i = 0; i < SIZE; i++)
		scanf("%d ", &data[i]);
}

int runCount()
{
	int i, count = 0;
	for (i = 0; i < DIGIT - 2; i++)
	{
		// Check run - 3 sequential numbers are checked
		if (digits[i] > 0 && digits[i+1] > 0 && digits[i+2] > 0)
		{
			count++;
			digits[i]--;
			digits[i+1]--;
			digits[i+2]--;

			/************************************************
			*	Both Run's can be formed with same digits,	*
			*		so same location is checked again.		*
			************************************************/
			i--;

			// For debugging how many test case is generated to find the solution
			//case_generated++;

			// Pruning: If both results are found, no need to check further
			//if (count == 2)
			//	break;
		}
	}
	return count;
}

int tripletCount()
{
	int i, count = 0;
	for (i = 0; i < DIGIT; i++)
	{
		// Check Triplet - same digit count must be 3 atleast
		if (digits[i] >= 3)
		{
			count++;
			digits[i] -= 3;

			/****************************************************
			*	Both Triplet's can be formed with same digits,	*
			*		so same location is checked again.			*
			****************************************************/
			i--;

			// For debugging how many test case is generated to find the solution
			//case_generated++;

			// Pruning: If both results are found, no need to check further
			//if (count == 2)
			//	break;
		}
	}

	return count;
}

void solveCase()
{
	int i;

	// Count each digit and store
	for (i = 0; i < SIZE; i++)
		digits[data[i]]++;

	// 'Run' or 'Triplet' anything can be checked first
	run = runCount();
	// Pruning: If both results are found, no need to check further
	//if(run != 2)
		triplet = tripletCount();
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

		if (run + triplet == 2)
			printf("#%d OK\n", test);
		else
			printf("#%d FAIL\n", test);

		// For debugging how many test case is generated to find the solution
		//printf("Case generated: %d\n", case_generated);
	}
	return 0;
}
