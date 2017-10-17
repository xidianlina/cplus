#include <stdio.h>
#include <math.h>

#define M 10

void transform(double[], double[], int, double(*)(double));
double reciprocal(double x);
double negative(double x);

int main(void)
{
	double source[M], target[M];
	int i;

	for (i = 0; i<M; i++)
		source[i] = i+1;

	printf("sin:\n");
	transform(source, target, M, sin);
	for (i = 0; i<M; i++)
		printf("%g -> %g\t", source[i], target[i]);

	printf("\n\nexp:\n");
	transform(source, target, M, exp);
	for (i = 0; i<M; i++)
		printf("%g -> %g\t", source[i], target[i]);

	printf("\n\nreciprocal:\n");
	transform(source, target, M, reciprocal);
	for (i = 0; i<M; i++)
		printf("%g -> %g\t", source[i], target[i]);

	printf("\n\nnegative:\n");
	transform(source, target, M, negative);
	for (i = 0; i<M; i++)
		printf("%g -> %g\t", source[i], target[i]);

	printf("\n");

	return 0;
}


void transform(double source[], double target[], int n, double(*p)(double))
{
	int i;
	for (i = 0; i<n; i++)
		target[i] = (*p)(source[i]);
}

double reciprocal(double x)
{
	return 1 / x;
}

double negative(double x)
{
	return -x;
}