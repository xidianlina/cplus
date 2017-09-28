#include <stdio.h>

int main(void)
{
	int years;
	int days;

	years = 29;
	days = 365 * years;
	printf("An age of %d years is %d days.\n", years, days);

	return 0;
}