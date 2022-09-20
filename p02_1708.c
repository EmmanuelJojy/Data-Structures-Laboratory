// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 02/1708
// String Comparison and Concatenation

#include <stdio.h>
void compare(char s1[50], char s2[50]);
void concat(char s1[50], char s2[50]);

void main()
{
	char s1[50], s2[50];
	int ch;
	printf("\nEnter String 1: ");
	scanf("%s", s1);
	printf("Enter String 2: ");
	scanf("%s", s2);
	printf("\n1. Lexicographic Compare");
	printf("\n2. Concatenate");
	printf("\nEnter choice: ");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: compare(s1, s2); break;
		case 2: concat(s1, s2); break;
		default: printf("Wrong choice!\n");
	}
	printf("\n");
}


void compare(char s1[50], char s2[50])
{
	//Assuming the strings are purely alphabetic
	//Lexicographic and case sensitive comparison.
	//strcmp()
	
	int i;
	printf("\n");
	for(i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if(s1[i] > s2[i])
		{
			printf("Not equal.\n%s comes before %s.\n", s2, s1);
			return;
		}
		else if(s1[i] < s2[i])
		{
			printf("Not equal.\n%s comes before %s.\n", s1, s2);
			return;
		}
		else
		{
			continue;
		}
	}
	if(s1[i] == s2[i])
	{
		printf("Equal Strings. %s = %s\n", s1, s2);
	}
	else if(s1[i] == '\0')
	{
		printf("Not equal.\n%s comes before %s.\n", s1, s2);
	}
	else
	{
		printf("Not equal.\n%s comes before %s.\n", s2, s1);
		return;
	}
}

void concat(char s1[50], char s2[50])
{
	int i, j;
	for(i = 0; s1[i] != '\0'; i++);
	for(j = 0; s2[j] != '\0'; i++, j++)
	{
		s1[i] = s2[j];
	}
	s1[i] = '\0';
	printf("\n%s", s1);
}
