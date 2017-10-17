#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 10
#define NLEN 20
#define SIZE 20

struct member {
	int num;
	char fname[LEN];
	char lname[LEN];
	int play;
	int hit;
	int walk;
	int rbi;
	float average;
};

void get_initial(struct member*);
void get_data(struct member*);
void cal_average(struct member*);
void display(struct member*);

int main(void)
{
	static struct member members[SIZE];

	get_initial(members);
	get_data(members);
	cal_average(members);
	display(members);

	return 0;
}

void get_initial(struct member *pst)
{
	int i;

	for (i = 0; i <SIZE; i++)
	{
		pst[i].num = 0;
		strcpy(pst[i].fname, "");
		strcpy(pst[i].lname, "");
		pst[i].play = 0;
		pst[i].hit = 0;
		pst[i].walk = 0;
		pst[i].rbi = 0;
		pst[i].average = 0;
	}
}

void get_data(struct member *pst)
{
	int number, play, hit, walk, rbi;
	FILE *fp;
	char name[NLEN];
	char f_name[LEN], l_name[LEN];

	printf("Please enter the file name:");
	scanf("%s", name);
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s", name);
		exit(EXIT_FAILURE);
	}
	while (fscanf(fp, "%d%s%s%d%d%d%d", &number, f_name, l_name, &play, &hit, &walk, &rbi) == 7)
	{
		pst[number].num = number;
		strcpy(pst[number].fname, f_name);
		strcpy(pst[number].lname, l_name);
		pst[number].play += play;
		pst[number].hit += hit;
		pst[number].walk += walk;
		pst[number].rbi += rbi;
	}
	fclose(fp);
}

void cal_average(struct member *pst)
{
	int i;
	
	for (i = 0; i < SIZE; i++)
		if (pst[i].play)
			pst[i].average = (float)pst[i].hit / (float)pst[i].play;
}

void display(struct member*pst)
{
	int i;
	struct member total = {"","",0,0,0,0,0 };

	printf("%7s%10s%10s%5s%5s%5s%5s%10s\n", "number", "firstname", "lastname", "play", "hit", "walk", "RBI", "average");

	for (i = 0; i < SIZE; i++)
		if (pst[i].play)
		{
			printf("%7d%10s%10s%5d%5d%5d%5d%10g\n", pst[i].num, pst[i].fname, pst[i].lname, pst[i].play, pst[i].hit, pst[i].walk, pst[i].rbi, pst[i].average);
			total.play += pst[i].play;
			total.hit += pst[i].hit;
			total.walk += pst[i].walk;
			total.rbi += pst[i].rbi;
		}
	if (total.play)
		total.average = (float)total.hit / (float)total.play;
	printf("%27s%5d%5d%5d%5d%10g\n", "total team", total.play, total.hit, total.walk, total.rbi, total.average);
}