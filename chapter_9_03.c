#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void chline(char, int, int);

int main(void)
{
	char ch;
	int i, j;

	printf("Please enter a char:");
	scanf("%c", &ch);
	printf("Please enter two ints:");
	scanf("%d %d", &i, &j);
	chline(ch, i, j);

	return 0;
}

void chline(char ch, int i, int j)
{
	int a, b;

	for (a = 0; a < j; a++)
	{
		for (b = 0; b < i; b++)
			printf("%c", ch);
		putchar('\n');
	}
}