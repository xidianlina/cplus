#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void)
{
	char ch = 'A';
	int i, j;
	char a;
	int ROWS = 0;

	printf("Please enter a character :");
	scanf("%c", &a);
	
	ROWS = a - 'A' + 1;
	
	for (i = 1; i <= ROWS; i++)
	{
		for (j = 1; j <= ROWS - i; j++)
			printf("%c",' ');
		for (j = 0; j<i; j++)
			printf("%c", ch + j);
		for (j = i - 2; j >= 0; j--)
			printf("%c", ch + j);
		printf("\n");
	}

	return 0;
}
