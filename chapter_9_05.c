#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void larger_of(double*, double*);

int main(void)
{
	double x, y;

	printf("Please enter two doubles:");
	scanf("%lf %lf", &x, &y);
	larger_of(&x, &y);
	printf("The result is: a = %lf,b = %lf\n", x, y);

	return 0;
}

void larger_of(double *x, double *y)
{
	double max = *x > *y ? *x : *y;
	*x = max;
	*y = max;
}