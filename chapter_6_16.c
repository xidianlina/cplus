#include <stdio.h>

#define RATE_DAPHNE 0.1														
#define RATE_DEIRDRE 0.05					
#define	MONEY 100						
int main(void)
{
	int year;
	double daphne = MONEY, deirdre = MONEY;	

	for (year = 1; daphne >= deirdre; year++)
	{
		daphne += MONEY * RATE_DAPHNE;
		deirdre += deirdre * RATE_DEIRDRE;
	}
	printf("After %d year, Deirdre's investment will be more than Daphne's,\n"
		"Daphne's investment will be $%lf,\nand Deirdre's investment will be $%lf.\n",
		year, daphne, deirdre);				

	return 0;
}