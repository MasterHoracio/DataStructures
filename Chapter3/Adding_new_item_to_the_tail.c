#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *next;
} Node, *ptrNode;

int main(){
	void printList(ptrNode);
	ptrNode makeNode(int);
	int n;
	ptrNode top, np, last;

	top = NULL;

	while(scanf("%d",&n)){
		if(n == 0)
			break;
		np = makeNode(n);
		if(top == NULL)
			top = np;
		else
			last -> next = np;
		last = np;
	}

	printList(top);

	return 0;
}

ptrNode makeNode(int n){
	ptrNode np = (ptrNode)malloc(sizeof(Node));
	np->num = n;
	np->next = NULL;
	return np;
}

void printList(ptrNode np){
	while(np != NULL){
		printf("%d\n",np->num);
		np = np->next;
	}
}