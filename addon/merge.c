#include <stdio.h>
#include <math.h>

int a[50], b[50], n;

// --- STACK CODE ---
// ------------------

struct item{
	int first;
	int last;
};

struct item s[50];
int TOP = -1;

void push(int i, int j){
	struct item x;
	x.first = i; 
	x.last = j;
	TOP++;
	s[TOP] = x;
	//printf("\n%d, %d", i, j);
}

struct item pop(){
	return s[TOP--];
}

// ------------------
// ------------------

void merge(int first, int last){
	int mid = (first + last) / 2;
	int i = first, j = mid + 1, k = first;
	while(i <= mid && j <= last){
		if(a[i] <= a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while(i <= mid)
		b[k++] = a[i++];
	while(j <= last)
		b[k++] = a[j++];
	for(i = first; i <= last; i++)
		a[i] = b[i];
}

/*void sort(){*/
/*	int c, i;*/
/*	for(c = n; c > 0; c /= 2){*/
/*		for(i = 0; i + c < n; i += c + 1){*/
/*			push(i, i + c);*/
/*		}*/
/*		if(i < n)*/
/*			push(i, n - 1);*/
/*	}*/
/*	*/
/*	while(TOP != -1){*/
/*		struct item x = pop();*/
/*		merge(x.first, x.last);*/
/*	}*/
/*}*/

void sort(){
	int c, i;
	for(c = 1; c <= n; c *= 2){
		for(i = 0; i + c < n; i += c)
			merge(i, i + c);
		if(i < n)
			merge(i, n - 1);
	}
}

void norm(){
	int size;
	for(int i = 0; pow(2, i) < n; i++){
		size = pow(2, i);
	}
	size = (size * 2);
	printf("Size = %d", size);
	if(size != n){
		for(int i = n; i < size; i++){
			a[i] = -100;
		}
		n = size;
	}
}

void main(){
	printf("--- Merge Sort Non Recursive ---");
	printf("\nEnter size of array: ");
	scanf("%d", &n);
	int i;
	
	for(i = 0; i < n; i++){
		printf("a[%d]: ", i);
		scanf("%d", &a[i]);
	}
	
	norm();
	sort();
	
	printf("\n\n");
	for(i = 0; i < n; i++){
		if(a[i] != -100)
			printf("%d, ", a[i]);
	}
	printf("\n");
}
