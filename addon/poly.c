#include <stdio.h>

struct term{
	int coef;
	int exp;
};

struct term a[10], b[10] ,pdt[30], res[30];
int n1, n2, n3;

// ---- Auxilliary ----
// ----            ----
// --------------------
void add(){
	int i = 0, j = 0, k = 0;
	while(i != n1 && j != n2){
		if(a[i].exp > b[j].exp){
			pdt[k].coef = a[i].coef;
			pdt[k].exp = a[i].exp;
			i++;
		}
		else if(a[i].exp < b[j].exp){
			pdt[k].coef = b[j].coef;
			pdt[k].exp = b[j].exp;
			j++;
		}
		else{
			pdt[k].coef = a[i].coef + b[j].coef;
			pdt[k].exp = a[i].exp;
			i++; j++;
		}
		k++;
	}
	while(i != n1){
		pdt[k].coef = a[i].coef;
		pdt[k].exp = a[i].exp;
		i++;
	}
	while(j != n2){
		pdt[k].coef = b[j].coef;
		pdt[k].exp = b[j].exp;
		j++;
	}
	
	n3 = k;
}
// --------------------

void sort(struct term *arr, int len){
	for(int i = 0; i < len - 1; i++){
		for(int j = 0; j < len - i - 1; j++){
			if(arr[j].exp < arr[j+1].exp){
				struct term temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void display(struct term *x, int n){
	for(int i = 0; i < n; i++){
		printf("%d(x^%d) + ", x[i].coef, x[i].exp);
	}
	printf("0\n");
}


void merge(){
	sort(pdt, n3);
	int k = -1, flag = 0;
	for(int i = 0; i < n3; i++){
		if(flag != pdt[i].exp){
			flag = pdt[i].exp;
			k++;
			res[k].exp = flag;
		}
		res[k].coef += pdt[i].coef;
	}
	display(res, k + 1);
}

void mul(){
	int i, j, k = 0;
	for(i = 0; i < n1; i++){
		for(j = 0; j < n2; j++){
			pdt[k].exp = a[i].exp + b[j].exp;
			pdt[k].coef = a[i].coef * b[j].coef;
			k++;
		}
	}
	n3 = k;
	merge();
}

void read(struct term *arr, int len){
	for(int i = 0; i < len; i++){
		printf("\tExponent: ");
		scanf("%d", &arr[i].exp);
		printf("\tCoeffecient: ");
		scanf("%d", &arr[i].coef);
	}
	sort(arr, len);
}

void main(){
	printf("Poly 1\n");
	printf("Enter number of terms: ");
	scanf("%d", &n1);
	read(a, n1);
	
	printf("\nPoly 2\n");
	printf("Enter number of terms: ");
	scanf("%d", &n2);
	read(b, n2);
	
	printf("\nPoly A: ");
	display(a, n1);
	printf("Poly B: ");
	display(b, n2);
	printf("Poly Mul: ");
	mul();
	return;
}
