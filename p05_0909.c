// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 05/0909
// Infix to Postfix Conversion
// See comb0506.c for updated version

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define FLAG 1


void convert(char inf[100]);
int rank(char c, int type);
void display(char STACK[], int *TOP, char pf[], char c);

void push(char STACK[], int *TOP, char ITEM);
char pop(char STACK[], int *TOP);


void main()
{
	char inf[100];
	printf("\nInfix -> Postfix.\n");
	printf("Enter Infix Expression: ");
	scanf("%s", inf);
	convert(inf);
}
// convert() does infix -> postfix
void convert(char inf[100])
{
	// STACK
	// Dynamic allocation since size depends on MAXSIZE
	char *STACK = malloc(sizeof(char) * MAXSIZE);
	int TOP = -1;
	char x;
	push(STACK, &TOP, '(');
	
	// Postfix character array
	char pf[100];
	pf[0] = '\0';
	
	// Counters
	int i, j = 0;
	
	// Appending ')' at the end of infix expression
	for(i = 0; inf[i] != '\0'; i++);
	inf[i] = ')';
	i++;
	inf[i] = '\0';
	
	// Table Head Row
	if(FLAG == 1)
	{
		printf("\nSr. no.\t\tCHAR\t\tSTACK\t\t\tEXPR\n");
		display(STACK, &TOP, pf, ' ');
	}
	
	// Loop iterates through each character in infix char array.
	for(i = 0; inf[i] != '\0'; i++)
	{
		x = pop(STACK, &TOP);
		if(inf[i] == ')') 
		{
			//Closing bracket found
			//Pop out all elements until '(' is encountered
			while(x != '(')
			{
				pf[j] = x;
				j++;
				pf[j] = '\0';
				x = pop(STACK, &TOP);
			}
		}
		else if(rank(inf[i], 1) == -1)
		{
			// Current character is not operator
			pf[j] = inf[i];
			j++;
			pf[j] = '\0';
			push(STACK, &TOP, x);
		}
		else if(rank(inf[i], 2) > rank(x, 1))
		{
			// When incoming character has higher priority than instack.
			push(STACK, &TOP, x);
			push(STACK, &TOP, inf[i]);
		}
		else
		{
			// Incase incoming character has lesser priority than instack.
			while(rank(inf[i], 2) <= rank(x, 1))
			{
				// Popping out until priority settles
				pf[j] = x;
				j++;
				pf[j] = '\0';
				x = pop(STACK, &TOP);
			}
			// Pushing since no more priority problems
			push(STACK, &TOP, x);
			push(STACK, &TOP, inf[i]);
		}
		display(STACK, &TOP, pf, inf[i]);
	}
	printf("\nPostfix Expression: %s\n\n", pf);
	free(STACK);
}

// rank() returns rank of operator.
// Incase of non operator -1 is returned 
int rank(char c, int type)
{
	//PRIORITY -> ^  *  /  +  -  (
	int ISP[6] = {3, 2, 2, 1, 1, 0}; //In-Stack  Priority // type = 1 
	int ICP[6] = {4, 2, 2, 1, 1, 4}; //In-Coming Priority // type = 2
	if(type == 1)
	{
		switch(c)
		{
			case '^': return ISP[0];
			case '*': return ISP[1];
			case '/': return ISP[2];
			case '+': return ISP[3];
			case '-': return ISP[4];
			case '(': return ISP[5];
			default:  return -1;
		}
	}
	else
	{
		switch(c)
		{
			case '^': return ICP[0];
			case '*': return ICP[1];
			case '/': return ICP[2];
			case '+': return ICP[3];
			case '-': return ICP[4];
			case '(': return ICP[5];
			default:  return -1;
		}
	}
}

// **STACK OPERATIONS**
// PUSH()
void push(char STACK[], int *TOP, char ITEM)
{
	if(*TOP >= MAXSIZE - 1)
	{
		printf("\nSTACK IS FULL. OVERFLOW\n");
		return;
	}
	*TOP = *TOP + 1;
	STACK[*TOP] = ITEM;
}

// POP()
char pop(char STACK[], int *TOP)
{
	if(*TOP == -1)
	{
		printf("\nSTACK IS EMPTY. UNDERFLOW\n");
		return '!';
	}
	char ITEM;
	ITEM = STACK[*TOP];
	*TOP = *TOP - 1;
	return ITEM;
}

// DISPLAY()
void display(char STACK[], int *TOP, char pf[], char c)
{
	if(FLAG == 0)
	{
		return;
	}
	static int count = 0;
	printf("%d\t\t'%c'\t\t", count++, c);
	if(*TOP == -1)
	{
		printf("EMPTY");
	}
	else
	{
		for(int i = 0; i <= *TOP; i++)
		{
			printf("%c", STACK[i]);
		}
	}
	printf("\t\t\t'%s'\n", pf);
}
