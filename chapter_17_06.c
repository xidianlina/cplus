#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

bool binary_search(int arr[], int, int);

int table[SIZE] = { 3,23,35,37,41,59,65,70,81,90 };

int main(void)
{
	int i;

	for (i = 0; i < 100; i++)
		if (binary_search(table, SIZE, i))
			printf("%d ", i);
	putchar('\n');

	return 0;
}

bool binary_search(int arr[], int max, int n)
{
	int low = 0;
	int high = max - 1;
	int mid = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] > n)
			high = mid - 1;
		else if (arr[mid] < n)
			low = mid + 1;
		else
			return true;
	}

	return false;
}