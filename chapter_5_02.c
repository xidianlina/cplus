#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num, count;
	printf("Please enter a number :");
	scanf("%d", &num);
	count = 0;
	while (count++ < 11)
	{
		printf("%5d", num);
		num++;
	}
	printf("\n");

	return 0;
}