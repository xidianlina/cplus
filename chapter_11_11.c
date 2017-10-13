#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIM 10
#define SIZE 80

char * s_gets(char * st, int n);		//��ȡ�ַ�������
char get_choice(void);			//��ȡѡ��
void print_sour(char * st[], int n);		//��ӡԴ�ַ���
void print_ascii(char * st[], int n);		//��ASCII��˳���ӡ
void print_length(char * st[], int n);		//������˳���ӡ
void print_first_word(char * st[], int n);	//����һ�����ʵĳ���˳���ӡ
int first_word(char * st);			//�����һ��������

int main(void)
{
	char str[LIM][SIZE];
	char * ptr[LIM];
	int row = 0;				//������ַ�������
	char choice;				//�û������ѡ���ַ�

	printf("Input some strings before EOF (no more than 10):\n");
	while (row < LIM && s_gets(str[row], SIZE) != NULL)
	{
		ptr[row] = str[row];		//����ָ��ָ���ַ��� 
		row++;
	}
	while ((choice = get_choice()) != 'q')
	{
		printf("\n");
		switch (choice)
		{
		case 'a': print_sour(ptr, row);
			break;
		case 'b': print_ascii(ptr, row);
			break;
		case 'c': print_length(ptr, row);
			break;
		case 'd': print_first_word(ptr, row);
			break;
		default: printf("Error!\n");
			break;
		}
		printf("\n");
	}
	printf("Bye.\n");

	return 0;
}

//��ȡ�û�ѡ��				
char get_choice(void)
{
	char ch;

	printf("a. print the sourse strings.     b. print in order of ASCII.\n");
	printf("c. print in order of length.	 d. print in order of the first word's length.\n");
	printf("q. quit.\n");
	printf("Enter a character (a, b, c, d or q):");
	ch = getchar();
	while (getchar() != '\n')
		continue;
	while (ch < 'a' || ch > 'd' && ch != 'q')
	{
		printf("Please input the right option (a, b, c, d or q): ");
		ch = getchar();
		while (getchar() != '\n')
			continue;
	}
	return ch;
}

//��ӡԴ�ַ���
void print_sour(char * st[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		puts(st[i]);
}

//��ASCII�е�˳���ӡ�ַ���
void print_ascii(char * st[], int n)
{
	int i, j;
	char * temp;

	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (strcmp(st[i], st[j]) > 0)
			{
				temp = st[j];
				st[j] = st[i];
				st[i] = temp;
			}
	for (i = 0; i < n; i++)
		puts(st[i]);
}

//������˳���ӡ		
void print_length(char * st[], int n)
{
	int i, j;
	char * temp;

	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (strlen(st[i]) > strlen(st[j]))
			{
				temp = st[j];
				st[j] = st[i];
				st[i] = temp;
			}
	for (i = 0; i < n; i++)
		puts(st[i]);
}
//����һ�����ʵĳ���˳���ӡ
void print_first_word(char * st[], int n)
{
	int i, j;
	char * temp;

	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (first_word(st[i]) > first_word(st[j]))
			{
				temp = st[j];
				st[j] = st[i];
				st[i] = temp;
			}
	for (i = 0; i < n; i++)
		puts(st[i]);
}

//�����һ�����ʵĳ���
int first_word(char * st)
{
	int i = 0;
	int count = 0;

	while (!isalpha(st[i]))
		i++;
	while (isalpha(st[i]))
	{
		i++;
		count++;
	}

	return count;
}

//�Զ�������뺯��
char * s_gets(char * st, int n)
{
	int i = 0;
	if (fgets(st, n, stdin) != NULL)	//������ֵst������NULL
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
		return st;
	}
	else
		return NULL;
}