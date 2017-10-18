#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int res = 0;
	int num;

	puts("Enter a integer: ");
	scanf("%d", &num);

	while (num > 0)
	{
		num = num&(num - 1);
		res++;
	}
	printf("The integer has %d one.\n",res);

	return 0;
}