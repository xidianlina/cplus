#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "chapter_17_08_tree.h"

#define LMAX 100

char menu(void);
void display(Node *node);
char *s_gets(char *st, int n);

int main(void)
{
	char choice;
	Tree pets;
	Item temp;

	InitializeTree(&pets);

	while ((choice = menu()) != 'q')
	{
		switch (choice)
		{
			case 'a':  
				puts("Please enter name of pet:");
				s_gets(temp.petname,MAX);
				puts("Please enter pet kind:");
				s_gets(temp.petkind[0],MAX);
				temp.times = 1;
				if (AddItem(&temp, &pets) == true)
					printf("%s %s has been added\n", temp.petname, temp.petkind[0]);
				else
					puts("add error!");
				break;

			case 'l':  
				if (TreeItemCount(&pets) >0)
					Traverse(&pets, display);
				else
					puts("there is no pets\n");
				break;
			case 'f': 
				s_gets(temp.petname,MAX);
				DisplayItem(&temp, &pets);
				break;
			case 'n':  
				printf("%d pets in club\n", TreeItemCount(&pets));
				break;
			case 'd':
				s_gets(temp.petname,MAX);
				if (DeleteItem(&temp, &pets) == true)
					printf("%s has been deleted\n", temp.petname);
				else
					puts("the pet is not in the tree");
				break;
			default: 
				puts("Switching error");
		}
	}
	DeleteAll(&pets);
	puts("Bye.");

	return 0;
}


char menu(void)
{
	int ch;

	puts("Nerfville Pet Club Membership Program");
	puts("Enter the letter corresponding to your choice:");
	puts("a) add a pet          l) show list of pets");
	puts("n) number of pets     f) find pets");
	puts("d) delete a pet       q) quit");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n')  
			continue;
		ch = tolower(ch);
		if (strchr("alrfndq", ch) == NULL)
			puts("Please enter an a, l, f, n, d, or q:");
		else
			break;
	}

	if (ch == EOF)      
		ch = 'q';

	return ch;
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}