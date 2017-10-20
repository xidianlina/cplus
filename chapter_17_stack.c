#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "chapter_17_stack.h"

static void CopyToNode(Item item, Node *pn);
static void CopyToItem(Node *pn, Item *pi);

void InitializeStack(Stack *ps)
{
	ps->top = ps->bottom = NULL;
}

bool StackIsEmpty(const Stack *ps)
{
	return ps->top == NULL;
}

bool StackIsFull(const Stack *ps)
{
	Node *pn;
	pn = (Node *)malloc(sizeof(Node));

	if (pn == NULL)
		return true;
	else
		free(pn);
	return false;
}

bool PushStack(Item item, Stack *ps)
{
	Node *pnew;

	if (StackIsFull(ps))
		return false;
	pnew = (Node *)malloc(sizeof(Node));

	if (pnew == NULL)
	{
		fprintf(stderr, "Unable to allocate memory!\n");
		exit(1);
	}
	CopyToNode(item, pnew);
	if (StackIsEmpty(ps))
	{
		pnew->next = NULL;
		ps->bottom = pnew;
	}
	else
		pnew->next = ps->top;
	ps->top = pnew;

	return true;
}

bool PopStack(Item *item, Stack *ps)
{
	Node *pn;
	if (StackIsEmpty(ps))
		return false;
	CopyToItem(ps->top, item);
	pn = ps->top;
	ps->top = ps->top->next;
	free(pn);
	if (ps->top == NULL)
		ps->bottom = NULL;

	return true;
}

static void CopyToNode(Item item, Node *pn)
{
	pn->item = item;
}

static void CopyToItem(Node *pn, Item *pi)
{
	*pi = pn->item;
}