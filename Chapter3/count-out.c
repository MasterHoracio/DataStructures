#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *next;
}Node, *ptrNode;

ptrNode makeNode(int);
ptrNode linkCircular(int);
ptrNode playGame(ptrNode,int,int);

int main(){
	ptrNode curr;
	int n, m;

	printf("Enter the number of children and length of count-out: ");
	scanf("%d %d",&n,&m);

	curr = linkCircular(n);

	curr = playGame(curr,n-1,m);

	printf("The winning child is: %d\n",curr->num);

	return 0;
}

ptrNode makeNode(int n){
	ptrNode np = (ptrNode) malloc(sizeof(Node));
	np->num = n;
	np->next = NULL;
	return np;
}

ptrNode linkCircular(int n){
	ptrNode first, np;
	first = np = makeNode(1);
	for(int i = 2; i <= n; i++){
		np->next = makeNode(i);
		np = np->next;
	}
	np->next = first;
	return first;
}

ptrNode playGame(ptrNode first, int x, int m){
	ptrNode prev, curr = first;
	for(int i = 1; i <= x; i++){
		for(int j = 1; j < m; j++){
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		free(curr);
		curr = prev->next;
	}
	return curr;
}