#include <stdio.h>
#include <stdlib.h>
#include "chapter_17_02_list.h"

void InitializeList(List *plist)
{
	plist->head = NULL;
	plist->end = NULL;
}

bool ListIsEmpty(const List *plist)
{
	if (plist->head == NULL)
		return true;
	else
		return false;
}

bool ListIsFull(const List *plist)
{
	Node *pt;
	bool full;

	pt = (Node *)malloc(sizeof(Node));
	if (pt == NULL)
		full = true;
	else
		full = false;
	free(pt);

	return full;
}

unsigned int ListItemCount(const List *plist)
{
	unsigned int count = 0;
	Node *pnode = plist->head;

	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next;
	}

	return count;
}

bool AddItem(Item item, List *plist)
{
	Node *pnew;
	
	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
		return false;

	pnew->next = NULL;
	pnew->item = item;

	if (plist->head == NULL)
		plist->head = pnew;
	else
		plist->end->next = pnew;
	plist->end = pnew;

	return true;
}

void Traverse(const List *plist, void(*pfun)(Item item))
{
	Node *pnode = plist->head;

	while (pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

void EmptyTheList(List *plist)
{
	Node *pnode;

	while (plist->head != NULL)
	{
		pnode = plist->head;
		plist->head = plist->head->next;
		free(pnode);
	}
}