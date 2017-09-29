#include <stdio.h>

int main(void)
{
	int i = 2147483647;
	signed int j = -2147483647;

	printf("%d\n%d\n%d\n", i,i+1,i+2);
	printf("%d\n%d\n%d\n", j, j - 1, j - 2);

	return 0;
}