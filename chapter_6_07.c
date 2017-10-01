#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char ch[40];
	int i;

	printf("Please enter a word :");
	scanf("%s", ch);
	for (i = strlen(ch)-1; i >= 0; i--)
		printf("%c", ch[i]);
	printf("\n");

	return 0;

}