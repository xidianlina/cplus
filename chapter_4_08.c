#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define GALLON 3.785
#define MILE 1.609

int main(void)
{
	float mile, gallon;
	printf("Please input miles and gallons : ");
	scanf("%f%f", &mile, &gallon);
	printf("Miles per gallon:%.1f\n", mile / gallon);
	printf("Lites per 100 kilometre:%.1f\n", gallon*GALLON / (100 * mile*MILE));

	return 0;
}