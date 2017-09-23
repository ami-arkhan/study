#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 20

int N, total_move, dest_row, dest_col, possible;

void knightMovement(int step, int row, int col)
{
	if (step == total_move)
	{
		if (row == dest_row && col == dest_col)
			possible = 1;
		return;
	}

	// Total possible movements: 8
	if (row - 2 >= 0 && !possible)
	{
		if (col - 1 >= 0)
			knightMovement(step + 1, row - 2, col - 1);
		if (col + 1 < N)
			knightMovement(step + 1, row - 2, col + 1);
	}
	if (row - 1 >= 0 && !possible)
	{
		if (col - 2 >= 0)
			knightMovement(step + 1, row - 1, col - 2);
		if (col + 2 < N)
			knightMovement(step + 1, row - 1, col + 2);
	}
	if (row + 1 < N && !possible)
	{
		if (col - 2 >= 0)
			knightMovement(step + 1, row + 1, col - 2);
		if (col + 2 < N)
			knightMovement(step + 1, row + 1, col + 2);
	}
	if (row + 2 < N && !possible)
	{
		if (col - 1 >= 0)
			knightMovement(step + 1, row + 2, col - 1);
		if (col + 1 < N)
			knightMovement(step + 1, row + 2, col + 1);
	}
}

int main()
{
	int test, T;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (test = 1; test <= T; test++)
	{
		possible = 0;
		scanf("%d %d %d %d\n", &N, &total_move, &dest_row, &dest_col);
		knightMovement(0, 0, 0);

		if (possible)
			printf("#%d OK\n", test);
		else
			printf("#%d FAIL\n", test);
	}
	return 0;
}
