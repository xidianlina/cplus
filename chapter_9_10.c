#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void to_base_n(unsigned long, unsigned int);

int main(void)
{
	unsigned long number;
	unsigned int base;

	printf("Enter an integer and the base from 2 to 10 (q to quit):");
	while (2 == scanf("%lu%lu", &number, &base))
	{
		printf("%lu's base %lu equivalent is ", number, base);
		to_base_n(number, base);
		printf("\nEnter your next pair of numbers (q to quit):");
	}
	printf("Done.\n");

	return 0;
}

void to_base_n(unsigned long n, unsigned int base)
{
	int r;

	r = n%base;
	if (n >= base)
		to_base_n(n / base, base);
	printf("%d", r);
}