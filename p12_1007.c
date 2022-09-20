// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 12/1007
// Sparse Matrix

#include <stdio.h>

void sparse(int a[20][20], int r, int c)
{
	 int b[20][3];
	int i, j, k = 1;
	b[0][0] = r;
	b[0][1] = c;
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			if(a[i][j] != 0)
			{
				b[k][0] = i;
				b[k][1] = j;
				b[k][2] = a[i][j];
				k++;
			}
		}
	}
	b[0][2] = k - 1;
	
	printf("\nSparse form - list of 3 triplets\n\n");
	for(i = 0; i < k; i++)
	{
		printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
	}
}

void main()
{
	int a[20][20], r, c;
	int i, j;
	
	printf("Enter size of matrix:\n");
	printf("Rows: ");
	scanf("%d", &r);
	printf("Columns: ");
	scanf("%d", &c);
	printf("\nEnter elements of matrix\n");
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			printf("[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	
	sparse(a, r, c);
}
