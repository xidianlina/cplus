#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char ch;
	printf("Please enter a number: ");
	scanf("%d", &ch);
	printf("%c\n", ch);

	return 0;
}