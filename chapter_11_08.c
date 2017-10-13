#include <stdio.h>
#include <string.h>
#define SIZE 40

char *s_gets(char *st, int n);
char *string_in(char *, char *);

int main(void)
{
	char s1[SIZE];
	char s2[SIZE];
	char *ret;

	puts("Please enter the first string (q to quit):");
	while (strcmp(s_gets(s1, SIZE), "q"))
	{
		printf("Please enter the second string:\n");
		s_gets(s2, SIZE);
		ret = string_in(s1, s2);
		if (ret)
		{
			printf("Find!\n");
			puts(ret);
		}
		else
			printf("Can not find!\n");
		printf("Please enter the first string (q to quit):\n");
	}
	puts("Bye");

	return 0;
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n'&&st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

char *string_in(char *s1, char *s2)
{
	int i;

	while (*s1)
	{
		i = 0;
		while (s1[i] == s2[i])
		{
			i++;
			if (!s2[i])
				return s1;
		}
		s1++;
	}

	return NULL;
}