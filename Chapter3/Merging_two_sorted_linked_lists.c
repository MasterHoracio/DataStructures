#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *next;
}Node,*ptrNode;

void printList(ptrNode);
ptrNode makeList(void);
ptrNode merge(ptrNode,ptrNode);

int main(){
	ptrNode A, B;

	printf("Enter sorted numbers for the first list (0 to end)\n");
	A = makeList();
	printf("Enter sorted numbers for the second list (0 to end)\n");
	B = makeList();

	printf("\nThe merge list is\n");

	printList(merge(A,B));

	return 0;
}

ptrNode makeList(){
	ptrNode makeNode(int), np, top, last;
	int n;
	top = NULL;
	while(scanf("%d",&n)){
		if(n == 0)
			break;
		np = makeNode(n);
		if(top == NULL)
			top = np;
		else
			last->next = np;
		last = np;
	}
	return top;
}

ptrNode makeNode(int n){
	ptrNode np = (ptrNode) malloc(sizeof(Node));
	np->num = n;
	np->next = NULL;
	return np;
}

void printList(ptrNode np){
	while(np != NULL){
		printf("%d ",np->num);
		np = np->next;
	}printf("\n");
}

ptrNode merge(ptrNode A, ptrNode B){
	ptrNode C = NULL, last = NULL;
	if(A == NULL)
		return B;
	if(B == NULL)
		return A;
	while(A != NULL && B != NULL){
		if(A->num < B->num){
			if(C == NULL)
				C = A;
			else
				last->next = A;
			last = A;
			A = A->next;
		}else{
			if(C == NULL)
				C = B;
			else
				last->next = B;
			last = B;
			B = B->next;
		}
	}
	if(A == NULL)
		last->next = B;
	else
		last->next = A;
	return C;
}