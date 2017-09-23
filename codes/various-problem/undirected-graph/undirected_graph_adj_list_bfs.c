#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

#define VERTEX 51
#define EDGE 101

int V, E, height, total_vertices;
int front, end, queue[VERTEX], visited[VERTEX], inQueue[VERTEX];

struct node {
	// Level is kept to store height of the node 
	int vertex, level;
	struct node *next;
}list[VERTEX];

struct node *createNode(int value)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->vertex = value;
	temp->level = 0;
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
	height = 0;
	front = end = 0;
	int i;
	for (i = 1; i <= V; i++)
	{
		list[i].vertex = i;
		list[i].level = 0;
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
		/************************************************************************
		*	1. In undirected graph vertices are connected in both direction,	*
		*		so Adjacency List is created for both direction.				*
		*	2. Source to Destination and Destination to Source.					*
		************************************************************************/

		scanf("%d %d ", &src, &dest);
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

void countVertices()
{
	int i;
	total_vertices = 0;
	for (i = 1; i <= V; i++)
		if (list[i].level == height)
			total_vertices++;
}
void bfs(int vertex)
{
	int level, count;
	struct node *cur;

	// Initial root vertex is pushed and marked as in queue
	pushQueue(vertex);
	inQueue[vertex] = 1;	// Marked as visited

							// Run BFS till queue is empty
	while (!isQueueEmpty())
	{
		// Vertex is poped and marked as visited
		vertex = popQueue();		// Poped vertex
		cur = &list[vertex];		// Pointer moved to corresponding Adjacency List
		visited[cur->vertex] = 1;	// Marked as visited

		/********************************************************
		*	1. Initial child vertex count is '0'.				*
		*	2. Current vertex height from source is 'level'.	*
		********************************************************/
		count = 0;
		level = cur->level;
		while (NULL != cur)
		{
			/****************************************************************
			*	1. If not visited AND not in queue,							*
			*		increase height of new vertices and add to queue.		*
			*	2. If height exists, it means already in queue for visit,	*
			*		OR we can check if not in queue.						*
			****************************************************************/

			// !inQueue[cur->vertex] OR !list[cur->vertex].level)
			if (visited[cur->vertex] != 1 && !inQueue[cur->vertex]) 
			{
				// Increase height of vertices in adjacency list (uses in countVertices)
				list[cur->vertex].level = level + 1;

				pushQueue(cur->vertex);
				inQueue[cur->vertex] = 1;
				count++;
			}
			cur = cur->next;
		}

		// If any vertex is found, increase total graph height
		if (count)
		{
			level++;
			if (level > height)
				height = level;
		}
	}

	// Count max height vertices from adjacency list
	countVertices();
}

int main()
{
	int test, T;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (test = 1; test <= T; test++)
	{
		readCase();

		/****************************************************************************
		*	1. Call BFS to calculate max height and total vertices at that height:	*
		*		From: source vertex: '1'.											*
		****************************************************************************/
		bfs(1);

		printf("#%d %d %d\n", test, height, total_vertices);
	}
	return 0;
}
