#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int begin;
	int end;
	int i;

	printf("Please enter a begin number :");
	scanf("%d", &begin);
	printf("Please enter a end number :");
	scanf("%d", &end);
	for (i = begin; i <= end; i++)
		printf("%5d %5d %5d\n", i, i*i, i*i*i);

	return 0;
}