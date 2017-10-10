#include <stdio.h>

int main(void)
{
	int i;

	for (i = 0; getchar() != EOF; i++);
	printf("There are %d char", i);

	return 0;
}