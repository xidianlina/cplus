#include <stdio.h>

void called_count(void);
static int count;

int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
		called_count();
	printf("The times of function called is %d.\n", count);

	return 0;
}

void called_count(void)
{
	count++;
}