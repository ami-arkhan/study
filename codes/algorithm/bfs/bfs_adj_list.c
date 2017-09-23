#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

#define VERTEX 51
#define EDGE 101

int V, S;
int front, end, queue[VERTEX], visited[VERTEX], inQueue[VERTEX];

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
void init()
{
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

	scanf("%d %d\n", &V, &S);
	init();

	while (2 == scanf("%d %d\n", &src, &dest))
	{
		if (src == dest && src == -1)
			break;

		/************************************************************************
		*	1. In directed graph vertices are connected in one direction only,	*
		*		so Adjacency List is created for one direction.					*
		*	2. Only source to destination direction is created.					*
		************************************************************************/

		makeAdjList(src, dest);
		makeAdjList(dest, src);
	}
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

void bfs(int vertex)
{
	struct node *cur;

	// Initial root vertex is pushed and marked as in queue
	pushQueue(vertex);
	inQueue[vertex] = 1;

	// Run BFS till queue is empty
	while (!isQueueEmpty())
	{
		// Pop queue, mark as visited and print vertex
		vertex = popQueue();
		cur = &list[vertex];
		visited[vertex] = 1;

		printf("%d ", cur->vertex);

		while (NULL != cur)
		{
			// If not visited AND not in queue, add to queue
			if (visited[cur->vertex] != 1 && !inQueue[cur->vertex])
			{
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

		printf("#%d ", test);
		// Call BFS from source: 'S'
		bfs(S);
		printf("\n");
	}
	return 0;
}
