// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 20/1511
// Queue Implementation
// Dynamic Memory Allocation

// Please review. 
// Code does not meet required standard.
// Use SLL to implement !

#include<stdio.h>
#include<stdlib.h>

void enqueue();
void dequeue();
void display();
void exit_free();

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *FRONT = NULL;
struct node *REAR = NULL;
struct node *temp;

void main(){
	int ch;
	while(1){
		printf("\n\n*** QUEUE OPTIONS ***");
		printf("\n1. ENQUEUE  2. DEQUEUE  3. DISPLAY  4. EXIT");
		printf("\nEnter choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: enqueue(); break;
			case 2: dequeue(); break;
			case 3: display(); break;
			default: exit_free(); return;
		}
	}
}


// Insertion at end
// Choice 2
void enqueue(){
	struct node *a = malloc(sizeof(struct node));
	printf("\tEnter data: ");
	scanf("%d", &(a->data));
	if(FRONT == NULL && REAR == NULL){
		a->prev = NULL;
		a->next = NULL;
		FRONT = a;
		REAR = a;
	}
	else{
		REAR->next = a;
		a->prev = REAR;
		a->next = NULL;
		REAR = a;
	}
	printf("\tSuccessfully enqueued %d", a->data);
}

// Deletion of beginning node
// Choice 4
void dequeue(){
	if(FRONT == NULL && REAR == NULL){
		printf("\n\tQUEUE is Empty");
		return;
	}
	temp = FRONT;
	printf("\n\tSuccessfully dequeued %d", temp->data);
	if(FRONT != REAR){
		FRONT = FRONT->next;
		FRONT->prev = NULL;
	}
	else{
		FRONT = NULL;
		REAR = NULL;
	}
	free(temp);
}


// Display DLL - FRONT to REAR
// Choice 7
void display(){
	if(FRONT == NULL && REAR == NULL){
		printf("\n\tQUEUE is Empty");
		return;
	}
	printf("\n\tCuurent QUEUE >>>");
	for(temp = FRONT; temp != NULL; temp = temp->next){
		printf(" %d  ", temp->data);
	}
}


// Final de-allocation of DLL
// de-allocation from FRONT
// Choice 9
void exit_free(){
	struct node *loc;
	if(FRONT != NULL){
		temp = FRONT;
		loc = temp->next; // Next node
		while(loc != NULL){
			free(temp);
			temp = loc;
			loc = loc->next;
		}
		free(temp);
	}
}
