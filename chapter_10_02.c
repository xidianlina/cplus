#include <stdio.h>
#define SIZE 5

void copy_arr(double[], double[], int);
void copy_ptr(double*, double*, int);
void copy_ptrs(double*, double*, double*);
void show_arr(double*, int);

int main(void)
{
	double source[SIZE] = { 1.1,2.2,3.3,4.4,5.5 };
	double target1[SIZE];
	double target2[SIZE];
	double target3[SIZE];

	printf("Show source:\n");
	show_arr(source, SIZE);
	copy_arr(target1, source, SIZE);
	copy_ptr(target2, source, SIZE);
	copy_ptrs(target3, source, source + SIZE);
	printf("Show target1:\n");
	show_arr(target1, SIZE);
	printf("Show target2:\n");
	show_arr(target2, SIZE);
	printf("Show target3:\n");
	show_arr(target3, SIZE);

	return 0;
}

void copy_arr(double target1[], double source[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		target1[i] = source[i];
}

void copy_ptr(double *target2, double *source, int n)
{
	int i;

	for (i = 0; i < n; i++)
		*(target2 + i) = *(source + i);
}

void copy_ptrs(double *target3, double *begin, double *end)
{
	while (begin < end)
		*target3++ = *begin++;
}

void show_arr(double *arr, int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%5.1lf", *(arr + i));
	putchar('\n');
}