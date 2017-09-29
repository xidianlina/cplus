#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	float speed;
	float size;

	printf("Please enter speed : ");
	scanf("%f", &speed);
	printf("Please enter size : ");
	scanf("%f", &size);
	printf("At %f megabits per second, a file of %f megabytes\n"
		"downloads in %f seconds.\n", speed, size, size / speed);

	return 0;
}