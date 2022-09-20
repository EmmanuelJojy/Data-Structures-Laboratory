// Emmanuel Jojy
// S3 CSE A
// Roll no: 53

// Prg 26/2812
// Heap Tree and Sort
// Ascending - MAX Heap

#include <stdio.h>

#define MAXSIZE 20

int A[MAXSIZE + 1], N = 0;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void display(){
	if(N == 0){
		printf("EMPTY");
		return;
	}
	int i;
	for(i = 1; i <= N; i++){
		printf("%d  ", A[i]);
	}
}

void heapInsert(int item){
	if(N >= MAXSIZE){
		printf("\tInsertion Unsuccessful");
	}
	else{
		int i, pos;
		N++;
		A[N] = item;
		i = N;
		pos = i / 2;
		while(pos > 0 && A[pos] < A[i]){
			swap(&A[pos], &A[i]);
			i = pos;
			pos = pos / 2;
		}
		printf("\tSuccessfully Inserted %d", item);
	}
}

void heapDelete(){
	if(N == 0){
		printf("\tDeletion Unsuccessful. Tree Empty");
	}
	else{
		int item, flag = 0, i = 1, lchild, rchild;
		int x, y; // infinity
		item = A[1];
		A[1] = A[N];
		N--;
		while(flag == 0 && i <= N){
			x = -10000;
			y = -10000;
			lchild = 2 * i;
			rchild = 2 * i + 1;
			if(lchild <= N){
				x = A[lchild];
			}
			if(rchild <= N){
				y = A[rchild];
			}
			if(A[i] >= x && A[i] >= y){
				flag = 1;
			}
			else{
				if(x >= y){
					swap(&A[i], &A[lchild]);
					i = lchild;
				}
				else{
					swap(&A[i], &A[rchild]);
					i = rchild;
				}
			}
		}
		printf("\tSuccessfully Deleted %d", item);
	}
}

void heapSort(){
	int i = N, j, lchild, rchild;
	printf("\n\tN = %d", N);
	while(i > 1){
		printf("\n\n\tSorting Tree: ");
		display();
		if(A[1] > A[i]){
			printf("\n\t*First Swap %d <-> %d", A[1], A[i]);
			swap(&A[1], &A[i]);
		}
		i--;
		j = 1;
		while(j < i){
			lchild = 2 * j;
			rchild = 2 * j + 1;
			if(lchild < i){
				if(rchild < i){
					if((A[lchild] > A[j]) && (A[lchild] > A[rchild])){
						printf("\n\t Swap %d <-> %d", A[j], A[lchild]);
						swap(&A[j], &A[lchild]);
						j = lchild;
					}
					else if((A[rchild] > A[j]) && (A[rchild] > A[lchild])){
						printf("\n\t Swap %d <-> %d", A[j], A[rchild]);
						swap(&A[j], &A[rchild]);
						j = rchild;
					}
					else{
						break;
					}
				}
				else{
					if(A[lchild] > A[j]){
						printf("\n\t Swap %d <-> %d", A[j], A[lchild]);
						swap(&A[j], &A[lchild]);
						j = lchild;
					}
					else{
						break;
					}
				}
			}
			else{
				break;
			}
		}
	}
	printf("\n\n\tSorted Tree:  ");
	display();
	printf("\n");
}

void main(){
	int ch, item;
	
	while(1){
		printf("\n\n*** Heap Tree Options ***");
		printf("\n1. Insert  2. Delete  3. Sort  4. Display  5. Exit");
		printf("\nEnter Choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1:{
				printf("\tEnter item: ");
				scanf("%d", &item);
				heapInsert(item);
				break;
			}
			case 2: heapDelete(); break;
			case 3: heapSort(); return;
			case 4:{
				printf("\tCurrent Tree: ");
				display();
				break;
			} 
			default: return;
		}
	}
}
