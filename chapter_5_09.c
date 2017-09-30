#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Temperatures(double);

int main(void)
{
	double fah;
	printf("Please enter the Fahrenheit:");
	while (scanf("%lf", &fah) == 1)
	{
		Temperatures(fah);
		printf("Please enter the Fahrenheit:");
	}
	printf("End\n");

	return 0;
}

void Temperatures(double fah)
{
	const double A = 1.8, B = 32.0, C = 273.16;
	printf("Fahrenheit = %lf\t", fah);
	printf("Celsius = %lf\t", fah + B);
	printf("Kelvin = %lf\n", A + fah + B + C);
}