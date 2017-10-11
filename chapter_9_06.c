#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sort_three(double*, double*, double*);

int main(void)
{
	double x, y, z;

	printf("Please enter three doubles:");
	scanf("%lf %lf %lf", &x, &y, &z);
	sort_three(&x, &y, &z);
	printf("The first is %lf,the second is %lf,and the third is %lf\n", x, y, z);

	return 0;
}

void sort_three(double *x, double *y, double *z)
{
	double temp;

	if (*y < *x)
	{
		temp = *x;
		*x = *y;
		*y = temp;
	}
	if (*z < *x)
	{
		temp = *x;
		*x = *z;
		*z = temp;
	}
	if (*z < *y)
	{
		temp = *z;
		*z = *y;
		*y = temp;
	}
}