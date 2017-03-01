#include <stdlib.h>

typedef struct nodo{
	StackData data;
	struct nodo *next;
}Nodo, *ptrNodo;

typedef struct{
	ptrNodo top;
}*Stack, StackType;

Stack initStack(){
	Stack S = (Stack) malloc(sizeof(StackType));
	S -> top = NULL;
	return S;
}

int empty(Stack S){
	return (S -> top == NULL);
}

void push(Stack S, StackData d){
	ptrNodo nodo = (ptrNodo) malloc(sizeof(Nodo));
	nodo -> data = d;
	nodo -> next = S -> top;
	S -> top = nodo;
}

StackData pop(Stack S){
	StackData hold = S -> top -> data;
	ptrNodo temp = S -> top;
	S -> top = S -> top -> next;
	free(temp);
	return hold;
}

StackData peek(Stack S){
	return S -> top -> data;
}