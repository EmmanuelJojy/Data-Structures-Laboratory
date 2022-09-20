// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 13/1110
// Polynomial Representation and Operations
// Static Array of Structures

#include<stdio.h>

struct var
{
	int pw;
	int co;
};

struct var a[10], b[10], c[20];
int a_max, b_max, c_max;

void read();
void sort();
void add();
void display();

void main()
{
	printf("\nPolynomial Addition\n");
	read();
	sort();
	
	printf("A:   ");
	display(a, a_max);
	printf("B:   ");
	display(b, b_max);
	
	add();
	
	printf("\nSUM: ");
	display(c, c_max);
}

void read()
{
	int i;
	printf("Polynomial A");
	printf("\nEnter Number of Non-Zero terms: ");
	scanf("%d", &a_max);
	for(i = 0; i < a_max; i++)
	{
		printf("\t(%d/%d) Enter power: ", (i + 1), a_max);
		scanf("%d", &a[i].pw);
		printf("\tEnter coeffecient: ");
		scanf("%d", &a[i].co);
		printf("\n");
	}
	printf("\nPolynomial B");
	printf("\nEnter Number of Non-Zero terms: ");
	scanf("%d", &b_max);
	for(i = 0; i < b_max; i++)
	{
		printf("\t(%d/%d) Enter power: ", (i + 1), b_max);
		scanf("%d", &b[i].pw);
		printf("\tEnter coeffecient: ");
		scanf("%d", &b[i].co);
		printf("\n");
	}
}

void add()
{
	int i = 0, j = 0, k = 0;
	
	while(1)
	{
		if(a[i].pw == b[j].pw)
		{
			c[k].pw = a[i].pw;
			c[k].co = a[i].co + b[j].co;
			i++;
			j++;
		}
		else if(a[i].pw > b[j].pw)
		{
			c[k].pw = a[i].pw;
			c[k].co = a[i].co;
			i++;
		}
		else
		{
			c[k].pw = b[j].pw;
			c[k].co = b[j].co;
			j++;
		}
		k++;
		if(i == a_max)
		{
			while(j != b_max)
			{
				c[k].pw = b[j].pw;
				c[k].co = b[j].co;
				j++;
				k++;
			}
			break;
		}
		if(j == b_max)
		{
			while(i != a_max)
			{
				c[k].pw = a[i].pw;
				c[k].co = a[i].co;
				i++;
				k++;
			}
			break;
		}
	}
	c_max = k;
}


void display(struct var poly[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d(x ^ %d) + ", poly[i].co, poly[i].pw);
	}
	printf("0\n");
}


void sort()
{
	int i, j, flag = 1;
	struct var temp;
	for(i = 0; i < a_max - 1 && flag == 1; i++)
	{
		flag = 0;
		for(j = 0; j < a_max - i - 1; j++)
		{
			if(a[j].pw < a[j + 1].pw)
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}
	}
	for(i = 0; i < b_max - 1 && flag == 1; i++)
	{
		flag = 0;
		for(j = 0; j < b_max - i - 1; j++)
		{
			if(b[j].pw < b[j + 1].pw)
			{
				temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
				flag = 1;
			}
		}
	}
}
