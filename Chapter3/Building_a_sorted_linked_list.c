#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *next;
}Node, *ptrNode;

void printList(ptrNode);
ptrNode addInPlace(ptrNode,int);
ptrNode makeNode(int);

int main(){
	ptrNode top = NULL;
	int n;
	while(scanf("%d",&n)){
		if(n == 0)
			break;
		top = addInPlace(top,n);
	}
	printList(top);
	return 0;
}

ptrNode addInPlace(ptrNode top, int n){
	ptrNode curr, prev, np;

	np = makeNode(n);

	prev = NULL;
	curr = top;

	while(curr != NULL && n > curr->num){
		prev = curr;
		curr = curr->next;
	}

	if(prev == NULL){
		np->next = top;
		return np;
	}
	np->next = curr;
	prev->next = np;
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
		printf("%d\n",np->num);
		np = np->next;
	}
}