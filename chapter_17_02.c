#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "chapter_17_02_list.h"

void show_list(Item item);
char *s_gets(char *st, int n);

int main(void)
{
	List movies;
	Item temp;

	//��ʼ��
	InitializeList(&movies);
	if (ListIsFull(&movies))
	{
		fprintf(stderr, "No memory available.\n");
		exit(1);
	}

	//��������
	printf("Please input the title of movie:\n");
	while (s_gets(temp.title, TSIZE) != NULL &&temp.title[0] != '\0')
	{
		printf("Enter your rating <0-10>:\n");
		scanf("%d", &temp.rating);
		while (getchar() != '\n')
			continue;
		if (AddItem(temp,&movies) == 0)
		{
			fprintf(stderr, "Allocting memory error.\n");
			break;
		}
		if (ListIsFull(&movies))
		{
			fprintf(stderr, "Sorry, the list is full.\n");
			break;
		}
		printf("Input the next title (Empty line to stop):\n");
	}

	//��ʾ����
	if (ListIsEmpty(&movies))
	{
		fprintf(stderr, "Sorry, the list is empty.\n");
		return 0;
	}
	printf("Here is the movie list:\n");
	Traverse(&movies, show_list);
	printf("You entered %u movies.\n", ListItemCount(&movies));

	//�������
	EmptyTheList(&movies);

	printf("Bye.\n");

	return 0;
}

void show_list(Item item)
{
	printf("Movie: %s   Rating: %d\n", item.title, item.rating);
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