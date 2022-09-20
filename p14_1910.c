// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 14/1910
// Standard Searching Algorithms
// Linear and Binary Search

#include<stdio.h>

void lsearch();
void bsearch();
void sort(int arr[], int n);

int arr[20], n, key;

void main()
{
	int i;
	int ch;
	printf("Enter length of array: ");
	scanf("%d", &n);
	printf("\nEnter elements\n");
	for(i = 0; i < n; i++)
	{
		printf("arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}
	while(1)
	{
		printf("*** Search Algorithms ***");
		printf("\n   1. Linear Search\n   2. Binary Search\n   3. Exit\nChoice: ");
		scanf("%d", &ch);
		printf("\n\tEnter element to search: ");
		scanf("%d", &key);
		switch(ch)
		{
			case 1: lsearch(); break;
			case 2: bsearch(); break;
			default: return;
		}
	}
}


void lsearch()
{
	int flag = 0, i, index;
	flag = 0;
	for(i = 0; i < n && flag == 0; i++)
	{
		if(arr[i] == key)
		{
			flag = 1;
			index = i;
		}
	}
	if(flag == 1)
	{
		printf("\n\tLinear Search >> %d found at index %d.\n", key, index);
	}
	else
	{
		printf("\n\tLinear Search >> %d Not found.\n", key);
	}
}


void bsearch()
{
	sort(arr, n);
	int low = 0, high = n - 1, mid = (low + high) / 2;
	while(key != arr[mid] && low < high)
	{
		if(key > arr[mid])
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
		mid = (low + high) / 2;
	}
	if(key == arr[mid])
	{
		printf("\n\tBinary Search >> %d found at index %d.\n", key, mid);
	}
	else
	{
		printf("\n\tBinary Search >> %d Not found.\n", key);
	}
}


void sort(int arr[], int n)
{
	int i, j, temp, flag = 1;
	for(i = 0; i < n - 1 && flag == 1; i++)
	{
		flag = 0;
		for(j = 0; j < n - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
	}
	printf("\tSorted array: ");
	for(i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}
