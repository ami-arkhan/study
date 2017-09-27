#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void bitPrint(char p)
{
	int i;
	for (i = 7; i >=0; i--)
		printf("%d", (p >> i) & 1);
}

void convertEndian(int *n)
{
	// Method 1
	char t, *p = (char *) n;
	t = p[0];
	p[0] = p[3];
	p[3] = t;

	t = p[1];
	p[1] = p[2];
	p[2] = t;

	// Method 2
	//*n = (*n << 24) | ((*n << 8) & 0x00ff0000) | ((*n >> 8) & 0x0000ff00) | (*n >> 24);
}

int main()
{
	char i, *p;

	char a = 0x10;
	int x = 0x01020304;
	int y = 123456789;

	printf("------------------\n");
	printf("1. Little Endians:");
	printf("\n------------------\n");
	printf("%d = ", a);
	p = &a;
	bitPrint(*p);
	printf(" => Little endian (Single byte, no visible difference).\n\n");

	printf("0%x = ", x);
	p = (char *) &x;
	for (i = 0; i < 4; i++)
	{
		bitPrint(*p++);
		printf(" ");
	}
	printf(" => Little endian (4 bytes).\n");

	printf("%d = ", y);
	p = (char *)&y;
	for (i = 0; i < 4; i++)
	{
		bitPrint(*p++);
		printf(" ");
	}
	printf(" => Little endian (4 bytes).\n");

	printf("\n-------------------\n");
	printf("2. Endian Exchange:");
	printf("\n-------------------\n");

	printf("0%x = ", x);
	convertEndian(&x);

	p = (char *)&x;
	for (i = 0; i < 4; i++)
	{
		bitPrint(*p++);
		printf(" ");
	}
	printf("\n => Little endian converted to big endian (4 bytes).\n");

	return 0;
}
