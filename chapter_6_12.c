#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double sum1 = 0, sum2 = 0;
	int cnt, items, sign;

	printf("Please enter the items:");
	scanf("%d", &items);
	for (cnt = 1, sign = 1; cnt <= items; cnt++, sign *= -1)
	{
		sum1 += 1.0 / cnt;
		sum2 += 1.0*sign / cnt;
	}
	printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ... = %f\n", sum1);
	printf("1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ... = %f\n", sum2);

	return 0;
}