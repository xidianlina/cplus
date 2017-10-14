#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int *make_array(int elm, int val);
void show_array(const int ar[], int n);

int main(void)
{
	int *pa;
	int size;
	int value;

	printf("Enter the number of elements: ");
	while (scanf("%d", &size) == 1 && size > 0)
	{
		printf("Enter the initialization value: ");
		scanf("%d", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of elements (<1 to quit): ");
	}
	printf("Done.\n");

	return 0;
}

int *make_array(int size, int value)
{
	int i;
	int *pt;

	pt = (int *)malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
		pt[i] = value;

	return pt;
}

void show_array(const int ar[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", ar[i]);
		if (i % 8 == 7)
			printf("\n");
	}
	printf("\n");
}