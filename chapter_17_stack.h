#ifndef _STACK_H_
#define _STACK_H_

typedef char Item;

typedef struct node {
	Item item;
	struct node *next;
}Node;

typedef struct stack {
	Node *top;
	Node *bottom;
}Stack;

void InitializeStack(Stack *ps);
bool StackIsEmpty(const Stack *ps);
bool StackIsFull(const Stack *ps);
bool PushStack(Item item, Stack *ps);
bool PopStack(Item *pitem, Stack *ps);

#endif