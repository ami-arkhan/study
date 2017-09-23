#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

#define MAX_VERTEX 101
#define MAX_EDGE 1001

int V, E, Q;
int Edge[MAX_VERTEX][MAX_VERTEX];

void init()
{
	int i, j;
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			Edge[i][j] = -1;
}

void insertEdge(int v1, int v2)
{
	Edge[v1][v2] = 1;
	Edge[v2][v1] = 1;
}

void read_data()
{
	int i, v1, v2;
	scanf("%d %d %d\n", &V, &E, &Q);

	init();
	for (i = 0; i < E; i++)
	{
		scanf("%d %d", &v1, &v2);
		insertEdge(v1, v2);
	}
}

void print_case(int query)
{
	int i;
	for (i = 0; i < V; i++)
		if (Edge[query][i] == 1)
			printf("%d ", i);

	printf("\n");
}

int main()
{
	int i, T, query;
	freopen("input.txt", "r", stdin);
	scanf("%d\n", &T);

	for (i = 1; i <= T; i++)
	{
		read_data();

		printf("#%d\n", i);
		while (Q--)
		{
			scanf("%d", &query);
			print_case(query);
		}
	}

	return 0;
}
