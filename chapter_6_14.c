#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 8

int main(void)
{
	double arr1[SIZE];
	double arr2[SIZE];
	int index;

	for (index = 0; index < SIZE; index++)
	{
		printf("Please enter the %d element in array:", index + 1);
		scanf("%lf", &arr1[index]);
	}
	arr2[0] = arr1[0];
	for (index = 1; index < SIZE; index++)
		arr2[index] = arr2[index - 1] + arr1[index];

	for (index = 0; index < SIZE; index++)
		printf("%6.2lf", arr1[index]);
	printf("\n");
	for (index = 0; index < SIZE; index++)
		printf("%6.2lf", arr2[index]);
	printf("\n");

	return 0;
}