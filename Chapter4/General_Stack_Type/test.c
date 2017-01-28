#include <stdio.h>

typedef struct{
	char ch;
}StackData;

#include "stack.h"

int main(){
	Stack S = initStack();
	StackData aux;
	char c;

	while((c = getchar()) != '\n'){
		aux.ch = c;
		push(S,aux);
	}

	printf("Reverse String\n");
	while(!empty(S)){
		printf("%c",pop(S).ch);
	}printf("\n");

	return 0;
}