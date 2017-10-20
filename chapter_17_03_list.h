#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TSIZE 45
#define MAXSIZE 5

typedef struct film {
	char titile[TSIZE];
	int rating;
} Item;

typedef struct list {
	Item entries[MAXSIZE];
	int items;
} List;

void InitializeList(List * plist);
bool ListIsEmpty(const List * plist);
bool ListIsFull(const List * plist);
bool AddItem(List * plist, Item item);
unsigned int ListItemCount(List * plist);
void Traverse(const List * plist, void(*pfun)(Item item));
void EmptyTheList(List * plist);

#endif