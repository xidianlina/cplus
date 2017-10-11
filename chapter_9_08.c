#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double power(double, int);

int main(void)
{
	double x, xpow;
	int exp;

	printf("Enter a number and the integer power (q to quit):\n");
	while (scanf("%lf%d", &x, &exp) == 2)
	{
		xpow = power(x, exp);
		printf("%.3g to the power %d is %g\n", x, exp, xpow);
		printf("Enter the next pair of numbers or q to quit.\n");
	}
	printf("Bye.\n");

	return 0;
}

double power(double x, int exp)
{
	int count;
	double pow = 1;

	if (exp == 0)
	{
		if (x == 0)
			printf("It is not defined.\n");
		else
			return 1.0;
	}
	else if (exp > 0)
	{
		for (count = 0; count < exp; count++)
			pow *= x;
	}
	else
		if (exp != 0)
			for (count = 0; count > exp; count--)
				pow /= x;
		else
			pow = 0.0;

	return pow;
}