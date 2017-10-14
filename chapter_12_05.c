#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void print_arr(int[], int);
void sort_arr(int[], int);

int main(void)
{
	int i;
	int digits[SIZE];

	for (i = 0; i < SIZE; i++)
		digits[i] = rand() % 10 + 1;
	printf("The original numbers is:\n");
	print_arr(digits, SIZE);
	sort_arr(digits, SIZE);
	printf("\nThe numbers in reverse order is:\n");
	print_arr(digits, SIZE);

	return 0;
}

void print_arr(int arr[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%3d", arr[i]);
		if (i % 10 == 9)
			printf("\n");
	}
}

void sort_arr(int arr[], int n)
{
	int i, j, tmp;

	for(i=0;i<SIZE;i++)
		for(j=i+1;j<SIZE;j++)
			if (arr[i] < arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
}