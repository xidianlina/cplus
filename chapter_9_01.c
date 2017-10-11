#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double min(double, double);

int main(void)
{
	double a, b;

	printf("Please enter two doubles:");
	scanf("%lf %lf", &a, &b);
	printf("The smaller is %lf\n", min(a, b));

	return 0;
}

double min(double a, double b)
{
	return a < b ? a : b;
}