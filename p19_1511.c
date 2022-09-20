// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 19/1511
// Stack Implementation
// Dynamic Memory Allocation

#include<stdio.h>
#include<stdlib.h>

void push();
void pop();
void display();

void exit_free();

struct node{
	int data;
	struct node *link;
};

struct node *TOP = NULL;
struct node *temp;

void main(){
	int ch;
	while(1){
		printf("\n\n*** STACK OPTIONS ***");
		printf("\n1. PUSH  2. POP  3. DISPLAY  4. EXIT");
		printf("\nEnter choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: push(); break;
			case 2: pop(); break;
			case 3: display(); break;
			default: exit_free(); return;
		}
	}
}


// Insertion at beginning - PUSH
// Choice 1
void push(){
	int d;
	struct node *a = malloc(sizeof(struct node));
	printf("\tEnter data: ");
	scanf("%d", &(a->data));
	a->link = TOP;
	TOP = a;
	printf("\tSuccessfully Pushed %d", a->data);
}


// Deletion from beginning - POP
// Choice 2
void pop(){
	if(TOP == NULL){
		printf("\tStack Underflow");
	}
	else{
		temp = TOP;
		TOP = TOP->link;
		printf("\tSuccessfully Popped %d", temp->data);
		free(temp);
	}
}

// Displaying all nodes
// Choice 3
void display(){
	if(TOP == NULL){
		printf("\tStack Underflow");
		return;
	}
	printf("\tCuurent STACK >>>");
	for(temp = TOP; temp != NULL; temp = temp->link){
		printf("\n\t%d", temp->data);
	}
}


// Final de-allocation of SLL
// Choice 4
void exit_free(){
	struct node *loc;
	if(TOP != NULL){
		temp = TOP;
		loc = temp->link; // Next node
		while(loc != NULL){
			free(temp);
			temp = loc;
			loc = loc->link;
		}
		free(temp);
	}
}
