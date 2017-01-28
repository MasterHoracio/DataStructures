#include <stdio.h>

typedef struct{
	int bit;
}StackData;

#include "stack.h"

int main(){
	Stack S = initStack();
	StackData temp;
	int num;

	printf("Enter a positive Integer: ");
	scanf("%d",&num);

	while(num > 0){
		temp.bit = num % 2;
		push(S, temp);
		num /= 2;
	}

	printf("Binary\n");
	while(!empty(S)){
		printf("%d",pop(S).bit);
	}printf("\n");

	return 0;
}