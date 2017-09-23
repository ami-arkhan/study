#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define HEX 701
#define BIT HEX*4

char hex[HEX];
char bin[BIT];

int bin_index, hex_count, sum;

void init()
{
	bin_index = hex_count = sum = 0;
}

void hexToBinary()
{
	int i, j, hex_value;

	// Count Hex Digit
	for (i = 0; hex[i]; i++)
		hex_count++;

	// Convert hex digit: 0~9, A~F to Binary
	for (i = 0; i < hex_count; i++)
	{
		hex_value = hex[i] - '0';

		// If A~F is found convert to Digit 10~15
		if (hex_value > 9)
			hex_value -= 7;

		/************************************************************************************
		*	1. Binary Conversion from Hexadecimal.											*
		*	2. As total number of Hex character is multiple of 7, no extra 0 is required.	*
		************************************************************************************/
		for (j = 3; j >= 0; j--)
			bin[bin_index++] = (hex_value >> j) & 1;
	}
}

void solveCase()
{
	int index, bit, number;

	// Convert hex to binary
	hexToBinary();

	for (index = 0; index < bin_index; index += 7)
	{
		/****************************************************
		*	1. Make decimal per 7 bit.						*
		*	2. Total number of bit is multiple of 7 bit.	*
		****************************************************/
		number = 0;
		for (bit = 0; bit < 7; bit++)
			number = (number << 1) + bin[index + bit];
		sum += number;
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

		printf("#%d %d\n", test, sum);
	}

	return 0;
}
