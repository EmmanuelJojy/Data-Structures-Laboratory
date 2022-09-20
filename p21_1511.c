// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 21/1511
// Polynomial representation and addition using SLL
// Dynamic Memory Allocation 

#include <stdio.h>
#include <stdlib.h>

struct poly{
	int co;
	int ex;
	struct poly *link;
};

struct poly *c = NULL, *temp_res;

struct poly *createPoly();
void sort(struct poly *start);
void polyAdd(struct poly *a, struct poly *b);
void result(int coe ,int exp);
void display(struct poly *a);

void exit_free(struct poly *start);

void main(){
	struct poly *a = createPoly();
	printf("\tPolynomial A = ");
	display(a);
	struct poly *b = createPoly();
	printf("\tPolynomial B = ");
	display(b);
	polyAdd(a, b);
	printf("\n\nSUM = ");
	display(c);
	printf("\n");
	exit_free(a);
	exit_free(b);
	exit_free(c);
}

struct poly *createPoly(){
	struct poly *start = NULL, *temp;
	int n;
	printf("\n\nEnter Number of Non-Zero terms: ");
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		struct poly *p = malloc(sizeof(struct poly));
		p->link = NULL;
		printf("\t(%d/%d) Enter power: ", i, n);
		scanf("%d", &(p->ex));
		printf("\tEnter coeffecient: ");
		scanf("%d", &(p->co));
		printf("\n");
		
		if(start == NULL){
			start = p;
			temp = p;
		}
		else{
			temp->link = p;
			temp = p;
		}
	}
	sort(start);
	return start;
}

void sort(struct poly *start){
	int temp_co, temp_ex;
	for(struct poly *i = start; i != NULL; i = i->link){
		for(struct poly *j = start; j->link != NULL; j = j->link){
			if(j->ex < j->link->ex){
				temp_co = j->co;
				j->co = j->link->co;
				j->link->co = temp_co;
				
				temp_ex = j->ex;
				j->ex = j->link->ex;
				j->link->ex = temp_ex;
			}
		}
	}
}

void display(struct poly *start){
	for(struct poly *temp = start; temp != NULL; temp = temp->link){
		printf(" %d(x ^ %d) + ", temp->co, temp->ex);
	}
	printf(" 0");
}

void polyAdd(struct poly *a, struct poly *b){
	struct poly *p = a, *q = b;
	while(p != NULL && q != NULL){
		if(p->ex == q->ex){
			int sum = p->co + q->co;
			result(sum, p->ex);
			p = p->link;
			q = q->link;
		}
		else if(p->ex > q->ex){
			result(p->co, p->ex);
			p = p->link;
		}
		else{
			result(q->co, q->ex);
			q = q->link;
		}
	}
	while(p != NULL){
		result(p->co, p->ex);
		p = p->link;
	}
	while(q != NULL){
		result(q->co, q->ex);
		q = q->link;
	}
}

void result(int coe, int exp){
	struct poly *r = malloc(sizeof(struct poly));
	r->co = coe;
	r->ex = exp;
	r->link = NULL;
	if(c == NULL){
		c = r;
		temp_res = r;
	}
	else{
		temp_res->link = r;
		temp_res = r;
	}
}
// Final de-allocation of SLL
// Choice 4
void exit_free(struct poly *start){
	struct poly *loc, *temp;
	if(start != NULL){
		temp = start;
		loc = temp->link; // link node
		while(loc != NULL){
			free(temp);
			temp = loc;
			loc = loc->link;
		}
		free(temp);
	}
}
