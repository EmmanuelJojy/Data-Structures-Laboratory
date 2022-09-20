// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 16/2510
// DLL Doubly Linked List
// Dynamic Memory Allocation

#include<stdio.h>
#include<stdlib.h>

void ins_b();
void ins_e();
void ins_p();

void del_b();
void del_e();
void del_p();

void display_h();
void display_t();
void exit_free();

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *temp;

void main(){
	int ch;
	while(1){
		printf("\n\n*** DOUBLY LINKED LIST [DLL] ***");
		printf("\nInsert at >>  1. Beginning  2. End  3. Position");
		printf("\nDelete at >>  4. Beginning  5. End  6. Position");
		printf("\nDisplay   >>  7. From Head  8. From Tail");
		printf("\n          >>  9. Exit");
		printf("\nEnter choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: ins_b(); break;
			case 2: ins_e(); break;
			case 3: ins_p(); break;
			
			case 4: del_b(); break;
			case 5: del_e(); break;
			case 6: del_p(); break;
			
			case 7: display_h(); break;
			case 8: display_t(); break;
			
			default: exit_free(); return;
		}
	}
}


// Insertion at Start
// Choice 1
void ins_b(){
	struct node *a = malloc(sizeof(struct node));
	printf("\tEnter data: ");
	scanf("%d", &(a->data));
	if(head == NULL && tail == NULL){
		a->prev = NULL;
		a->next = NULL;
		head = a;
		tail = a;
	}
	else{
		a->next = head;
		a->prev = NULL;
		head->prev = a;
		head = a;
	}
	printf("\tSuccessfully inserted %d", a->data);
}


// Insertion at end
// Choice 2
void ins_e(){
	struct node *a = malloc(sizeof(struct node));
	printf("\tEnter data: ");
	scanf("%d", &(a->data));
	if(head == NULL && tail == NULL){
		a->prev = NULL;
		a->next = NULL;
		head = a;
		tail = a;
	}
	else{
		tail->next = a;
		a->prev = tail;
		a->next = NULL;
		tail = a;
	}
	printf("\tSuccessfully inserted %d", a->data);
}


// Insertion at specific position
// Choice 3
void ins_p(){
	int pos, i = 1;
	printf("\tEnter position: ");
	scanf("%d", &pos);
	if(pos <= 0){
		printf("\tError in position! Do not enter index");
		return;
	}
	if(pos == 1){
		ins_b();
		return;
	}
	
	for(temp = head; temp != NULL && i < (pos - 1); i++){
		temp = temp->next;
	}
	if(temp != NULL){
		struct node *a = malloc(sizeof(struct node));
		struct node *loc;
		loc = temp->next;
		printf("\tEnter data: ");
		scanf("%d", &(a->data));
		a->prev = temp;
		a->next = loc;
		temp->next = a;
		if(loc == NULL){
			// Insertion at end
			tail = a;
		}
		else{
			loc->prev = a;
		}
		printf("\tSuccessfully inserted %d at position %d", a->data, pos);
	}
	else{
		printf("\tError in position!");
	}
}


// Deletion of beginning node
// Choice 4
void del_b(){
	if(head == NULL && tail == NULL){
		printf("\n\tDLL is Empty");
		return;
	}
	temp = head;
	printf("\n\tSuccessfully deleted %d", temp->data);
	if(head != tail){
		head = head->next;
		head->prev = NULL;
	}
	else{
		head = NULL;
		tail = NULL;
	}
	free(temp);
}


// Deletion of node from end
// Choice 5
void del_e(){
	if(head == NULL && tail == NULL){
		printf("\n\tDLL is Empty");
		return;
	}
	temp = tail;
	printf("\n\tSuccessfully deleted %d", temp->data);
	if(head != tail){
		tail = tail->prev;
		tail->next = NULL;
	}
	else{
		head = NULL;
		tail = NULL;
	}
	free(temp);
}


// Deletion of node at specific position
// Choice 6
void del_p(){
	if(head == NULL && tail == NULL){
		printf("\n\tDLL is Empty");
		return;
	}
	int pos, i = 1;
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
	for(temp = head; temp != NULL && i < (pos - 1); i++){
		temp = temp->next;
	}
	struct node *loc;
	loc = temp->next;
	if(temp != NULL && loc != NULL){
		if(loc == tail){
			del_e();
			return;
		}
		else{
			temp->next = loc->next;
			loc->next->prev = temp;
			printf("\tSuccessfully deleted %d from position %d", loc->data, pos);
			free(loc);
		}
	}
	else{
		printf("\tError in position!");
	}
}


// Display DLL - Head to Tail
// Choice 7
void display_h(){
	printf("\n\tCuurent DLL >>>");
	for(temp = head; temp != NULL; temp = temp->next){
		printf(" %d <->", temp->data);
	}
	printf(" NULL");
}


// Display DLL - Tail to Head - Reverse
// Choice 8
void display_t(){
	printf("\n\tCuurent DLL >>>");
	for(temp = tail; temp != NULL; temp = temp->prev){
		printf(" %d <->", temp->data);
	}
	printf(" NULL");
}


// Final de-allocation of DLL
// de-allocation from head
// Choice 9
void exit_free(){
	struct node *loc;
	if(head != NULL){
		temp = head;
		loc = temp->next; // Next node
		while(loc != NULL){
			free(temp);
			temp = loc;
			loc = loc->next;
		}
		free(temp);
	}
}
