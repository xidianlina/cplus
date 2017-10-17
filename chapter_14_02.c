#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int days(int day, int month, int year);
int leapyear(int year);

struct month {
	char name[10];
	char abbrev[4];
	int days;
	int monnumb;
};

struct month months[12] =
{
	{ "January","jan",31,1 },
	{ "February","feb",28,2 },
	{ "March","mar",31,3 },
	{ "April","apr",30,4 },
	{ "May","may",31,5 },
	{ "June","jun",30,6 },
	{ "July","jul",31,7 },
	{ "August","aug",31,8 },
	{ "September","sep",30,9 },
	{ "October","oct",31,10 },
	{ "November","nov",30,11 },
	{ "December","dec",31,12 }
};

int main(void)
{
	int day = 1, mon = 12, year = 1, total;

	printf("Enter the number of day,month,year: ");
	while (scanf("%d%d%d", &day, &mon, &year) == 3)
	{
		total = days(day, mon, year);
		if (total > 0)
			printf("There are %d days through day %d,month %d,year %d.\n", total, day, mon, year);
		else
			printf("day %d,month %d,year %d is not valid input.\n", day, mon, year);
		printf("Next month (q to quit): ");
	}
	puts("Bye");

	return 0;
}

int days(int day, int mon, int year)
{
	int i, total;
	
	if (leapyear(year))
		months[1].days = 29;
	else
		months[1].days = 28;
	if (mon < 1 || mon>12 || day<1 || day>months[mon - 1].days)
		return -1;
	else
		for (i = 0, total = 0; i < mon - 1; i++)
			total += months[i].days;

	return (total + day);
}

int leapyear(int year)
{
	if (year % 400 == 0)
		return 1;
	else if (year % 100 != 0 && year % 4 == 0)
		return 1;
	else
		return 0;
}