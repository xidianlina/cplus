#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	float height;
	char name[40];

	printf("Please enter your height by inches : ");
	scanf("%f", &height);
	printf("Please enter your name : ");
	scanf("%s", name);
	printf("%s,you are %f feet tall\n", name, height / 12);

	return 0;
}