#include <stdio.h>
#include <ctype.h>
#define SIZE 40

void get_words(char *, int);

int main(void)
{
	char str[SIZE];

	puts("Enter some characters:");
	get_words(str, SIZE);
	puts(str);

	return 0;
}

void get_words(char *str, int n)
{
	char ch;
	int i = 0;

	while (isspace(ch = getchar()))
		continue;
	do {
		*(str + i) = ch;
		i++;
	} while (!isspace(ch = getchar()) && i < n - 1);
	*(str + i) = '\0';
}