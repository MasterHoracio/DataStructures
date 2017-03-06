#include <stdlib.h>

typedef struct{
	int head, tail;
	int QA[maxQ];
}typeQ, *Queue;

Queue initQueue(){
	Queue q = (Queue) malloc(sizeof(typeQ));
	q -> head = q -> tail = 0;
	return q;
}

int empty(Queue q){
	return (q -> head == q -> tail);
}

void enqueue(Queue q, int n){
	if(q -> tail == maxQ - 1)
		q -> tail = 0;
	else
		q -> tail += 1;
	if(q -> tail == q -> head){
		printf("\nQueue is full\n");
		exit(1);
	}
	q -> QA[q -> tail] = n;
}

int dequeue(Queue q){
	if(empty(q)){
		printf("\nQueue is empty\n");
		exit(1);
	}
	if(q -> head == maxQ - 1)
		q -> head = 0;
	else
		q -> head += 1;
	return q -> QA[q -> head];
}