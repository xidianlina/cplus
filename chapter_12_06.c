#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
#define SIZE_N 10
#define SIZE_S 10

int main(void)
{
	int i, j;
	int times[SIZE_N];

	unsigned int seed[SIZE_S] = { 1,2,3,4,5,6,7,8,9,10 };
	for (i = 0; i < SIZE_S; i++)
	{
		for (j = 0; j < SIZE_N; j++)
			times[j] = 0;
		srand(seed[i]);
		printf("seed = %d:\n", seed[i]);
		for (j = 0; j < SIZE; j++)
			times[rand() % 10]++;
		for (j = 0; j < SIZE_N; j++)
		{
			printf("%d:%-5d ", j + 1, times[j]);
			if (j == 4)
				printf("\n");
		}
		printf("\n");
	}

	return 0;
}