#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num;
	int even;
	int odd;
	int sum_even;
	int sum_odd;

	even = odd = sum_even = sum_odd = 0;
	printf("Please enter numbers (0 to quit):");
	scanf("%d", &num);
	while (num != 0)
	{
		if (num % 2 == 0)
		{
			even++;
			sum_even += num;
		}
		else
		{
			odd++;
			sum_odd += num;
		}
		scanf("%d", &num);
	}
	printf("%d evens and even average is %d.\n", even, sum_even / even);
	printf("%d odds and odd average is %d.\n", odd, sum_odd / odd);

	return 0;
}