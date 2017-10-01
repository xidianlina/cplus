#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int min;
	int max;
	int sum;
	int i;

	printf("Enter lower and upper integer limits:");
	scanf("%d%d", &min, &max);
	while (min < max)
	{
		for (sum=0, i = min; i <= max; i++)
			sum += i*i;
		printf("The sums of the squares from %d to %d is %d\n", min*min, max*max, sum);
		printf("Enter next set of limits:");
		scanf("%d%d", &min, &max);
	}
	printf("Done\n");

	return 0;
}