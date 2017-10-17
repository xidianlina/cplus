#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

char *s_gets(char *, int);
void sort_title(struct book*, int);
void sort_value(struct book*, int);

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index;

	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS&&s_gets(library[count].title, MAXTITL) != NULL&&library[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf("Enter the next title.\n");
	}

	if (count > 0)
	{
		printf("Here is the list of your books:\n");
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);

		printf("\nHere is the list of your books by title:\n");
		sort_title(&library[0], count);
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);

		printf("\nHere is the list of your books by value:\n");
		sort_value(&library[0], count);
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
	}
	else
		printf("No books? Too bad.\n");

	return 0;
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

void sort_title(struct book *books, int n)
{
	int i, j;
	struct book tmp;

	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			if (strcmp(books[j].title, books[i].title) < 0)
			{
				tmp = books[i];
				books[i] = books[j];
				books[j] = tmp;
			}
}

void sort_value(struct book *books, int n)
{
	int i, j;
	struct book tmp;

	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			if (books[i].value > books[j].value)
			{
				tmp = books[i];
				books[i] = books[j];
				books[j] = tmp;
			}
}