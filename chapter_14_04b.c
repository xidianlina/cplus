#include <stdio.h>
#define SIZE 5

void display(struct persons[]);

struct names {
	char fname[20];
	char mname[20];
	char lname[20];
};

struct persons {
	int number;
	struct names name;
};

struct persons person[SIZE] = {
	{ 3020,{ "Dribble","Mackede","Flossie" } },
	{ 8732,{ "Gadenfs","Kasdfd","Pakd" } },
	{ 7899,{ "Kadkjf","Akeiu","Ekdfj" } },
	{ 5676,{ "Adj","Ydkj","Ldfakj" } },
	{ 9209,{ "Qkjdj","","Tfdj" } }
};

int main(void)
{
	display(person);

	return 0;
}

void display(struct persons p[])
{
	int i;

	for (i = 0; i < SIZE; i++)
		if (p[i].name.mname[0] != '\0')
			printf("%s, %s %c. -- %d\n", p[i].name.fname, p[i].name.lname, p[i].name.mname[0], p[i].number);
		else
			printf("%s,%s -- %d\n", p[i].name.fname, p[i].name.lname, p[i].number);
}