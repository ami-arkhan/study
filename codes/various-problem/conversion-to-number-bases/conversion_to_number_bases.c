#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define HEX 51
#define BIT HEX*4
#define CRYPT 10

char hex[HEX];
char bin[BIT];

int bin_index, hex_count, total_sum;
int table[CRYPT];

char crypt_table[CRYPT + 1][6 + 1] = {
	"001101",
	"010011",
	"111011",
	"110001",
	"100011",
	"110111",
	"001011",
	"111101",
	"011001",
	"101111"
};

void init()
{
	bin_index = hex_count = total_sum = 0;
}

void hexToBinary()
{
	int i, j, hex_value;

	// Count Hex Digit
	for (i = 0; hex[i]; i++)
		hex_count++;

	// Convert to Binary, 0~9 & A~F
	for (i = 0; i < hex_count; i++)
	{
		hex_value = hex[i] - '0';

		// If A~F is found convert to Digit 10~15
		if (hex_value > 9)
			hex_value -= 7;

		for (j = 3; j >= 0; j--)
			bin[bin_index++] = (hex_value >> j) & 1;
	}
}

void makeDecryptTable()
{
	int row, index, bit;
	for (row = 0; row < CRYPT; row++)
	{
		table[row] = 0;
		for (index = 0; index < 6; index++)
		{
			bit = crypt_table[row][index] - '0';
			table[row] = (table[row] << 1) + bit;
		}
	}
}

int searchDecryptTable(int value)
{
	int index, decrypt_value;

	decrypt_value = -1;
	for (index = 0; index < CRYPT; index++)
		if ((value^table[index]) == 0)
			decrypt_value = index;

	return decrypt_value;
}

void solveCase()
{
	int index, bit, number, value, count;

	// Make integer equivalent from crypt table
	makeDecryptTable();

	// Convert hex to binary
	hexToBinary();

	count = 0;
	for (index = bin_index; index >= 0 && count <= 6;)
	{
		/************************************************************************
		*	1. Find index to 1st '1' from last. Trailing 0 will be ignored.		*
		*	2. Every crypt value have 1 in last 6th digit,						*
		*		so there will be no 0 at the last digit in the middle either.	*
		************************************************************************/
		while (!bin[index])
			index--;

		/************************************************************************
		*	1. Make decimal per 6 bit from last									*
		*	2. All crypt value has common 1 in last 6th digit,					*
		*		so if calculated from start position crypt value will be wrong	*
		*		as there could be many leading 0's at the beginning.			*
		************************************************************************/
		number = 0;
		for (bit = 5; bit >= 0; bit--)
			number += (bin[index - bit] << bit);

		// Get corresponding value from crypt table
		value = searchDecryptTable(number);
		if (value >= 0)
		{
			total_sum += value;
			index -= 6; // reduce next checking index by 6
			/****************************************************************
			*	If total 6 crypt value is found no need to check further.	*
			*		so leading 0 will be ignored							*
			****************************************************************/
			count++;
		}
		else
			// If crypt value not found reduce index, even though crypt values are sequential
			index--;
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
		scanf("%s", &hex);
		solveCase();

		printf("#%d %d\n", test, total_sum);
	}
	return 0;
}
