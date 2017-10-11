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
	int k;

	for (k = 1; k < i; k++)
		putchar(' ');
	for (; k <= j; k++)
		putchar(ch);
	putchar('\n');
}