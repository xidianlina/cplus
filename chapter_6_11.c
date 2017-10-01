#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int arr[8];
	int i;

	printf("Please enter 8 integers :");
	for (i = 0; i < 8; i++)
		scanf("%d", &arr[i]);
	for (i = 7; i >= 0; i--)
		printf("%5d", arr[i]);
	printf("\n");

	return 0;
}