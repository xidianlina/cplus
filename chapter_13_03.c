#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 40

char *s_gets(char *st, int n);

int main(void)
{
	FILE *fs;
	FILE *ft;
	char name_s[SIZE];
	char name_t[SIZE];
	char ch;

	fprintf(stdout, "Please enter the source file name:\n");
	s_gets(name_s, SIZE);
	fprintf(stdout, "Please enter the target file name:\n");
	s_gets(name_t, SIZE);

	if ((fs = fopen(name_s, "r")) == NULL)
	{
		fprintf(stderr, "Couldn't open the %s\n", name_s);
		exit(EXIT_FAILURE);
	}
	if ((ft = fopen(name_t, "w")) == NULL)
	{
		fprintf(stderr, "Couldn't open the %s\n", name_t);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fs)) != EOF)
		putc(toupper(ch), ft);
	fclose(fs);
	fclose(ft);

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
			find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}