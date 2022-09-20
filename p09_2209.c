// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 09/2209
// Queue Implementation
// Static Array

#include<stdio.h>
#define MAXSIZE 3

//Global variables
int Q[MAXSIZE];
int FRONT = -1;
int REAR = -1;


void queue();
void enqueue(int ITEM);
void dequeue();
void display();

void main()
{
	queue();
}


void queue()
{
	int ch;
	while(1)
	{
		printf("\n\n**QUEUE OPERATIONS**");
		printf("\n1. Enqueue    2. Dequeue    3. Display    4. Exit");
		printf("\nChoice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: 
			{
				int ITEM;
				printf("\nEnter element to enqueue: ");
				scanf("%d", &ITEM);
				enqueue(ITEM);
				break;
			}
			case 2: dequeue(); break;
			case 3: display(); break;
			default: return;
		}
	}
}


void enqueue(int ITEM)
{
	if(REAR == MAXSIZE - 1)
	{
		printf("\nQUEUE IS FULL!");
		return;
	}
	if(FRONT == -1 && REAR == -1)
	{
		FRONT++;
	}
	REAR++;
	Q[REAR] = ITEM;
}


void dequeue()
{
	if(FRONT == -1 && REAR == -1)
	{
		printf("\nQUEUE IS EMPTY!");
		return;
	}
	int ITEM = Q[FRONT];
	printf("\nDequeued %d Successfully", ITEM);
	if(FRONT == REAR)
	{
		FRONT = -1;
		REAR = -1;
	}
	else
	{
		FRONT++;
	}
	//return ITEM;
}

void display()
{
	if(FRONT == -1 && REAR == -1)
	{
		printf("\nQUEUE IS EMPTY!");
		return;
	}
	int i;
	printf("\nCURRENT QUEUE:\n");
	for(i = 0; i < MAXSIZE; i++)
	{
		printf("[%d]\t", i);
	}
	printf("\n");
	for(i = 0; i < FRONT; i++)
	{
		printf("***\t");
	}
	for(i = FRONT; i <= REAR; i++)
	{
		printf("%d\t", Q[i]);
	}
	for(i = REAR + 1; i < MAXSIZE; i++)
	{
		printf("***\t");
	}
	printf("\n");
}
