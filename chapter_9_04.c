#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double average(double, double);

int main(void)
{
	double x, y;

	printf("Please enter two doubles:");
	scanf("%lf %lf", &x, &y);
	printf("1/((1/x+1/y)/2) = %lf\n", average(x, y));

	return 0;
}

double average(double x, double y)
{
	return 1 / ((1 / x + 1 / y) / 2);
}