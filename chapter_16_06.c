#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 40
#define NUM 5

struct names {
	char first[SIZE];
	char last[SIZE];
};

void show_array(const struct names[], int);
int comp(const void*, const void*);

int main(void)
{
	int i;
	struct names staff[NUM] = {
		{ "zha", "yujie" },
		{ "xia", "yufeng" },
		{ "bu", "jianqiang" },
		{ "xu", "feifan" },
		{ "ding","bing" }
	};
	
	printf("Original array is :\n");
	show_array(staff, NUM);
	printf("Sorted array is :\n");
	qsort(staff, NUM, sizeof(struct names), comp);
	show_array(staff, NUM);

	return 0;
}

void show_array(const struct names staff[], int n)
{
	int i;

	for (i = 0; i < NUM; i++)
		printf("%s %s\n", staff[i].first, staff[i].last);

	return 0;
}

int comp(const void *p1, const void *p2)
{
	const struct names *ps1 = (const struct names *)p1;
	const struct names *ps2 = (const struct names *)p2;
	int res;

	res = strcmp(ps1->first, ps2->first);
	if (res)
		return res;
	else
		return strcmp(ps1->last, ps2->last);
}