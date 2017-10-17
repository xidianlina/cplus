#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define FLIGHT 4
#define SEAT 12

void read_file(struct flight *p, char* filename);
void load_data(struct flight *p);
int choose_flight(void);
int choose_command(struct flight *p);
void show_number_empty(struct seat *p);
void show_list_empty(struct seat *p);
void show_list(struct seat *p);
void assign_seat(struct seat *p);
void delete_seat(struct seat *p);
void confirm_seat(struct seat *p);
void write_file(struct flight *p, char* filename);
char *s_gets(char *, int);

struct seat {
	int number;
	int assign;
	char lastname[10];
	char firstname[10];
};

struct flight {
	int number;
	struct seat seats[SEAT];
};

struct flight flights[4] = {
	{ 102 },
	{ 311 },
	{ 444 },
	{ 519 }
};

int main(void)
{
	int n;
	read_file(flights, "seat.dat");
	while (1)
	{
		n = choose_flight();
		if (n<0 || n >= FLIGHT) 
			break;
		while (choose_command(&flights[n]))
			continue;
	}
	write_file(flights, "seat.dat");
	puts("Quit");

	return 0;
}

void read_file(struct flight *p, char* filename)
{
	FILE * pseats;
	if ((pseats = fopen(filename, "rb")) == NULL)
	{
		printf("Can't open %s file. So load default data.\n", filename);
		load_data(p);
	}
	else
	{
		rewind(pseats);            
		while (fread(p, sizeof(struct flight), FLIGHT, pseats) == 1)
			continue;
		fclose(pseats);
		printf("read %s successfully!\n", filename);
	}
}

void load_data(struct flight *p)//载入默认数据
{
	int i, j;
	for (i = 0; i<FLIGHT; i++)
		for (j = 0; j<SEAT; j++)
		{
			p[i].seats[j].number = i * 100 + j;//按实际情况设置座位号
			p[i].seats[j].assign = 0;
		}
}

int choose_flight(void)//返回航班下标
{
	char command[10];
	printf("\nTo choose a flight, enter its letter label:\n");
	printf("a) Flights 102\n");
	printf("b) Flights 311\n");
	printf("c) Flights 444\n");
	printf("d) Flights 519\n");
	printf("e) Quit\n");
	s_gets(command,10);
	switch (command[0])
	{
		case 'a': 
			return 0;
		case 'b':
			return 1;
		case 'c': 
			return 2;
		case 'd': 
			return 3;
		default: 
			return 4;
	}
}

int choose_command(struct flight *p)
{
	char command[10];
	printf("\nFlight %d:\n", p->number);
	printf("To choose a function, enter its letter label:\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Confirm a seat assignment\n");
	printf("g) Exit to the top-level menu\n");
	s_gets(command,10);
	switch (command[0])
	{
		case 'a':
			show_number_empty(p->seats);
			return 1;
		case 'b': 
			show_list_empty(p->seats); 
			return 1;
		case 'c': 
			show_list(p->seats);  
			return 1;
		case 'd': 
			assign_seat(p->seats); 
			return 1;
		case 'e':
			delete_seat(p->seats); 
			return 1;
		case 'f':
			confirm_seat(p->seats); 
			return 1;
		default: return 0;
	}
}

void show_number_empty(struct seat *p)
{
	int i, n;
	for (i = 0, n = 0; i<SEAT; i++)
		if (p[i].assign == 0)
			n++;
	printf("There are %d empty seats\n", n);
}

void show_list_empty(struct seat *p)
{
	int i;
	printf("empty seats:\n");
	for (i = 0; i<SEAT; i++)
		if (p[i].assign == 0)
			printf("number %d\n", p[i].number);
}

void show_list(struct seat *p)
{
	int i;
	printf("seat list:\n");
	for (i = 0; i<SEAT; i++)
	{
		printf("number %d\t", p[i].number);
		if (p[i].assign == 1)
			printf("full    %s %s\n", p[i].firstname, p[i].lastname);
		else
			printf("empty\n");
	}
}

void assign_seat(struct seat *p)
{
	int number, i;
	printf("Input the seat number:");
	scanf("%d", &number);
	getchar();
	for (i = 0; i<SEAT; i++)
		if (p[i].number == number)
		{
			if (p[i].assign == 1)
				printf("NO.%d seat is already assigned!\n", p[i].number);
			else
			{
				printf("Input firstname of the holder:");
				scanf("%s", p[i].firstname);
				printf("Input lastname of the holder:");
				scanf("%s", p[i].lastname);
				getchar();
				p[i].assign = 1;
				printf("assign NO.%d seat successfully!\n", p[i].number);
			}
			return;
		}
	printf("%d is a invalid seat number!\n", number);
}

void delete_seat(struct seat *p)
{
	int number, i;
	printf("Input the seat number:");
	scanf("%d", &number);
	getchar();
	for (i = 0; i<SEAT; i++)
		if (p[i].number == number)
		{
			if (p[i].assign == 0)
				printf("NO.%d seat is already empty!\n", number);
			else
			{
				p[i].assign = 0;
				printf("delete NO.%d seat successfully!\n", number);
			}
			return;
		}
	printf("%d is a invalid seat number\n", number);
}

void confirm_seat(struct seat *p)
{
	int number, i;
	printf("Input the seat number:");
	scanf("%d", &number);
	getchar();
	for (i = 0; i<SEAT; i++)
		if (p[i].number == number)
		{
			if (p[i].assign == 0)
				printf("NO.%d seat is empty!\n", number);
			else
				printf("NO.%d seat is assigned! its holder is %s %s\n", number, p[i].firstname, p[i].lastname);
			return;
		}
	printf("%d is a invalid seat number\n", number);
}

void write_file(struct flight *p, char* filename)
{
	FILE * pseats;
	if ((pseats = fopen(filename, "wb")) == NULL)
	{
		printf("Can't open %s file.", filename);//将文件以可写模式打开，没有则创造，清空文件内容
		exit(1);
	}
	fwrite(p, sizeof(struct seat), SEAT*FLIGHT, pseats);
	fclose(pseats);
}


char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}