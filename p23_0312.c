// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 23/0312
// Binary Tree using Linked List

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *lchild, *rchild;
};

struct node *root = NULL;

void exit_free(struct node *r);

struct node *search(struct node *r, int key){
	struct node *x = NULL;
	if(r->data == key){
		return r;
	}
	else if(r->lchild != NULL){
		x = search(r->lchild, key);
	}
	if(x == NULL && r->rchild != NULL){
		x = search(r->rchild, key);
	}
	return x;
}

// Additional function to obtain parent
// of a key node
struct node *parent(struct node *r, struct node *key){
	struct node *x = NULL;
	if(r->lchild == key || r->rchild == key){
		return r;
	}
	else if(r->lchild != NULL){
		x = parent(r->lchild, key);
	}
	if(x == NULL && r->rchild != NULL){
		x = parent(r->rchild, key);
	}
	return x;
}


void insert(int key, int item){
	struct node *i = search(root, key);
	if(i != NULL && (i->lchild == NULL || i->rchild == NULL)){
		struct node *x = malloc(sizeof(struct node));
		x -> data = item;
		x -> lchild = NULL;
		x -> rchild = NULL;
		printf("\tChild Option: 1. Left  2. Right");
		printf("\n\tEnter Choice : ");
		int ch;
		scanf("%d", &ch);
		if(ch == 1 && i->lchild == NULL){
			i->lchild = x;
		}
		else if(ch == 2 && i->rchild == NULL){
			i->rchild = x;
		}
		else{
			printf("Could Not Insert. Child Not Empty.");
			free(x);
			return;
		}
	}
	else{
		printf("\tInsertion Unsuccessful. Choose Leaf Node");
		return;
	}
	printf("\tInsertion Successful.");
}

void del(int key){
	struct node *ptr = search(root, key), *par;
	if(ptr == NULL){
		printf("\tCould Not Find %d", key);
		return;
	}
	
	// Primary check to see if node
	// is deletable. lc = rc = X
	// Root also handled.
	if(ptr -> lchild != NULL || ptr -> rchild != NULL){
		printf("\tDeletion Unsuccessful. Choose a leaf node.");
		return;
	}
	
	// Never expecting parent to be NULL
	// unless ptr is root
	par = parent(root, ptr);
	if(par == NULL){
		root = NULL;
	}
	else if(par->lchild == ptr){
		par->lchild = NULL;
	}
	else{
		par->rchild = NULL;
	}
	free(ptr);
	printf("\tDeletion Successful.");
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

void build(struct node *r){
	int ch, item;
	printf("   Does Node [%d] have left  subtree [1-yes]: ", r->data);
	scanf("%d", &ch);
	if(ch == 1){
		struct node *n = malloc(sizeof(struct node));
		printf("   >>Enter Data: ");
		scanf("%d", &item);
		n -> data = item;
		n -> lchild = NULL;
		n -> rchild = NULL;
		r -> lchild = n;
		build(n);
	}
	printf("   Does Node [%d] have right subtree [1-yes]: ", r->data);
	scanf("%d", &ch);
	if(ch == 1){
		struct node *n = malloc(sizeof(struct node));
		printf("   >>Enter Data: ");
		scanf("%d", &item);
		n -> data = item;
		n -> lchild = NULL;
		n -> rchild = NULL;
		r -> rchild = n;
		build(n);
	}
}

void main(){
	int n, ch;
	printf("--- Binary Tree Using Linked List ---");
	while(1){
		if(root == NULL){
			printf("\n\n*** Build Binary Tree ***");
			printf("\nEnter Root Element: ");
			scanf("%d", &n);
			struct node *x = malloc(sizeof(struct node));
			x->data = n;
			x->lchild = NULL;
			x->rchild = NULL;
			root = x;
			build(root);
		}
		printf("\n\n*** Binary Tree Options ***");
		printf("\n1. Search  2. Traverse  3. Insert  4. Delete  5. Exit\nChoice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1:{
				printf("\tEnter element to search: ");
				scanf("%d", &n);
				if(search(root, n) == NULL){
					printf("\tCould Not Find Element.");
				}
				else{
					printf("\tElement Found.");
				}
				break;
			}
			case 2:{
				printf("\t*** Traversal Option ***");
				printf("\n\t1. Inorder  2. Preorder  3. Postorder");
				printf("\n\tEnter Choice: ");
				scanf("%d", &ch);
				printf("\t\t");
				switch(ch){
					case 1: inorder(root); break;
					case 2: preorder(root); break;
					case 3: postorder(root); break;
				}
				break;
			}
			case 3:{
				int pnode, item;
				printf("\tEnter Parent Node: ");
				scanf("%d", &pnode);
				printf("\tEnter item to insert: ");
				scanf("%d", &item);
				insert(pnode, item);
				break;
			}
			case 4:{
				printf("\tEnter item to delete: ");
				scanf("%d", &n);
				del(n);
				break;
			}
			default: exit_free(root); return;
		}
	}
}

void exit_free(struct node *r){
	struct node *ptr = r;
	if(ptr != NULL){
		exit_free(ptr->lchild);
		exit_free(ptr->rchild);
		free(ptr);
	}
}
