#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	float f;
	printf("Please enter a float : ");
	scanf("%f", &f);
	printf("a.The input is %.1f or %.1e\n", f, f);
	printf("b.The input is %+.3f or %.3E\n", f, f);

	return 0;
}