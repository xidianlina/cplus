#include "chapter_17_03_list.h"

void InitializeList(List * plist)
{
	int i;

	for (i = 0; i < MAXSIZE; i++)
	{
		strcpy((plist->entries[i]).titile, "");
		(plist->entries[i]).rating = 0;
		plist->items = 0;
	}
}

bool ListIsEmpty(const List * plist)
{
	if (plist->items == 0)
		return true;
	else
		return false;
}

bool ListIsFull(const List * plist)
{
	if (plist->items == MAXSIZE)
		return true;
	else
		return false;
}

bool AddItem(List * plist, Item item)
{
	if (plist->items == MAXSIZE)
	{
		fprintf(stderr, "The list is full.\n");
		return false;
	}

	plist->entries[plist->items] = item;
	(plist->items)++;

	return true;
}

unsigned int ListItemCount(List * plist)
{
	return plist->items;
}

void Traverse(const List * plist, void(*pfun)(Item item))
{
	int i;

	for (i = 0; i < plist->items; i++)
	{
		(*pfun)(plist->entries[i]);
	}
}

void EmptyTheList(List * plist)
{
	int i;

	for (i = 0; i < plist->items; i++)
	{
		strcpy((plist->entries[i]).titile, "");
		(plist->entries[i]).rating = 0;
		plist->items = 0;
	}
}