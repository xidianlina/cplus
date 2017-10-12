#include <stdio.h>
#define SIZE 5

void sort_arr(double[], int);
void show_arr(double[], int);

int main(void)
{
	double arr[SIZE] = { 0.5,9.3,8.4,2.1,4.2 };

	show_arr(arr, SIZE);
	sort_arr(arr, SIZE);
	show_arr(arr, SIZE);

	return 0;
}

void sort_arr(double arr[], int n)
{
	int i, j;
	double tmp;

	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			if (arr[i] < arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
}

void show_arr(double arr[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%5.1lf", arr[i]);
	putchar('\n');
}