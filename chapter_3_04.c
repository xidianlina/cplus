#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	float f;

	printf("Enter a floating-point value: ");
	scanf("%f", &f);
	printf("fixed-point notation: %f\n", f);
	printf("exponential notation: %e\n", f);
	printf("p notation: %a\n", f);

	return 0;
}