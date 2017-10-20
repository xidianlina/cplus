#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "chapter_17_07_tree.h"

void InorderTraversal(Node *pnode, void(*pfun)(void *));
void PostorderTraversal(Node *pnode, void(*pfun)(void *));
int PreorderTraversal(Node *pnode);
Node **BinarySearch(Item *pitem, Node **ppnode);
Node *MakeNode(Item item);
int CompareItem(Item, Item);

void InitializeTree(Tree *ptree)
{
	ptree->root = NULL;
}

bool TreeIsEmpty(const Tree *ptree)
{
	if (ptree->root == NULL)
		return true;
	else
		return false;
}

bool TreeIsFull(const Tree *ptree)
{
	Node *pn;

	pn = (Node *)malloc(sizeof(Node));
	if (pn == NULL)
		return true;
	free(pn);

	return false;
}

int TreeItemCount(const Tree *ptree)
{
	return PreorderTraversal(ptree->root);
}

bool AddItem(Item *pitem, Tree *ptree)
{
	if (*BinarySearch(pitem, &(ptree->root)) != NULL)
		return false;
	else
	{
		*BinarySearch(pitem, &(ptree->root)) = MakeNode(*pitem);
		return true;
	}
}

bool InTree(Item *pitem, Tree *ptree)
{
	if (*BinarySearch(pitem, &(ptree->root)) == NULL)
		return false;
	else
		return true;
}

bool DeleteItem(Item *pitem, Tree *ptree)
{
	Node **ppnode;
	Node *mid, *left, *right;

	ppnode = BinarySearch(pitem, &(ptree->root));
	if (*ppnode == NULL)
		return false;
	mid = *ppnode;
	left = mid->left;
	right = mid->right;
	if (left == NULL&&right == NULL)
		*ppnode = NULL;
	else if (left == NULL&&right != NULL)
		*ppnode = right;
	else if (left != NULL&&right == NULL)
		*ppnode = left;
	else
	{
		while (left->right != NULL)
			left = left->right;
		left->right = right;
		*ppnode = mid->left;
	}
	printf("delete:%s", mid->item.word);
	free(mid);

	return true;
}

void Traverse(const Tree *ptree, void(*pfun)(Node *node))
{
	InorderTraversal(ptree->root, (*pfun));
}

void DeleteAll(Tree *ptree)
{
	PostorderTraversal(ptree->root, free);
	ptree->root = NULL;
}

bool ChangeItem(Item *pitem, Tree *ptree)
{
	if (*BinarySearch(pitem, &(ptree->root)) == NULL)
		return false;
	else
	{
		(*BinarySearch(pitem, &(ptree->root)))->item.times++;
		return true;
	}
}

bool DisplayItem(Item *pitem, Tree *ptree)
{
	Node *pnode = *BinarySearch(pitem, &(ptree->root));
	if (pnode == NULL)
		return false;
	else
	{
		printf("%s has occurred %d times\n", pnode->item.word, pnode->item.times);
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
		return 1 + PreorderTraversal(pnode->left) + PreorderTraversal(pnode->right);
	else
		return 0;
}

Node **BinarySearch(Item *pitem, Node **ppnode)
{
	if (*ppnode == NULL || CompareItem(*pitem, (*ppnode)->item) == 0)
		return ppnode;
	if (CompareItem(*pitem, (*ppnode)->item) < 0)
		return BinarySearch(pitem, &((*ppnode)->left));
	else
		return BinarySearch(pitem, &((*ppnode)->right));
}

Node *MakeNode(Item item)
{
	Node *pnew;
	pnew = (Node *)malloc(sizeof(Node));
	pnew->item = item;
	pnew->left = NULL;
	pnew->right = NULL;
	return pnew;
}

int CompareItem(Item item1, Item item2)
{
	return strcmp(item1.word, item2.word);
}