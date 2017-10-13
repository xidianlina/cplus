#include <stdio.h>
#include <string.h>
#define SIZE 40

char *s_gets(char *, int);
void reverse_str(char *);

int main(void)
{
	char str[SIZE];
	
	puts("Please enter a string (q to quit):");
	while (strcmp(s_gets(str, SIZE), "q"))
	{
		reverse_str(str);
		puts(str);
		puts("Please enter next a string (q to quit):");
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

void reverse_str(char *str)
{
	unsigned int i;
	char temp;

	size_t len = strlen(str);
	for (i = 0; i < len / 2; i++)
	{
		temp = str[len - i - 1];
		str[len - i - 1] = str[i];
		str[i] = temp;
	}
	str[len] = '\0';
}