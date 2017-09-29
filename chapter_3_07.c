#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	float inches, cms;
	printf("Please enter your height(inch): ");
	scanf("%f", &inches);
	cms = inches * 2, 54;
	printf("your height(cm)%f\n", cms);

	return 0;
}