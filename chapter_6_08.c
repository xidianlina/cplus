#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double num1, num2;
	printf("Please enter two numbers :");
	while (2 == scanf("%lf%lf", &num1, &num2))
	{
		printf("%lf\n", (num1 - num2) / (num1*num2));
		printf("Please enter next two numbers :");
	}
	printf("Bye!\n");

	return 0;
	
}