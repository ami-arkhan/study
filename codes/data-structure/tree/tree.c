#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

#define SIZE 10001

int node, edge;

struct TNode{
	int parent;
	int leftChild;
	int rightChild;
}Tree[SIZE];

void init()
{
	int i;
	for (i = 1; i <= node; i++)
	{
		Tree[i].parent = -1;
		Tree[i].leftChild = -1;
		Tree[i].rightChild = -1;
	}
}

void insertNode(int p, int c)
{
	if (Tree[p].leftChild == -1)
		Tree[p].leftChild = c;
	else
		Tree[p].rightChild = c;

	Tree[c].parent = p;
}

void read_data()
{
	int i, parent, child;
	scanf("%d %d\n", &node, &edge);

	init();
	for (i = 0; i < edge; i++)
	{
		scanf("%d %d", &parent, &child);
		insertNode(parent, child);
	}
}

int searchParent()
{
	int i;
	for (i = 1; i <= node; i++)
		if (Tree[i].parent == -1)
			return i;

	return 0;
}

void print_preorder(int index)
{
	printf("%d ", index);

	if (Tree[index].leftChild != -1)
		print_preorder(Tree[index].leftChild);
	if(Tree[index].rightChild != -1)
		print_preorder(Tree[index].rightChild);
}

int main()
{
	int i, T, index;
	freopen("input.txt", "r", stdin);
	scanf("%d\n", &T);

	for (i = 1; i <= T; i++)
	{
		read_data();

		index = searchParent();

		printf("#%d\n", i);
		print_preorder(index);
		printf("\n");
	}

	return 0;
}
