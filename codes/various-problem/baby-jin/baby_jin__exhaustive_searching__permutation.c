#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 6

int run, triplet, isBabyJin, used;
int data[SIZE], permutation[SIZE];

// For debugging how many permutations are generated to find the solution
//int permutations_generated;

void init()
{
	used = 0;
	isBabyJin = 0;

	// For debugging how many permutations are generated to find the solution
	//permutations_generated = 0;
}

void readCase()
{
	int i;
	for (i = 0; i < SIZE; i++)
		scanf("%d ", &data[i]);
}

int comp(int a, int b)
{
	// Return the difference
	return (b - a);
}

int runCount()
{
	int i, count = 0;
	for (i = 0; i < SIZE; i += 3)
		// Check run - numbers are sequencial in each 3 number set
		if (comp(permutation[i], permutation[i + 1]) == 1 && comp(permutation[i + 1], permutation[i + 2]) == 1)
			count++;

	return count;
}

int tripletCount()
{
	int i, count = 0;
	for (i = 0; i < SIZE; i += 3)
		// Check triplet - numbers are same in each 3 number set
		if (comp(permutation[i], permutation[i + 1]) == 0 && comp(permutation[i + 1], permutation[i + 2]) == 0)
			count++;

	return count;
}

void solveCase(int index)
{
	int i;
	if (index == SIZE)
	{
		triplet = tripletCount();
		run = runCount();

		// For debugging how many permutations are generated to find the solution
		//permutations_generated++;

		if (run + triplet == 2)
			isBabyJin = 1;

		return;
	}

	for (i = 0; i < SIZE; i++)
	{
		// Put usage number as bit value in variable 'used'
		if (!(used&(1 << i)))
		{
			/****************************************
			*	1. Set a bit:		A |= (1<<X)		*
			*	2. Clear a bit:		A &= ~(1<<X)	*
			*	3. Toggle a bit:	A ^= (1<<X)		*
			****************************************/

			// Set bit, when number is taken
			used |= (1 << i);
			permutation[index] = data[i];

			solveCase(index + 1);
			// Pruning: If babygin found, no need to check further
			//if (isBabyJin)
			//	return;

			// Clear bit, when number is not taken
			used &= ~(1 << i);
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
		solveCase(0);

		if (isBabyJin)
			printf("#%d OK\n", test);
		else
			printf("#%d FAIL\n", test);

		// For debugging how many permutations are generated to find the solution
		//printf("Permutations generated: %d\n", permutations_generated);
	}
	return 0;
}
