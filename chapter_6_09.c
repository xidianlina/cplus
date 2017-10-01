#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double cal(double, double);

int main(void)
{
	double num1, num2;
	printf("Please enter tow numbers :");
	while (2 == scanf("%lf%lf", &num1, &num2))
	{
		printf("%lf\n", cal(num1, num2));
		printf("Please enter next two numbers :");
	}
	printf("Bye!\n");

	return 0;
}

double cal(double num1, double num2)
{
	return (num1 - num2) / (num1*num2);
}