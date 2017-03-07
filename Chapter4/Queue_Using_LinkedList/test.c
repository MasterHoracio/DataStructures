#include <stdio.h>
typedef struct{
	int num;
}QueueData;
#include "queue.h"

int main(){
	Queue q = initQueue();
	QueueData temp;
	int n;

	printf("Ingresa un numero: ");
	scanf("%d",&n);

	while(n){
		temp.num = n % 10;
		enqueue(q, temp);
		n /= 10;
	}

	printf("El numero invertido es: ");
	while(!empty(q)){
		printf("%d",dequeue(q).num);
	}printf("\n");

	return 0;
}