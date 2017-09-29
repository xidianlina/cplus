#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char name[40];
	int width;

	printf("Please enter your first name : ");
	scanf("%s", name);
	printf("A:\"%s\"\n", name);
	printf("B:\"%20s\"\n", name);
	printf("C:\"%-20s\"\n", name);
	width = strlen(name) + 3;
	printf("D:\"%*s\"\n", width, name);

	return 0;
}