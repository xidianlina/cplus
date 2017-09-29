#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char firstname[40];
	char lastname[40];
	printf("Please enter your first name : ");
	scanf("%s", firstname);
	printf("Please enter your last name : ");
	scanf("%s", lastname);
	printf("Your name is %s,%s\n", firstname, lastname);

	return 0;
}