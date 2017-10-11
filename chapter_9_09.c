#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double power(double, int);

int main(void)
{
	double x;
	int exp;
	printf("Please enter a double and a integer:");
	while (2 == scanf("%lf%d", &x, &exp))
	{
		printf("%.3g to the power %d is %.5g\n", x, exp, power(x, exp));
		printf("Please enter a double and a integer:");
	}

	return 0;
}

double power(double x, int exp)
{
	int i;
	double pow;

	if (exp > 0)
		pow = x*power(x, exp - 1);
	else if (exp < 0)
		if (x != 0)
			pow = (1.0 / x)*power(x, exp + 1);
		else
			pow = 0;
	else
		pow = 1;

	return pow;
}