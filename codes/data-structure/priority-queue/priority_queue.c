#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

#define MAX_SIZE 101

int heap[MAX_SIZE], heapSize;
int node;

void heapInit()
{
	heapSize = 0;
}

int heapPush(int value)
{
	int parent, child, temp;
	if (heapSize + 1 > MAX_SIZE)
	{
		printf("queue is full!\n");
		return 0;
	}

	heap[heapSize] = value;
	child = heapSize;
	parent = (child - 1) / 2;
	while (child > 0 && heap[child] < heap[parent])
	{
		temp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = temp;

		child = parent;
		parent = (child - 1) / 2;
	}
	heapSize = heapSize + 1;

	return 1;
}

int heapPop(int *value)
{
	int parent, child, temp;
	if (heapSize <= 0)
		return -1;

	*value = heap[0];
	heapSize = heapSize - 1;
	heap[0] = heap[heapSize];

	parent = 0;
	child = parent * 2 + 1;
	while (child < heapSize)
	{
		if (child + 1 != heapSize && heap[child] > heap[child + 1])
			child =  child + 1;

		if (heap[parent] < heap[child])
			break;

		temp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = temp;

		parent = child;
		child = parent * 2 + 1;
	}

	return 1;
}

void read_data()
{
	int i, num;
	scanf("%d\n", &node);

	for (i = 0; i < node; i++)
	{
		scanf("%d", &num);
		if (!heapPush(num))
			break;
	}
}

void print_case()
{
	int value;
	while (node--)
	{
		heapPop(&value);
		printf("%d ", value);
	}
	printf("\n");
}

int main()
{
	int i, T;
	freopen("input.txt", "r", stdin);
	scanf("%d\n", &T);

	for (i = 1; i <= T; i++)
	{
		heapInit();
		read_data();
		printf("#%d ", i);
		print_case();
	}

	return 0;
}
