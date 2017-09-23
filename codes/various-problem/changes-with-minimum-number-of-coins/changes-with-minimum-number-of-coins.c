#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 20

int type, money, changes, total_changes;
int coins[SIZE];

// For debugging how many test case is generated to find the solution
// int case_generated;
// int used[SIZE];

void init()
{
	int i;

	// For debugging how many test case is generated to find the solution
	/*
	case_generated = 0;
	for (i = 0; i < type; i++)
	used[i] = 0;
	//*/
	changes = 0;
	total_changes = money;
}

void readCase()
{
	int i;
	scanf("%d %d\n", &type, &money);
	for (i = 0; i < type; i++)
		scanf("%d ", &coins[i]);
}


void coinsChange(int i, int remains)
{
	if (i == type)
		return;

	if (remains == 0)
	{
		// For debugging how many test case is generated to find the solution
		/*
		case_generated++;
		printf(":%d ", case_generated);
		for (int j = 0; j < type; j++)
		printf("%d*%d ", coins[j], used[j]);
		printf("\n");
		//*/

		if (changes < total_changes)
			total_changes = changes;
		return;
	}

	/********************************************************************************
	*	1. If money taken, reduce remaining amount.									*
	*	2. Same amount of money can be taken multiple times.						*
	*	3. Pruning invalid path: Reducing path checking when solution is invalid.	*
	*		Such as current change is greater than previous minimum change found.	*
	********************************************************************************/
	if (remains - coins[i] >= 0 && changes <= total_changes)
	{
		changes++;

		// For debugging how many test case is generated to find the solution
		// used[i]++;

		coinsChange(i, remains - coins[i]);

		// For debugging how many test case is generated to find the solution
		// used[i]--;

		changes--;
	}

	// If money not taken
	i++;
	coinsChange(i, remains);
}

int main()
{
	int test, T;

	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &T);

	for (test = 1; test <= T; test++)
	{
		readCase();
		init();
		coinsChange(0, money);

		printf("#%d %d\n", test, total_changes);
	}
	return 0;
}
