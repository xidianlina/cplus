#include <stdio.h>
#include <ctype.h>
#define SIZE 40

void get_words(char *ar);

int main(void)
{
	char str[SIZE];

	puts("Enter some characters:");
	get_words(str);
	puts(str);

	return 0;
}

void get_words(char *str)
{
	char ch;

	while (isspace(ch = getchar()))
		continue;
	do
	{
		*str++ = ch;
	} while (!isspace(ch = getchar()));
	*str = '\0';
}