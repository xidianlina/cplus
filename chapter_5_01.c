#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define H_PER_M 60

int main(void)
{
	int hour, minute, left;
	printf("Enter the number of minutes :");
	scanf("%d", &minute);
	while (minute > 0)
	{
		hour = minute / H_PER_M;
		left = minute%H_PER_M;
		printf("%d minutes if %d hours and %d minutes.\n", minute, hour, left);
		printf("Enter your next value :");
		scanf("%d", &minute);
	}

	printf("Good Bye!\n");

	return 0;
}