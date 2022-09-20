#include <stdio.h>

int a[20][20], b[20][3];
int r, c, k = 0;

void read(){
	printf("row: ");
	scanf("%d", &r);
	printf("col: ");
	scanf("%d", &c);
	
	b[0][0] = r;
	b[0][1] = c;
	
	printf("\nEnter elements\n");
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			printf("a[%d][%d]: ", i, j);
			scanf("%d", &a[i][j]);
			if(a[i][j] != 0){
				k++;
				b[k][0] = i;
				b[k][1] = j;
				b[k][2] = a[i][j];
			}
		}
	}
	b[0][2] = k;
}

void main(){
	read();
	printf("Array:\n");
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	printf("\nTuple:\n");
	for(int i = 0; i < b[0][2] + 1; i++){
		for(int j = 0; j < 3; j++){
			printf("%d\t", b[i][j]);
		}
		printf("\n");
	}
}
