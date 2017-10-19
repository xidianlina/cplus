#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define AVERAGE(X,Y) (1/((((1/(X))+(1/(Y))))/2))

int main(void)
{
	double x, y;

	puts("Enter two doubles:");
	while (scanf("%lf%lf", &x, &y) == 2)
	{
		printf("Harmonic mean of %g and %g is %g\n", x, y, AVERAGE(x, y));
		puts("Enter next two doubles:");
	}
	puts("Bye!");

	return 0;
}