#include <stdio.h>
#define maxQ 100
#include "queue.h"

int main(){
	Queue q = initQueue();
	int n;

	printf("Dame un numero: ");
	scanf("%d",&n);

	while(n){
		enqueue(q, n % 10);
		n /= 10;
	}

	printf("elementos invertidos\n");
	while(!empty(q)){
		printf("%d",dequeue(q));
	}printf("\n");

	return 0;
}