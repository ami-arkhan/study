#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

#define VERTEX 51
#define EDGE 101

int V, S;
int visited[VERTEX];

struct node {
	int vertex;
	struct node *next;
}list[VERTEX];

void init()
{
	int i;
	for (i = 1; i <= V; i++)
	{
		list[i].vertex = i;
		list[i].next = NULL;

		visited[i] = 0;
	}
}
struct node *createNode(int value)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->vertex = value;
	temp->next = NULL;

	return temp;
}
void insertAdjList(int src, int dest)
{
	int i;
	struct node *cur;

	cur = &list[src];
	while (NULL != cur->next)
		cur = cur->next;
	cur->next = createNode(dest);
}
void readCase()
{
	int i, src, dest;

	scanf("%d %d\n", &V, &S);
	init();

	while (2 == scanf("%d %d\n", &src, &dest))
	{
		if (src == dest && src == -1)
			break;

		/************************************************************************
		*	1. In undirected graph vertices are connected in both direction,	*
		*		so Adjacency List is created for both direction.				*
		*	2. Source to Destination and Destination to Source.					*
		************************************************************************/

		insertAdjList(src, dest);
		insertAdjList(dest, src);
	}
}

void dfs(int vertex)
{
	struct node *cur = &list[vertex];

	// Print current node and mark as visited
	printf("%d ", cur->vertex);
	visited[cur->vertex] = 1;

	while (NULL != cur)
	{
		// For each adjacent vertex, if not visited check dfs
		if (visited[cur->vertex] != 1)
			dfs(cur->vertex);

		cur = cur->next;
	}
}

int main()
{
	int test, T;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (test = 1; test <= T; test++)
	{
		readCase();

		// Call DFS from source: 'S'
		printf("#%d ", test);
		dfs(S);
		printf("\n");
	}
	return 0;
}
