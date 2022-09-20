// Emmanuel Jojy
// Roll no: 53
// S3 CSE A (19-23')

// Prg 04/2408
// Stack Implemention

// Lab 24/08/2020
// Question: Implement Stack


#include <stdio.h>
#define MAXSIZE 100

void push(int S[], int *TOP);
void pop(int S[], int *TOP);
void display(int S[], int *TOP);


void main()
{
	int TOP = -1, S[100];
	while(1)
	{
		int ch;
		printf("\n***STACK MENU***\n1. PUSH    2. POP    3. DISPLAY    4. QUIT\nEnter choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: push(S, &TOP); break;
			case 2: pop(S, &TOP); break;
			case 3: display(S, &TOP); break;
		}
		if(ch == 4)
		{
			break;
		}
	}
}


void push(int S[], int *TOP)
{
	if(*TOP >= MAXSIZE - 1)
	{
		printf("\nSTACK IS FULL.\n");
		return;
	}
	int ITEM;
	*TOP = *TOP + 1;
	printf("\nELEMENT TO PUSH: ");
	scanf("%d",&ITEM);
	S[*TOP] = ITEM;
}


void pop(int S[], int *TOP)
{
	if(*TOP == -1)
	{
		printf("\nSTACK IS EMPTY.\n");
		return;
	}
	int ITEM;
	ITEM = S[*TOP];
	printf("\nPOPPED ELEMENT: %d", ITEM);
	*TOP = *TOP - 1;
}


void display(int S[], int *TOP)
{
	if(*TOP == -1)
	{
		printf("\nSTACK IS EMPTY\n");
		return;
	}
	printf("\nTOP CURRENTLY: %d", *TOP);
	printf("\nELEMENTS OF STACK S:\n");
	for(int i = *TOP; i >= 0; i--)
	{
		printf("S[%d]: %d\n", i, S[i]);
	}
	printf("\n");
}
