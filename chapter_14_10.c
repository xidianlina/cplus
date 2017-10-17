#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FUN 4

float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);
char *s_gets(char *, int);

int main(void)
{
	char command[5];
	float x, y;
	float(*p[FUN])(float x, float y) = { add,subtract,multiply,divide };

	while (1)
	{
		printf("Select function:\n");
		printf("1 :  x + y\n");
		printf("2 :  x - y\n");
		printf("3 :  x * y\n");
		printf("4 :  x / y\n");
		printf("q :  quit\n");
		s_gets(command,5);
		if (command[0] < '1' || command[0] > '4') 
			break;
		printf("input x, y:");
		scanf("%f%f", &x, &y);
		getchar();
		printf("result is %g\n", (*p[command[0] - '1'])(x, y));
	}
	
	return 0;
}

float add(float x, float y)
{
	return x + y;
}

float subtract(float x, float y)
{
	return x - y;
}

float multiply(float x, float y)
{
	return x * y;
}

float divide(float x, float y)
{
	return x / y;
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