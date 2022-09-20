// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 10/2209
// Circular Queue Implementation
// Static Array

#include<stdio.h>
#define MAXSIZE 4

//Global variables
int CQ[MAXSIZE];
int FRONT = -1;
int REAR = -1;


void cqueue();

void encqueue();
void decqueue();
void display();

void main()
{
	cqueue();
}


void cqueue()
{
	int ch;
	while(1)
	{
		printf("\n\n---- CIRCULAR QUEUE OPERATIONS ----");
		printf("\n1. Encqueue\t2. Decqueue\t3. Display\t4. Exit");
		printf("\nChoice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: 
			{
				encqueue();
				break;
			}
			case 2: decqueue(); break;
			case 3: display(); break;
			default: return;
		}
	}
}


void encqueue()
{
	if((REAR + 1) % MAXSIZE == FRONT)
	{
		printf("\n   CIRCULAR QUEUE IS FULL!");
		return;
	}
	int ITEM;
	printf("\n   Enter element to enqueue: ");
	scanf("%d", &ITEM);
	if(FRONT == -1 && REAR == -1)
	{
		FRONT++;
		REAR++;
		CQ[REAR] = ITEM;
	}
	else
	{
		REAR = (REAR + 1) % MAXSIZE;
		CQ[REAR] = ITEM;
	}
	printf("   Encqueued %d Successfully", ITEM);
}


void decqueue()
{
	if(FRONT == -1 && REAR == -1)
	{
		printf("\n   QUEUE IS EMPTY!");
		return;
	}
	int ITEM = CQ[FRONT];
	printf("\n   Decqueued %d Successfully", ITEM);
	if(FRONT == REAR)
	{
		FRONT = -1;
		REAR = -1;
	}
	else
	{
		FRONT = (FRONT + 1) % MAXSIZE;
	}
	//return ITEM;
}

void display()
{
	int x = FRONT, y = REAR;
	if(FRONT == -1 && REAR == -1)
	{
		printf("\n   QUEUE IS EMPTY!");
		return;
	}
	int i;
	printf("\n\tCURRENT CIRCULAR QUEUE:\n\t");
	for(i = 0; i < MAXSIZE; i++)
	{
		printf("[%d]\t", i);
	}
	printf("\n\t");
	
	if(x > y)
	{
		for(i = 0; i <= y; i++)
		{
			printf("%d\t", CQ[i]);
		}
		for(; i < x; i++)
		{
			printf("***\t");
		}
		for(i = x; i < MAXSIZE; i++)
		{
			printf("%d\t", CQ[i]);
		}
	}
	else
	{
		for(i = 0; i < FRONT; i++)
		{
			printf("***\t");
		}
		for(i = FRONT; i <= REAR; i++)
		{
			printf("%d\t", CQ[i]);
		}
		for(i = REAR + 1; i < MAXSIZE; i++)
		{
			printf("***\t");
		}
	}
	printf("\n");
}
