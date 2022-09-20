// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 03/1708
// Check for palindrome

#include <stdio.h>
void check(char s[50]);

void main()
{
	char s[50];
	printf("\nEnter string to check: ");
	scanf("%s", s);
	check(s);
}

void check(char s[50])
{
	int i, j;
	for(i = 0; s[i] != '\0'; i++);
	for(j = 0, i--; i >= j; j++, i--)
	{
		if(s[i] != s[j])
		{
			printf("\nNot Palindrome\n");
			return;
		}
	}
	printf("\nPalindrome\n");
}
