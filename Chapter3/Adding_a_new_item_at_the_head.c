#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *next;
}Node, *ptrNode;

void printlist(ptrNode);
ptrNode makeNode(int);

int main(){
	int n;
	ptrNode top, np;
	top = NULL;
	while(scanf("%d",&n)){
		if(n == 0)
			break;
		np = makeNode(n);
		np->next = top;
		top = np;
	}

	printlist(top);
	return 0;
}

ptrNode makeNode(int n){
	ptrNode np = (ptrNode) malloc(sizeof(Node));
	np->num = n;
	np->next = NULL;
	return np;
}

void printlist(ptrNode np){
	while(np != NULL){
		printf("%d\n",np->num);
		np = np->next;
	}
}