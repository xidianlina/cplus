#include <stdio.h>
#define SIZE 5

void copy_arr(double[][SIZE], double[][SIZE], int rows);
void show_arr(double[][SIZE], int rows);

int main(void)
{
	double source[3][SIZE] = {
		{1,2,3,4,5},
		{2,3,4,5,6},
		{3,4,5,6,7}
	};
	double target[3][SIZE];

	printf("Source array:\n");
	show_arr(source, 3);
	copy_arr(target, source, 3);
	printf("Target array:\n");
	show_arr(target, 3);

	return 0;
}

void copy_arr(double target[][SIZE], double source[][SIZE], int rows)
{
	int i, j;

	for (i = 0; i < rows; i++)
		for (j = 0; j < SIZE; j++)
			target[i][j] = source[i][j];
}

void show_arr(double arr[][SIZE], int rows)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < SIZE; j++)
			printf("%5.1lf", arr[i][j]);
		putchar('\n');
	}
}