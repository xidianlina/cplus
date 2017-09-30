#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define CM_PER_FEET 30.48
#define CM_PER_INCH 2.54

int main(void)
{
	int feet;
	float cm, inch;
	printf("Enter a height centimeters:");
	scanf("%f", &cm);
	while (cm > 0)
	{
		feet = (int)(cm / CM_PER_FEET);
		inch = (cm - feet*CM_PER_FEET) / CM_PER_INCH;
		printf("%.1f cm = %d feet, %.1f inches\n", cm, feet, inch);
		printf("Enter a height centimeters (<=0 to quit): ");
		scanf("%f", &cm);
	}
	printf("bye\n");

	return 0;
}