#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int return_num(char);

int main(void)
{
	char ch;

	printf("Please enter a char:");
	while (scanf("%c", &ch) != EOF)
	{
		printf("The position of the char is %d\n", return_num(ch));
		while (getchar()!='\n');
		printf("Please enter a char:");
	}

	return 0;
}

int return_num(char ch)
{
	if (isalpha(ch))
		return tolower(ch) - 'a' + 1;
	return -1;
}