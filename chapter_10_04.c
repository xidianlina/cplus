#include <stdio.h>

int max_index(double *, int);

int main(void)
{
	double arr[] = { 9.0,0.3,2.0,8.4,3.1,5.6,13.5 };
	int index;

	index = max_index(arr, sizeof arr / sizeof arr[0]);
	printf("The max index of array is %d.\n", index);

	return 0;
}

int max_index(double *arr, int n)
{
	int max = *arr;
	int index = 0;
	int i;

	for (i = 1; i < n; i++)
		if (max < *(arr + i))
			index = i;

	return index;
}