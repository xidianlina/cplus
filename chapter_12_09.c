#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 40

char **mal_arr(int n);

int main(void)
{
	int words, i;
	char **st;

	printf("How many words do you wish to enter? ");
	scanf("%d", &words);
	getchar();
	printf("Enter %d words now:\n", words);
	st = mal_arr(words);
	printf("Here are your words:\n");
	for (i = 0; i < words; i++)
	{
		puts(st[i]);
		free(st[i]);
	}
	free(st);

	return 0;
}

char **mal_arr(int n)
{
	char **pt;
	int i;

	pt = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
	{
		pt[i] = (char *)malloc(SIZE * sizeof(char));
		scanf("%s", pt[i]);
	}

	return pt;
}