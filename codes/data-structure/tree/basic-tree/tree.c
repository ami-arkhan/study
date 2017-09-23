#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

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

struct TNode *insert(struct TNode *root, int n)
{
	if (NULL == root)
	{
		root = createNode(n);
		return root;
	}
	if (n > root->data)
		root->left = insert(root->left, n);
	else if (n < root->data)
		root->right = insert(root->right, n);



	return root;
}
