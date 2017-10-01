#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 255

int main(void)
{
	int index;
	char s[SIZE];

	for (index = 0, scanf("%c", &s[0]); s[index] != '\n';)
	{
		index++;
		scanf("%c", &s[index]);
	}
	
	for (index += 1; index < SIZE; index++)
		s[index] = '\0';

	for (index = strlen(s); index >= 0; index--)
		printf("%c", s[index]);
	printf("\n");

	return 0;
}