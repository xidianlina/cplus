#include <stdio.h>
#define SIZE 3

void copy_arr(double[], double[], int);
void show_arr(double [][SIZE], int);

int main(void)
{
	double arr[2][SIZE] = { {3,5,9},{0,2,1} };
	double target[2][SIZE];
	int i;

	show_arr(arr, 2);
	for (i = 0; i < 2; i++)
		copy_arr(target[i], arr[i], SIZE);
	show_arr(target, 2);

	return 0;
}

void show_arr(double arr[][SIZE], int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < SIZE; j++)
			printf("%5.2lf", arr[i][j]);
		putchar('\n');
	}
}

void copy_arr(double target[], double source[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		target[i] = source[i];
}