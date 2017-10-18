#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define M 8*sizeof(int)+1

char *extend(char *, char *);
char *reverse(char *, char *);
char *and(char *, char *, char *);
char * or (char *, char *, char *);
char *exclusive_or(char *, char *, char *);

int main(int argc,char *argv[])
{
	char x[M], y[M], z[M];

	printf("    x = %s\n", extend(x, argv[1]));
	printf("    y = %s\n", extend(y, argv[2]));
	printf("   ^x = %s\n", reverse(z, x));
	printf("   ^y = %s\n", reverse(z, y));
	printf("x & y = %s\n", and (z, x, y));
	printf("x | y = %s\n", or (z, x, y));
	printf("x ^ y = %s\n", exclusive_or(z, x, y));

	return 0;
}

char *extend(char *dest, char *source)
{
	unsigned int i;

	for (i = 0; i < M - 1 - strlen(source); i++)
		dest[i] = '0';
	dest[i] = '\0';
	strcat(dest, source);

	return dest;
}

char *reverse(char *dest, char *source)
{
	char *save = dest;

	strcpy(dest, source);
	while (*dest != '\0')
	{
		if (*dest == '0')
			*dest = '1';
		else
			*dest = '0';
		dest++;
	}

	return save;
}

char *and(char *dest, char *source1, char *source2)
{
	char *save = dest;

	while (*source1 != '\0')
	{
		if (*source1 == '1'&&*source2 == '1')
			*dest = '1';
		else
			*dest = '0';
		source1++;
		source2++;
		dest++;
	}

	return save;
}

char * or (char *dest, char *source1, char *source2)
{
	char *save = dest;

	while (*source1 != '\0')
	{
		if (*source1 == '1' || *source2 == '1')
			*dest = '1';
		else
			*dest = '0';
		source1++;
		source2++;
		dest++;
	}

	return save;
}

char *exclusive_or(char *dest, char *source1, char *source2)
{
	char *save = dest;

	while (*source1 != '\0')
	{
		if (*source1 != *source2)
			*dest = '1';
		else
			*dest = '0';
		source1++;
		source2++;
		dest++;
	}

	return save;
}