#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "chapter_17_07_tree.h"
#define SLEN 100

char *s_gets(char *st, int n);

void display(Node *node);
char *take(char *, char word[]);

int main(void)
{
	char str[SLEN];
	char *p;
	FILE *fp;
	Tree article;
	Item item;
	InitializeTree(&article);

	printf("Enter the filename: ");
	s_gets(str,SLEN);
	while ((fp = fopen(str, "r")) == NULL)
	{
		printf("Can not open %s,Please enter again!", str);
		s_gets(str, SLEN);
	}
	while ((p = fgets(str, SLEN, fp)) != NULL)
	{
		while (*(p = take(p, item.word)) != '\0')
		{
			if (InTree(&item, &article) == false)
			{
				item.times = 1;
				AddItem(&item, &article);
			}
			else
				ChangeItem(&item, &article);
		}
	}

	while (1)
	{
		printf("\na.list all the words\n");
		printf("b.report how many times the word occurred\n");
		printf("c.quit\n");
		s_gets(str, SLEN);
		switch (tolower(str[0]))
		{
			case 'a': 
				Traverse(&article, display);
				break;
			case 'b':  
				s_gets(item.word, SIZE);
				if (InTree(&item, &article)) 
					DisplayItem(&item, &article);
				else 
					puts("the word is not in the tree");
				break;
			case 'c': 
				puts("quit");
				DeleteAll(&article);
				return 0;
			default:  
				break;
		}
	}

	return 0;
}

void display(Node *node)
{
	printf("%-20s%-20d\n", node->item.word, node->item.times);
}

//从p字符串中读出第一个单词到word里，返回此单词后面一个字符的地址
char * take(char *p, char word[])
{
	while (!isalpha(*p))
	{
		if (*p == '\0')
			return p;
		p++;
	}
	do
	{
		*word++ = *p++;
	} while (isalpha(*p));
	*word = '\0';

	return p;
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