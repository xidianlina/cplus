#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isPrime(int);

int main(void)
{
	int num;
	int i;
	
	printf("Enter a positive number:");
	scanf("%d", &num);
	printf("all the primes <= %d:\n", num);
	for (i = 2; i <= num; i++)
		if (isPrime(i))
			printf("%d\t", i);
	printf("\n");

	return 0;
}

int isPrime(int n)
{
	int div;
	for (div = 2; div*div <= n; div++)
		if (n%div == 0)
			return 0;
	
	return 1;
}