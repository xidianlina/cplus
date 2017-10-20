#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "chapter_17_08_tree.h"

void InorderTraversal(Node *pnode, void(*pfun)(void *));
void PostorderTraversal(Node *pnode, void(*pfun)(void *));
int PreorderTraversal(Node *pnode);
Node** BinarySearch(Item *pitem, Node **ppnode);
Node* MakeNode(Item item);
int  CompareItem(Item, Item);
void display(Node *pnode);

void InitializeTree(Tree * ptree)
{
	ptree->root = NULL;
}

bool TreeIsEmpty(const Tree * ptree)
{
	if (ptree->root == NULL)
		return true;
	else
		return false;
}

bool TreeIsFull(const Tree *ptree)
{
	Node *p;
	p = malloc(sizeof(Node));
	if (p == NULL)
		return true;
	free(p);
	return false;
}

int TreeItemCount(const Tree * ptree)
{
	return PreorderTraversal(ptree->root);
}

bool AddItem(Item *pitem, Tree * ptree)
{
	Node *pnode;
	int i;

	if (TreeIsFull(ptree))
		return false;
	pnode = *BinarySearch(pitem, &(ptree->root));
	if (pnode != NULL)
	{
		for (i = 0; i < pnode->item.times; i++)
			if (strcmp(pnode->item.petkind[i], (*pitem).petkind[0]) == 0)
				return false;
		strcpy(pnode->item.petkind[pnode->item.times], (*pitem).petkind[0]);
		(pnode->item.times)++;
		return true;
	}
	else
	{
		*BinarySearch(pitem, &(ptree->root)) = MakeNode(*pitem);
		return true;
	}
}

bool InTree(Item * pitem, Tree * ptree)
{
	if (*BinarySearch(pitem, &(ptree->root)) == NULL)
		return false;
	else
		return true;
}

bool DeleteItem(Item * pitem, Tree * ptree)
{
	Node **ppnode;
	Node *middle, *left, *right;
	ppnode = BinarySearch(pitem, &(ptree->root));
	if (*ppnode == NULL)
		return false;
	middle = *ppnode;
	left = middle->left;
	right = middle->right;
	if (left == NULL && right == NULL)
		*ppnode = NULL;
	else if (left == NULL && right != NULL)
		*ppnode = right;
	else if (left != NULL && right == NULL)
		*ppnode = left;
	else
	{
		while (left->right != NULL)
			left = left->right;
		left->right = right;
		*ppnode = middle->left;
	}
	free(middle);
	return true;
}

void Traverse(const Tree * ptree, void(*pfun)(Node *node))
{
	InorderTraversal(ptree->root, (*pfun));
}

void DeleteAll(Tree * ptree)
{
	PostorderTraversal(ptree->root, free);
	ptree->root = NULL;
}

bool DisplayItem(Item * pitem, Tree * ptree)
{
	Node *pnode = *BinarySearch(pitem, &(ptree->root));
	if (pnode == NULL)
	{
		puts("the word is not in the tree");
		return false;
	}
	else
	{
		display(pnode);
		return true;
	}
}

void InorderTraversal(Node *pnode, void(*pfun)(void *))
{
	if (pnode != NULL)
	{
		InorderTraversal(pnode->left, (*pfun));
		(*pfun)(pnode);
		InorderTraversal(pnode->right, (*pfun));
	}
}

void PostorderTraversal(Node *pnode, void(*pfun)(void *))
{
	if (pnode != NULL)
	{
		PostorderTraversal(pnode->left, (*pfun));
		PostorderTraversal(pnode->right, (*pfun));
		(*pfun)(pnode);
	}
}

int PreorderTraversal(Node *pnode)
{
	if (pnode != NULL)
		return pnode->item.times + PreorderTraversal(pnode->left) + PreorderTraversal(pnode->right);
	else
		return 0;
}

Node** BinarySearch(Item *pitem, Node **ppnode)
{
	if (*ppnode == NULL || CompareItem(*pitem, (*ppnode)->item) == 0)
		return ppnode;
	if (CompareItem(*pitem, (*ppnode)->item) < 0)
		return BinarySearch(pitem, &((*ppnode)->left));
	else
		return BinarySearch(pitem, &((*ppnode)->right));
}

Node* MakeNode(Item item)
{
	Node *pnew;
	pnew = (Node *)malloc(sizeof(Node));
	pnew->item = item;
	pnew->left = NULL;
	pnew->right = NULL;
	return pnew;
}

int  CompareItem(Item item1, Item item2)
{
	return strcmp(item1.petname, item2.petname);
}

void display(Node *pnode)
{
	int i;

	printf("%-15s", pnode->item.petname);
	if (pnode->item.times == 1)
		printf("%d kind  pet: ", 1);
	else
		printf("%d kinds pet: ", pnode->item.times);
	for (i = 0; i < pnode->item.times; i++)
		printf("%s,", pnode->item.petkind[i]);
	printf("\b\n");
}