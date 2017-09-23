#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 101

int N, start, end;
int queue[SIZE];

void init()
{
	start = end = 0;
}

void enqueue(int num)
{
	queue[end++] = num;
}
void read_data()
{
	int i, num;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		enqueue(num);
	}
}

int dequeue()
{
	return queue[start++];
}
void print_queue()
{
	int i;
	while (start < end)
		printf(" %d", dequeue());
	printf("\n");
}

int main()
{
	int i, T;
	freopen("input.txt", "r", stdin);
	scanf("%d\n", &T);

	for (i = 1; i <= T; i++)
	{
		init();
		read_data();
		printf("#%d", i);
		print_queue();
	}

	return 0;
}
