#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *prev;
	struct nodo *next;
}tNodo, *ptrNodo;

typedef struct{
	ptrNodo top;
	ptrNodo tail;
}linkedList;

int empty(linkedList lista){
	return lista.top == NULL;
}

linkedList insertTop(linkedList lista, int n){
	ptrNodo new = (ptrNodo) malloc(sizeof(tNodo));
	
	new -> num = n;
	new -> prev = NULL;
	new -> next = NULL;
	
	if(empty(lista)){
		lista.top = new;
		lista.tail = new;
	}else{
		new -> next = lista.top;
		lista.top->prev = new;
		lista.top = new;
	}
	
	return lista;
}

void printLista(linkedList lista){
	while(lista.top != NULL){
		printf("%d ",lista.top->num);
		lista.top = lista.top->next;
	}printf("\n");
}

void printListaReverse(linkedList lista){
	while(lista.tail != NULL){
		printf("%d ",lista.tail->num);
		lista.tail = lista.tail->prev;
	}printf("\n");
}

int main(){
	linkedList lista;
	
	lista.top = lista.tail == NULL;
	
	lista = insertTop(lista, 5);
	lista = insertTop(lista, 6);
	lista = insertTop(lista, 7);
	lista = insertTop(lista, 8);
	lista = insertTop(lista, 9);
	
	printLista(lista);
	printListaReverse(lista);
	
	return 0;
}
