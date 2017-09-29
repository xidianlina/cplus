#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double quarts, n;
	double m = 3.0e-23;

	printf("Please enter the number of quarts: ");
	scanf("%lf", &quarts);
	n = quarts * 950 / m;
	printf("the number of water molecules is : %e\n", n);

	return 0;
}