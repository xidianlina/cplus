#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define D_PER_W 7

int main(void)
{
	int days;
	int weeks;
	int left;

	printf("Please enter days :");
	scanf("%d", &days);
	while (days > 0)
	{
		weeks = days / D_PER_W;
		left = days%D_PER_W;
		printf("%d days are %d weeks, %d days.\n", days, weeks, left);
		printf("Please enter next days :");
		scanf("%d", &days);
	}
	printf("Bye!\n");

	return 0;
}