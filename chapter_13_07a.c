#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
#define SLEN 81

char *s_gets(char *, int);

int main(void)
{
	FILE *f1, *f2;
	char st[SLEN];
	char name_f1[SIZE];
	char name_f2[SIZE];
	char *ret_val1;
	char *ret_val2;

	fprintf(stdout, "Please enter the first file name:\n");
	s_gets(name_f1, SIZE);
	fprintf(stdout, "Please enter the second file name:\n");
	s_gets(name_f2, SIZE);

	if ((f1 = fopen(name_f1, "r")) == NULL)
	{
		fprintf(stderr, "Could not open the %s\n", name_f1);
		exit(EXIT_FAILURE);
	}
	if ((f2 = fopen(name_f2, "r")) == NULL)
	{
		fprintf(stderr, "Could not open the %s\n", name_f2);
		exit(EXIT_FAILURE);
	}
	do {
		if ((ret_val1 = fgets(st, SLEN, f1)) != NULL)
			fputs(st, stdout);
		if ((ret_val2 = fgets(st, SLEN, f2)) != NULL)
			fputs(st, stdout);
	} while (ret_val1 != NULL || ret_val2 != NULL);
	fclose(f1);
	fclose(f2);

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
