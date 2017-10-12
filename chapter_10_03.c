#include <stdio.h>

int max_in_arr(int*, int);

int main(void)
{
	int arr[] = { 9,0,4,3,1,5,2,12 };
	int max;

	max = max_in_arr(arr, sizeof arr / sizeof arr[0]);
	printf("The max value of array is %d.\n", max);

	return 0;
}

int max_in_arr(int *arr, int n)
{
	int max = *arr;
	int i;

	for (i = 1; i < n; i++)
		if (max < *(arr + i))
			max = *(arr + i);

	return max;
}