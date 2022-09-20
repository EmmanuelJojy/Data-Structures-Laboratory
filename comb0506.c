// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg Combined 0506
// Prg 05/0909 + Prg 06/0909
// Infix to Postfix Conversion and Evaluvation

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define FLAG 1

// INFIX -> POSTFIX FUNCTIONS
void convert(char inf[100]);
int rank(char c, int type);
void display(char STACK[], int *TOP, char pf[], char c);

void push(char STACK[], int *TOP, char ITEM);
char pop(char STACK[], int *TOP);
// END

//POSTFIX EVALUAVTION FUNCTIONS
struct var
{
	char letter;
	float value;
};

void evaluvate(char pf[100]);
void analyse(struct var alpha[26], char pf[100]);
float result(float x, float y, char op);
int type(char ITEM);

void push_e(float STACK_E[], int *TOP_E, float ITEM);
float pop_e(float STACK_E[], int *TOP_E);

void display_e(float STACK_E[], int *TOP_E, char c);
// END

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
	evaluvate(pf);
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

void evaluvate(char pf[100])
{
	// STACK_E - FLOAT
	// Dynamic allocation since size depends on MAXSIZE
	float *STACK_E = malloc(sizeof(float) * MAXSIZE);
	int TOP_E = -1;
	
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
	
	// Appending '#' at the end of infix expression
	for(i = 0; pf[i] != '\0'; i++);
	pf[i] = '#';
	i++;
	pf[i] = '\0';
	
	// Table Head Row
	printf("\nSr no\t|     SYMBOL\t|\tPOP() [Y, X]\t|\tPUSH()\t\t|\tSTACK_E[0 -> TOP_E]\n\n");
	
	// Loop over postfix epression
	i = 0;
	ITEM = pf[0];
	while(ITEM != '#')
	{
		printf("%d\t|\t%c\t|\t", i+1, ITEM);
		if(type(ITEM) == 1)
		{
			printf("\t\t|\t");
			push_e(STACK_E, &TOP_E, (float)(ITEM - '0'));
		}
		else if(type(ITEM) == 2)
		{
			printf("\t\t|\t");
			push_e(STACK_E, &TOP_E, alpha[ITEM - 'a'].value);
		}
		else if(type(ITEM) == 3)
		{
			y = pop_e(STACK_E, &TOP_E);
			x = pop_e(STACK_E, &TOP_E);
			printf("\t|\t");
			res = result(x, y, ITEM);
			push_e(STACK_E, &TOP_E, res);
		}
		else
		{
			printf("\n\nInvalid Expression! End Evaluavtion.\n\n");
			return;
		}
		display_e(STACK_E,&TOP_E,ITEM);
		i++;
		ITEM = pf[i];
	}
	printf("%d\t|\t#\t|\t", i + 1);
	res = pop_e(STACK_E, &TOP_E);
	printf("\t\t|\t\t\t|\tEMPTY\n\n");
	printf("RESULT = %f\n\n", res);
	free(STACK_E);
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


// **STACK_E OPERATIONS**
// push_e()
void push_e(float STACK_E[], int *TOP_E, float ITEM)
{
	if(*TOP_E >= MAXSIZE - 1)
	{
		printf("\nSTACK_E IS FULL. OVERFLOW\n");
		return;
	}
	*TOP_E = *TOP_E + 1;
	STACK_E[*TOP_E] = ITEM;
	printf("%-12.2f", ITEM);
}


// pop_e()
float pop_e(float STACK_E[], int *TOP_E)
{
	if(*TOP_E == -1)
	{
		printf("\nSTACK_E IS EMPTY. UNDERFLOW\n");
		return '0';
	}
	float ITEM;
	ITEM = STACK_E[*TOP_E];
	*TOP_E = *TOP_E - 1;
	printf("%-6.2f ", ITEM);
	return ITEM;
}


// display_e_I()
void display_e(float STACK_E[], int *TOP_E, char c)
{
	printf("\t|\t");
	if(*TOP_E == -1)
	{
		printf("EMPTY");
	}
	else
	{
		for(int i = 0; i <= *TOP_E; i++)
		{
			printf("%.2f  ", STACK_E[i]);
		}
	}
	printf("\n");
}
