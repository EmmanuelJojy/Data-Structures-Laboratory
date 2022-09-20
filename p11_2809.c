// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 11/2809
// Double Ended Queue Implementation
// Static Array

#include<stdio.h>
#define MAXSIZE 5

//Global variables
int DQ[MAXSIZE];
int FRONT = -1;
int REAR = -1;

void dqueue();

void pushdq();
void popdq();
void inject();
void eject();
void display();

void main()
{
	dqueue();
}


void dqueue()
{
	int ch;
	while(1)
	{
		printf("\n\n---- DE-QUEUE OPERATIONS ----");
		printf("\n1. PUSHDQ\t2. POPDQ\t3. INJECT\t4. EJECT\t5. DISPLAY\t6. EXIT");
		printf("\nChoice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: pushdq(); break;
			case 2: popdq(); break;
			case 3: inject(); break;
			case 4: eject(); break;
			case 5: display(); break;
			default: return;
		}
	}
}


void pushdq()
{
	int ITEM, temp;
	printf("\n   Enter element to enqueue: ");
	scanf("%d", &ITEM);
	if(FRONT == -1 && REAR == -1)
	{
		FRONT = 0;
		REAR = 0;
		DQ[FRONT] = ITEM;
		return;
	}
	
	//FRONT at 0
	temp = FRONT == 0 ? MAXSIZE - 1 : FRONT - 1;
	if(temp == REAR)
	{
		printf("   DQ is full!\n");
		return;
	}
	FRONT = temp;
	DQ[FRONT] = ITEM;
}


void popdq()
{
	int ITEM;
	if(FRONT == -1 && REAR == -1)
	{
		printf("\n   DQ is empty!\n");
		return;
	}
	ITEM = DQ[FRONT];
	printf("\n   POPDQ %d SUCCESSFULLY", ITEM);
	if(FRONT == REAR)
	{
		FRONT = -1;
		REAR = -1;
	}
	else
	{
		FRONT = (FRONT + 1) % MAXSIZE;
	}
}

void inject()
{
	int ITEM;
	printf("\n   Enter element to inject: ");
	scanf("%d", &ITEM);
	if((REAR + 1) % MAXSIZE == FRONT)
	{
		printf("\n   DQ IS FULL");
		return;
	}
	if(FRONT == -1 && REAR == -1)
	{
		FRONT = 0;
		REAR = 0;
		DQ[REAR] = ITEM;
	}
	else
	{
		REAR = (REAR + 1) % MAXSIZE;
		DQ[REAR] = ITEM;
	}
}


void eject()
{
	int ITEM;
	if(FRONT == -1 && REAR == -1)
	{
		printf("\n   DQ is Empty");
		return;
	}
	if(FRONT == REAR)
	{
		ITEM = DQ[REAR];
		FRONT = -1;
		REAR = -1;
	}
	else
	{
		ITEM = DQ[REAR];
		REAR = REAR == 0 ? MAXSIZE - 1 : REAR - 1;
	}
	printf("\n   EJECTED %d SUCCESSFULLY", ITEM);
}


void display()
{
	if(FRONT == -1 && REAR == -1)
	{
		printf("\n   DE - QUEUE IS EMPTY\n");
		return;
	}
	printf("\n\t");
	int i;
	for(i = FRONT; i != REAR; i = (i + 1) % MAXSIZE)
	{
		printf("%d\t", DQ[i]);
	}
	printf("%d\n", DQ[i]);
}
