#include <stdio.h>
#define DUNBAR 150

int main(void)
{
	int friend;
	int week;

	for (friend = 5, week = 1; friend < DUNBAR; week++)
	{
		friend = (friend - week) * 2;
		printf("The %d week Rabnud has %d friends.\n", week, friend);
	}

	return 0;
}