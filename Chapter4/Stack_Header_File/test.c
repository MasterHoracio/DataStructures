#include <stdio.h>
#include "stack.h"

int main(){
	int num;

	Stack S = initStack();

	if(scanf("%d",&num)!= 1)
		num = 0;

	while(num != 0){
		push(S,num);
		if(scanf("%d",&num) != 1)
			num = 0;
	}

	while(!empty(S)){
		printf("%d ",pop(S));
	}printf("\n");

	return 0;
}