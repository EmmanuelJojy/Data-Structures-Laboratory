// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 01/1708
// Insertion and Deleltion to Array

#include <stdio.h>
void insert(int arr[], int *n);
void delete(int arr[], int *n);


void main()
{
	int n, i, arr[100];
	printf("N: ");
	scanf("%d", &n);
	printf("Enter array elements:\n");
	for(i = 0; i < n; i++)
	{
		printf("arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	while(1)
	{
		int ch;
		printf("\n1. Insert\n2. Delete\n3. Quit\nEnter choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: insert(arr, &n); break;
			case 2: delete(arr, &n); break;
		}
		if(ch == 3)
		{
			break;
		}
	}
}


void insert(int arr[], int *n)
{
	int index, e;
	printf("Enter index to insert: ");
	scanf("%d", &index);
	if(index > *n)
	{
		return ;
	}
	printf("Enter element to insert: ");
	scanf("%d", &e);
	for(int i = index, temp = e; i < *n + 1; i++)
	{
		temp = arr[i];
		arr[i] = e;
		e = temp;
	}
	*n = *n + 1;
	printf("\nElements after insertion: ", *n);
	for(int i = 0; i < *n; i++)
	{
		printf("\t%d", arr[i]);
	}
	printf("\n");
}


void delete(int arr[], int *n)
{
	int index;
	printf("Enter index of element to delete: ");
	scanf("%d", &index);
	if(index > *n - 1)
	{
		return ;
	}
	for(int i = index; i < *n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	*n = *n - 1;
	printf("\nElements after deletion:  ");
	for(int i = 0; i < *n; i++)
	{
		printf("\t%d", arr[i]);
	}
	printf("\n");
}

