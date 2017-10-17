#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct month {
	char name[10];
	char abbrev[4];
	int days;
	int monumb;
};

struct month months[12]=
{
	{"January","jan",31,1},
	{"February","feb",28,2},
	{"March","mar",31,3},
	{"April","apr",30,4},
	{"May","may",31,5},
	{"June","jun",30,6},
	{"July","jul",31,7},
	{"August","aug",31,8},
	{"September","sep",30,9},
	{"October","oct",31,10},
	{"November","nov",30,11},
	{"December","dec",31,12}
};

int days(char *month);

int main(void)
{
	char input[10];
	int total;

	printf("Enter the name of a month:");
	while (gets(input) != NULL&&input[0] != '\0')
	{
		total = days(input);
		if (total > 0)
			printf("There are %d days through %s.\n", total, input);
		else
			printf("%s is not valid input.\n", input);
		printf("Next month (empty line to quit):");
	}
	puts("Bye");

	return 0;
}

int days(char *month)
{
	int i = 0, total = 0;

	for (i = 0; i < 12; i++)
	{
		total += months[i].days;
		if (strcmp(month, months[i].name) == 0)
			return total;
	}

	return -1;
}