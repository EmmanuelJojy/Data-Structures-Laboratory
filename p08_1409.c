// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 08/1409
// Prefix Evaluvation
// See comb0506.c for updated version

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

struct var
{
	char letter;
	float value;
};

void evaluvate(char pf[100]);
void analyse(struct var alpha[26], char pf[100]);
float result(float x, float y, char op);
int type(char ITEM);
void reverse(char arr[]);

void push(float STACK[], int *TOP, float ITEM);
float pop(float STACK[], int *TOP);

void display(float STACK[], int *TOP, char c);

void main()
{
	char pf[100];
	printf("\nPrefix Evaluvation\n");
	printf("Enter Prefix Expression: ");
	scanf("%s", pf);
	evaluvate(pf);
}

void evaluvate(char pf[100])
{
	// STACK - FLOAT
	// Dynamic allocation since size depends on MAXSIZE
	float *STACK = malloc(sizeof(float) * MAXSIZE);
	int TOP = -1;
	
	float x, y, res;
	char ITEM;
	
	// Counter
	int i;
	
	struct var alpha[26];
	for(i = 0; i < 25; i++)
	{
		// Initialising letter in structure
		alpha[i].letter = '!';
	}
	
	analyse(alpha, pf);
	reverse(pf);
	// Appending '#' at the end of infix expression
	for(i = 0; pf[i] != '\0'; i++);
	pf[i] = '#';
	i++;
	pf[i] = '\0';
	
	// Table Head Row
	printf("\nSr no\t|     SYMBOL\t|\tPOP() [X, Y]\t|\tPUSH()\t\t|\tSTACK[0 -> TOP]\n\n");
	
	// Loop over postfix epression
	i = 0;
	ITEM = pf[0];
	while(ITEM != '#')
	{
		printf("%d\t|\t%c\t|\t", i+1, ITEM);
		if(type(ITEM) == 1)
		{
			printf("\t\t|\t");
			push(STACK, &TOP, (float)(ITEM - '0'));
		}
		else if(type(ITEM) == 2)
		{
			printf("\t\t|\t");
			push(STACK, &TOP, alpha[ITEM - 'a'].value);
		}
		else if(type(ITEM) == 3)
		{
			x = pop(STACK, &TOP);
			y = pop(STACK, &TOP);
			printf("\t|\t");
			// operand swap!!
			res = result(x, y, ITEM);
			push(STACK, &TOP, res);
		}
		else
		{
			printf("\n\nInvalid Expression! End Evaluavtion.\n\n");
			return;
		}
		display(STACK,&TOP,ITEM);
		i++;
		ITEM = pf[i];
	}
	printf("%d\t|\t#\t|\t", i + 1);
	res = pop(STACK, &TOP);
	printf("\t\t|\t\t\t|\tEMPTY\n\n");
	printf("RESULT = %f\n\n", res);
	free(STACK);
}


void analyse(struct var alpha[26], char pf[100])
{
	int i = 0;
	char ch = pf[i];
	float temp;
	while(ch != '\0')
	{
		if(ch >= 'a' && ch <= 'z')
		{
			if(alpha[ch - 'a'].letter != ch)
			{
				alpha[ch - 'a'].letter = ch;
				printf("Input '%c': ", ch);
				scanf("%f", &temp);
				alpha[ch - 'a'].value = temp;
			}
		}
		i++;
		ch = pf[i];
	}
}


float result(float x, float y, char op)
{
	switch(op)
	{
		case '^':
		{
			if(x == 0)
			{
				return 0;
			}
			if(y == 0)
			{
				return 1;
			}
			float res = x;
			for(int i = 2; i <= y; i++)
			{
				res *= x;
			}
			return res;
		}
		case '/': return x / y;
		case '*': return x * y;
		case '+': return x + y;
		case '-': return x - y;
	}
}


int type(char ITEM)
{
	if(ITEM >= '0' && ITEM <= '9')
	{
		return 1;
	}
	else if(ITEM >= 'a' && ITEM <= 'z')
	{
		return 2;
	}
	else if(ITEM == '^' || ITEM == '*' || ITEM == '/' || ITEM == '+' || ITEM == '-')
	{
		return 3;
	}
	else
	{
		return 0;
	}
}


// Reverse() reverses the array passed
// Call by reference method
void reverse(char arr[])
{
	int i, j;
	char rev[100];
	
	/* Storing reverse string to res[] */
	for(i = 0; arr[i] != '\0'; i++);
	i--;
	for(j = 0; i > -1; i--, j++)
	{
		rev[j] = arr[i];
	}
	rev[j] = '\0';
	/* res[] now has reverse string */
	
	// Copying back reverse string to pf
	for(i = 0; i <= j; i++)
	{
		arr[i] = rev[i];
	}
}


// **STACK OPERATIONS**
// PUSH()
void push(float STACK[], int *TOP, float ITEM)
{
	if(*TOP >= MAXSIZE - 1)
	{
		printf("\nSTACK IS FULL. OVERFLOW\n");
		return;
	}
	*TOP = *TOP + 1;
	STACK[*TOP] = ITEM;
	printf("%-12.2f", ITEM);
}


// POP()
float pop(float STACK[], int *TOP)
{
	if(*TOP == -1)
	{
		printf("\nSTACK IS EMPTY. UNDERFLOW\n");
		return '0';
	}
	float ITEM;
	ITEM = STACK[*TOP];
	*TOP = *TOP - 1;
	printf("%-6.2f ", ITEM);
	return ITEM;
}


// DISPLAY_I()
void display(float STACK[], int *TOP, char c)
{
	printf("\t|\t");
	if(*TOP == -1)
	{
		printf("EMPTY");
	}
	else
	{
		for(int i = 0; i <= *TOP; i++)
		{
			printf("%.2f  ", STACK[i]);
		}
	}
	printf("\n");
}
