#include <stdio.h>
#define SIZE 7

void copy_ptrs(double*, double*, double*);
void show_arr(double*, int);

int main(void)
{
	double source[SIZE] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7 };
	double target[3];

	printf("Show source:\n");
	show_arr(source, SIZE);
	copy_ptrs(target, source+2, source + 5);
	printf("Show target:\n");
	show_arr(target, 3);

	return 0;
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