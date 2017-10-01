#include <stdio.h>

int main(void)
{
	char ch;
	int i;
	char arr[26];

	for (i = 0, ch = 'a'; ch <= 'z'; i++, ch++)
		arr[i] = ch;
	for (i = 0; i < 26; i++)
		printf("%2c", arr[i]);
	printf("\n");

	return 0;
}