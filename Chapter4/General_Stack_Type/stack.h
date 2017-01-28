#include <stdlib.h>

typedef struct nodo{
	StackData data;
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

void push(Stack S, StackData d){
	ptrNodo new = (ptrNodo) malloc(sizeof(Nodo));
	new -> data = d;
	new -> next = S -> top;
	S -> top = new;
}

StackData pop(Stack S){
	if(empty(S))
		exit(1);
	StackData hold = S -> top -> data;
	ptrNodo temp = S -> top;
	S -> top = S -> top -> next;
	free(temp);
	return hold;
}