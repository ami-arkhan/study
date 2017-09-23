#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

#define VERTEX 51
#define EDGE 101

int V, E, found, front, end;
int queue[VERTEX], visited[VERTEX], inQueue[VERTEX];

struct node {
	int vertex;
	struct node *next;
}list[VERTEX];

struct node *createNode(int value)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->vertex = value;
	temp->next = NULL;

	return temp;
}
void makeAdjList(int src, int dest)
{
	int i;
	struct node *cur;

	cur = &list[src];
	while (NULL != cur->next)
		cur = cur->next;
	cur->next = createNode(dest);
}

// Queue started from '0' index
void pushQueue(int value)
{
	queue[end++] = value;
}
int popQueue()
{
	int temp = queue[front++];
	queue[front - 1] = 0;

	return temp;
}
int isQueueEmpty()
{
	if (front == end)
		return 1;

	return 0;
}

void init()
{
	found = 0;
	front = end = 0;
	int i;
	for (i = 1; i <= V; i++)
	{
		list[i].vertex = i;
		list[i].next = NULL;

		queue[i] = visited[i] = inQueue[i] = 0;
	}
}
void readCase()
{
	int i, src, dest;
	scanf("%d %d\n", &V, &E);
	init();

	for (i = 0; i < E; i++)
	{
		/****************************************************************
		*	1. In directed graph direction is one way,					*
		*		so Adjacency List is created in one direction.			*
		*	2. Only Source to destination Adjacency List is created.	*
		****************************************************************/

		scanf("%d %d ", &src, &dest);
		makeAdjList(src, dest);
	}
}

void bfs(int vertex)
{
	struct node *cur;

	// Initial root vertex is pushed and marked as in queue
	pushQueue(vertex);
	inQueue[vertex] = 1;

	// Run BFS till queue is empty OR destination vertex is found
	while (!isQueueEmpty() && !found)
	{
		// Vertex is poped and marked as visited
		vertex = popQueue();		// Poped vertex
		cur = &list[vertex];		// Pointer moved to corresponding Adjacency List
		visited[cur->vertex] = 1;	// Marked as visited

									// Check for each child vertices
		while (NULL != cur)
		{
			// If not visited check AND not in queue, add vertex to queue
			if (visited[cur->vertex] != 1 && !inQueue[cur->vertex])
			{
				if (V == cur->vertex)
				{
					found = 1;
					break;
				}
				pushQueue(cur->vertex);
				inQueue[cur->vertex] = 1;
			}
			cur = cur->next;
		}
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

		/****************************************
		*	1. Call BFS to reach:				*
		*		From: source vertex: '1'.		*
		*		To: destination vertex: 'V'.	*
		****************************************/
		bfs(1);

		if (found)
			printf("#%d OK\n", test);
		else
			printf("#%d FAIL\n", test);
	}
	return 0;
}
