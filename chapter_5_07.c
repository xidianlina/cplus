#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float cube(float);

int main(void)
{
	float num;
	printf("Please enter the number:");
	scanf("%f", &num);
	printf("The cube of %f is %f\n", num, cube(num));

	return 0;
}

float cube(float num)
{
	return num*num*num;
}