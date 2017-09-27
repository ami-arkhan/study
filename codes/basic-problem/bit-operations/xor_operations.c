#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 55;
	int b = 10;
	int c = 23;
	int d = 75;

	printf("Initial values:\n");
	printf("a = %d, b = %d\n\n", a, b);

	printf("XOR operations: Numbers are exchanged without third variable !!!\n");
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a = %d, b = %d\n\n", a, b);

	printf("Initial value:\n");
	printf("c = %d, d = %d\n\n", c, d);

	c = c ^ d;
	printf("c^d = %d => Number changed: Encrypted.\n", c);
	c = c ^ d;
	printf("c^d = %d => Number returned to it's original: Decrypted.\n\n", c);

	return 0;
}
