#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

int preIndex, postIndex;

struct TNode{
	int data;
	struct TNode *left, *right;
};

struct TNode *createNode(int n)
{
	struct TNode *temp;
	temp = (struct TNode *)malloc(sizeof(struct TNode));
	temp->data = n;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct TNode *makeTree(int  In[], int Pre[], int start, int end)
{
	struct TNode *root;
	int inIndex;
	if (start > end)
		return NULL;

	root = createNode(Pre[preIndex++]);
	for (inIndex = start; inIndex <= end; inIndex++)
	{
		if (root->data == In[inIndex])
			break;
	}
	root->left = makeTree(In, Pre, start, inIndex - 1);
	root->right = makeTree(In, Pre, inIndex + 1, end);

	return root;
}

struct TNode *makeTreePost(int In[], int Post[], int start, int end)
{
	struct TNode *root;
	int inIndex;
	if (start > end)
		return NULL;

	root = createNode(Post[postIndex--]);
	for (inIndex = start; inIndex <= end; inIndex++)
	{
		if (root->data == In[inIndex])
			break;
	}

	root->right = makeTreePost(In, Post, inIndex + 1, end);
	root->left = makeTreePost(In, Post, start, inIndex - 1);

	return root;
}

void printPathBST(struct TNode *root, int n, int path[], int level)
{
	int i;
	if (NULL == root)
		return;
	path[level] = root->data;
	if (root->data > n)
		printPathBST(root->left, n, path, level + 1);
	else if (root->data < n)
		printPathBST(root->right, n, path, level + 1);
	else
	{
		for (i = 0; i <= level; i++)
			printf("%d ", path[i]);
		printf("\n");
	}
}

void printPath(struct TNode *root, int n, int path[], int level)
{
	int i;
	if (NULL == root)
		return;
	path[level] = root->data;

	if(root->data == n)
	{
		for (i = 0; i <= level; i++)
			printf("%d ", path[i]);
		printf("\n");
	}

	printPath(root->left, n, path, level + 1);
	printPath(root->right, n, path, level + 1);
}

void preorder(struct TNode *root)
{
	if (NULL == root)
		return;
	printf("%d ", root->data);
	if (root->left != NULL)
		preorder(root->left);
	if (root->right != NULL)
		preorder(root->right);
}

void inorder(struct TNode *root)
{
	if (NULL == root)
		return;

	if (root->left != NULL)
		inorder(root->left);
	printf("%d ", root->data);
	if (root->right != NULL)
		inorder(root->right);
}

void postorder(struct TNode *root)
{
	if (NULL == root)
		return;

	if (root->left != NULL)
		postorder(root->left);
	if (root->right != NULL)
		postorder(root->right);
	printf("%d ", root->data);
}

int main()
{
	int N, i, path[100];
	int In[100], Pre[100], Post[100];
	struct TNode *root;

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &In[i]);
	for (i = 0; i < N; i++)
		scanf("%d", &Pre[i]);
	for (i = 0; i < N; i++)
		scanf("%d", &Post[i]);

	preIndex = 0;
	//root = makeTree(In, Pre, 0, N - 1);

	postIndex = N-1;
	root = makeTreePost(In, Post, 0, N-1);

	printf("\nInorder: ");
	inorder(root);
	printf("\nPreorder: ");
	preorder(root);
	printf("\nPostorder: ");
	postorder(root);
	scanf("%d", &i);
	printf("\nPrint Path: ");
	printPathBST(root, i, path, 0);
	printf("Print Path: ");
	printPath(root, i, path, 0);

	return 0;
}
