// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 17/2910
// Circular Singly Linked List
// Dynamic Memory Allocation

// Please review program before execution.
// Incomplete or Error Prone !

#include<stdio.h>
#include<stdlib.h>

void ins_b();
void ins_e();
void ins_p();

void del_b();
void del_e();
void del_p();

void display();
void exit_free();

struct node{
	int data;
	struct node *link;
};

struct node *start = NULL;
struct node *temp;

void main(){
	int ch;
	while(1){
		printf("\n\n*** CIRCULAR SINGLY LINKED LIST [C - SLL] ***");
		printf("\nInsert at >>  1. Beginning  2. End  3. Position");
		printf("\nDelete at >>  4. Beginning  5. End  6. Position");
		printf("\n          >>  7. Display    8. Exit");
		printf("\nEnter choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: ins_b(); break;
			case 2: ins_e(); break;
			case 3: ins_p(); break;
			
			case 4: del_b(); break;
			case 5: del_e(); break;
			case 6: del_p(); break;
			
			case 7: display(); break;
			default: exit_free(); return;
		}
	}
}


// Insertion at beginning
// Choice 1
void ins_b(){
	int d;
	struct node *a = malloc(sizeof(struct node));
	printf("\tEnter data: ");
	scanf("%d", &(a->data));
	a->link = start;
	start = a;
	printf("\n\tSuccessfully inserted %d at beginning", a->data);
}


// Insertion at end
// Choice 2
void ins_e(){
	struct node *a = malloc(sizeof(struct node));
	printf("\tEnter data: ");
	scanf("%d", &(a->data));
	a->link = NULL;
	if(start == NULL){
		a->link = start;
		start = a;
	}
	else{
		for(temp = start; temp->link != NULL; temp = temp->link);
		temp->link = a;
	}
	printf("\n\tSuccessfully inserted %d at end", a->data);
}


// Insertion at specific valid position
// Choice 3
void ins_p(){
	int pos, i = 1;
	printf("\tEnter position: ");
	scanf("%d", &pos);
	if(pos == 1){
		ins_b();
		return;
	}
	for(temp = start; temp != NULL && i < (pos - 1); i++){
		temp = temp->link;
	}
	if(temp != NULL){
		struct node *a = malloc(sizeof(struct node));
		printf("\tEnter data: ");
		scanf("%d", &(a->data));
		a->link = temp->link;
		temp->link = a;
		printf("\n\tSuccessfully inserted %d at position %d", a->data, pos);
	}
	else{
		printf("\tError in position!");
	}
}


// Deletion of node at start
// Choice 4 
void del_b(){
	if(start == NULL){
		printf("\n\tSLL is Empty");
	}
	else{
		temp = start;
		start = start->link;
		printf("\n\tSuccessfully deleted %d from the beginning", temp->data);
		free(temp);
	}
}


// Deletion of node at end
// Choice 5
void del_e(){
	if(start == NULL){
		printf("\n\tSLL is Empty");
	}
	else if(start->link == NULL){
		del_b();
	}
	else{
		for(temp = start; (temp->link)->link != NULL; temp = temp->link);
		printf("\n\tSuccessfully deleted %d from the end", (temp->link)->data);
		free(temp->link);
		temp->link = NULL;
	}
}


// Deletion of node at specific position
// Choice 6
void del_p(){
	if (start == NULL){
		printf("\n\tSLL is Empty");
		return;
	}
	int pos;
	printf("\tEnter position: ");
	scanf("%d", &pos);
	if(pos <= 0){
		printf("\tError in position! Do not enter index");
		return;
	}
	if(pos == 1){
		del_b();
		return;
	}
	int i = 1;
	for(temp = start; temp != NULL && i < (pos - 1); i++){
		temp = temp->link;
	}
	struct node *loc;
	loc = temp->link;
	if(temp != NULL && loc != NULL){
		temp->link = loc->link;
		printf("\n\tSuccessfully deleted %d from position %d", loc->data, pos);
		free(loc);
	}
	else{
		printf("\tError in position!");
	}
}

// Displaying all nodes - Start to NULL
// Choice 7
void display(){
	printf("\n\tCuurent SLL >>>");
	for(temp = start; temp != NULL; temp = temp->link){
		printf(" %d ->", temp->data);
	}
	printf(" NULL");
}


// Final de-allocation of SLL
// Choice 8
void exit_free(){
	struct node *loc;
	if(start != NULL){
		temp = start;
		loc = temp->link; // Next node
		while(loc != NULL){
			free(temp);
			temp = loc;
			loc = loc->link;
		}
		free(temp);
	}
}
