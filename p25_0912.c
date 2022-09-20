// Emmanuel Jojy
// S3 CSE A
// Roll no: 53

// Prg 25/0912
// Standard Sorting Algorithms

#include<stdio.h>

int A[20], B[20], n;

void swap(int *a, int *b){
	printf("\tswap(%d, %d)\n", *a, *b);
	int temp = *a;
	*a = *b;
	*b = temp;
}

void display(){
	for(int i = 0; i < n; i++){
		printf("%d  ", A[i]);
	}
	printf("\n");
}


void bubble(){
	int i, j;
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++){
			if(A[j] > A[j + 1]){
				swap(&A[j], &A[j + 1]);
			}
			printf("\tCurrent Array: ");
			display();
		}
	}
}

void select(){
	int i, k, loc, min;
	for(i = 0; i < n - 1; i++){
		loc = i;
		min = A[i];
		for(k = i + 1; k < n; k++){
			if(min > A[k]){
				loc = k;
				min = A[k];
			}
		}
		if(loc != i){
			swap(&A[i], &A[loc]);
		}
		printf("\tCurrent Array: ");
		display();
	}
}

void insert(){
	int i, j, m;
	for(i = 1; i < n; i++){
		m = A[i];
		for(j = i - 1; j >= 0; j--){
			if(A[j] > m){
				A[j + 1] = A[j];
			}
			else{
				break;
			}
/*			printf("\tCurrent Array: ");*/
/*			display();*/
		}
		A[j + 1] = m;
		printf("\tCurrent Array: ");
		display();
	}
}

void merge(int lb, int mid, int ub){
	int i = lb, j = mid + 1, B[20], k = lb;
	while(i <= mid && j <= ub){
		if(A[i] < A[j]){
			B[k] = A[i];
			i++;
		}
		else{
			B[k] = A[j];
			j++;
		}
		k++;
	}
	while(i <= mid){
		B[k] = A[i];
		i++;
		k++;
	}
	while(j <= ub){
		B[k] = A[j];
		j++;
		k++;
	}
	for(i = lb; i <= ub; i++){
		A[i] = B[i];
	}
	printf("\tCurrent Array: ");
	display();
}

void mergesort(int lb, int ub){
	int mid;
	if(lb < ub){
		mid = (lb + ub) / 2;
		mergesort(lb, mid);
		mergesort(mid + 1, ub);
		merge(lb, mid, ub);
	}
}

int partition(int lb, int ub){
	int pivot = A[lb];
	int start = lb, end = ub;
	while(start < end){
		printf("\tPivot = %d\n", pivot);
		while(start <= ub && A[start] <= pivot){
			start++;
		}
		while(end >= lb && A[end] > pivot){
			end--;
		}
		if(start < end){
			swap(&A[start], &A[end]);
			printf("\tCurrent Array: ");
			display();
		}
	}
	if(end != lb){
		swap(&A[end], &A[lb]);
		printf("\tCurrent Array: ");
		display();
	}
	return end;
}

void quick(int lb, int ub){
	if(lb < ub){
		int end = partition(lb, ub);
		quick(lb, end - 1);
		quick(end + 1, ub);
	}
}

void read(){
	printf("Enter Number of Elements: ");
	scanf("%d", &n);
	printf("Enter Elements\n");
	for(int i = 0; i < n; i++){
		printf(" A[%d]: ", i);
		scanf("%d", &A[i]);
	}
	printf("\nUnsorted array: ");
	display();
}

void main(){
	int i, ch;
	read();
	while(1){
		printf("\n*** Sorting Options ***");
		printf("\n1. Bubble  2. Selection  3. Insertion  4. Merge  5. Quick\n6. Change array  7. Exit");
		printf("\nEnter Choice: ");
		scanf("%d", &ch);
		printf("\n");
		switch(ch){
			case 1: bubble(); break;
			case 2: select(); break;
			case 3: insert(); break;
			case 4: mergesort(0, n - 1); break;
			case 5: quick(0, n - 1); break;
			case 6: read(); break;
			default: return;
		}
		if(ch == 6){
			continue;
		}
		printf("\n\tSorted Array:   ");
		display();
	}
	
	
}
