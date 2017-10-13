#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 80

int is_within(char *, char);

int main(void)
{
	char str[SIZE];
	char ch;

	printf("Please enter a string (q to quit):\n");
	while (strcmp(gets(str), "q"))
	{
		printf("Please enter a character:");
		scanf("%c", &ch);
		while (getchar() != '\n')
			continue;
		if (is_within(str, ch))
			printf("Find!\n");
		else
			printf("Can not find!\n");
		printf("Please enter next a string (q to quit):\n");
	}
	printf("Bye!\n");

	return 0;
}

int is_within(char *str, char ch)
{
	int flag = 0;
	size_t cnt = 0;

	while(cnt++<strlen(str))
		if (*str++ == ch)
		{
			flag = 1;
			break;
		}

	return flag;
}