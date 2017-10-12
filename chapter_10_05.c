#include <stdio.h>
#define SIZE 5

double diff_max_min(double[], int);

int main(void)
{
	double arr[SIZE] = { 0.5,9.0,5.3,6.0,1.2 };
	double diff;

	diff = diff_max_min(arr, SIZE);
	printf("The diff between max and min of array is %5.2lf.\n", diff);

	return 0;
}

double diff_max_min(double arr[], int n)
{
	double max = arr[0];
	double min = arr[0];
	int i;

	for (i = 1; i < n; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}

	return max - min;
}