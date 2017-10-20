#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "chapter_17_stack.h"
#define SLEN 80

char *s_gets(char *, int);

int main(void)
{
	char str[SLEN];
	Stack stack;
	int i;
	Item ch;

	InitializeStack(&stack);
	printf("Please enter string:");
	s_gets(str, SLEN);
	puts("Original order is ");
	puts(str);

	for (i = 0; str[i] != '\0'&&i < SLEN; i++)
		PushStack(str[i], &stack);

	puts("Reverse order is ");
	while (PopStack(&ch, &stack))
		putchar(ch);

	putchar('\n');

	return 0;
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