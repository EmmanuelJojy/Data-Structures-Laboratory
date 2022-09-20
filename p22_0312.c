// Emmanuel Jojy
// S3 CSE A 
// Roll no: 53

// Prg 22/0312
// Binary Tree using Array

#include<stdio.h>

#define N 20

// Using character array
// 0 represent NUL
char A[N + 1];

void init(){
	// Setting all values to NUL
	for(int i = 0; i < N + 1; i++){
		A[i] = 0;
	}
}

int search(int index, char key){
	int i = index, x;
	if(A[i] == key){
		return i;
	}
	else if(2 * i <= N){
		x = search(2 * i, key);
	}
	else{
		return 0;
	}
	if(x == 0 && 2 * i + 1 <= N){
		x = search(2 * i + 1, key);
	}
	return x;
}

void insert(char key, char item){
	int l = search(1, key);
	if(l == 0){
		printf("\tElement Not Found");
		return;
	}
	if(A[2*l] == 0 || A[2*l + 1] == 0){
		printf("\tChild Option: 1. Left  2. Right");
		printf("\n\tEnter Choice : ");
		int ch;
		__fpurge(stdin);
		scanf("%d", &ch);
		if(ch == 1 && A[2*l] == 0){
			A[2 * l] = item;
		}
		else if(ch == 2 && A[2 * l + 1] == 0){
			A[2 * l + 1] = item;
		}
		else{
			printf("\tInsertion Unsuccessful");
			return;
		}
	}
	else{
		printf("\tInsertion Unsuccessful. Choose Leaf Node");
		return;
	}
	printf("\tInsertion Successful");
}

void del(char key){
	int l = search(1, key);
	if(l == 0){
		printf("\tElement Not Found");
	}
	else if(A[2*l] == 0 && A[2*l + 1] == 0){
		A[l] = 0;
		printf("\tDeletion Successful");
	}
	else{
		printf("\tDeletion Unsuccessful. Node is not a leaf node");
	}
}

void build(int l, char item){
	if(l != 0){
		char ch;
		A[l] = item;
		printf("   Does Node [%c] have left  subtree [1-yes]: ", A[l]);
		__fpurge(stdin);
		scanf("%c", &ch);
		if(ch == '1'){
			printf("   >>Enter Item: ");
			__fpurge(stdin);
			scanf("%c", &ch);
			build(2 * l, ch);
		}
		printf("   Does Node [%c] have right subtree [1-yes]: ", A[l]);
		__fpurge(stdin);
		scanf("%c", &ch);
		if(ch == '1'){
			printf("   >>Enter Item: ");
			__fpurge(stdin);
			scanf("%c", &ch);
			build(2 * l + 1, ch);
		}
	}
}

void inorder(int index){
	if(index <= N && A[index] != 0){
		inorder(2 * index);
		printf("%c  ", A[index]);
		inorder(2 * index + 1);
	}
}

void preorder(int index){
	if(index <= N && A[index] != 0){
		printf("%c  ", A[index]);
		preorder(2 * index);
		preorder(2 * index + 1);
	}
}

void postorder(int index){
	if(index <= N && A[index] != 0){
		postorder(2 * index);
		postorder(2 * index + 1);
		printf("%c  ", A[index]);
	}
}

void main(){
	init();
	char ch;
	printf("--- Binary Tree using Array with MAXSIZE %d ---", N);
	int i;
	while(1){
		if(A[1] == 0){
			printf("\n\n### Build Binary Tree ###\nEnter Root Item: ");
			__fpurge(stdin);
			scanf("%c", &ch);
			build(1, ch);
		}
		printf("\n\n*** Binary Tree Options ***");
		printf("\n1. Search  2. Traverse  3. Insert  4. Delete  5. Exit\nChoice: ");
		__fpurge(stdin);
		scanf("%d", &i);
		switch(i){
			case 1:{
				printf("\tEnter element to search: ");
				__fpurge(stdin);
				scanf("%c", &ch);
				if(search(1, ch) == 0){
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
				scanf("%d", &i);
				printf("\t\t");
				switch(i){
					case 1: inorder(1); break;
					case 2: preorder(1); break;
					case 3: postorder(1); break;
				}
				break;
			}
			case 3:{
				char pnode, item;
				printf("\tEnter Parent Node: ");
				__fpurge(stdin);
				scanf("%c", &pnode);
				printf("\tEnter item to insert: ");
				__fpurge(stdin);
				scanf("%c", &item);
				insert(pnode, item);
				break;
			}
			case 4:{
				printf("\tEnter item to delete: ");
				__fpurge(stdin);
				scanf("%c", &ch);
				del(ch);
				break;
			}
			default: return;
		}
	}
}
