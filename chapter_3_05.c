#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int age;
	double seconds;

	printf("Please enter your age: ");
	scanf("%d", &age);
	seconds = age * 3, 156e7;
	printf("the corresponding seconds are: %e\n", seconds);

	return 0;
}