#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define DEFAULT -9999

typedef struct{
	int top;
	int ST[MAX];
} StackType, *Stack;

Stack initStack();
void push(Stack,int);
int pop(Stack);
int empty(Stack);

int main(){
	Stack S;
	int num;

	S = initStack();

	if(scanf("%d",&num) != 1)
		num = 0;

	while(num != 0){
		push(S, num);
		if(scanf("%d",&num) != 1)
			num = 0;
	}

	printf("Imprimiendo Stack\n");
	while(!empty(S)){
		printf("%d ",pop(S));
	}printf("\n");


	return 0;
}

Stack initStack(){
	Stack S = (Stack) malloc(sizeof(StackType));
	S -> top = -1;
	return S;
}

void push(Stack S, int num){
	if(S -> top == MAX - 1){
		printf("Stack Overflow\n");
		exit(1);
	}
	(S -> top)++;
	S -> ST[S -> top] = num;
}

int pop(Stack S){
	int temp;
	if(empty(S)){
		printf("Empty Srack");
		return DEFAULT;
	}
	temp = S -> ST[S -> top];
	(S -> top)--;
	return temp;
}

int empty(Stack S){
	return (S -> top == -1);
}