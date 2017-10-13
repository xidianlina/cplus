#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 40

char * mystrncpy(char *, char *, int);

int main(void)
{
	char s1[SIZE];
	char s2[SIZE];
	int num;

	printf("Please enter the first string (q to quit):\n");
	while (strcmp(gets(s1), "q"))
	{
		printf("Please enter the second string:\n");
		gets(s2);
		printf("Please enter the number of char copied from s2:");
		scanf("%d", &num);
		getchar();
		if (strlen(s2) >= num)
			s1[strlen(s1) + num] = '\0';
		puts(mystrncpy(s1, s2, num));
		printf("Please enter the first string (q to quit):\n");
	}
	puts("Bye");

	return 0;
}

char *mystrncpy(char *s1, char *s2, int n)
{
	int i = 1;
	char *p = s1;

	while (*s1++)
		continue;
	*--s1 = *s2;
	while (i < n&&*s2)
	{
		*++s1 = *++s2;
		i++;
	}

	return p;
}