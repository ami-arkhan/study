#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

#define VERTEX 51
#define EDGE 101

int V, E, heapSize, minWeight;
int visited[VERTEX], inHeap[VERTEX];

struct node {
	int vertex;
	int weight;
	struct node *next;
}list[VERTEX];

struct node *createNode(int value, int weight)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->vertex = value;
	temp->weight = weight;
	temp->next = NULL;

	return temp;
}
void makeAdjList(int src, int dest, int weight)
{
	int i;
	struct node *cur;

	cur = &list[src];
	while (NULL != cur->next)
		cur = cur->next;
	cur->next = createNode(dest, weight);
}

// Priority queue (Minimum Heap) started from '0' index
struct heapNode {
	int vertex;
	int parent;
	int weight;
}*heap[VERTEX];

void swapHeapNode(int parent, int child)
{
	struct heapNode *temp = heap[parent];

	heap[parent] = heap[child];
	heap[child] = temp;
}
void moveUp(int parent, int child)
{
	while (child > 0 && heap[parent]->weight > heap[child]->weight)
	{
		swapHeapNode(parent, child);
		child = parent;
		parent = (child - 1) / 2;
	}
}
struct heapNode *createHeapNode(int value, int parent, int weight)
{
	struct heapNode *temp = (struct heapNode *)malloc(sizeof(struct heapNode));
	temp->vertex = value;
	temp->parent = parent;
	temp->weight = weight;

	return temp;
}
void pushHeap(int value, int parent, int weight)
{
	int child;

	// Create new heap node
	heap[heapSize] = createHeapNode(value, parent, weight);

	/********************************************************************
	*	1. Adjust created heap node. Lowest weight should be in root,	*
	*		so heap update will be upwards.								*
	********************************************************************/
	child = heapSize;
	parent = (child - 1) / 2;

	moveUp(parent, child);

	// New node added so increase heap size
	heapSize++;
}
struct heapNode *popHeap()
{
	int parent, child;
	struct heapNode *temp;

	// Store root node data before removing
	temp = createHeapNode(heap[0]->vertex, heap[0]->parent, heap[0]->weight);

	// Swap root with last node and delete node
	heapSize--;
	swapHeapNode(0, heapSize);
	heap[heapSize] = NULL;

	/************************************************
	*	1. After swapping root and last heap node,	*
	*		correct root heap node.					*
	*	2. Root heap node should go downwards.		*
	************************************************/
	parent = 0;
	child = parent * 2 + 1;
	while (child < heapSize)
	{
		// If right child exists and is less than left child, swap with right child
		if (child + 1 < heapSize &&
			heap[child]->weight > heap[child + 1]->weight)
			child += 1;

		// If parent is already less than child, stop swapping
		if (heap[parent]->weight < heap[child]->weight)
			break;

		swapHeapNode(parent, child);
		parent = child;
		child = parent * 2 + 1;
	}

	return temp;
}
void updateHeap(int vertex, int parent, int weight)
{
	int child, index;

	// Search vertex in heap and update weight if necessary
	for (index = 0; index < heapSize; index++)
	{
		if (vertex == heap[index]->vertex)
			break;
	}

	// If minimum weight not found, return
	if (weight > heap[index]->weight)
		return;

	heap[index]->weight = weight;
	heap[index]->parent = parent;

	/************************************************************************
	*	1. Once vertex weight is reduced in heap, update heap structure.	*
	*	2. Lowest weighted vertex should be in root.						*
	*	3. Vertex weight is updated only if lower weight is found,			*
	*		so heap update will be upwards.									*
	************************************************************************/
	child = index;
	parent = (child - 1) / 2;

	moveUp(parent, child);
}
int isHeapEmpty()
{
	if (heapSize == 0)
		return 1;
	return 0;
}

void init()
{
	minWeight = heapSize = 0;
	int i;
	for (i = 1; i <= V; i++)
	{
		list[i].vertex = i;
		list[i].weight = 0;
		list[i].next = NULL;

		visited[i] = inHeap[i] = 0;
	}
}
void readCase()
{
	int i, src, dest, weight;
	scanf("%d %d\n", &V, &E);
	init();

	for (i = 0; i < E; i++)
	{
		/****************************************************************
		*	1. In directed graph direction is one way,					*
		*		so Adjacency List is created in one direction.			*
		*	2. Only Source to destination Adjacency List is created.	*
		****************************************************************/

		scanf("%d %d %d\n", &src, &dest, &weight);
		makeAdjList(src, dest, weight);
	}
}

void sp_Dijkstra(int vertex)
{
	int weight;
	struct node *cur;
	struct heapNode *temp;

	// Initial root vertex is pushed into heap and marked as in heap
	pushHeap(vertex, 0, 0);
	inHeap[vertex] = 1;

	/********************************************************
	*	1. Run BFS till all vertices are visited.			*
	*	2. Break loop when destination vertex 'V' is found.	*
	********************************************************/
	while (!isHeapEmpty())
	{
		// Vertex is poped and marked as visited and unmark as not in heap
		temp = popHeap();				// Poped vertex
		visited[temp->vertex] = 1;		// Marked as visited
		inHeap[temp->vertex] = 0;		// Not in heap anymore
		weight = temp->weight;			// Parent weight is stored

		// Destination vertex is found, store it's weight and exit
		if (temp->vertex == V)
		{
			minWeight = temp->weight;
			break;
		}

		// Pointer moved to corresponding Adjacency List to traverse as BFS
		cur = &list[temp->vertex];

		// For debugging which vertex are connecting to tree
		//printf("%d %d %d\n", temp->parent, temp->vertex, temp->weight);

		/****************************************************************************
		*	1. Dijkstra's Algorithm is similar to Prim's Algorithm.					*
		*	2. Dijkstra's Algorithm states that minimum vertex is added	from		*
		*		'unvisited vertex' that has an edge to current constructing tree.	*
		*	3. In minimum heap only possilbe unvisited vertex are inserted by BFS,	*
		*		that is which have connection to current constructing tree.			*
		*	4. As BFS is applied for pushing, there is no chance for pushing		*
		*		unvisited vertex that has no connection to tree.					*
		****************************************************************************/
		while (NULL != cur)
		{
			// If not visited
			if (visited[cur->vertex] != 1)
			{
				// If not in heap, push to heap and mark in heap
				if (inHeap[cur->vertex] != 1)
				{
					// Heap vertex location modification is done inside pushHeap()
					pushHeap(cur->vertex, temp->vertex, weight + cur->weight);
					inHeap[cur->vertex] = 1;
				}
				// If in heap, then check for weight reduction
				else
					// Heap vertex location modification is done inside updateHeap()
					updateHeap(cur->vertex, temp->vertex, weight + cur->weight);
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

		/************************************************************
		*	1. Dijkstra's Algorithm to find SP (Shortest Path):		*
		*		From: source vertex: '1'.							*
		*		To: destination vertex: 'V'							*
		************************************************************/
		sp_Dijkstra(1);

		printf("#%d %d\n", test, minWeight);
	}
	return 0;
}
