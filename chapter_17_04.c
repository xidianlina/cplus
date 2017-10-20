#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <stdbool.h>

typedef struct item {
	long arrive;
	int processtime;
}Item;

#define MAXQUEUE 10

typedef struct node {
	Item item;
	struct node *next;
}Node;

typedef struct queue {
	Node *front;
	Node *rear;
	int items;
}Queue;

void InitializeQueue(Queue * pq);

bool QueueIsFull(const Queue *pq);

bool QueueIsEmpty(const Queue *pq);

int QueueItemCount(const Queue *pq);

bool EnQueue(Item item, Queue *pq);

bool DeQueue(Item *item, Queue *pq);

void EmptyTheQueue(Queue *pq);

#endif

static void CopyToNode(Item item, Node *pn);
static void CopyToItem(Node *pn, Item *pi);

void InitializeQueue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

bool QueueIsFull(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

bool QueueIsEmpty(const Queue *pq)
{
	return pq->items == 0;
}

int QueueItemCount(const Queue *pq)
{
	return pq->items;
}

bool EnQueue(Item item, Queue *pq)
{
	Node *pnew;

	if (QueueIsFull(pq))
	{
		return false;
	}

	pnew = (Node *)malloc(sizeof(Node));
	if (pnew == NULL)
	{
		fprintf(stderr, "Unable to allocate memory!\n");
		exit(1);
	}
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (QueueIsEmpty(pq))
		pq->front = pnew;
	else
		pq->rear->next = pnew;
	pq->rear = pnew;
	pq->items++;

	return true;
}

bool DeQueue(Item *pitem, Queue *pq)
{
	Node *pt;

	if (QueueIsEmpty(pq))
		return false;
	CopyToItem(pq->front, pitem);
	pt = pq->front;
	pq->front = pq->front->next;
	free(pt);
	pq->items--;
	if (pq->items == 0)
		pq->rear = NULL;

	return true;
}

void EmptyTheQueue(Queue *pq)
{
	Item dummy;

	while (!QueueIsEmpty(pq))
		DeQueue(&dummy, pq);
}

static void CopyToNode(Item item, Node *pn)
{
	pn->item = item;
}

static void CopyToItem(Node *pn, Item *pi)
{
	*pi = pn->item;
}

bool new_person(Item *person, int minute, double person_per_minute);

int main(void)
{
	Queue line1, line2;
	Item person;
	int minute, total_time;
	double person_per_minute;
	int customer = 0, served = 0, turnaway = 0;
	int service_time1 = 0, service_time2 = 0, total_line = 0, total_wait_time = 0;

	InitializeQueue(&line1);
	InitializeQueue(&line2);
	srand((unsigned int)time(0));   

	puts("Case Study: Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation hours:");
	scanf("%d", &total_time);  
	total_time *= 60;     

	puts("Enter the average number of customers per hour:");
	scanf("%lf", &person_per_minute);
	person_per_minute = person_per_minute / 60;

	for (minute = 0; minute<total_time; minute++)
	{
		if (new_person(&person, minute, person_per_minute) == true)
		{
			if (QueueIsFull(&line1) == true && QueueIsFull(&line2) == true)
				turnaway++;
			else
			{
				if (QueueItemCount(&line1) <= QueueItemCount(&line2))
					EnQueue(person, &line1);
				else
					EnQueue(person, &line2);
				customer++;
			}
		}

		if (service_time1 <= 0 && QueueIsEmpty(&line1) == false)  //检查队列1
		{
			DeQueue(&person, &line1);
			served++;
			service_time1 = person.processtime;
			total_wait_time += minute - person.arrive;
		}

		if (service_time2 <= 0 && QueueIsEmpty(&line2) == false)  //检查队列2
		{
			DeQueue(&person, &line2);
			served++;
			service_time2 = person.processtime;
			total_wait_time += minute - person.arrive;
		}
		//服务一分钟
		if (service_time1>0) 
			service_time1--;
		if (service_time2>0)
			service_time2--;
		total_line += QueueItemCount(&line1) + QueueItemCount(&line2);
	}

	if (customer > 0)
	{
		printf("customers accepted: %d\n", customer);
		printf("  customers served: %d\n", served);
		printf("         turnaways: %d\n", turnaway);
		printf("average queue size: %.2f\n", (double)total_line / total_time);
		printf(" average wait time: %.2f minutes\n", (double)total_wait_time / served);
	}
	else
		puts("No customers!");

	EmptyTheQueue(&line1);
	EmptyTheQueue(&line2);
	puts("Bye!");

	return 0;
}

bool new_person(Item *p_person, int minute, double person_per_minute)  //为*person创造一个新人，若成功返回true
{
	if ((double)rand() / RAND_MAX < person_per_minute) //概率为 person_per_minute  ,注意要有double强制转换
	{
		p_person->arrive = minute;  //标记 入队时间
		p_person->processtime = rand() % 3 + 1;  //服务时间随机为1、2、3  （等概率）
		return true;
	}
	return false;
}