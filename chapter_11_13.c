#include <stdio.h>

int main(int argc, char *argv[])
{
	int cnt;

	if (argc < 2)
		printf("No arguments!");

	for (cnt = argc - 1; cnt > 0; cnt--)
		printf("%s ", argv[cnt]);
	putchar('\n');

	return 0;
}