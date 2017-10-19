#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 20

void random_pick(const int [], int size, int number);

int main(void)
{
	int i, member[SIZE], number;

	srand(time(0));
	printf("the array members are:\n");
	for (i = 0; i<SIZE; i++)
	{
		member[i] = 100 + i;
		printf("%d\t", member[i]);
	}
	printf("\ninput the size you want to pick (q to quit):");
	while (scanf("%d", &number) == 1)
	{
		random_pick(member, SIZE, number);
		printf("input the size you want to pick (q to quit):");
	}

	return 0;
}

void random_pick(const int ar[], int size, int n)
{
	int i;
	int count;
	int index;
	int acpy[SIZE];

	//创建一个数组副本，避免修改原始数组
	memcpy(acpy, ar, SIZE * sizeof(int));
	if (n > size)
		printf("The number is too big.\n");
	else
	{
		for (count = 0; count < n; count++)
		{
			index = rand() % size;
			printf("%d ", acpy[index]);
			for (i = index; i < size - 1; i++)
			{
				acpy[i] = acpy[i + 1];
			}
			size--;
		}
		printf("\n");
	}
}