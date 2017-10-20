#ifndef _TREE_H_
#define _TREE_H_

#define SIZE 30

typedef struct {
	char word[SIZE];
	int times;
}Item;

typedef struct node {
	Item item;
	struct node *left;
	struct node *right;
}Node;

typedef struct {
	struct node *root;
}Tree;

void InitializeTree(Tree * ptree);

bool TreeIsEmpty(const Tree * ptree);

bool TreeIsFull(const Tree * ptree);

int TreeItemCount(const Tree * ptree);

bool AddItem(Item * pitem, Tree * ptree);

bool InTree(Item * pi, Tree * ptree);

bool DeleteItem(Item * pi, Tree * ptree);

void Traverse(const Tree * ptree, void(*pfun)(Node *node));

void DeleteAll(Tree * ptree);

bool ChangeItem(Item * pi, Tree * ptree);

bool DisplayItem(Item * pi, Tree * ptree);

#endif