#include <stdlib.h>

#define ERR -9999

typedef struct nodo{
	int num;
	struct nodo *next;
}Nodo, *ptrNodo;

typedef struct{
	ptrNodo top;
}StackType, *Stack;

Stack initStack(){
	Stack S = (Stack) malloc(sizeof(StackType));
	S -> top = NULL;
	return S;
}

int empty(Stack S){
	return (S -> top == NULL);
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
	int aux = S -> top -> num;
	ptrNodo temp = S -> top;
	S -> top = S -> top -> next;
	free(temp);
	return aux;
}