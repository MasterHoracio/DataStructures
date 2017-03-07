#include <stdlib.h>

typedef struct nodo{
	QueueData data;
	struct nodo *next;
}Nodo, *ptrNodo;

typedef struct{
	ptrNodo head, tail;
}typeQueue, *Queue;

Queue initQueue(){
	Queue q = (Queue) malloc(sizeof(typeQueue));
	q -> head = q -> tail = NULL;
	return q;
}

int empty(Queue q){
	return (q -> head == NULL);
}

void enqueue(Queue q, QueueData d){
	ptrNodo nod = (ptrNodo) malloc(sizeof(Nodo));
	nod -> data = d;
	nod -> next = NULL;
	if(empty(q)){
		q -> head = q -> tail = nod;
	}else{
		q -> tail -> next = nod;
		q -> tail = nod;
	}
}

QueueData dequeue(Queue q){
	if(empty(q)){
		printf("\nIntento de borrar elemento de cola cuando esta vacia\n");
		exit(1);
	}
	QueueData hold = q -> head -> data;
	ptrNodo temp = q -> head;
	q -> head = q -> head -> next;
	if(q -> head == NULL)
		q -> tail = NULL;
	free(temp);
	return hold;
}