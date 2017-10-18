#include <stdio.h>
#define SIZE 16

int bin_to_int(char *);
char *s_gets(char *, int);

int main(void)
{
	char pbin[SIZE];

	puts("Enter binary string: ");
	s_gets(pbin, SIZE);
	printf("Binary string %s to int is %d\n", pbin, bin_to_int(pbin));

	return 0;
}

int bin_to_int(char *pbin)
{
	int res = 0;
	
	while (*pbin)
		res = (res << 1) + (*pbin++ - '0');
	
	return res;
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