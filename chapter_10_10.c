#include <stdio.h>
#define SIZE 4

void add_arr(int[], int[], int[], int);
void show_arr(int[], int);

int main(void)
{
	int a[SIZE] = { 2,4,5,8 };
	int b[SIZE] = { 1,0,4,6 };
	int target[SIZE];

	printf("The array a is:\n");
	show_arr(a, SIZE);
	printf("The array b is:\n");
	show_arr(b, SIZE);
	add_arr(a, b, target, SIZE);
	printf("The array target is:\n");
	show_arr(target, SIZE);

	return 0;
	
}

void add_arr(int a[], int b[], int target[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		target[i] = a[i] + b[i];
}

void show_arr(int arr[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%5d", arr[i]);
	putchar('\n');
}