// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 24/0312
// Binary Search Tree using Linked List

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *lchild, *rchild;
};

struct node *root = NULL;

void insert();

void inorder_nr();
void inorder(struct node *r);
void postorder(struct node *r);
void preorder(struct node *r);

void search();

void del(int item);

void exit_free(struct node *r);

void main()
{
	while(1){
		printf("\n\n*** Tree Options ***");
		printf("\n1. Insert  2. Traverse  3. Search  4. Delete  5. Exit");
		int ch;
		printf("\nEnter Choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: insert(); break;
			case 2:{
				if(root == NULL){
					printf("\tEmpty Binary Search Tree");
					break;
				}
				printf("\t*** Traversal Option ***");
				printf("\n\t1. Inorder(NR)  2. Inorder  3. Preorder  4. Postorder");
				printf("\n\tEnter Choice: ");
				scanf("%d", &ch);
				printf("\t\t");
				switch(ch){
					case 1: inorder_nr(); break;
					case 2: inorder(root); break;
					case 3: preorder(root); break;
					case 4: postorder(root); break;
					
				}
				break;
			}
			case 3:{
				if(root == NULL){
					printf("\tEmpty Binary Search Tree");
					break;
				}
				search(); 
				break;
			} 
			case 4:{
				if(root == NULL){
					printf("\tEmpty Binary Search Tree");
					break;
				}
				int item;
				printf("\tEnter item to delete : ");
				scanf("%d", &item);
				del(item); 
				break;
			} 
			default: exit_free(root); return;
		}
	}
}

void insert(){
	struct node *x = malloc(sizeof(struct node));
	printf("\tEnter data to insert: ");
	scanf("%d", &(x->data));
	x->lchild = NULL;
	x->rchild = NULL;
	if(root == NULL){
		root = x;
		printf("\tSuccessfully Inserted.");
		return;
	}
	struct node *ptr, *parent;
	ptr = root;
	while(ptr != NULL){
		parent = ptr;
		if(x->data > ptr->data){
			ptr = ptr->rchild;
		}
		else if(x->data < ptr->data){
			ptr = ptr->lchild;
		}
		else{
			printf("\tDuplicate Element. Could Not Insert.");
			free(x);
			return;
		}
	}
	if(x->data > parent->data){
		parent->rchild = x;
	}
	else{
		parent->lchild = x;
	}
	printf("\tSuccessfully Inserted.");
}

void inorder(struct node *r){
	struct node *ptr = r;
	if(ptr != NULL){
		inorder(ptr->lchild);
		printf("%d  ", ptr->data);
		inorder(ptr->rchild);
	}
}
void preorder(struct node *r){
	struct node *ptr = r;
	if(ptr != NULL){
		printf("%d  ", ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}
void postorder(struct node *r){
	struct node *ptr = r;
	if(ptr != NULL){
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d  ", ptr->data);
	}
}

// *** Stack using SLL ***
// START -----------------

struct snode{
	struct node *data;
	struct snode *link;
};

struct snode *TOP = NULL;
struct snode *temp;

void push(struct node *item){
	int d;
	struct snode *a = malloc(sizeof(struct snode));
	a->data = item;
	a->link = TOP;
	TOP = a;
}


struct node *pop(){
	if(TOP == NULL){
		printf("\tStack Underflow");
	}
	else{
		temp = TOP;
		TOP = TOP->link;
		struct node *item = temp->data;
		free(temp);
		return item;
	}
}

// END -------------------
// *** Stack using SLL ***

void inorder_nr(){
	// NR = Non Recursive
	struct node *ptr = root;
	while(TOP != NULL || ptr != NULL){
		if(ptr != NULL){
			push(ptr);
			ptr = ptr->lchild;
		}
		else{
			ptr = pop();
			printf("%d  ", ptr->data);
			ptr = ptr->rchild;
		}
	}
}

void search(){
	int item;
	printf("\tEnter item to search : ");
	scanf("%d", &item);
	struct node *ptr = root;
	while(ptr != NULL){
		if(item > ptr -> data){
			ptr = ptr->rchild;
		}
		else if(item < ptr->data){
			ptr = ptr->lchild;
		}
		else{
			printf("\t%d found.", item);
			return;
		}
	}
	printf("\t%d could not be found.", item);
}

struct node *succ(struct node *ptr){
	ptr = ptr->rchild; //mutate
	while(ptr->lchild != NULL){
		ptr = ptr->lchild;
	}
	return ptr;
}
void del(int item){
	int flag = 0;
	struct node *ptr = root, *parent = root;
	while(ptr != NULL){
		if(item == ptr->data){
			flag = 1;
			break;
		}
		// ALGO EDIT R->R->R
		// To avoid parent == ptr
		parent = ptr;
		if(item > ptr -> data){
			ptr = ptr->rchild;
		}
		else{
			ptr = ptr->lchild;
		}
	}
	if(flag == 0){
		printf("\t%d could not be found.", item);
		return;
	}
	// Three cases as is from ppt algorithm
	int ch;
	if(ptr->lchild == NULL && ptr->rchild == NULL){
		ch = 1;
	}
	else if(ptr->lchild != NULL && ptr->rchild != NULL){
		ch = 3;
	}
	else{
		ch = 2;
	}
	switch(ch){
		case 1:{
			if(ptr == root){ 
				root = NULL; // Add condition
			}
			else if(parent->lchild == ptr){
				parent->lchild = NULL;
			}
			else{
				parent->rchild = NULL;
			}
			free(ptr);
			break;
		}
		case 2:{
			if(ptr == root){ 
				if(ptr->lchild == NULL){
					root = ptr->rchild;
				}
				else{
					root = ptr->lchild;
				}
			}
			else if(parent->lchild == ptr){
				if(ptr->lchild == NULL){
					parent->lchild = ptr->rchild;
				}
				else{
					parent->lchild = ptr->lchild;
				}
			}
			else{
				if(ptr->lchild == NULL){
					parent->rchild = ptr->rchild;
				}
				else{
					parent->rchild = ptr->lchild;
				}
			}
			free(ptr);
			break;
		}
		case 3:{
			struct node *sp = succ(ptr);
			int sd = sp->data;
			del(sd);
			ptr->data = sd;
			return; // Just to avoid printing feedback twice
		}
	}
	printf("\tSuccessfully deleted.");
}

void exit_free(struct node *r){
	struct node *ptr = r;
	if(ptr != NULL){
		exit_free(ptr->lchild);
		exit_free(ptr->rchild);
		free(ptr);
	}
}
