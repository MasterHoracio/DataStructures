#include <stdio.h>
#include <stdlib.h>

#define ERR -9999

typedef struct nodo{
	int num;
	struct nodo *next;
}Nodo, *ptrNodo;

typedef struct{
	ptrNodo top;
}StackType, *Stack;

Stack initStack();
int empty(Stack);
void push(Stack,int);
int pop(Stack);

int main(){
	Stack S;
	int num;

	S = initStack();

	if(scanf("%d",&num) != 1)
		num = 0;

	while(num != 0){
		push(S, num);
		if(scanf("%d",&num) != 1)
			num = 0;
	}

	printf("Lista invertida: \n");

	while(!empty(S)){
		printf("%d ",pop(S));
	}printf("\n");


	return 0;
}

Stack initStack(){
	Stack S = (Stack) malloc(sizeof(StackType));
	S -> top = NULL;
	return S;
}

void push(Stack S, int n){
	ptrNodo new = (ptrNodo) malloc(sizeof(Nodo));
	new -> num = n;
	new -> next = S -> top;
	S -> top = new;
}

int pop(Stack S){
	if(empty(S))
		return ERR;
	int num = S -> top -> num;
	ptrNodo temp = S -> top;
	S -> top = S -> top -> next;
	free(temp);
	return num;
}

int empty(Stack S){
	return (S -> top == NULL);
}