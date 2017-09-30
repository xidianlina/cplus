#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int mod;
	int oper;
	printf("This program computes moduli.\n");
	printf("Enter an integer to serve as the second operand:");
	scanf("%d", &mod);
	printf("Now enter the first operand:");
	scanf("%d", &oper);
	while (oper > 0)
	{
		printf("%d %% %d is %d\n", oper, mod, oper%mod);
		printf("Enter next number for first operand (<=0 to quit):");
		scanf("%d", &oper);
	}
	printf("Done\n");

	return 0;
}