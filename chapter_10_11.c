#include <stdio.h>
#define COLS 5

void show_arr(double[][COLS], int);
void double_arr(double[][COLS], int);

int main(void)
{
	double arr[3][COLS] = {
		{1.1,2.2,3.3,4.4,5.5},
		{2.2,3.3,4.4,5.5,6.6},
		{3.3,4.4,5.5,6.6,7.7}
	};

	printf("Original array is:\n");
	show_arr(arr, 3);
	double_arr(arr, 3);
	printf("Double array is:\n");
	show_arr(arr, 3);

	return 0;
}

void show_arr(double arr[][COLS], int rows) 
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < COLS; j++)
			printf("%5.1lf", arr[i][j]);
		putchar('\n');
	}
}

void double_arr(double arr[][COLS], int rows)
{
	int i, j;

	for (i = 0; i < rows; i++)
		for (j = 0; j < COLS; j++)
			arr[i][j] *= 2;
}