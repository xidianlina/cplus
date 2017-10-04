#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ARTICHOKE 1.25
#define BEET 0.65
#define CARROT 0.89
#define DISCOUNT_LIMIT 100
#define DISCOUNT_RATE 0.05
#define FREIGHT_FEE1 3.50
#define FREIGHT_LIMIT1 5
#define FREIGHT_FEE2 10.00
#define FREIGHT_LIMIT2 20
#define FREIGHT_FEE3 8
#define FREIGHT_RATE 0.1

int main(void)
{
	char ch;
	double artichoke = 0, beet = 0, carrot = 0;
	double sum, discount, freight;
	printf("Please select your vegetable:a,b,c,q\n");
	printf("a.artichoke price:$%.2f\n", ARTICHOKE);
	printf("b.beet price:$%.2f\n", BEET);
	printf("c.carrot price:$%.2f\n", CARROT);
	printf("q.quit\n");
	printf("(price as dollars per pound)\n");
	while ((ch = tolower(getchar())) != 'q')
	{
		switch (ch)
		{
			case 'a':
				printf("How many pounds of artichokes do you want?");
				scanf("%lf", &artichoke);
				printf("Please select your vegetable:a,b,c,q:");
				break;
			case 'b':
				printf("How many pounds of beets do you want?");
				scanf("%lf", &beet);
				printf("Please select your vegetable:a,b,c,q:");
				break;
			case 'c':
				printf("How many pounds of carrots do you want?");
				scanf("%lf", &carrot);
				printf("Please select your vegetable:a,b,c,q:");
				break;
			defalut:
				break;
		}
	}
	printf("%10s%10s%10s%10s\n", "", "artichoke", "beet", "carrot");
	printf("%10s%10.2lf%10.2lf%10.2lf\n", "price", ARTICHOKE, BEET, CARROT);
	printf("%10s%10.2lf%10.2lf%10.2lf\n","pound", artichoke, beet, carrot);
	printf("%10s%10.2lf%10.2lf%10.2lf\n", "charge", ARTICHOKE*artichoke, BEET*beet, CARROT*carrot);
	sum = ARTICHOKE*artichoke + BEET*beet + CARROT*carrot;
	if (sum > DISCOUNT_LIMIT)
		discount = sum*DISCOUNT_RATE;
	else
		discount = 0;
	printf("discount:%.2f\n", discount);
	if (artichoke + beet + carrot <= 5)
		freight = 3.50;
	else if (artichoke + beet + carrot < 20)
		freight = 10;
	else
		freight = 8 + (artichoke + beet + carrot)*0.1;
	printf("freight:%.2f\n", freight);
	sum = sum - discount + freight;
	printf("sum:%.2f\n", sum);

	return 0;
}